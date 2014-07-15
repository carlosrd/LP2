//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTorneo.h"
#include <fstream>
#include <iostream>
using namespace std;

void torneo_inicializar(TTorneo &t){
        t.num_equipos=0;

        t.equipos.primero=NULL;
        t.equipos.ultimo=NULL;

        t.clasificacion.primero=NULL;
        t.clasificacion.ultimo=NULL;

        t.partidos=NULL;
} //torneo_inicializar



void torneo_limpiar_arbol(ArbolPartidos* &arbol) {
  if ( arbol != NULL ) {
    torneo_limpiar_arbol(arbol->izq);
    torneo_limpiar_arbol(arbol->der);
    delete arbol;
  }
} //torneo_limpiar_arbol



void torneo_limpiar (TTorneo &t){

     //limpiar lista clasificacion
     //*******************************
        //Si los punt primeros apuntan a nulo la lista a
        //limpiar esta vacia y no hay que hacer nada
     if (t.clasificacion.primero!=NULL){
     
        ListaEquipos *aux_sig,*aux_act;

        aux_act=t.clasificacion.primero;
        aux_sig=NULL;

        while (aux_act!=NULL){
              aux_sig=aux_act->sig;
              delete(aux_act);
              aux_act=aux_sig;
              }

        }// limpiar clasif
        //limpiar equipos

        //limpiar lista partidos
        //*************************
     if (t.partidos!=NULL){

        torneo_limpiar_arbol(t.partidos);

        }// limpiar partidos


        //limpiar lista equipos
        //***********************
     if (t.equipos.primero!=NULL){

        ListaEquipos *aux_sig,*aux_act;

        aux_act=t.equipos.primero;
        aux_sig=NULL;

        while (aux_act!=NULL){
              aux_sig=aux_act->sig;
              delete(aux_act->info);
              delete(aux_act);
              aux_act=aux_sig;
              }
        }

} //torneo_limpiar



int torneo_numero_equipos(TTorneo t){
        return(t.num_equipos);
} // torneo_numero_equipos



int torneo_id_equipo(TTorneo t,AnsiString nombre_equipo){

        ListaEquipos* tmp;
        tmp=t.equipos.primero;
        
        int cont=0;
        while ((tmp->info->nombre!=nombre_equipo) &&
              (tmp!=NULL)){
              cont++;
              tmp=tmp->sig;
              }
        return(cont);
} //torneo_id_equipo



bool torneo_validar_id(int id_local, int id_visitante){

        if ((id_visitante<0) && (id_visitante>=MAX_EQUIPOS) ||
           (id_local<0) && (id_local>=MAX_EQUIPOS) ||
           (id_visitante==id_local))
           return(true);
         else
           return(false);

} //torneo_id_valido



bool torneo_nombre_equipo(TTorneo t, int id_equipo,
                          AnsiString &nombre_equipo){

        ListaEquipos* aux;
        aux=t.equipos.primero;

        int cont=0;

        if ((id_equipo<MAX_EQUIPOS) && (id_equipo>=0) && (aux!=NULL)){
           while (cont<id_equipo){
                 aux=aux->sig;
                 cont++;
                 }
           nombre_equipo=aux->info->nombre;
           return(true);
           }
        else
           return(false);
}  //torneo_nombre_equipo



