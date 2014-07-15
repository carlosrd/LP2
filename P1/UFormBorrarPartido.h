//---------------------------------------------------------------------------

#ifndef UFormBorrarPartidoH
#define UFormBorrarPartidoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UTorneo.h"
//---------------------------------------------------------------------------
class TFormBorrarPartido : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBoxEquipoCasa;
        TComboBox *ComboBoxEquipoVisitante;
        TButton *ButtonBorrarEquipo;
        TButton *ButtonCancelar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall ButtonBorrarEquipoClick(TObject *Sender);
private:	// User declarations
        TTorneo &t;
public:		// User declarations
        __fastcall TFormBorrarPartido(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormBorrarPartido *FormBorrarPartido;
//---------------------------------------------------------------------------
#endif
