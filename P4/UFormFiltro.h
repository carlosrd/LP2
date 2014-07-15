//---------------------------------------------------------------------------

#ifndef UFormFiltroH
#define UFormFiltroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFormFiltro : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        TEdit *Edit2;
        TEdit *Edit3;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFormFiltro(TComponent* Owner);
};
//---------------------------------------------------------------------------
//extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
