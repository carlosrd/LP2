//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormBorrarPartido.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormBorrarPartido *FormBorrarPartido;
//---------------------------------------------------------------------------
__fastcall TFormBorrarPartido::TFormBorrarPartido(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormBorrarPartido::FormCreate(TObject *Sender)
{
        int num_equipos=torneo_numero_equipos(t);
        AnsiString nombre_equipo;

        for (int i=0;i<num_equipos;i++){
            torneo_nombre_equipo(t,i,nombre_equipo);
            ComboBoxEquipoCasa->Items->Values[i]=nombre_equipo;
        }


        for (int i=0;i<num_equipos;i++){
            torneo_nombre_equipo(t,i,nombre_equipo);
            ComboBoxEquipoVisitante->Items->Values[i]=nombre_equipo;
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarPartido::ButtonCancelarClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormBorrarPartido::ButtonBorrarEquipoClick(
      TObject *Sender)
{

        int a=torneo_borrar_partido(t,
                                     ComboBoxEquipoCasa->ItemIndex,
                                     ComboBoxEquipoVisitante->ItemIndex);

        if (a==-1)
                ShowMessage("Imposible borrar: Los equipos introducidos son el mismo");
            else {
                if (a==-2)
                        ShowMessage("Imposible borrar: El partido aun no ha sido jugado");
                        else {
                          ShowMessage("El partido ha sido borrado correctamente");
                          Close();
                          }
                  }

}
//---------------------------------------------------------------------------

