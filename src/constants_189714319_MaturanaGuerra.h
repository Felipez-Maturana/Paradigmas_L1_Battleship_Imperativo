#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

typedef enum {N=78, A=65,P=80,S=83,B=66,O=79,X=88,W	=35} pieza;
typedef enum {J=74, E=69} Comandante;
typedef enum {FALSE, TRUE} bool;
typedef enum {OK, ERROR_FILE_404, ERROR_FILE_NOT_PERM, ERROR_ID_NOT_FOUND, IMPOSSIBLE_VALID_BOARD, NOT_ENOUGH_MEMORY, WRONG_DIM, ERROR, WRONG_DIFFICULTY, BOARD_NOT_FOUND, PUT_ERROR_OCUPPED, ERROR_MAX_SHIP_REACHED, ERROR_ITS_NOT_YOUR_TURN, ERROR_GAME_FINALIZED} code;

#endif