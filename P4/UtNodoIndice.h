//---------------------------------------------------------------------------

#ifndef UtNodoIndiceH
#define UtNodoIndiceH

#include "UtPalabra.h"
#include "UtBST.h"

class tNodoIndice {
        friend void BST_inicializaDato(tNodoIndice* &a);
        friend void BST_actualizaDato(tNodoIndice* &a,tNodoIndice* b);
        friend void BST_NodoToString(tNodoIndice* a,AnsiString &c);
        friend void BST_mostrarNodo(tNodoIndice *a,TStrings* p);
        friend bool mayorAbb(tNodoIndice* a,tNodoIndice* b);
        friend bool igualesAbb(tNodoIndice* a,tNodoIndice* b);
private:

        char letra;
        tBST<tPalabra*> *palabras;

public:
        tNodoIndice();
        tNodoIndice(char let,string pal,int np);
        ~tNodoIndice();
};
//---------------------------------------------------------------------------

// Funcionas amigas para la clase "tNodoIndice"

void BST_inicializaDato(tNodoIndice* &a){a = NULL;};
void BST_asignaDato(tNodoIndice* &a,tNodoIndice* b){a=b;};
void BST_eliminaDato(tNodoIndice* a){delete a;};
void BST_actualizaDato(tNodoIndice* &a,tNodoIndice* b){
        tPalabra* w1 = b->palabras->raiz();
        tPalabra* w2 = new tPalabra(w1);
        delete b;
        a->palabras->insertar(w2);
};
void BST_mostrarNodo(tNodoIndice *a,TStrings* p){
        p->Add(" ");
        p->Add(a->letra);
        p->Add("*******");
        a->palabras->mostrar(p);
}
void BST_NodoToString(tNodoIndice* a,AnsiString &c){
        c = UpCase(a->letra);
       //a->palabras->mostrar(p);
}

bool mayorAbb(tNodoIndice* a,tNodoIndice* b){return a->letra < b->letra;};
bool igualesAbb(tNodoIndice* a,tNodoIndice* b){return a->letra == b->letra;};



//---------------------------------------------------------------------------
#endif