//Funcion que coloca el puntero apuntando al partido solicitado o nulo en otro caso
//************************************************************************************
ArbolPartidos* torneo_busca_partido(TTorneo t, int id_local, int id_visitante){

        AnsiString nombre_local;
        AnsiString nombre_visitante;

        torneo_nombre_equipo(t,id_local,nombre_local);
        torneo_nombre_equipo(t,id_visitante,nombre_visitante);

        /* Para buscar el partido, usaremos el metodo "paritod_mayor" que
           que nos indica en que direccion buscar. Como recibe parametros de
           tipo TPartido, crearemos una caja artifical de este tipo y la
           rellenaremos solo con los nombres que es lo relevante en "partido mayor"
           Despues, sera pasar esta nueva caja por el metodo de modo cte
        */

        // Buscamos la direccion del equipo en la lista de equipos para agregarla
        // a nuestra caja artificial

        ListaEquipos* aux_local;
        ListaEquipos* aux_visitante;

        aux_local=t.equipos.primero;
        aux_visitante=aux_local;

        //colocar punteros auxiliares para modificar resumenes de equipos
        while (aux_local->info->nombre!=nombre_local)
              aux_local=aux_local->sig;

        while (aux_visitante->info->nombre!=nombre_visitante)
              aux_visitante=aux_visitante->sig;

        // Creamos la caja artificial y enlazamos
        TPartido tmp;

        tmp.equipo_local=aux_local->info;
        tmp.equipo_visitante=aux_visitante->info;

        //Puntero auxiliar para recorrer el arbol
        ArbolPartidos* aux;

        aux=t.partidos;
        bool encontrado=false;

        if (aux!=NULL){ // if 1

           while ((aux!=NULL) && !(encontrado)){
                 if (partido_mayor(tmp,aux->info))
                    aux=aux->izq;
                  else {
                    if ((aux->info.equipo_local->nombre == nombre_local) &&
                       (aux->info.equipo_visitante->nombre == nombre_visitante))
                       encontrado=true;
                   else
                       aux=aux->der;
                    } // while
                   } //else

           }// if 1

        //if (!encontrado)
        //   aux=NULL;

        return(aux);

} //torneo_busca_partido




int torneo_info_partido(TTorneo t, int id_local, int id_visitante,
                        int &goles_local, int &goles_visitante){

        if (torneo_validar_id(id_local,id_visitante))
           return(-1);
         else{ //1

            ArbolPartidos* aux;

            aux=torneo_busca_partido(t,id_local,id_visitante);

            if (aux==NULL)
               return(-2);
              else { //2
               goles_local=aux->info.goles_local;
               goles_visitante=aux->info.goles_visitante;
               return(0);
               } //else 2

           } //else 1

} // torneo_info_partido

//funcion que devuelve la informacion de un equipo en la posicion
//pos de la clasificiacion.
//****************************************************************
TEquipo* torneo_linea_clasificacion (TTorneo t,int pos){

        if (t.clasificacion.primero!=NULL){
           ListaEquipos *aux;
           aux=t.clasificacion.primero;

           for (int i=0;i<pos;i++)
               aux=aux->sig;

           return (aux->info);
           }//if

}//torneo_linea_clasificacion




void torneo_inserta_en_clasificacion(TTorneo &t,TEquipo* equipo){

        ListaEquipos* nuevoEquipo;
        nuevoEquipo=new ListaEquipos;

        nuevoEquipo->info=equipo;
        nuevoEquipo->sig=NULL;

        //Sino es el primer equipo a crear en la clasificacion añadirlo
        //al final, sino, al principio.
        if (t.clasificacion.primero!=NULL){
           t.clasificacion.ultimo->sig=nuevoEquipo;
           t.clasificacion.ultimo=t.clasificacion.ultimo->sig;
           }
         else {
           t.clasificacion.primero=nuevoEquipo;
           t.clasificacion.ultimo=t.clasificacion.primero;
           }

} //torneo_inserta_en_clasificacion




int torneo_anyadir_equipo(TTorneo &t,AnsiString nombre_equipo){

        if (t.num_equipos<MAX_EQUIPOS){//if 1 -Principal

           /**
           Comprobar si el equipo ya esta registrado

           Si primero no apunta a nulo, la lista no esta vacia y hay
           que buscar una posible coincidencia
           /**/
           bool encontrado;
           encontrado=false;

           if (t.equipos.primero!=NULL){ // if 2
              ListaEquipos* aux;
              aux=t.equipos.primero;

              while ((aux!=NULL) && !(encontrado)){
                    if (aux->info->nombre==nombre_equipo)
                       encontrado=true;
                     else
                       aux=aux->sig;
                    }
              }// if 2 - No necesita "else", ya que implica que
               //        la lista esté vacia y "encontrado" se
               //        mantendrá a "false" por lo que entrará
               //        en el "else" siguiente y se registrará

           if (encontrado) // if 3
              return(-2);
            else { // else 3
              //Guardar equipo con su nombre
              ListaEquipos* nuevoEquipo;
              nuevoEquipo=new ListaEquipos;

              TEquipo *tmp;
              tmp=new TEquipo;

              tmp->nombre=nombre_equipo;
              tmp->partidos_casa=0;
              tmp->partidos_fuera=0;
              tmp->partidos_ganados=0;
              tmp->partidos_empatados=0;
              tmp->partidos_perdidos=0;
              tmp->goles_favor=0;
              tmp->goles_contra=0;
              tmp->puntos=0;

              t.num_equipos++;

              nuevoEquipo->info=tmp;
              nuevoEquipo->sig=NULL;

              //Si el primero apunta a nulo, es el primer nodo
              //a crear, sino, enviarlo al final de la lista
              if (t.equipos.primero==NULL){
                 t.equipos.primero=nuevoEquipo;
                 t.equipos.ultimo=nuevoEquipo;
                 }
               else {
                 t.equipos.ultimo->sig=nuevoEquipo;
                 t.equipos.ultimo=t.equipos.ultimo->sig;
                 }

              torneo_inserta_en_clasificacion(t,tmp);

              return(t.num_equipos-1);
              } //else 3

        } // if 1 - princpial
        else
           return(-1);
} //torneo_anyadir_equipo



