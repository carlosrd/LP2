//---------------------------------------------------------------------------

#ifndef UListaH
#define UListaH


//---------------------------------------------------------------------------

template <class T>
class Lista{
        friend class Punto;
        friend class Polilinea;
        friend void asigna(Punto* &p1,Punto* p2);
        friend void asigna(Polilinea*& p1,Polilinea* p2);
        friend bool compara(Punto*& p1,Punto* p2);

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
        //Constructores
        template <class T>
        Lista(){
                this->primero=NULL;
                this->segundo=NULL;
                this->num_elementos=0;
        }

        //Destructora
        //***********
        ~Lista(){
                Nodo *aux_ant,*aux_act;
                aux_act=this->primero;

                if (aux_act!=NULL){
                   aux_ant=aux_act;

                   while (aux_act!=NULL){
                         aux_act=aux_act->sig;
                         delete(aux_ant->info);
                         delete(aux_ant);
                         aux_ant=aux_act;
                         }//while
                   }//if
        } //~Lista


        //Getters
        //*******
        template <class T>
        int getNumElementos(){
                return(this->num_elementos);
        }

        template <class T>
        Nodo* getPrimero(){
                return(this->primero);
        }

        template <class T>
        Nodo* getUltimo(){
                return(this->ultimo);
        }

        template <class T>
        Nodo* getElementoEnPos(int n){
                Nodo *aux;
                aux=this->primero;

                if (aux!=NULL){
                   int j=1;
                   while (j<n) && (aux!=NULL)
                         aux=aux->sig;
                   }

                return(aux);
        }

        template <class T>
        int getPosicionElemento(const T& dato){
                Nodo *aux;
                aux=this->primero;

                bool iguales=false;
                int pos=0;
                
                if (aux!=NULL){
                   while ((aux!=NULL) && !(iguales)) {
                         iguales=compara(aux->info,dato);
                         aux=aux->sig;
                         pos++
                   }

                return(aux);
        }

        //Setters
        //*******
        template <class T>
        void setNumElementos(int num){
                this->num_elementos=num;
        }

        template <class T>
        void setPrimero(Nodo* primero){
                this->primero=primero;
        }

        template <class T>
        void setUltimo(Nodo* ultimo){
                this->ultimo=ultimo;
        }

        //Metodos
        //*******
        template <class T>
        void anyadirElemento(const T& dato){
                Nodo* tmp;
                tmp = new Nodo;

                asigna(tmp->info,dato);
                tmp->sig=NULL;

                //Si no es nulo, al final de la lista, sino es el primero
                if (this->primero!=NULL){
                    this->ultimo->sig=tmp;
                    this->ultimo=lista->ultimo->sig;
                    }
                 else {
                    this->primero=tmp;
                    this->ultimo=this->primero;
                    }

                this->num_elementos++;
        }

        template <class T>
        bool borrarElemento(int pos){
                Nodo *aux_ant,*aux_act;
                aux_act=this->primero;
                aux_ant=NULL;

                int i=1;

                if (aux_act!=NULL){ 
                   while ((aux_act!=NULL) && (i<pos)){
                         aux_ant=aux_act;
                         aux_act=aux_act->sig;
                         i++
                         }

                   if (aux_act=this->primero)
                      this->primero=aux_act->sig;
                    else
                      aux_ant->sig=aux_act->sig;

                   delete(aux_act->info);
                   delete(aux_act);

                   this->num_elementos--;

                   return(true);
                   }
                 else
                   return(false);

        } //borrarElemento

};


#endif

