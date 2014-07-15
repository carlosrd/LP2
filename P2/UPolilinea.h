//---------------------------------------------------------------------------

#ifndef UPolilineaH
#define UPolilineaH
#include "ULista.h"
#include "UPunto.h"

//---------------------------------------------------------------------------
class Polilinea{
        private:
        //Atributos
        Lista<Punto*> *listaLineas; //Lineas representadas por puntos
        int grosor;

        public:
        //Constructores
        //*************
        Polilinea(){
                this->listaLineas=new Lista<Punto>();
                this->listaLineas=NULL;
                this->grosor=1;
        };

        //Destructora
        //***********
        ~Polilinea(){
                delete(listaLineas);


        //Getters
        Lista<Punto>* getListaLineas(){
                return(this->listaLineas);
                }

        int getGrosor(){
                return(this->grosor);
                }

        //Setters
        void setGrosor(int grosor){
                this->grosor=grosor;
        

        //Cabeceras
        void anyadir_Punto(int x,int y,TColor color);

        void borrar_Punto(int x,int y,TColor color);







};

#endif