void torneo_borra_en_clasificacion(TTorneo &t, int id_equipo)
{
        AnsiString nombre_equipo;
        torneo_nombre_equipo(t,id_equipo,nombre_equipo);

        ListaEquipos *aux_ant,*aux_act;
        aux_act=t.clasificacion.primero;
        aux_ant=NULL;

        // Colocar punteros actual y anterior
    if (aux_act!=NULL){
        while (aux_act->info->nombre!=nombre_equipo){
              aux_ant=aux_act;
              aux_act=aux_act->sig;
              }

        // Comprobar que el actual a borrar no sea el ultimo
        // sino, barajar otras posibilidades.

        if (aux_ant==NULL)
           t.clasificacion.primero=aux_act->sig;
         else {
           if (aux_act==t.clasificacion.ultimo){
              aux_ant->sig=NULL;
              t.clasificacion.ultimo=aux_ant;
              }
            else
              aux_ant->sig=aux_act->sig;
            }

        delete(aux_act);

        }// if aux_act!=NULL
} // torneo_borra_en_clasificacion



void torneo_inserta_ordenado(TTorneo &t, int id_equipo)
{
        AnsiString nombre_equipo;
        torneo_nombre_equipo(t,id_equipo,nombre_equipo);

          // "tmp" almacenara temporalmente la informacion
          // del equipo que queremos introducir ordenadamente

        ListaEquipos *tmp,*pos,*pos_ant;
        tmp=t.equipos.primero;

          // Colocar tmp para que apunte al equipo a insertar
        while (tmp->info->nombre!=nombre_equipo)
              tmp=tmp->sig;

          // "pos" almacena la posicion del nodo que ira despues
          // de que hayamos introducido tmp en clasificacion

        pos=t.clasificacion.primero;

          // "efecto" indicara si se ha entrado en bucle while
        bool efecto=false;

       // Si pos apunta a nulo, la clasificacion esta vacia
    if (pos!=NULL){ // 1

              // (pos!=NULL) AND
              // ((1a cond) OR (2a cond) OR (3a cond) OR (4a cond))

              //Si pos es nulo, llego al final de la lista clasificacion
        while ((pos!=NULL) &&

              // 1a condicion: puntos diferentes
              ((tmp->info->puntos < pos->info->puntos) ||

              // 2a condicion puntos iguales
              ((tmp->info->puntos == pos->info->puntos) &&
              (tmp->info->goles_favor < pos->info->goles_favor)) ||

              // 3a condicion: puntos y goles a favor iguales
              ((tmp->info->puntos == pos->info->puntos) &&
              (tmp->info->goles_favor == pos->info->goles_favor) &&
              (tmp->info->goles_favor - tmp->info->goles_contra < pos->info->goles_favor - pos->info->goles_contra)) ||

              // 4a condicion: puntos, goles a favor y diferencia de g.favor-g.contra iguales
              ((tmp->info->puntos == pos->info->puntos) &&
              (tmp->info->goles_favor == pos->info->goles_favor) &&
              (tmp->info->goles_favor - tmp->info->goles_contra == pos->info->goles_favor - pos->info->goles_contra) &&
              (tmp->info->nombre > pos->info->nombre)))) {

              pos=pos->sig;
              efecto=true;
              }

              ListaEquipos* nuevoEquipo;
              nuevoEquipo=new ListaEquipos;

              // "pos_ant" se colocara antes de pos, para que despues pos_ant
              // apunte a "tmp" y esta a su vez a "pos": pos_ant -> tmp -> pos
              pos_ant=t.clasificacion.primero;


              // Si "efecto" es false, es que en el bucle while no ha
              // entrado y hay que añadirlo al principio, sino, habra
              // que verificar otras condiciones

              if (efecto){ //2

                 //Colocar "pos_ant" antes de "pos"
                 while (pos_ant->sig!=pos)
                       pos_ant=pos_ant->sig;

                 // Tras las vueltas del bucle while habra que comprobar
                 // si "pos" se paró en el ultimo nodo ("pos" es nulo) de
                 // la clasificacion, o en un nodo intermedio

                 if (pos==NULL){ //3
                    nuevoEquipo->info=tmp->info;
                    nuevoEquipo->sig=NULL;

                    t.clasificacion.ultimo=nuevoEquipo;
                    pos_ant->sig=nuevoEquipo;
                    } // 3
                  else { // Hay que colocarlo en un nodo intermedio
                    nuevoEquipo->info=tmp->info;
                    nuevoEquipo->sig=pos;

                    pos_ant->sig=nuevoEquipo;
                    } // 3
                 } // 2
               else { // El bucle no ha tenido efecto. Hay que
                      // colocarlo antes que el primer nodo que ya haya
                 nuevoEquipo->info=tmp->info;
                 nuevoEquipo->sig=t.clasificacion.primero;

                 t.clasificacion.primero=nuevoEquipo;
                 } // 2
       } // 1
    else {
       // La clasificacion esta vacia: añadir el primer nodo
       ListaEquipos* nuevoEquipo;
       nuevoEquipo=new ListaEquipos;

       nuevoEquipo->info=tmp->info;
       nuevoEquipo->sig=NULL;
       t.clasificacion.primero=nuevoEquipo;
       } // 1



} // torneo_inserta_ordenado



