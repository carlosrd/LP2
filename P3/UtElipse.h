//---------------------------------------------------------------------------

#ifndef UtElipseH
#define UtElipseH

#include "UtGrafico.h"


class tElipse : public tGrafico {


public:		// User declarations

     // Constructoras
     // *************
        // Ctor por defecto
        tElipse() : tGrafico(){};

        tElipse(int x1, int y1, int x2, int y2,
                    TColor c, bool r, int g ) : tGrafico(x1,y1,x2,y2,c,r,g){};

     // Destructora
     // ***********
        virtual ~tElipse(){};


     // Métodos
     // *******
        void dibujar(TCanvas* canvas);
        tGrafico* copiar();
        void salvarFich(ofstream& archivo);
        void leerFich(ifstream& archivo);


}; // class tElipse

//---------------------------------------------------------------------------
#endif
