//---------------------------------------------------------------------------

#ifndef UtBMPH
#define UtBMPH

#include "UtGrafico.h"


class tBMP : public tGrafico {

private:
        AnsiString nombreArchivo;
        Graphics::TBitmap* bmp;

public:		// User declarations

     // Constructoras
     // *************
        // Ctor por defecto
        tBMP() : tGrafico(){
                 bmp = new Graphics::TBitmap();
                 };

        tBMP(int Xi, int Yi,const AnsiString &arch) : tGrafico(){
                    nombreArchivo = arch;
                    setPuntoSingular(Xi,Yi);
                    bmp = new Graphics::TBitmap();
                    bmp->LoadFromFile(arch.c_str());
                    };

     // Destructora
     // ***********
        virtual ~tBMP(){
                delete bmp;
                }; // dtor
        
     // Modificadora
     // ************
        /*void setNombreArchivo(AnsiString archivo){
                nombreArchivo = archivo;
                bmp->LoadFromFile(nombreArchivo.c_str());
                } // setNombreArchivo
        /*/
                
     // Métodos
     // *******
        void dibujar(TCanvas* canvas);
        tGrafico* copiar();
        void salvarFich(ofstream& archivo);
        void leerFich(ifstream& archivo);

}; // class tLinea

//---------------------------------------------------------------------------
#endif
