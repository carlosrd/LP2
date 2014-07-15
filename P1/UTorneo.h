//---------------------------------------------------------------------------

#ifndef UTorneoH
#define UTorneoH

#define MAX_EQUIPOS 20

#include <fstream>
#include <iostream>

struct TEquipo {
                AnsiString nombre;
                int partidos_casa;
                int partidos_fuera;
                int partidos_ganados;
                int partidos_empatados;
                int partidos_perdidos;
                int goles_favor;
                int goles_contra;
                int puntos;
                };

struct ListaEquipos {
                TEquipo* info;
                ListaEquipos* sig;
                };

struct TEquipos {
                ListaEquipos* primero;
                ListaEquipos* ultimo;
                };

struct TPartido {
                TEquipo* equipo_local;
                TEquipo* equipo_visitante;
                int goles_local;
                int goles_visitante;
                };

struct ArbolPartidos {
        TPartido info;
        ArbolPartidos *izq;
        ArbolPartidos *der;
        };

struct ListaAux {
        ArbolPartidos* info;
        ListaAux *sig;
        };

struct TTorneo {
                int num_equipos;
                TEquipos equipos;
                TEquipos clasificacion;
                ArbolPartidos* partidos;
                };




void torneo_inicializar(TTorneo &t);

void torneo_limpiar_arbol(ArbolPartidos* &arbol);

void torneo_limpiar(TTorneo &t);

int torneo_numero_equipos(TTorneo t);

int torneo_id_equipo(TTorneo t,AnsiString nombre_equipo);

bool torneo_validar_id(int id_local, int id_visitante);

bool torneo_nombre_equipo(TTorneo t,
                                int id_equipo, AnsiString &nombre_equipo);
                                
ArbolPartidos* torneo_busca_partido(TTorneo t, int id_local, int id_visitante);

int torneo_info_partido(TTorneo t, int id_local, int id_visitante,
                                int &goles_local, int &goles_visitante);

TEquipo* torneo_linea_clasificacion (TTorneo t,int pos);
/*
bool torneo_linea_clasificacion(TTorneo t,
                                        int pos,
                                        AnsiString &nombre,
                                        int &partidos_casa,
                                        int &partidos_fuera,
                                        int &partidos_ganados,
                                        int &partidos_empatados,
                                        int &partidos_perdidos,
                                        int &goles_favor,
                                        int &goles_contra,
                                        int &puntos);
/*/

void torneo_inserta_en_clasificacion(TTorneo &t,TEquipo* equipo);

int torneo_anyadir_equipo(TTorneo &t,AnsiString nombre_equipo);

void torneo_borra_en_clasificacion(TTorneo &t, int id_equipo);

void torneo_inserta_ordenado(TTorneo &t, int id_equipo);

void torneo_ordena_clasificacion(TTorneo &t,int id_local,int id_visitante);

int torneo_anyadir_partido(TTorneo &t, int id_local, int id_visitante,
                           int goles_local, int goles_visitante);

bool partido_mayor(TPartido A, TPartido B);

ArbolPartidos* torneo_arbol_borrar_partido(ArbolPartidos *t, TPartido partido);

bool torneo_borrar_equipo(TTorneo &t, int id_equipo);

int torneo_borrar_partido(TTorneo &t, int id_local, int id_visitante);

 // Metodos que convierten un arbol en una lista ordenada)
ListaAux* torneo_arbol_a_lista_linear(ArbolPartidos *t);
void torneo_arbol_a_lista_linear_aux(ArbolPartidos *t, ListaAux *&inicio, ListaAux *&ultimo);

 // Metodos para guardar y abrir torneos desde ficheros
void torneo_guardar(TTorneo &t, AnsiString f);
void torneo_abrir(TTorneo &t, AnsiString f);


//---------------------------------------------------------------------------
#endif


