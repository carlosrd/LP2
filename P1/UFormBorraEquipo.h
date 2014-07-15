//---------------------------------------------------------------------------

#ifndef UFormBorraEquipoH
#define UFormBorraEquipoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Utorneo.h"
//---------------------------------------------------------------------------
class TFormBorrarEquipo : public TForm
{
__published:	// IDE-managed Components
        TComboBox *ComboBoxEquipo;
        TButton *ButtonBorrarEquipo;
        TButton *ButtonCancelar;
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall ButtonBorrarEquipoClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
        TTorneo &t;
public:		// User declarations
        __fastcall TFormBorrarEquipo(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBorrarEquipo *FormBorrarEquipo;
//---------------------------------------------------------------------------
#endif
