//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ULista.h"

void Lista<T>::asigna(Punto* &p1,Punto* p2){
        p1=p2;
)

void Lista<T>::asigna(Polilinea* &p1,Polilinea* p2){
        p1=p2;
}

bool Lista<T>::compara(Punto* &p1,Punto* p2){
        return p1->getX()==p2->getX() &&
                p1->getY()==p2->getY() ;
}


//---------------------------------------------------------------------------

#pragma package(smart_init)






