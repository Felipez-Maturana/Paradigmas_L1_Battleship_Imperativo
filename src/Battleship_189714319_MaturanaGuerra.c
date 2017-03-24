#include "funciones_189714319_MaturanaGuerra.h"
#include "structs_189714319_MaturanaGuerra.h"
#include "constants_189714319_MaturanaGuerra.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
/*
	//PRUEBAS REALIZADAS.
	code sc;
	Params params;
	Ship Normal, Acorazado, PortaAvion,Submarino,Buque;
	
	Normal = cfgShips(3, 1, 0, N, 0);
	Acorazado = cfgShips(4, 1, 0, A, 1);
	PortaAvion = cfgShips(3, 1, 1, P, 0);
	Submarino = cfgShips(3, 1, 2, S, 0);
	Buque = cfgShips(2, 1, 3, B, 0);
	
	int Dificultad=1;
	params = setParams(Dificultad, &sc);
	printf("Dificultad %d\n",params.Dificultad);
	printf("***************Barcos Normales: %d***************\n||Largo: %d\tAncho: %d||\n||Ataque Especial: %d\t char: %c\tDefensa: %d||\n",params.CantidadxTipoBarco[0],Normal.Largo,Normal.Ancho,Normal.TipoAtaque,Normal.charBarco,Normal.Defensa);
	printf("***************Barcos Acorazados: %d***************\n||Largo: %d\tAncho: %d||\n||Ataque Especial: %d\t char: %c\tDefensa: %d||\n",params.CantidadxTipoBarco[1],Acorazado.Largo,Acorazado.Ancho,Acorazado.TipoAtaque,Acorazado.charBarco,Acorazado.Defensa);
	printf("***************Barcos Porta Aviones: %d***************\n||Largo: %d\tAncho: %d||\n||Ataque Especial: %d\t char: %c\tDefensa: %d||\n",params.CantidadxTipoBarco[2],PortaAvion.Largo,PortaAvion.Ancho,PortaAvion.TipoAtaque,PortaAvion.charBarco,PortaAvion.Defensa);
	printf("***************Barcos Submarinos: %d***************\n||Largo: %d\tAncho: %d||\n||Ataque Especial: %d\t char: %c\tDefensa: %d||\n",params.CantidadxTipoBarco[3],Submarino.Largo,Submarino.Ancho,Submarino.TipoAtaque,Submarino.charBarco,Submarino.Defensa);
	printf("***************Barcos Piratas: %d***************\n||Largo: %d\tAncho: %d||\n||Ataque Especial: %d\t char: %c\tDefensa: %d||\n",params.CantidadxTipoBarco[4],Buque.Largo,Buque.Ancho,Buque.TipoAtaque,Buque.charBarco,Buque.Defensa);
	printf("***************INICIO Creacion de Tablero***************\n");
	Board *b1 = createBoard(10,10,params,&sc);
	printf("***************FIN Creacion de Tablero***************\n");
	print(b1,1,&sc);
	printf("***************INICIO Verificacion de Tablero Creado***************\n");
	int a=checkBoard(b1,&sc);
	printf("***************FIN Verificacion de Tablero Creado***************\n");
	printf("El barco es propiedad de: %c\n",b1->Enemigos[4].comandante);
	printf("***************INICIO Guardar Tablero Creado***************\n");
	saveBoard(b1,generateID(),&sc);
	printf("***************FIN Guardar Tablero Creado***************\n");
	printf("***************INICIO Cargar Tablero***************\n");
	Board *b2=loadBoard(8563, &sc);
	printf("***************FIN Cargar Tablero***************\n");
	printf("***************INICIO Verificacion de Tablero Cargado***************\n");
	a=checkBoard(b2,&sc);
	printf("***************FIN Verificacion de Tablero Cargado***************\n");
	print(b2,1,&sc);
	printf("***************INICIO Posicionamiento en 0,1 BARCO: P***************\n");
	putShip(b1, setPosition(0,1), PortaAvion, &sc);
	printf("El barco es propiedad de: %c\n",b1->Jugador[0].comandante);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[0].PosicionesTablero[0][0],b1->Jugador[0].PosicionesTablero[0][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[0].PosicionesTablero[1][0],b1->Jugador[0].PosicionesTablero[1][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[0].PosicionesTablero[2][0],b1->Jugador[0].PosicionesTablero[2][1]);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 0,1 BARCO: P***************\n");
	
	printf("***************INICIO Posicionamiento en 4,3 BARCO: S***************\n");
	putShip(b1, setPosition(4,3), Submarino, &sc);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[1].PosicionesTablero[0][0],b1->Jugador[1].PosicionesTablero[0][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[1].PosicionesTablero[1][0],b1->Jugador[1].PosicionesTablero[1][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[1].PosicionesTablero[2][0],b1->Jugador[1].PosicionesTablero[2][1]);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 4,3 BARCO: S***************\n");
	
	printf("***************INICIO Posicionamiento en 2,3 BARCO: B***************\n");
	putShip(b1, setPosition(2,3), Buque, &sc);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 2,3 BARCO: B***************\n");
	
	printf("***************INICIO Posicionamiento en 1,4 BARCO: A***************\n");
	putShip(b1, setPosition(1,4), Acorazado, &sc);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 1,4 BARCO: A***************\n");
	
	printf("***************INICIO Posicionamiento en 1,2 BARCO: N***************\n");
	putShip(b1, setPosition(1,2), Normal, &sc);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[0][0],b1->Jugador[4].PosicionesTablero[0][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[1][0],b1->Jugador[4].PosicionesTablero[1][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[2][0],b1->Jugador[4].PosicionesTablero[2][1]);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 1,2 BARCO: N***************\n");

	printf("***************INICIO Posicionamiento en 6,2 BARCO: A***************\n");
	putShip(b1, setPosition(6,2), Acorazado, &sc);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 6,2 BARCO: A***************\n");
	
	// SE INTENTARA POSICIONAR UN BARCO EN UNA POSICION OCUPADA.
	
	printf("***************INICIO Posicionamiento en 3,2 BARCO: N***************\n");
	putShip(b1, setPosition(3,2), Normal, &sc);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[0][0],b1->Jugador[4].PosicionesTablero[0][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[1][0],b1->Jugador[4].PosicionesTablero[1][1]);
	printf("Fila %d ///// Columna %d\n",b1->Jugador[4].PosicionesTablero[2][0],b1->Jugador[4].PosicionesTablero[2][1]);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 1,2 BARCO: N***************\n");
	
	printf("***************INICIO Posicionamiento en 5,0 BARCO: A***************\n");
	putShip(b1, setPosition(5,0), Acorazado, &sc);
	print(b1,1,&sc);
	printf("Hay %d Barcos JUGADOR\n",b1->BarcosJugador);
	printf("***************FIN Posicionamiento en 5,0 BARCO: A***************\n");
	
	
	printf("***************INICIO DE ATAQUES***************\n");
	printf("Barcos Enemigos %d Actual %d Barcos Jugador %d Actual %d\n",b1->BarcosEnemigos,b1->ActualBarcosEnemigos,b1->BarcosJugador,b1->ActualBarcosJugador);
	//Se realizara un disparo masivo de 3x3, Se necesita un BUQUE.
	
	//printf("TIPO ATK %d\n",b1->Enemigos[3].TipoAtaque);
	Position * pArray;
	//pArray=malloc(sizeof(Position *));
	printf("***************INICIO ATAQUE FILA (Porta avion) EN 1,1 de Enemigo a Jugador***************\n");
	pArray=AtaquesMasivos(b1->Jugador[2], setPosition(1,1), b1);
	play(b1, b1->Enemigos, pArray, &sc);
	print(b1,1,&sc);
	printf("Actual: %c\n",b1->UltimoJugador);
	
	
	printf("***************INICIO ATAQUE FILA EN 3,3 Por el mismo PLAYER***************\n");
	pArray=AtaquesMasivos(b1->Jugador[1], setPosition(3,3), b1); //Ataque dos veces consecutivo del mismo PLAYER.
//	printf("ME CAI?\n");
	play(b1, b1->Enemigos, pArray, &sc);
//	printf("ME CAI?\n");
	print(b1,1,&sc);
	printf("Actual: %c Jugar:\n",b1->UltimoJugador);
	
	printf("***************INICIO ATAQUE EN AREA (Buque) EN 4,6 de Jugador a Enemigo***************\n");
	pArray=AtaquesMasivos(b1->Jugador[1], setPosition(4,6), b1); 
	printf("Actual: %c Jugar:\n",b1->UltimoJugador);
	play(b1, b1->Jugador, pArray, &sc);
	print(b1,1,&sc);
	printf("Actual: %c Jugar:\n",b1->UltimoJugador);
		
	printf("***************INICIO ATAQUE Normal EN 4,4 de Enemigo En su propio tablero***************\n");
	pArray=AtaquesMasivos(b1->Jugador[4], setPosition(2,6), b1); 
	printf("ME CAI? FINAL\n");
	printf("Actual: %c Jugar:\n",b1->UltimoJugador);
	play(b1, b1->Enemigos, pArray, &sc);
	print(b1,1,&sc);
	printf("Actual: %c Jugar:\n",b1->UltimoJugador);
	
	printf("Presione una tecla para salir del programa\n");
	getchar();
*/

	
	//INICIO MENU
	int menu=0;
	int Game=0;
	int n =-1;
	int m =-1;
	int x=-1;
	int k=-1;
	int z=-1;
	int y=-1;
	int ATK=0;
	int ID=0;
	Position * pArray;
	code sc;
	Params params;
	Ship Generico,Normal, Acorazado, PortaAvion,Submarino,Buque;
	Normal = cfgShips(3, 1, 0, N, 0);
	Acorazado = cfgShips(4, 1, 0, A, 1);
	PortaAvion = cfgShips(3, 1, 1, P, 0);
	Submarino = cfgShips(3, 1, 2, S, 0);
	Buque = cfgShips(2, 1, 3, B, 0);
	int Dificultad=1;
	params = setParams(Dificultad, &sc);
	Position p;
	Board *b1;
	Board *b2;
	Board *b;
	
	
	while(Game==0)
	{
		printf("***************MENU BATTLESHIP V1.0**************\n");
		n =-1;
		m =-1;
		x=-1;
		k=-1;
		z=-1;
		y=-1;
		printf("Ingrese la opcion a la que quiere acceder\n1.- Crear un Tablero \n2.- Cargar un tablero \n3.-Posicionar un Barco Jugador \n4.-Imprimir el Tablero.\n5.- Realizar una jugada.\n9.- para salir.\n");
		scanf("%d",&menu);			
		switch(menu)
		{
			case 1:
			while(n<=0)
			{
				printf("Ingrese la cantidad de Filas\n");
				scanf("%d",&n);					
			}
			while(m<=0 || m%2!=0)
			{
				printf("Ingrese la cantidad de Columnas, debe ser un numero par\n");
				scanf("%d",&m);					
			}
			printf("Se creara un tablero de %d x %d\n",n,m);
			b1 = createBoard(n,m,params,&sc);
			b=b1;
			printf("Desea imprimir el tablero por pantalla? Presione\n 1.- Para imprimirlo de forma completa\n 2.- Para imprimir solo el tablero del jugador\n");
			scanf("%d",&z);	
			if(z==1)
			{
				print(b1,1,&sc);
			}
			else if(z==2)
			{
				print(b1,0,&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			
			printf("Desea Verificar el tablero creado? Presione\n 1.- Para Verificar\n");
			scanf("%d",&z);	
			if(z==1)
			{
				checkBoard(b1,&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			
			printf("Desea Guardar el tablero creado? Presione\n 1.- Para guardarlo\n");
			scanf("%d",&z);	
			if(z==1)
			{
				saveBoard(b1,generateID(),&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			break;
			
			case 2:
			while(ID<=0)
			{
				printf("Ingrese el id del Tablero que desee cargar (Es un entero positivo)\n");
				scanf("%d",&ID);					
			}
			b2 = loadBoard(ID, &sc);
			b=b2;
			printf("Desea Verificar el tablero Cargado? Presione\n 1.- Para Verificar\n");
			scanf("%d",&z);	
			if(z==1)
			{
				checkBoard(b2,&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			
			printf("Desea imprimir el tablero  cargado? Presione\n 1.- Para imprimirlo de forma completa\n 2.- Para imprimir solo el tablero del jugador\n");
			scanf("%d",&z);	
			if(z==1)
			{
				print(b2,1,&sc);
			}
			else if(z==2)
			{
				print(b2,0,&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			break;
			
			case 3:
			
			if(checkBoard(b,&sc)!=0)
			{
				while(k<=0 || k>5)
				{
					printf("Ingresa el numero del barco que deseas posicionar\n1.- Normal\n2.-Acorazado\n3.- Submarino\n4.- Porta aviones\n5.- Buque Pirata\n");
					scanf("%d",&k);
					if(k==1)
					{
						Generico=Normal;
					}
					if(k==2)
					{
						Generico=Acorazado;
					}
					if(k==3)
					{
						Generico=Submarino;
					}
					if(k==4)
					{
						Generico=PortaAvion;
					}
					if(k==5)
					{
						Generico=Buque;
					}
				}
				while(z<0 || z > b->n)
				{
					printf("Ingresa la coordenada de fila\n");                 
					scanf("%d",&z);					
					
				}
				while(x<0 || x > b->m/2)
				{
					printf("Ingresa la coordenada de columna\n");
					scanf("%d",&x);					
				}
				p=setPosition(z,x);
				putShip(b, p, Generico, &sc);
				print(b,0,&sc);
			}
			else
			{	
				printf("No es un tablero valido\n");
				break;				
				
			}
			break;
			case 4:
			printf("Presione\n 1.- Para imprimirlo de forma completa\n 2.- Para imprimir solo el tablero del jugador\n");
			scanf("%d",&z);	
			if(z==1)
			{
				print(b,1,&sc);
			}
			else if(z==2)
			{
				print(b,0,&sc);
			}
			else{
				printf("Opcion invalida\n");
			}
			break;
			
			case 5:
			while(z!=1 && z!=2 )
			{
				printf("QuiEn realizarA el disparo \n1.- Jugador\n2.- Enemigo\n");
				scanf("%d",&z);					
			}
			
			while(y<0 || y > b->n)
			{
				printf("Ingresa la coordenada de fila\n");                 
				scanf("%d",&y);					
				
			}
			
			if(z==1)
			{
				while(x<0 || x < b->m/2)
				{
					printf("Ingresa la coordenada de columna\n");
					scanf("%d",&x);					
				}
			}
			else if(z==2)
			{
				while(x<0 || x >= b->m/2 || x> b->m)
				{
					printf("Ingresa la coordenada de columna\n");
					scanf("%d",&x);					
				}
			}
			printf("AQUI1\n");
			p=setPosition(x,y);
			printf("AQUI2\n");				
			while(k<=0 || k>5)
			{
				printf("Ingresa el barco que realizarA el disparo\n1.- Normal\n2.-Acorazado\n3.- Submarino\n4.- Porta aviones\n5.- Buque Pirata\n");
				scanf("%d",&k);
				if(k==1)
				{
					pArray=AtaquesMasivos(Normal, p, b);
					
				}
				if(k==2)
				{
					pArray=AtaquesMasivos(Acorazado, p, b);
				}
				if(k==3)
				{
					pArray=AtaquesMasivos(Submarino, p, b);
				}
				if(k==4)
				{
					pArray=AtaquesMasivos(PortaAvion, p, b);
				}
				if(k==5)
				{
					pArray=AtaquesMasivos(Buque, p, b);
				}
			}
			if(z==1)
			{
				play(b, b->Jugador,pArray, &sc);
			}
			else if(z==2)
			{
				play(b, b->Enemigos,pArray, &sc);
			}
			print(b,0,&sc);
			break;
			
			case 9:
			Game=1;
			break;
		}
	printf("**********PARADIGMAS DE PROGRAMACION 2-2016**************\n");
	}

	


	
	
	
	
	
	
	

	
	
	return 0;	
}