//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UPolilinea.h"

//Metodos
//*******
void Polilinea::anyadir_Punto(int x,int y,TColor color){
        Punto *coordenada;
        coordenada = new Punto(x,y,color);

        this->listaLineas.anyadirElemento(coordenada);
}


bool Polilinea::borrar_Punto(int x,int y){
        Punto *coordenada;
        coordenada = new Punto(x,y,clBlack);

        int pos=this->listaLineas.getPosicionElemento(coordenada);

        delete(coordenada);

        if (pos!=-1){
           this->listaLineas.borrarElemento(pos);
           return(true);
           }
         else
           return(false);
}

void Polilinea::dibuja(TCanvas* canvas, int x, int y){
        canvas->Pen->Width(
        canvas->LineTo(x,y);
        canvas->MoveTo(x,y);
}






//---------------------------------------------------------------------------

#pragma package(smart_init)


