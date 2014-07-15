//---------------------------------------------------------------------------

#ifndef UtGraficoH
#define UtGraficoH

#include "fstream.h"
#include "UExcepciones.h"

class tGrafico {

protected:	// User declarations

        int Xini;
        int Yini;
        
        int Xfin;
        int Yfin;

        // Propiedades del dibujo
        TColor color;
        bool relleno;
        int grosorLinea;

public:		// User declarations

     // Constructoras
     // *************

        tGrafico(){};

        tGrafico(int x1,int y1, int x2, int y2,
                 TColor colorActual, bool rellenoActual, int grosorActual){
                this->Xini = x1;
                this->Yini = y1;
                this->Xfin = x2;
                this->Yfin = y2;

                this->color = colorActual;
                this->relleno = rellenoActual;
                this->grosorLinea = grosorActual;
                } // ctor


     // Destructora
     // ***********

        ~tGrafico(){};

     // Modificadoras
     // *************
        void setCoordenadas(int x1, int y1, int x2, int y2){
                this->Xini = x1;
                this->Yini = y1;
                this->Xfin = x2;
                this->Yfin = y2;
                }

        void setPuntoSingular(int x, int y){
                this->Xini = x;
                this->Yini = y;
                }

     // Consultora
     // **********
        void getPuntoSingular(int &x, int &y){
                x = this->Xini;
                y = this->Yini;
                }

        void getPuntoNoSingular(int &x, int &y){
                x = this->Xfin;
                y = this->Yfin;
                }

     // Metodos
     // *******
        // Con "virtual" y "=0", metodo abstracto a definir después
        virtual void dibujar(TCanvas* canvas)=0;
        virtual tGrafico* copiar()=0;

        virtual void dibujarConPS(TCanvas* canvas){

                dibujar(canvas);

                canvas->MoveTo(this->Xini, this->Yini);
                canvas->Brush->Color = clBlack;
                canvas->Pen->Color = clBlack;
                canvas->Pen->Width = 4;
                canvas->Rectangle(this->Xini-4, this->Yini+4,
                                  this->Xini+4, this->Yini-4);
                                  
                } // dibujarConPS

        virtual void salvarFich(ofstream &archivo)=0;
        virtual void leerFich(ifstream &archivo)=0;

}; // class tGrafico

ofstream& operator << (ofstream& f,const tGrafico* &g)
{
        g->salvarFich(f);
        return f;
}

ifstream& operator >> (ifstream& f,const tGrafico* &g)
{
        g->leerFich(f);
        return f;
}



//---------------------------------------------------------------------------
#endif
 