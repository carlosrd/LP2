//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtNodoIndice.h"


tNodoIndice::tNodoIndice(){
        this->letra ='@';
        this->palabras = NULL;
}

tNodoIndice::tNodoIndice(char let,string pal,int np){
        this->letra = let;
        tPalabra* w = new tPalabra(pal,np);
        this->palabras = new tBST<tPalabra*>;
        this->palabras->insertar(w);
}

tNodoIndice::~tNodoIndice(){
        delete this->palabras;
}




//---------------------------------------------------------------------------

#pragma package(smart_init)
