//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAnyadirPartido.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnyadirPartido *FormAnyadirPartido;
//---------------------------------------------------------------------------
__fastcall TFormAnyadirPartido::TFormAnyadirPartido(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAnyadirPartido::FormCreate(TObject *Sender)
{
         int num_equipos=torneo_numero_equipos(t);
        AnsiString nombre_equipo;

        for (int i=0; i<num_equipos; i++){
            torneo_nombre_equipo(t,i,nombre_equipo);
            ComboBoxEquipoCasa->Items->Values[i]=nombre_equipo;
        }

        for (int i=0; i<num_equipos; i++){
            torneo_nombre_equipo(t,i,nombre_equipo);
            ComboBoxEquipoVisitante->Items->Values[i]=nombre_equipo;
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirPartido::ButtonCancelarClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirPartido::ButtonAnyadirEquipoClick(
      TObject *Sender)
{

    if ((EditGolesEquipoCasa->Text=="") || (EditGolesEquipoVisitante->Text==""))
       ShowMessage("Introduzca un valor para los goles");
     else { 
        int a=torneo_anyadir_partido(t,ComboBoxEquipoCasa->ItemIndex,
                                    ComboBoxEquipoVisitante->ItemIndex,
                                    EditGolesEquipoCasa->Text.ToInt(),
                                    EditGolesEquipoVisitante->Text.ToInt());

        switch (a){
                case 0: {
                        ShowMessage("Se ha añadido el partido");
                        Close();
                        }//case 0
                        break;
                case -1: ShowMessage("Los equipos son el mismo");
                            break;
                case -2: {
                          if (MessageDlg("El partido ya ha sido jugado. ¿Deseas sobreescribirlo?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
                              {
                              torneo_borrar_partido(t,
                                                    ComboBoxEquipoCasa->ItemIndex,
                                                    ComboBoxEquipoVisitante->ItemIndex);

                              torneo_anyadir_partido(t,
                                                    ComboBoxEquipoCasa->ItemIndex,
                                                    ComboBoxEquipoVisitante->ItemIndex,
                                                    EditGolesEquipoCasa->Text.ToInt(),
                                                    EditGolesEquipoVisitante->Text.ToInt());

                              ShowMessage("Se ha sobreescrito el partido con éxito");
                              Close();
                              }//if
                        }//case2
                        break;
                case -3: ShowMessage("El valor introducido para los goles no es valido");
                         break;
                } //switch (a)
           } //else
}
//---------------------------------------------------------------------------

