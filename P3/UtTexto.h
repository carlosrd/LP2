//---------------------------------------------------------------------------

#ifndef UtTextoH
#define UtTextoH

#include "UtGrafico.h"


class tTexto : public tGrafico {

private:
        int tam;
        AnsiString cadena;

public:		// User declarations

     // Constructoras
     // *************
        // Ctor por defecto
        tTexto() : tGrafico(){};

        tTexto(int x1, int y1, int x2, int y2,
                    TColor c, bool r, int g ) : tGrafico(x1,y1,x2,y2,c,r,g){
                    tam = 10;
                    cadena = "";
                    };

     // Destructora
     // ***********
        virtual ~tTexto(){};

     // Modificadoras
     // *************
        void ponChar(char c){
                cadena+=c;
                }

        void borrarChar(){
                cadena.Delete(cadena.Length(),1);
                }

        void setTamFuente(int tam){
                this->tam = tam;
                }


     // Consultora
     // **********
        AnsiString getCadena(){
                return cadena;
                }

     // Métodos
     // *******
        void dibujar(TCanvas* canvas);
        tGrafico* copiar();
        void salvarFich(ofstream& archivo);
        void leerFich(ifstream& archivo);


}; // class tTexto




//---------------------------------------------------------------------------
#endif