void torneo_ordena_clasificacion(TTorneo &t,int id_local,int id_visitante)
{
        // Metodo:
        // -> Se elimina el nodo del equipo a ordenar de la lista de clasificacion
        //    y se inserta de nuevo en el sitio que le corresponde calculandolo a
        //    traves de una comprobacion nodo a nodo desde el primero al ultimo

        //Colocar el equipo local
        torneo_borra_en_clasificacion(t,id_local);
        torneo_inserta_ordenado(t,id_local);

        // Colocar el equipo visitante
        torneo_borra_en_clasificacion(t,id_visitante);
        torneo_inserta_ordenado(t,id_visitante);

}// torneo_ordena_clasificacion



//Si es true, tirar al nodo izquierdo; Si es false, al derecho
//************************************************************
bool partido_mayor(TPartido A, TPartido B) {

        return (A.equipo_local->nombre > B.equipo_local->nombre) ||
               ((A.equipo_local->nombre == B.equipo_local->nombre) &&
               (A.equipo_visitante->nombre > B.equipo_visitante->nombre));
               
}//bool partido_mayor




int torneo_anyadir_partido(TTorneo &t, int id_local, int id_visitante,
                           int goles_local, int goles_visitante){
        //copiar goles o se modificaran en "info partido"
        int g_local=0;
        int g_visitante=0;

        int a=torneo_info_partido(t,id_local,id_visitante,g_local,g_visitante);

        if ((goles_local<0) || (goles_visitante<0))
           return(-3);
         else{
           switch (a){
                  //El partido ha sido jugado -> -2
                  case 0: {
                          return(-2);
                          }
                          break;
                  // Los ids no son validos -> -1
                  case -1:{
                          return(-1);
                          }
                          break;
                  //El partido no ha sido jugado; añadir partido entonces -> 0
                  case -2:{
                          //actualizar resumen del equipo en funcion de los datos del  partido
                          AnsiString nombre_local;
                          AnsiString nombre_visitante;

                           //capturar nombre de los equipos
                          torneo_nombre_equipo(t,id_local,nombre_local);
                          torneo_nombre_equipo(t,id_visitante,nombre_visitante);

                          ListaEquipos* aux_local;
                          ListaEquipos* aux_visitante;

                          aux_local=t.equipos.primero;
                          aux_visitante=aux_local;

                          //colocar punteros auxiliares para modificar resumenes de equipos
                          while (aux_local->info->nombre!=nombre_local)
                                aux_local=aux_local->sig;

                          while (aux_visitante->info->nombre!=nombre_visitante)
                                aux_visitante=aux_visitante->sig;

                             //actualizar numero partidos   
                          aux_local->info->partidos_casa++;
                          aux_visitante->info->partidos_fuera++;

                          aux_local->info->goles_favor+=goles_local;
                          aux_local->info->goles_contra+=goles_visitante;;

                          aux_visitante->info->goles_favor+=goles_visitante;
                          aux_visitante->info->goles_contra+=goles_local;

                            //añadir puntos
                          if (goles_local>goles_visitante){
                             aux_local->info->partidos_ganados++;
                             aux_local->info->puntos+=3;

                             aux_visitante->info->partidos_perdidos++;
                             }
                           else{ //1
                             if (goles_local<goles_visitante){
                                aux_visitante->info->partidos_ganados++;
                                aux_visitante->info->puntos+=3;

                                aux_local->info->partidos_perdidos++;
                                }
                              else{ //2
                                aux_visitante->info->partidos_empatados++;
                                aux_visitante->info->puntos++;

                                aux_local->info->partidos_empatados++;
                                aux_local->info->puntos++;
                                } //else 2
                              }// else 1

                          //añadir info al nuevo nodo en lista partidos
                          ArbolPartidos *nuevoPartido;
                          nuevoPartido=new ArbolPartidos;

                          TPartido tmp;

                          tmp.goles_local=goles_local;
                          tmp.goles_visitante=goles_visitante;
                          tmp.equipo_local=aux_local->info;
                          tmp.equipo_visitante=aux_visitante->info;

                          nuevoPartido->info=tmp;
                          nuevoPartido->izq=NULL;
						  nuevoPartido->der=NULL;

                          //puntero auxiliar para enlazar tmp a la lista
                          ArbolPartidos *aux;
                          aux=t.partidos;

                          if (aux!=NULL){
                             while (aux!=NULL){
                                if (partido_mayor(tmp,aux->info)){
                                   if (aux->izq==NULL){
                                      aux->izq=nuevoPartido;
                                      aux=NULL;
                                      }
                                    else
                                      aux=aux->izq;
                                   }
                                 else { // 2
                                   if (aux->der==NULL){
                                      aux->der=nuevoPartido;
                                      aux=NULL;
                                      }
                                    else
                                      aux=aux->der;
                                   } // else 2
                               } // while
                             } //if
                           else
                             t.partidos=nuevoPartido;



                          //-> Partido añadido

                          //Ordenar la clasificacion
                          torneo_ordena_clasificacion(t,id_local,id_visitante);

                          return(0);

                          } //case -2
                          break;
                  }//switch
           }//else (if principal)
}// torneo_anyadir_partido

