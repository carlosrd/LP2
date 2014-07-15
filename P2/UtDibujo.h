//---------------------------------------------------------------------------

#ifndef UtDibujoH
#define UtDibujoH

#include "UPolilinea.h"
//---------------------------------------------------------------------------
class UtDibujo{

        private:
        //Atributos
        Lista<Polilinea*> *listaPolilineas;


        public:
        //Constructores
        //*************
        UtDibujo(){
                this->listaPolilineas=new Lista<Polilineas>();
                listaPolilineas=NULL;
        };

        //Destructora
        //*************
        ~UtDibujo(){
                delete(this->listaPolilineas);
        };

        //Getters
        //*******
        Lista<Polilineas*> getListaPolilineas(){
                return(this->listaPolilineas);
                }



        //Metodos
        //*******
        void anyadir_Polilinea(Lista<Punto*> *primero){
                this->listaPoliineas.anyadirElemento(primero);
        }

        void UtDibujo::borrar_Polilinea(int x,int y);
};





#endif
