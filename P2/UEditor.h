//---------------------------------------------------------------------------

#ifndef UEditorH
#define UEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMainMenu *MainMenu1;
        TMenuItem *Polilinea1;
        TMenuItem *DibujarPolilinea1;
        TMenuItem *EliminarPolilinea1;
        TMenuItem *ColorFondo1;
        TMenuItem *ColorPolilinea1;
        TMenuItem *GrosorLinea1;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N31;
        TColorDialog *ColorDialog1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
          
private:	// User declarations
        UtDibujo* dibujo;
        TColor colorFondo;
        TColor colorActual;
        Polilinea* poliLineaActual;
        int grosorActual;
        bool dibujando;



public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
