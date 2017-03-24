#include "constants_189714319_MaturanaGuerra.h"
#include "structs_189714319_MaturanaGuerra.h"

#ifndef _FUNCIONES_H
#define _FUNCIONES_H

Board* createBoard(int n, int m, Params params, code *statusCode);
void print(Board *b,int showComplete, code *statusCode);
int checkBoard(Board * b, code *statusCode);
void saveBoard(Board *b, int * id, code *statusCode);
Board * loadBoard(int id, code * statusCode);
void putShip(Board *b, Position p, Ship s, code *statusCode);
int play(Board *b, Ship * ship,Position * pArray, code *statusCode);

Position setPosition(int Fila, int Columna);
Ship cfgShips(int Largo, int Ancho, int ATKEspecial, char charBarco, int DEF);
int BarcoAtacado(Position p, Comandante comandante, Board *b);
int * generateID();
Params setParams(int Dificultad, code *statusCode);
Position * AtaquesMasivos(Ship s, Position p,Board * b);
void destroyBoard(Board **b);
int getScore(Game g);

#endif