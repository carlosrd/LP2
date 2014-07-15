//---------------------------------------------------------------------------

#ifndef UEditorH
#define UEditorH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>

#include "UtVector.h"
#include "UtGrafico.h"
#include "UtRectangulo.h"
#include "UtElipse.h"
#include "UtLinea.h"
#include "UtTexto.h"
#include "UtBMP.h"
#include "UFormAux.h"

#include "fstream.h"
#include <ImgList.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>

//---------------------------------------------------------------------------
class TFormEditor : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *pintarRectangulo;
        TImageList *ImageList1;
        TToolButton *pintarElipse;
        TToolButton *pintarLinea;
        TToolButton *pintarTexto;
        TToolButton *pintarBMP;
        TOpenDialog *OpenDialog1;
        TToolButton *ToolButton1;
        TToolButton *setColorRelleno;
        TToolButton *setRelleno;
        TToolButton *setColorFondo;
        TColorDialog *ColorDialog1;
        TToolButton *setGrosorLinea;
        TToolButton *setTamFuente;
        TToolButton *ToolButton2;
        TToolButton *seleccionarGrafico;
        TToolButton *borrarGrafico;
        TToolButton *moverGrafico;
        TToolButton *copiarGrafico;
        TMainMenu *MainMenu1;
        TMenuItem *Archivo1;
        TMenuItem *NuevoDibujo1;
        TMenuItem *Guardarcomo1;
        TSaveDialog *SaveDialog1;
        TMenuItem *AbrirDibujo1;
        TToolButton *ToolButton3;
        TToolButton *NuevoDibujoButton;
        TToolButton *AbrirDibujoButton;
        TToolButton *GuardarDibujoButton;
        TMenuItem *Guardar1;
        TMenuItem *Salir1;
        TStatusBar *StatusBar1;
        TMenuItem *Edicin1;
        TMenuItem *Seleccionar1;
        TMenuItem *CopiarGrafico1;
        TMenuItem *CopiarGrfico1;
        TMenuItem *CopiarGrfico2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall pintarRectanguloClick(TObject *Sender);
        void __fastcall FormPaint(TObject *Sender);
        void __fastcall pintarElipseClick(TObject *Sender);
        void __fastcall pintarLineaClick(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall pintarTextoClick(TObject *Sender);
        void __fastcall pintarBMPClick(TObject *Sender);
        void __fastcall setRellenoClick(TObject *Sender);
        void __fastcall setColorRellenoClick(TObject *Sender);
        void __fastcall setColorFondoClick(TObject *Sender);
        void __fastcall setGrosorLineaClick(TObject *Sender);
        void __fastcall setTamFuenteClick(TObject *Sender);
        void __fastcall seleccionarGraficoClick(TObject *Sender);
        void __fastcall borrarGraficoClick(TObject *Sender);
        void __fastcall moverGraficoClick(TObject *Sender);
        void __fastcall copiarGraficoClick(TObject *Sender);
        void __fastcall Guardarcomo1Click(TObject *Sender);
        void __fastcall AbrirDibujo1Click(TObject *Sender);
        void __fastcall NuevoDibujo1Click(TObject *Sender);
        void __fastcall NuevoDibujoButtonClick(TObject *Sender);
        void __fastcall AbrirDibujoButtonClick(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall GuardarDibujoButtonClick(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
        void __fastcall Seleccionar1Click(TObject *Sender);
        void __fastcall CopiarGrafico1Click(TObject *Sender);
        void __fastcall CopiarGrfico1Click(TObject *Sender);
        void __fastcall CopiarGrfico2Click(TObject *Sender);
private:	// User declarations
        // Enumerado que indica el modo en el que estamos
        enum tipoGrafico {ninguno,rectangulo,elipse,linea,texto,BMP,
                          selectGrafico,moveGrafico,copyGrafico};

        // Vector que alamacena los graficos del dibujo
        tVector<tGrafico> vectorGraficos;

        // Parametros del dibujo
        TColor colorFondo;
        TColor colorActual;
        bool relleno;
        int tamFuenteActual;
        int grosorActual;
        AnsiString rutaArchivoActual;

        // Grafico temporal con el que trabajar
        tGrafico* graficoActual;
        int posGraficoActual;

        // En modo "mover Grafico" sirve para mantener la relacion
        // de aspecto del grafico durante el movimiento
        int distanciaX,distanciaY;

        // Variables de control de estado de la aplicacion
        tipoGrafico tipo_grafico;

        bool dibujando;
        bool moviendo;




public:		// User declarations
        __fastcall TFormEditor(TComponent* Owner);

        // Funciones propias
        void inicializarDibujo();
        void limpiarDibujo();
        void dibujarGraficos(TCanvas* canvas);
        void dibujarGraficosConPS(TCanvas* canvas);
        tGrafico* buscaGrafico(int x,int y,int &pos);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormEditor *FormEditor;
//---------------------------------------------------------------------------
#endif