//Metodo que borra un nodo (un partido) del arbol de partidos
//************************************************************
ArbolPartidos* torneo_arbol_borrar_partido(ArbolPartidos *arbol, TPartido partido) {

  ArbolPartidos *aux_ant=NULL;
  ArbolPartidos *aux_act=arbol;

  AnsiString nombre_local=partido.equipo_local->nombre;
  AnsiString nombre_visitante=partido.equipo_visitante->nombre;


  while ( aux_act != NULL &&
          aux_act->info.equipo_local->nombre != nombre_local &&
          aux_act->info.equipo_visitante->nombre != nombre_visitante) {

        aux_ant=aux_act;

        if (partido_mayor(partido,aux_act->info))
           aux_act=aux_act->izq;
         else
           aux_act=aux_act->der;
        } // while

  if ( aux_act != NULL ) {

     ArbolPartidos *x = aux_act;

    if ( aux_act->izq != NULL && aux_act->der != NULL) {

      ArbolPartidos *sig;
      sig=aux_act->der;
      
      while( sig->izq != NULL )
           sig = sig->izq;

      sig->izq = aux_act->izq;
      x=aux_act->der;
      }
    else
      if ( aux_act->izq == NULL )
         x = aux_act->der;
       else
         x = aux_act->izq;


    if ( aux_ant != NULL ) {
       if ( aux_act == aux_ant->der )
          aux_ant->der=x;
        else
          aux_ant->izq=x;

       delete aux_act;

       return arbol;
       }
     else {
       delete aux_act;
       return x;
       }
   }
}


