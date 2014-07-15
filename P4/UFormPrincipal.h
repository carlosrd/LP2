//---------------------------------------------------------------------------

#ifndef UFormPrincipalH
#define UFormPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>

#include "UtBST.h"
#include "UtNodoIndice.h"
#include "UFormAux.h"
#include "UFormFiltro.h"
#include <Dialogs.hpp>

#include <iostream>
#include "fstream.h"

//---------------------------------------------------------------------------
class TFormPrincipal : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TLabel *Label1;
        TMainMenu *MainMenu1;
        TMenuItem *IndicedePalabras1;
        TMenuItem *IndiceGeneral1;
        TMenuItem *Archivo1;
        TMenuItem *Generar1;
        TMenuItem *Mostrar1;
        TMenuItem *NuevoFiltro1;
        TMenuItem *AnyadirPalabra1;
        TMenuItem *MostrarFiltro1;
        TMenuItem *Nuevotexto1;
        TMenuItem *Abrirtexto1;
        TMenuItem *Guardartexto1;
        TMenuItem *Guardarcomo1;
        TMenuItem *Salir1;
        TSaveDialog *SaveDialog1;
        TOpenDialog *OpenDialog1;
        TMenuItem *Abrirfiltro1;
        TMenuItem *Guardarfiltrocomo1;
        TMenuItem *Guardar1;
        TMenuItem *Archivo2;
        TMenuItem *Eliminarpalabra1;
        TMenuItem *IndiceGeneral2;
        TMenuItem *Generar2;
        TMenuItem *Mostrar2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall Generar1Click(TObject *Sender);
        void __fastcall Mostrar1Click(TObject *Sender);
        void __fastcall NuevoFiltro1Click(TObject *Sender);
        void __fastcall AnyadirPalabra1Click(TObject *Sender);
        void __fastcall MostrarFiltro1Click(TObject *Sender);
        void __fastcall Nuevotexto1Click(TObject *Sender);
        void __fastcall Guardarcomo1Click(TObject *Sender);
        void __fastcall Abrirtexto1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Guardarfiltrocomo1Click(TObject *Sender);
        void __fastcall Abrirfiltro1Click(TObject *Sender);
        void __fastcall Guardartexto1Click(TObject *Sender);
        void __fastcall Guardar1Click(TObject *Sender);
        void __fastcall Eliminarpalabra1Click(TObject *Sender);
        void __fastcall Generar2Click(TObject *Sender);
private:	// User declarations

        tBST<tNodoIndice*> *indicePalabras;
        tBST<string> *filtro;
        tListaOrd<Seccion> *indiceGeneral;

        struct Seccion{
                AnsiString seccion;
                AnsiString titulo;
                int numPag;
        }

        AnsiString rutaArchivoActual;
        AnsiString rutaArchivoFiltro;

public:		// User declarations
        __fastcall TFormPrincipal(TComponent* Owner);

        void procesarLinea(AnsiString l,int &numPag);
        void leerBlancos(AnsiString linea,int &i);
        void leerPalabra(AnsiString linea,int &i,string pal,int &numPag);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormPrincipal *FormPrincipal;
//---------------------------------------------------------------------------
#endif
