//---------------------------------------------------------------------------

#ifndef UFormAuxH
#define UFormAuxH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormAux : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TFormAux(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TFormAux *FormAux;
//---------------------------------------------------------------------------
#endif
