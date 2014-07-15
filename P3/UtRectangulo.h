//---------------------------------------------------------------------------

#ifndef UtRectanguloH
#define UtRectanguloH

#include "UtGrafico.h"



class tRectangulo : public tGrafico {


public:		// User declarations

     // Constructoras
     // *************
        // Ctor por defecto
        tRectangulo() : tGrafico(){};

        tRectangulo(int x1, int y1, int x2, int y2,
                    TColor c, bool r, int g ) : tGrafico(x1,y1,x2,y2,c,r,g){};

     // Destructora
     // ***********
        virtual ~tRectangulo(){};

     // Metodos
     // *******
        void dibujar(TCanvas* canvas);
        tGrafico* copiar();
        void salvarFich(ofstream& archivo);
        void leerFich(ifstream& archivo);

}; // class tRectangulo





//---------------------------------------------------------------------------
#endif
 