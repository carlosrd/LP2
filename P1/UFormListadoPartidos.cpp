//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UFormListadoPartidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormListadoPartidos *FormListadoPartidos;
//---------------------------------------------------------------------------
__fastcall TFormListadoPartidos::TFormListadoPartidos(TComponent* Owner, TTorneo &x)
        : TForm(Owner), t(x)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormListadoPartidos::FormCreate(TObject *Sender)
{
        int num_equipos=torneo_numero_equipos(t);
        AnsiString nombre_equipo;

        for (int i=0; i<num_equipos; i++){
            torneo_nombre_equipo(t,i,nombre_equipo);
            ComboBoxEquipo->Items->Values[i]=nombre_equipo;
            }

            GridListadoPartidos->RowCount=2;
            GridListadoPartidos->Cells[0][0]="Partido";
            GridListadoPartidos->Cells[1][0]="Equipo Casa";
            GridListadoPartidos->Cells[2][0]="Goles Equipo Casa";
            GridListadoPartidos->Cells[3][0]="Equipo Fuera";
            GridListadoPartidos->Cells[4][0]="Goles Equipo Fuera";

}
//---------------------------------------------------------------------------

void __fastcall TFormListadoPartidos::ButtonCancelarClick(TObject *Sender)
{
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TFormListadoPartidos::ComboBoxEquipoChange(TObject *Sender)
{
        int contador=1;
        int a;
        int goles_local;
        int goles_visitante;
        AnsiString nombreEquipo;

        ListaPartidos* aux;
        aux=t.partidos;

        //if (aux!=NULL)
        //   while (aux->sig!

        for (int id_visitante=0;id_visitante<torneo_numero_equipos(t);id_visitante++)
              {
              a=torneo_info_partido(t,ComboBoxEquipo->ItemIndex,id_visitante,
                        goles_local,goles_visitante);
              if (a==0){
                GridListadoPartidos->Cells[0][contador]=contador;

                torneo_nombre_equipo(t,ComboBoxEquipo->ItemIndex,nombreEquipo);
                GridListadoPartidos->Cells[1][contador]=nombreEquipo;

                GridListadoPartidos->Cells[2][contador]=goles_local;

                torneo_nombre_equipo(t,id_visitante,nombreEquipo);
                GridListadoPartidos->Cells[3][contador]=nombreEquipo;

                GridListadoPartidos->Cells[4][contador]=goles_visitante;
                contador++;
                }//if
        }//for

        for (int id_visitante=0;id_visitante<torneo_numero_equipos(t);id_visitante++){
              a=torneo_info_partido(t,id_visitante,ComboBoxEquipo->ItemIndex,
                        goles_local,goles_visitante);
              if (a==0){
                GridListadoPartidos->Cells[0][contador]=contador;

                torneo_nombre_equipo(t,id_visitante,nombreEquipo);
                GridListadoPartidos->Cells[1][contador]=nombreEquipo;

                GridListadoPartidos->Cells[2][contador]=goles_local;

                torneo_nombre_equipo(t,ComboBoxEquipo->ItemIndex,nombreEquipo);
                GridListadoPartidos->Cells[3][contador]=nombreEquipo;

                GridListadoPartidos->Cells[4][contador]=goles_visitante;
                contador++;
                }//if
        }//for

        GridListadoPartidos->RowCount=contador;


}
//---------------------------------------------------------------------------

