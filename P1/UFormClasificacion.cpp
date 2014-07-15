 //---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormClasificacion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormClasificacion *FormClasificacion;
//---------------------------------------------------------------------------
__fastcall TFormClasificacion::TFormClasificacion(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormClasificacion::ButtonSalirClick(TObject *Sender)
{
if (MessageDlg("Se va a cerrar la aplicacion. Los cambios no guardados se perderán. ¿Desea continuar?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        {
        Close();
        }
}

void TFormClasificacion::MostrarClasificacion(){
        //inicializar Grid
        for (int i=0;i<=torneo_numero_equipos(t)+1;i++){
            for(int j=0;j<=11;j++)
                GridClasificacion->Cells[j][i]="";
            }

        //Cabeceras columnas Grid
        GridClasificacion->RowCount=torneo_numero_equipos(t)+2;
        GridClasificacion->Cells[0][0]="Posicion";
        GridClasificacion->Cells[1][0]="Nombre";
        GridClasificacion->Cells[2][0]="Partidos jugados";
        GridClasificacion->Cells[3][0]="En casa";
        GridClasificacion->Cells[4][0]="Fuera";
        GridClasificacion->Cells[5][0]="PG";
        GridClasificacion->Cells[6][0]="PP";
        GridClasificacion->Cells[7][0]="PE";
        GridClasificacion->Cells[8][0]="GF";
        GridClasificacion->Cells[9][0]="GC";
        GridClasificacion->Cells[10][0]="Puntos";

        TEquipo* datos;
        AnsiString nombre_equipo;

        for (int pos=0;pos<torneo_numero_equipos(t);pos++){
            datos=torneo_linea_clasificacion(t,pos);

            GridClasificacion->Cells[0][pos+1]=pos+1;
            GridClasificacion->Cells[1][pos+1]=datos->nombre;
            GridClasificacion->Cells[2][pos+1]=datos->partidos_casa+datos->partidos_fuera;
            GridClasificacion->Cells[3][pos+1]=datos->partidos_casa;
            GridClasificacion->Cells[4][pos+1]=datos->partidos_fuera;
            GridClasificacion->Cells[5][pos+1]=datos->partidos_ganados;
            GridClasificacion->Cells[6][pos+1]=datos->partidos_perdidos;
            GridClasificacion->Cells[7][pos+1]=datos->partidos_empatados;
            GridClasificacion->Cells[8][pos+1]=datos->goles_favor;
            GridClasificacion->Cells[9][pos+1]=datos->goles_contra;
            GridClasificacion->Cells[10][pos+1]=datos->puntos;
            }//for

}//void MostrarClasificacion

//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::b_anyadir_equipo(TObject *Sender)
{
        TForm *x=new TFormAnyadirEquipo(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::crear_clasificacion(TObject *Sender)
{
        torneo_inicializar(t);
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::b_borrar_equipo(TObject *Sender)
{
        TForm *x=new TFormBorrarEquipo(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::b_anyadir_partido(TObject *Sender)
{
        TForm *x=new TFormAnyadirPartido(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::b_borrar_partido(TObject *Sender)
{
        TForm *x=new TFormBorrarPartido(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::b_listado_partidos(TObject *Sender)
{
        TForm *x=new TFormListadoPartidos(this,t);
        x->ShowModal();
        delete x;
        MostrarClasificacion();
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::Abrirtorneo1Click(TObject *Sender)
{
        if (DlgAbrirTorneo->Execute()){
            torneo_abrir(t,DlgAbrirTorneo->FileName);
            MostrarClasificacion();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::Guardartorneo1Click(TObject *Sender)
{
        if (DlgGuardarTorneo->Execute()){
            torneo_guardar(t,DlgGuardarTorneo->FileName);
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::Salir1Click(TObject *Sender)
{
     if (MessageDlg("Se va a cerrar la aplicacion. Los cambios no guardados se perderán. ¿Desea continuar?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        {
        Close();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::FormDestroy(TObject *Sender)
{
torneo_limpiar(t);        
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::NuevoTorneoClick(TObject *Sender)
{
if (MessageDlg("Va a comenzar un torneo nuevo. Los cambios no guardados se perderán. ¿Desea continuar?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        {
        torneo_limpiar(t);
        torneo_inicializar(t);
        MostrarClasificacion();
        }
}
//---------------------------------------------------------------------------

void __fastcall TFormClasificacion::Nuevotorneo1Click(TObject *Sender)
{
if (MessageDlg("Va a comenzar un torneo nuevo. Los cambios no guardados se perderán. ¿Desea continuar?",mtConfirmation,TMsgDlgButtons()<<mbYes<<mbNo,0)==mrYes)
        {
        torneo_limpiar(t);
        torneo_inicializar(t);
        MostrarClasificacion();
        }
}
//---------------------------------------------------------------------------



