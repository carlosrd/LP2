//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormFiltro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TFormFiltro::TFormFiltro(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormFiltro::Button1Click(TObject *Sender)
{
        ModalResult = mrOk;        
}
//---------------------------------------------------------------------------

