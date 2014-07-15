//---------------------------------------------------------------------------

#ifndef UDibujoH
#define UDibujoH

#include "ULista.h"
#include "UtGrafico.h"
//---------------------------------------------------------------------------
class Dibujo {

private:	// User declarations

        Lista<tGrafico*>* listaGraficos;


public:		// User declarations

     // Constructora
     // ************
        Dibujo(){
                this->listaGraficos = new Lista<tGrafico*>;
                }

     // Destructora
     // ***********
        ~Dibujo(){
                delete(this->listaGraficos);
                }

     // Metodos
     // *******
        void ponGrafico(tGrafico*  grafico){
                this->listaGraficos->anyadirElemento(grafico);
                } // ponGrafico

        void dibujarGraficos(TCanvas* canvas){

                tGrafico* grafico;
                int max = this->listaGraficos->getNumElementos();
                
                for (int i=1; i<=max; i++){
                    grafico = this->listaGraficos->getElementoEnPos(i);
                    grafico->dibujar(canvas);
                    } // for

                } // dibujarGraficos




}; // class Dibujo



//---------------------------------------------------------------------------
#endif
