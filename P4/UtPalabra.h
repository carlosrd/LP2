//---------------------------------------------------------------------------

#ifndef UtPalabraH
#define UtPalabraH

#include <string>
#include <iostream>
#include "UListaOrd.h"

using namespace std;

//---------------------------------------------------------------------------

class tPalabra {
        friend void BST_inicializaDato(tPalabra* &dato);
        friend void BST_actualizaDato(tPalabra* &a,tPalabra* b);
        friend void BST_NodoToString(tPalabra* a,AnsiString &c);
        friend bool mayorAbb(tPalabra* a,tPalabra* b);
        friend bool igualesAbb(tPalabra* a,tPalabra* b);
private:
        string cadena;
        tListaOrd<int>* listaPaginas;

public:
        tPalabra();
        tPalabra(const tPalabra* &w);
        tPalabra(string pal,int np);
        ~tPalabra();
};

//---------------------------------------------------------------------------

// Funcionas amigas para la clase "string"

void BST_inicializaDato(tPalabra* &a){a = NULL;};
void BST_asignaDato(tPalabra* &a,tPalabra* b){a=b;};
void BST_eliminaDato(tPalabra* a){delete a;};
void BST_actualizaDato(tPalabra* &a,tPalabra* b){
        int max = b->listaPaginas->getNumElementos();
        int np;
        for (int i=0; i < max; i++){
            np = b->listaPaginas->getElemento(i);
            a->listaPaginas->insertar(np);
            }
        delete b;
};
void BST_mostrarNodo(tPalabra *a,TStrings* p){
        AnsiString c = "";
        BST_NodoToString(a,c);
        p->Add(c);
}
void BST_NodoToString(tPalabra* a,AnsiString &c){
        c = a->cadena.c_str();
        c += ": ";
        c += a->listaPaginas->toString();
}
bool mayorAbb(tPalabra* a,tPalabra* b){
        if (igualesAbb(a,b))
           return false;
         else
           return a->cadena < b->cadena;
};
bool igualesAbb(tPalabra* a,tPalabra* b){
        string pal = "";
        if (a->cadena == b->cadena)
           return true;
         else {
           pal = a->cadena;
           pal[0] = UpCase(pal[0]);
           if (pal == b->cadena)
              return true;
            else {
              pal = b->cadena;
              pal[0] = UpCase(pal[0]);
              if (pal == a->cadena)
                 return true;
               else
                 return false;
              }
           }

};
//---------------------------------------------------------------------------
#endif
