//---------------------------------------------------------------------------

#ifndef UExcepcionesH
#define UExcepcionesH

#include "string.h"

class Excepcion {
protected:
        AnsiString Mensaje;
public:

        Excepcion(){
                Mensaje = "";
                }

        Excepcion(AnsiString error){
                Mensaje = error;
                }

        ~Excepcion(){};

        AnsiString getMensaje(){
                return Mensaje;
                }

};

class ExcepcionVector: public Excepcion{
public:
        ExcepcionVector(): Excepcion(){
                 Mensaje = "¡Error accediendo al vector!";
                 };
        ExcepcionVector(AnsiString error): Excepcion(error){};
        ~ExcepcionVector(){};
};

class ExcepcionInFichero: public Excepcion{
public:
        ExcepcionInFichero(): Excepcion(){
                 Mensaje = "¡Error cargando desde el fichero!";
                 };
        ExcepcionInFichero(AnsiString error): Excepcion(error){};
        ~ExcepcionInFichero(){};

        AnsiString getMensajeErrorTipo(){
                return "Error cargando desde fichero! No se pudo leer el tipo de grafico. Compruebe que el archivo elegido es un archivo valido.";
                }

        AnsiString getMensajeErrorLinea(int numLinea,AnsiString tipo){
                numLinea+=2;
                AnsiString msj = "¡Error cargando grafico ";
                msj+=tipo;
                msj+=" desde fichero en linea ";
                msj+=numLinea;
                msj+="! Por favor, compruebe que el archivo elegido es un archivo valido";
                return msj;
                }
};



//---------------------------------------------------------------------------
#endif
