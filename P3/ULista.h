//---------------------------------------------------------------------------

#ifndef UListaH
#define UListaH

#include "fstream.h"
//---------------------------------------------------------------------------

template <class T>
class Lista{
        private:

        struct Nodo {
                T info;
                Nodo* sig;
        };

        //Atributos
        Nodo* primero;
        Nodo* ultimo;
        int num_elementos;

        public:
                        
        //Constructora
        //************
        Lista(){
                this->primero=NULL;
                this->ultimo=NULL;
                this->num_elementos=0;
        } //ctor


        //Destructora
        //***********
        ~Lista(){
                Nodo *aux_ant,*aux_act;
                aux_act=this->primero;

                if (aux_act!=NULL){
                   aux_ant=aux_act;

                   while (aux_act!=NULL){
                         aux_act=aux_act->sig;
                         liberaMemoria(aux_ant->info);
                         delete(aux_ant);
                         aux_ant=aux_act;
                         }//while
                }//if
        } //~Lista




        //Getters
        //*******

        int getNumElementos(){
                return(this->num_elementos);
        }


        T getElementoEnPos(int n){
                Nodo *aux;
                aux=this->primero;

                if (aux!=NULL){
                   int j=1;
                   while ((j<n) && (aux!=NULL)){
                         aux=aux->sig;
                         j++;
                         }
                   }

                return(aux->info);
        }

        //Metodos
        //*******

        void anyadirElemento(const T& dato){
                Nodo* tmp;
                tmp = new Nodo;

                asigna(tmp->info,dato);
                tmp->sig=NULL;

                //Si no es nulo, al final de la lista, sino es el primero
                if (this->primero!=NULL){
                    this->ultimo->sig=tmp;
                    this->ultimo=this->ultimo->sig;
                    }
                 else {
                    this->primero=tmp;
                    this->ultimo=this->primero;
                    }

                this->num_elementos++;
        }

        bool borrarElemento(int pos){
                Nodo *aux_ant,*aux_act;
                aux_act=this->primero;
                aux_ant=NULL;

                if ((aux_act!=NULL) && (pos <= this->num_elementos)) {
                   int i=1;

                   while (i<pos){
                         aux_ant=aux_act;
                         aux_act=aux_act->sig;
                         i++;
                         } //while

                   if ((aux_act==this->primero) && (aux_act==this->ultimo)){
                      this->primero=NULL;
                      this->ultimo=NULL;
                      }
                    else { // 1
                      if (aux_act==this->primero)
                         this->primero=aux_act->sig;
                       else { //2
                         if (aux_act==this->ultimo)
                            this->ultimo=aux_ant;
                         aux_ant->sig=aux_act->sig;
                         } // else 2
                      } // else 1

                   liberaMemoria(aux_act->info);
                   delete(aux_act);

                   this->num_elementos--;

                   return(true);
                   } // if principal
                 else
                   return(false);

        } //borrarElemento
        
        void guardarLista(ofstream &fs){
             Nodo* aux;
             aux = this->primero;

             if (aux!=NULL){
                while (aux!=NULL){
                      guardaEnFichero(fs,aux->info);
                      aux = aux->sig;
                      } // while
                } // if
        } // guardarLista

        void cargarLista(ifstream &fe, T &dato, int numElem){

                while (numElem > 0){
                      dato = cargarDeFichero(fe,dato);
                      anyadirElemento(dato);
                      numElem--;
                      }



        } // cargarLista


}; // class Lista


#endif



