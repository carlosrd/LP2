//---------------------------------------------------------------------------

#ifndef UFormClasificacionH
#define UFormClasificacionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include "UTorneo.h"
#include "UFormAnyadirEquipo.h"
#include "UFormBorraEquipo.h"
#include "UFormAnyadirPartido.h"
#include "UFormBorrarPartido.h"
#include "UFormListadoPartidos.h"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFormClasificacion : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *GridClasificacion;
        TButton *ButtonAnyadirEquipo;
        TButton *ButtonBorrarEquipo;
        TButton *ButtonAnyadirPartido;
        TButton *ButtonBorrarPartido;
        TButton *ButtonListadoPartidos;
        TButton *ButtonSalir;
        TMainMenu *MenuDesplegable;
        TMenuItem *Archivo1;
        TMenuItem *Abrirtorneo1;
        TMenuItem *Guardartorneo1;
        TMenuItem *N1;
        TMenuItem *Salir1;
        TOpenDialog *DlgAbrirTorneo;
        TSaveDialog *DlgGuardarTorneo;
        TButton *NuevoTorneo;
        TMenuItem *Nuevotorneo1;
        void __fastcall ButtonSalirClick(TObject *Sender);
        void __fastcall b_anyadir_equipo(TObject *Sender);
        void __fastcall crear_clasificacion(TObject *Sender);
        void __fastcall b_borrar_equipo(TObject *Sender);
        void __fastcall b_anyadir_partido(TObject *Sender);
        void __fastcall b_borrar_partido(TObject *Sender);
        void __fastcall b_listado_partidos(TObject *Sender);
        void __fastcall Abrirtorneo1Click(TObject *Sender);
        void __fastcall Guardartorneo1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall NuevoTorneoClick(TObject *Sender);
        void __fastcall Nuevotorneo1Click(TObject *Sender);
private:	// User declarations
        TTorneo t;
        void MostrarClasificacion();
public:		// User declarations
        __fastcall TFormClasificacion(TComponent* Owner, TTorneo &x);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormClasificacion *FormClasificacion;
//---------------------------------------------------------------------------
#endif
