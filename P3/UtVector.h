//---------------------------------------------------------------------------

#ifndef UtVectorH
#define UtVectorH

#include <typeinfo>
#include "fstream.h"
#include "UExcepciones.h"

template <class T>
class tVector {

private:	// User declarations
        // indica puntero a un vector, cuyas posiciones son punteros tb
        T* *vector;
        int numElem;
        int size;



public:		// User declarations

     // Constructora
     // ************
        tVector(){
                numElem = 0;
                size = 1;
                vector = new T*[size];
        } //ctor

     // Destructora
     // ***********
        ~tVector(){
                for (int i=0; i<numElem; i++){
                    delete vector[i];
                    vector[i] = NULL;
                    } // for
                delete []vector;
                vector = NULL;
                size = 0;
        } // dtor

     // Consultoras
     // ***********
        T* tVector<T>::operator[] (int i){
                if (i > size){
                   ExcepcionVector e;
                   throw Exception(e.getMensaje());
                   }
                 else
                   return vector[i];
                } // operator []

        int getNumElementos(){
                return numElem;
                }
                
     // Metodos
     // *******
        void ponElemento(T* dato) throw (ExcepcionVector){
                if (numElem == size)
                   resize();

                vector[numElem] = dato;
                numElem++;
        } // ponElemento

        void resize(){
                size*=2;
                T** vAux = new T*[size];

                for (int i=0; i<numElem; i++)
                    vAux[i] = vector[i];

                delete []vector;
                vector = vAux;
        } // resize


        bool borraElemento(int pos){

            if (pos!=-1){
                delete vector[pos];

                for (int i=pos; i<numElem-1; i++)
                    vector[i] = vector[i+1];

                numElem--;

                return(true);
                }
              else
                return(false);
        } //borraElemento


        void borraTodo(){
                for (int i=0; i<numElem; i++){
                    delete vector[i];
                    vector[i] = NULL;
                    } // for
                delete []vector;

                numElem = 0;
                size = 1;
                vector = new T*[size];
                }
                
        void guardarVector(ofstream &fs){
                fs << numElem << endl;
                for (int i=0; i<numElem; i++){
                    if (typeid(*vector[i]) == typeid(tRectangulo))
                       fs << "\\Rectangulo";
                    if (typeid(*vector[i]) == typeid(tElipse))
                       fs << "\\Elipse";
                    if (typeid(*vector[i]) == typeid(tLinea))
                       fs << "\\Linea";
                    if (typeid(*vector[i]) == typeid(tTexto))
                       fs << "\\Texto";
                    if (typeid(*vector[i]) == typeid(tBMP))
                       fs << "\\BMP";
                    //vector[i]->salvarFich(fs);
                    fs << vector[i];
                    } // for

        } // guardarFichero

        bool cargarVector(ifstream &fe){
             tGrafico* grafico;
             int max;
             try{
                fe >> max;
                }
             catch (const Exception &e){
                throw Exception("¡Error mientras se cargaba el numero de graficos! Compruebe que el archivo seleccionado es un archivo valido.");
                }
                int i = 1;

                //tGrafico* grafico;
                string stipo;
                while (i <= max){
                      try {
                          fe >> stipo;
                          }
                      catch (const Exception &e){
                          ExcepcionInFichero ef;
                          FormEditor->Color = clWhite;
                          fe.close();
                          throw Exception(ef.getMensajeErrorTipo());
                          }
                      if (stipo=="\\Rectangulo")
                         grafico = new tRectangulo();
                      if (stipo=="\\Elipse")
                         grafico = new tElipse();
                      if (stipo=="\\Linea")
                         grafico = new tLinea();
                      if (stipo=="\\Texto")
                         grafico = new tTexto();
                      if (stipo=="\\BMP")
                         grafico = new tBMP();

                      // Si el grafico es Nulo, es que se ha leido un string
                      // que no contiene el tipo de grafico = ERROR   
                      if (grafico!=NULL){
                         // Probar a cargar parametros del grafico
                         try{
                            //grafico->leerFich(fe);
                            fe >> grafico;
                            ponElemento(grafico);
                            }
                         catch (const Exception &e){
                            borraTodo();
                            delete grafico;
                            ExcepcionInFichero ef;
                            FormEditor->Color = clWhite;
                            fe.close();
                            throw Exception(ef.getMensajeErrorLinea(i,stipo.c_str()));
                            } // catch
                         } // if
                       else {
                         // El tipo leido no es valido
                         borraTodo();
                         ExcepcionInFichero e;
                         FormEditor->Color = clWhite;
                         fe.close();
                         throw Exception(e.getMensajeErrorTipo());
                         } // else
                         
                      grafico = NULL;
                      i++;
                      } // while

        } // guardarFichero


}; // class tVector

//---------------------------------------------------------------------------
#endif
 