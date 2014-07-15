//---------------------------------------------------------------------------

#ifndef UtBSTH
#define UtBSTH

#include <string>
#include <iostream>
#include "UExcepciones.h"

using namespace std;

//---------------------------------------------------------------------------

template <class S>
class tBST {
protected:
        S dato;
        tBST<S>* HI;
        tBST<S>* HD;

        S maximo();
public:
        tBST();            // hecho
        tBST(const tBST<S>& a);    // hecho
        ~tBST();                   // hecho
        S raiz(){return dato;};    // hecho
        bool esVacio();            // hecho
        bool esHoja();              // hecho
        int getNumElementos();
        void insertar(const S& info);   // hecho
        void eliminar(const S& info);    // hecho
        void eliminarAux();              // hecho
        void mostrar(TStrings* p);
        bool esta(const S info);   // hecho
        AnsiString toString();
        void salvarArbol(ofstream &fs);

};


//---------------------------------------------------------------------------
// Constructora
// ************
template <class S>
tBST<S>::tBST()
{
        BST_inicializaDato(this->dato);
        HI = HD = NULL;
}


template <class S>
tBST<S>::tBST(const tBST<S>& a)
{
        if (a.esVacio()){
           HI = NULL;
           HD = NULL;
           BST_inicializaDato(dato);
           }
         else {
           HI = new tBST<*a.HI>;
           HD = new tBST<*a.HD>;
           BST_asignaDato(a,a.dato);
           }
}
//---------------------------------------------------------------------------
// Destructora
// ***********

template <class S>
tBST<S>::~tBST()
{
        if (esVacio())
           BST_eliminaDato(this->dato);
         else {
           BST_eliminaDato(this->dato);
           delete HI;
           HI = NULL;
           delete HD;
           HD = NULL;
           }
}


//---------------------------------------------------------------------------
// Metodos
// ************
template <class S>
bool tBST<S>::esVacio(){
        return HD==NULL && HI==NULL;
}
//---------------------------------------------------------------------------
template <class S>
bool tBST<S>::esHoja(){
        return HD->esVacio() && HI->esVacio();
}
//---------------------------------------------------------------------------
template <class S>
void tBST<S>::insertar(const S& info)
{
        if (esVacio()){
           BST_asignaDato(this->dato,info);
           HI = new tBST<S>;
           HD = new tBST<S>;
           }
         else{
           if (mayorAbb(info,dato))
              HI->insertar(info);
            else{
              if (mayorAbb(dato,info))
                 HD->insertar(info);
               else{
                 if (igualesAbb(dato,info))
                   BST_actualizaDato(dato,info);
                 }
              }
           }
}
//---------------------------------------------------------------------------
template <class S>
void tBST<S>::eliminar(const S& info)
{
        if (esVacio()){
           ExcepcionArbol e;
           throw Exception(e.getMensajeEliminar());
           }
         else { // 1
           if (mayorAbb(info,dato))
              HI->eliminar(info);
            else { // 2
              if (mayorAbb(dato,info))
                 HD->eliminar(info);
               else { // 3
                 if (igualesAbb(dato,info))
                    eliminarAux();
                   } // else 3
                } // else 2
             } // else 1
}


template <class S>
void tBST<S>::eliminarAux()
{
        tBST<S> *aux;
        if (esHoja()){
           BST_eliminaDato(dato);
           delete HI;
           delete HD;
           HD = HI = NULL;
           }
         else {
           if (HI->esVacio()){
              delete HI;
              HI = NULL;
              BST_eliminaDato(dato);
              BST_asignaDato(dato,HD->dato);
              aux = HD;
              HI = HD->HI;
              HD = HD->HD;
              aux->HD = NULL;
              aux->HI = NULL;
              delete aux;
              aux = NULL;
              }
            else {
              if (HD->esVacio()){
                 delete HD;
                 HD = NULL;
                 BST_eliminaDato(dato);
                 BST_asignaDato(dato,HI->dato);
                 aux = HI;
                 HD = HI->HD;
                 HI = HI->HI;
                 aux->HI = NULL;
                 aux->HD = NULL;
                 delete aux;
                 aux = NULL;
                 }
               else
                 if (!HI->esVacio() && !HD->esVacio()){
                    S max = HI->maximo();
                    BST_eliminaDato(dato);
                    BST_asignaDato(dato,max);
                    HI->eliminar(max);
                    }


              }
           }
}
//---------------------------------------------------------------------------
template <class S>
bool tBST<S>::esta(const S info)
{
        if (esVacio())
           return (false);
         else { // 1
           if (mayorAbb(info,dato))
              return HI->esta(info);
            else { // 2
              if (mayorAbb(dato,info))
                 return HD->esta(info);
               else { // 3
                 if (igualesAbb(dato,info))
                    return true;
                 } // else 3
              } // else 2
           } // else 1
}
//---------------------------------------------------------------------------
template <class S>
AnsiString tBST<S>::toString()
{
        AnsiString c = "";
        BST_NodoToString(dato,c);
        return c;
}
//---------------------------------------------------------------------------
template <class S>
void tBST<S>::mostrar(TStrings* p)
{
        if (HI != NULL)
           HI->mostrar(p);
        if (!esVacio())
           BST_mostrarNodo(dato,p);
        if (HD != NULL)
           HD->mostrar(p);

}
//---------------------------------------------------------------------------
template <class S>
S tBST<S>::maximo()
{
        if (HD->esVacio())
           return dato;
         else
           return HD->maximo();
}
//---------------------------------------------------------------------------

template <class S>
int tBST<S>::getNumElementos()
{
        //........
}
//---------------------------------------------------------------------------
template <class S>
void tBST<S>::salvarArbol(ofstream &fs)
{
        if (!esVacio()){
           AnsiString c;
           BST_NodoToString(dato,c);
           fs << c.c_str() << endl;
           }
        if (HI != NULL)
           HI->salvarArbol(fs);
        if (HD != NULL)
           HD->salvarArbol(fs);
}
//---------------------------------------------------------------------------


// Funcionas amigas para la clase "string"

void BST_inicializaDato(string &dato){dato = "#";};
void BST_asignaDato(string &a,string b){a=b;};
void BST_eliminaDato(string a){};
void BST_actualizaDato(string a,string b){};
bool igualesAbb(string a,string b){
        string pal = "";
        if (a == b)
           return true;
         else {
           pal = a;
           pal[0] = UpCase(pal[0]);
           if (pal == b)
              return true;
            else {
              pal = b;
              pal[0] = UpCase(pal[0]);
              if (pal == a)
                 return true;
               else
                 return false;
              }
           }
}
bool mayorAbb(string a,string b){
        if (igualesAbb(a,b))
           return false;
         else
           return a < b;
}
void BST_mostrarNodo(string a,TStrings *p){
        p->Add(a.c_str());
}
void BST_NodoToString(string a,AnsiString &c){
        c = a.c_str();
}

#endif
