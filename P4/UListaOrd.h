//---------------------------------------------------------------------------

#ifndef UListaOrdH
#define UListaOrdH

#include "limits.h"

template<class T>
class tListaOrd {

private:

        struct Nodo {
                T info;
                Nodo* sig;
        };

        struct puntoInteres {
                int indice;
                Nodo* pAnterior;
        };

        //Atributos
        T maximal;
        int longitud;
        
        Nodo* pCabecera;
        puntoInteres* pi;

public:

        tListaOrd();
        tListaOrd(tListaOrd<T>* l);
        ~tListaOrd();
        T getElemento(int indice);
        int getNumElementos(){return longitud;};
        void insertar(const T& dato);
        bool buscaPos(const T& dato);
        AnsiString toString();
        void mostrar(TStrings* p);


        // Metodos para el Punto de Interes
        // * * * * * * * * * * * * * * * * 
        void reiniciarPI(){
                pi->pAnterior = pCabecera;
                pi->indice = 0;
        }

        void avanzarPI(){
                pi->pAnterior = pi->pAnterior->sig;
                pi->indice++;
        }

};

// Constructora
// ************
template <class T>
tListaOrd<T>::tListaOrd()
{
        longitud = 0;
        T max;
        maximal = inicializaMaximal(max);

        pCabecera = new Nodo;
        pCabecera->sig = pCabecera;
        pCabecera->info = maximal;

        pi = new puntoInteres;
        pi->indice = 0;
        pi->pAnterior = pCabecera;
}

template <class T>
tListaOrd<T>::tListaOrd(tListaOrd<T>* l)
{
        longitud = 0;
        T max;
        maximal = inicializaMaximal(max);

        pCabecera = new Nodo;
        pCabecera->sig = pCabecera;
        pCabecera->info = maximal;

        pi = new puntoInteres;
        pi->indice = 0;
        pi->pAnterior = pCabecera;

        for (int i=0; i<l->longitud; i++)
            insertar(l->getElemento(i));

}
// Destructora
// ***********
template <class T>
tListaOrd<T>::~tListaOrd()
{
        reiniciarPI();
        pi->pAnterior = pi->pAnterior->sig;
        Nodo *aux;

        while (mayor(pi->pAnterior->info,maximal)){
              aux = pi->pAnterior;
              avanzarPI();
              liberaNodo(aux->info);
              delete(aux);
              }
              
        liberaNodo(pCabecera->info);
        delete(pCabecera);
        delete(pi);

}

// Consultoras
// ***********
template <class T>
T tListaOrd<T>::getElemento(int indice)
{
        if (indice < pi->indice)
           reiniciarPI();
        while (pi->indice < indice)
              avanzarPI();
        return (pi->pAnterior->sig->info);
}

// Metodos
// ********
template <class T>
bool tListaOrd<T>::buscaPos(const T& dato)
{
        if (mayor(dato,pi->pAnterior->sig->info))
           reiniciarPI();
        while (mayor(pi->pAnterior->sig->info,dato))
              avanzarPI();
        return iguales(dato,pi->pAnterior->sig->info);
}

template <class T>
void tListaOrd<T>::insertar(const T& dato)
{
        if (buscaPos(dato) == true)
           actualizaNodo(pi->pAnterior->sig->info,dato);
         else{
           Nodo* tmp = new Nodo;
           asignaNodo(tmp->info,dato);
           tmp->sig = pi->pAnterior->sig;

           pi->pAnterior->sig = tmp;
           longitud++;
           }
}

template <class T>
AnsiString tListaOrd<T>::toString()
{
        AnsiString cadena = "";
        reiniciarPI();
        int i = 0;
        while (mayor(pi->pAnterior->sig->info,maximal)){
              cadena += NodoToString(pi->pAnterior->sig->info,i);
              avanzarPI();
              i++;
              }
        return cadena;
}

// NO SE USA SI NO SE HACE EL OPCIONAL!
template <class T>
void tListaOrd<T>::mostrar(TStrings* p)
{
        p->Add(ListaToString());
}

// Funciones amigas clase "int"

int inicializaMaximal(int &a){return INT_MAX;};
void asignaNodo(int &a,int b){a=b;};
void liberaNodo(int a){};
void actualizaNodo(int a,int b){};
bool mayor(int a,int b){return a<b;};
bool iguales(int a,int b){return a==b;};
AnsiString NodoToString(int a,int i){
        AnsiString c;
        if (i != 0)
           c += ", ";
        c += a;
        return c;
};
                                         


//---------------------------------------------------------------------------
#endif
