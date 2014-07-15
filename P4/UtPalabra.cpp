//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UtPalabra.h"

tPalabra::tPalabra()
{
        this->cadena = "@";
        this->listaPaginas = NULL;
}

tPalabra::tPalabra(const tPalabra* &w)
{
        this->cadena = w->cadena;
        this->listaPaginas = new tListaOrd<int>(w->listaPaginas);
}

tPalabra::tPalabra(string pal,int np)
{
        this->cadena = pal;
        this->listaPaginas = new tListaOrd<int>;
        this->listaPaginas->insertar(np);
}

tPalabra::~tPalabra()
{
        delete this->listaPaginas;
}



//---------------------------------------------------------------------------

#pragma package(smart_init)