int torneo_borrar_partido(TTorneo &t, int id_local, int id_visitante){

    //comprobar que los id's son validos
    if (torneo_validar_id(id_local,id_visitante))
       return(-1);
      else{ //else principal
       //comprobar que el partido haya sido jugado
       ArbolPartidos* aux;
       aux=torneo_busca_partido(t,id_local,id_visitante);

       //si aux no apunta a null, ha encontrado el partido
       if (aux!=NULL){

          //actualizar goles equipo local
          aux->info.equipo_local->goles_favor-=aux->info.goles_local;
          aux->info.equipo_local->goles_contra-=aux->info.goles_visitante;

          //actualizar goles equipo visitante
          aux->info.equipo_visitante->goles_favor-=aux->info.goles_visitante;
          aux->info.equipo_visitante->goles_contra-=aux->info.goles_local;

          //actualizar partidos
          aux->info.equipo_local->partidos_casa--;
          aux->info.equipo_visitante->partidos_fuera--;

          //actualizar puntos y partidos
          if (aux->info.goles_local>aux->info.goles_visitante){
             aux->info.equipo_local->puntos-=3;
             aux->info.equipo_local->partidos_ganados--;
             aux->info.equipo_visitante->partidos_perdidos--;
             }
           else{ //2
             if (aux->info.goles_local<aux->info.goles_visitante){
                aux->info.equipo_visitante->puntos-=3;
                aux->info.equipo_local->partidos_perdidos--;
                aux->info.equipo_visitante->partidos_ganados--;
                }
              else{ //1
                aux->info.equipo_local->puntos--;
                aux->info.equipo_visitante->puntos--;
                aux->info.equipo_local->partidos_empatados--;
                aux->info.equipo_visitante->partidos_empatados--;
                }//else 1
             }//else 2

          // Creamos la caja artificial y enlazamos
          TPartido tmp;

          tmp.equipo_local=aux->info.equipo_local;
          tmp.equipo_visitante=aux->info.equipo_local;

          int g_local,g_visitante;
          torneo_info_partido(t,id_local,id_visitante,g_local,g_visitante);

          tmp.goles_local=g_local;
          tmp.goles_visitante=g_visitante;

          t.partidos=torneo_arbol_borrar_partido(t.partidos,tmp);

          // Ordenar clasificacion
          torneo_ordena_clasificacion(t,id_local,id_visitante);

          return(0);
        }else //Sino, aux apunta a nulo y el partido no ha sido jugado
           return(-2);
     } //else principal
} //torneo borrar_partido

bool torneo_borrar_equipo(TTorneo &t, int id_equipo){

if ((id_equipo<MAX_EQUIPOS) && (id_equipo>=0)){

        ArbolPartidos* aux;

        //borrar partidos
        //******************
        for(int id_aux=0;id_aux<t.num_equipos;id_aux++){

           //jugados en casa
           aux=torneo_busca_partido(t,id_equipo,id_aux);

           if (aux!=NULL)
              torneo_borrar_partido(t,id_equipo,id_aux);

           //jugados fuera
           aux=torneo_busca_partido(t,id_aux,id_equipo);

           if (aux!=NULL)
              torneo_borrar_partido(t,id_aux,id_equipo);

           }// for

        //actualizar clasificacion
        //*************************
        ListaEquipos *aux_act,*aux_ant;

        aux_act=t.clasificacion.primero;
        aux_ant=NULL;

        AnsiString nombre_equipo;
        torneo_nombre_equipo(t,id_equipo,nombre_equipo);

          //colocar punteros
        while (aux_act->info->nombre!=nombre_equipo){
              aux_ant=aux_act;
              aux_act=aux_act->sig;
              }

          //si anterior apunta a nulo, vamos a borrar
          //el equipo que va primero en la clasificacion
        if (aux_ant==NULL)
           t.clasificacion.primero=aux_act->sig;
         else { //1
           if (aux_act==t.clasificacion.ultimo){
              aux_ant->sig=NULL;
              t.clasificacion.ultimo=aux_ant;
              }
            else
              aux_ant->sig=aux_act->sig;
           } // else 1

        delete(aux_act);

        
        //actualizar lista equipos
        //************************
        aux_act=t.equipos.primero;
        aux_ant=NULL;

        int cont=0;

          //colocar punteros
        while (cont<id_equipo){
              aux_ant=aux_act;
              aux_act=aux_act->sig;
              cont++;
              }

          //si anterior apunta a nulo,
          //vamos a borrar el equipo con id=0
        if (aux_ant==NULL)
           t.equipos.primero=aux_act->sig;
         else { //1
           if (aux_act==t.equipos.ultimo){
              aux_ant->sig=NULL;
              t.equipos.ultimo=aux_ant;
              }
            else
              aux_ant->sig=aux_act->sig;
           } // else 1

        delete(aux_act->info);
        delete(aux_act);
        

        //actualizar numero equipos
        //*************************
        t.num_equipos--;

        return(true);
        }
      else
        return(false);

}//torneo_borrar_equipo

