//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtDibujo.h"



void UtDibujo::borrar_Polilinea(int x,int y){
        Punto *coordenada;
        coordenada = new Punto(x,y,clBlack);

        int polilinea=1;
        int max=this->listaPolilineas->getNumElementos();
        bool puntoEncontrado=false;

        *Nodo aux;
        aux=this->listaPolilineas->getPrimero();

        if (aux!=NULL){
           aux=aux->info;

           while (!(encontrado) && (polilinea<max)){
                 puntoEncontrado=aux->borrarPunto(x,y);
                 if !(puntoEncontrado){
                    polilinea++;
                    aux=this->listaPolilineas->getElementoEnPos(polilinea);
                    aux=aux->info;
                    } // if
                 }// while
           } // if



        delete(coordenada);


};


//---------------------------------------------------------------------------

#pragma package(smart_init)







