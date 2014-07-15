//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAnyadirEquipo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormAnyadirEquipo *FormAnyadirEquipo;
//---------------------------------------------------------------------------
__fastcall TFormAnyadirEquipo::TFormAnyadirEquipo(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirEquipo::ButtonCancelarClick(TObject *Sender)
{
        Close();        
}
//---------------------------------------------------------------------------

void __fastcall TFormAnyadirEquipo::ButtonAnyadirEquipoClick(
      TObject *Sender)
{
        if (EditNombreEquipo->Text=="")
           ShowMessage("Escribe un nombre por favor");
         else { //1
           int a=torneo_anyadir_equipo(t,EditNombreEquipo->Text);
           if (a==-1)
              ShowMessage("No se pueden añadir más equipos");
            else { //2
              if (a==-2)
                 ShowMessage("Ya existe un equipo con ese nombre");
               else
                 Close();
              } //else 2

           }//else 1        
}
//---------------------------------------------------------------------------

