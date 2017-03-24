/*
para evitar duplicidad producto de la
inclusión de archivos de encabezados
desde distintas fuentes que den lugar
errores durante el proceso de compilacion
se deben especificar las directivas de compilacion #ifndef y #endif como
se ilustra en el ejemplo.
A través de define se establece un identificador. ifndef verifica que este
no haya sido definido producto de la inclusión desde otra fuente
*/

#include "constants_189714319_MaturanaGuerra.h"

#ifndef _STRUCTS_H_
#define _STRUCTS_H_
typedef struct
{
	int * CantidadxTipoBarco; // 0, normal; 1, Acorazado; 2, PortaAviones; 3, Submarino; 4, BuquePirata;
	int Dificultad;
} Params;

typedef struct
{
	int Fila;
	int Columna;
} Position;

typedef struct
{				// Ex. Normal
	int Largo; // 3
	int Ancho;// 1 
	int Vida;
	int TipoAtaque; // 0 NO TIENE ATAQUE ESPECIAL.
	char charBarco;
	Comandante comandante;
	int Defensa; //0
	int ** PosicionesTablero;
	Position * PosicionTablero;
} Ship;
typedef struct
{
	char **matriz;
	int n;
	int m;
	int Dificultad;
	pieza lastPlayer;
	int BarcosEnemigos;
	int BarcosJugador;
	int ActualBarcosEnemigos;
	int ActualBarcosJugador;
	int JuegoFinalizado;
	Comandante UltimoJugador;
	Ship * Enemigos;
	Ship * Jugador;
} Board;
typedef struct
{
	Board board;
} Game;
#endif