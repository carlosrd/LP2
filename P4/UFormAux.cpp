//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormAux.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//TFormAux *FormAux;
//---------------------------------------------------------------------------
__fastcall TFormAux::TFormAux(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormAux::FormClose(TObject *Sender, TCloseAction &Action)
{
        ModalResult = mrOk;        
}
//---------------------------------------------------------------------------