//Metodo que recibe un arbol y lo devuelve en forma de lista enlazada linear
//*************************************************************************
ListaAux* torneo_arbol_a_lista_linear(ArbolPartidos *t) {
  ListaAux* inicio=NULL;
  ListaAux* ultimo=NULL;
  torneo_arbol_a_lista_linear_aux(t,inicio,ultimo);
  return (inicio);
} // torneo_arbol_a_lista_linear

void torneo_arbol_a_lista_linear_aux(ArbolPartidos *t, ListaAux *&inicio, ListaAux *&ultimo) {
  if ( t != NULL ) {

    torneo_arbol_a_lista_linear_aux(t->izq,inicio,ultimo);

    ListaAux *tmp = new ListaAux;
    tmp->info=t;
    tmp->sig=NULL;
    if ( inicio == NULL ){
        inicio=tmp;
        ultimo=inicio;
        }
      else{
        ultimo->sig=tmp;
        ultimo=ultimo->sig;
        }

    torneo_arbol_a_lista_linear_aux(t->der,inicio,ultimo);
  } // if
} // torneo_arbol_a_lista_linear_aux
//*************************************************


void torneo_guardar(TTorneo &t, AnsiString f){

        //crear fichero de salida
        f=f+".txt";
        ofstream fs(f.c_str());

        //guardamos información
          //numero de equipos
        fs << t.num_equipos << endl;

          //nombre de los equipos
        int i=0;
        ListaEquipos* aux;
        aux=t.equipos.primero;

        while (i<t.num_equipos){
              fs << aux->info->nombre.c_str() << endl;
              i++;
              aux=aux->sig;
              }

          //partidos jugados
        ArbolPartidos* aux2;
        aux2=t.partidos;

        //Lista auxiliar para almacenar el arbol
        ListaAux* aux3;
        aux3=torneo_arbol_a_lista_linear(aux2);

        int id_local,id_visitante,goles_local,goles_visitante;
        AnsiString nombre_local,nombre_visitante;

        while (aux3!=NULL){
              nombre_local=aux2->info.equipo_local->nombre;
              nombre_visitante=aux2->info.equipo_visitante->nombre;

              goles_local=aux2->info.goles_local;
              goles_visitante=aux2->info.goles_visitante;

              id_local=torneo_id_equipo(t,nombre_local);
              id_visitante=torneo_id_equipo(t,nombre_visitante);

              fs << id_local << " " << id_visitante << " " << goles_local << " " << goles_visitante << endl;

              aux3=aux3->sig;
              } //while

        //limpiar lista auxiliar
        ListaAux *aux_act,*aux_sig;

        aux_act=aux3;
        aux_sig=NULL;

        while (aux_act!=NULL){
              aux_sig=aux_act->sig;
              delete(aux_act);
              aux_act=aux_sig;
              }

        //cerrar fichero
        fs.close();
}//torneo_guardar

void torneo_abrir(TTorneo &t, AnsiString f){
      torneo_inicializar(t);
      ifstream ent;
      ent.open(f.c_str());

      string tmp;

      int x;
      //leemos primer entero (num equipos)
      ent >> x;
      //saltamos de linea
      getline(ent,tmp);


     //leer nombres de equipos
      for (int i=0;i<x;i++){
         getline(ent,tmp);
         torneo_anyadir_equipo(t,tmp.c_str());
      }

      int y;
      int z;
      int w;

      //añadir partidos
      while ( ent >> x >> y >> z >> w ){
         torneo_anyadir_partido(t,x,y,z,w);
      }

      ent.close();
}


//---------------------------------------------------------------------------

#pragma package(smart_init)
