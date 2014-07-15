//---------------------------------------------------------------------------

#ifndef UFormAnyadirPartidoH
#define UFormAnyadirPartidoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "UTorneo.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFormAnyadirPartido : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TComboBox *ComboBoxEquipoCasa;
        TComboBox *ComboBoxEquipoVisitante;
        TEdit *EditGolesEquipoCasa;
        TEdit *EditGolesEquipoVisitante;
        TLabel *Label3;
        TLabel *Label4;
        TButton *ButtonAnyadirEquipo;
        TButton *ButtonCancelar;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ButtonCancelarClick(TObject *Sender);
        void __fastcall ButtonAnyadirEquipoClick(TObject *Sender);
private:	// User declarations
        TTorneo &t;
public:		// User declarations
        __fastcall TFormAnyadirPartido(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormAnyadirPartido *FormAnyadirPartido;
//---------------------------------------------------------------------------
#endif
