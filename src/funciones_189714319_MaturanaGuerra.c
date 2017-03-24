#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "structs_189714319_MaturanaGuerra.h"
#include "funciones_189714319_MaturanaGuerra.h"
#include "constants_189714319_MaturanaGuerra.h"

Board* createBoard(int n, int m, Params params, code *statusCode)
{
	char b0,b1,b2,b3,b4;
	b0='N';
	b1='A';
	b2='P';
	b3='S';
	b4='B';
	time_t t;
	srand((unsigned) time(&t));
	//Position * PosicionTablero;
	
	if ((n>=4)&&(m>=4)) // Tamanho minimo para que quepan los 5 barcos predeterminados.
	{
		if(m%2==0)  // El largo del tablero debe ser par, pues cada jugador utiliza la mitad de -este.
		{
			Board *b = (Board*)malloc(sizeof(Board));
		
			if (b!=NULL)
			{
				b->n = n;
				b->m = m;
				b->matriz = (char**)malloc(sizeof(char*)*n);	
				
				if (b->matriz!=NULL)
				{
					int i;
					int j;
					for (i=0;i<n;i++)
					{
						b->matriz[i] = (char*)calloc(m,sizeof(char));
						if (b->matriz[i]==NULL)
						{
							*statusCode = NOT_ENOUGH_MEMORY;
							return NULL;
						}					
					} // Fin de la asignacion de memoria.
					Ship Generico;
					
					Generico.PosicionesTablero = (int **) calloc(10,sizeof(int*));
					for (i=0;i<7;i++)
					{
						Generico.PosicionesTablero[i]= (int*)calloc(10,sizeof(int));
					}
					
					b->Enemigos = (Ship *)malloc(7*(sizeof(Ship)));
					b->BarcosEnemigos = (int) malloc(sizeof(int));
					b->ActualBarcosEnemigos = (int) malloc(sizeof(int));
					b->BarcosEnemigos=0;
					b->ActualBarcosEnemigos=0;
					int x=0;					
					int acum=0;
					int z;
					for(i=0; i<5; i++)
					{
						for(j=0;j<params.CantidadxTipoBarco[i];j++)
						{
							
							if(i==0)
							{
								b0=b0;
								
								if(acum==0)
								{
									Ship Normal1 = cfgShips(3,1,0,N,0);
									Generico=Normal1;
									//Generico=Normal1;
									//Position p = setPosition(1,2);
									//Normal1.PosicionTablero[0]=p;
									//printf("Fila %d ///// Columna %d\n",Normal1.PosicionTablero[0].Fila,Normal1.PosicionTablero[0].Columna);
									
									
									Normal1.PosicionesTablero = calloc(10,sizeof(int*));
									for(z=0;z<4;z++){
										Normal1.PosicionesTablero[z]= calloc(10,sizeof(int));
									}
									
									//printf("aki1");
									//Normal1.PosicionesTablero[1][0]=1;
									//printf("aki1");
									//Normal1.PosicionesTablero[1][1]=1;
									//printf("aki1");
									b->Enemigos[acum] = Normal1;
									b->Enemigos[acum].comandante=E;
									//printf("acum %d\n",acum);
									//printf("%d %d\n",b->Enemigos[0].PosicionesTablero[1][0],b->Enemigos[0].PosicionesTablero[1][1]);
									//printf("Fila %d ///// Columna %d\n",b->Enemigos[0].PosicionTablero[0].Fila,b->Enemigos[0].PosicionTablero[0].Columna);
									
									//Normal1.PosicionesTablero = (int **) calloc(10,sizeof(char*));
									//for (i=0;i<7;i++)
									//{
									//	Normal1.PosicionesTablero[i]= (int*)calloc(10,sizeof(int));
									//}
									
								}
								else if(acum==1)
								{
									Ship Normal2 = cfgShips(3,1,0,N,0);
									Generico=Normal2;
									Normal2.PosicionesTablero = calloc(10,sizeof(int*));
									for(z=0;z<4;z++){
										Normal2.PosicionesTablero[z]= calloc(10,sizeof(int));
									}
									b->Enemigos[acum] = Normal2;
									b->Enemigos[acum].comandante=E;
								}
								
							}
							else if(i==1)
							{
								b0=b1;
								Ship Acorazadol = cfgShips(4,1,0,A,2);
								Generico=Acorazadol;
								Acorazadol.PosicionesTablero = calloc(10,sizeof(int*));
								for(z=0;z<4;z++){
									Acorazadol.PosicionesTablero[z]= calloc(10,sizeof(int));
								}
								b->Enemigos[acum] = Acorazadol;
								b->Enemigos[acum].comandante=E;
								
							}
							else if(i==2)
							{
								b0=b2;
								Ship PortaAviones1 = cfgShips(3,1,1,P,0);
								Generico=PortaAviones1;
								PortaAviones1.PosicionesTablero = calloc(10,sizeof(int*));
								for(z=0;z<4;z++){
									PortaAviones1.PosicionesTablero[z]= calloc(10,sizeof(int));
								}
								b->Enemigos[acum] = PortaAviones1;
								b->Enemigos[acum].TipoAtaque=1;
								b->Enemigos[acum].comandante=E;
								
							}
							else if(i==3)
							{
								b0=b3;
								Ship Submarino1 = cfgShips(3,1,2,S,0);
								Generico=Submarino1;
								Submarino1.PosicionesTablero = calloc(10,sizeof(int*));
								for(z=0;z<4;z++){
									Submarino1.PosicionesTablero[z]= calloc(10,sizeof(int));
								}
								b->Enemigos[acum] = Submarino1;
								b->Enemigos[acum].comandante=E;
								
							}
							else if(i==4)
							{
								b0=b4;
								Ship Buque1 = cfgShips(2,1,3,S,0);
								Generico=Buque1;
								Buque1.PosicionesTablero = calloc(10,sizeof(int*));
								for(z=0;z<4;z++){
									Buque1.PosicionesTablero[z]= calloc(10,sizeof(int));
								}
								b->Enemigos[acum] = Buque1;
								b->Enemigos[acum].comandante=E;
							}
							x = rand() %(m/2);
							
							x=x+m/2;
							
							
							b->matriz[acum][x]=b0;
							b->Enemigos[acum].PosicionesTablero[0][0]=acum;
							//printf("acum %d\n",acum);
							b->Enemigos[acum].PosicionesTablero[0][1]=x;
							//printf("acum %d\n",acum);
							//Position p;
							//p=setPosition(0,1);
							//b->Enemigos[acum].PosicionTablero[0].Fila=acum;
							//b->Enemigos[acum].PosicionTablero[0].Columna=x;
							
							if (x==m-1)
							{
								
								b->matriz[acum][x-1]=b0;
								
								//b->Enemigos[acum].PosicionTablero[1].Fila=acum;
								//b->Enemigos[acum].PosicionTablero[1].Columna=x-1;
								
								b->Enemigos[acum].PosicionesTablero[1][0]=acum;
								
								b->Enemigos[acum].PosicionesTablero[1][1]=x-1;
								if (i!=4 )
								{
									b->matriz[acum][x-2]=b0;
									//b->Enemigos[acum].PosicionTablero[2].Fila=acum;
									//b->Enemigos[acum].PosicionTablero[2].Columna=x-2;
									b->Enemigos[acum].PosicionesTablero[2][0]=acum;
									b->Enemigos[acum].PosicionesTablero[2][1]=x-2;
									if(i==1)
									{
										b->matriz[acum][x-3]=b0;
										b->Enemigos[acum].PosicionesTablero[3][0]=acum;
										b->Enemigos[acum].PosicionesTablero[3][1]=x-3;
										//b->Enemigos[acum].PosicionTablero[3].Fila=acum;
										//b->Enemigos[acum].PosicionTablero[3].Columna=x-3;
									}
								}
							}
							else if(x==m/2)
							{
								b->matriz[acum][x+1]=b0;
								b->Enemigos[acum].PosicionesTablero[1][0]=acum;
								b->Enemigos[acum].PosicionesTablero[1][1]=x+1;
								//b->Enemigos[acum].PosicionTablero[1].Fila=acum;
								//b->Enemigos[acum].PosicionTablero[1].Columna=x+1;
								if (i!=4)
								{
									b->matriz[acum][x+2]=b0;
									b->Enemigos[acum].PosicionesTablero[2][0]=acum;
									b->Enemigos[acum].PosicionesTablero[2][1]=x+2;
									//b->Enemigos[acum].PosicionTablero[2].Fila=acum;
									//b->Enemigos[acum].PosicionTablero[2].Columna=x+2;
									if (i==1)
									{
										b->matriz[acum][x+3]=b0;
										b->Enemigos[acum].PosicionesTablero[3][0]=acum;
										b->Enemigos[acum].PosicionesTablero[3][1]=x+3;
										//b->Enemigos[acum].PosicionTablero[3].Fila=acum;
										//b->Enemigos[acum].PosicionTablero[3].Columna=x+3;
									}
								}
								
							}
							else
							{
								b->matriz[acum][x+1]=b0;
								b->Enemigos[acum].PosicionesTablero[1][0]=acum;
								b->Enemigos[acum].PosicionesTablero[1][1]=x+1;
								//b->Enemigos[acum].PosicionTablero[1].Fila=acum;
								//b->Enemigos[acum].PosicionTablero[1].Columna=x+1;
								if(i!=4)
								{
									b->matriz[acum][x-1]=b0;
									b->Enemigos[acum].PosicionesTablero[2][0]=acum;
									b->Enemigos[acum].PosicionesTablero[2][1]=x-1;
									//b->Enemigos[acum].PosicionTablero[2].Fila=acum;
									//b->Enemigos[acum].PosicionTablero[2].Columna=x-1;
									if (i==1)
									{
										if(x==m-2)
										{
											b->matriz[acum][x-2]=b0;
											b->Enemigos[acum].PosicionesTablero[3][0]=acum;
											b->Enemigos[acum].PosicionesTablero[3][1]=x-2;
											//b->Enemigos[acum].PosicionTablero[3].Fila=acum;
											//b->Enemigos[acum].PosicionTablero[3].Columna=x-2;
										}
										else
										{
											b->matriz[acum][x+2]=b0;
											b->Enemigos[acum].PosicionesTablero[3][0]=acum;
											b->Enemigos[acum].PosicionesTablero[3][1]=x+2;
											//b->Enemigos[acum].PosicionTablero[3].Fila=acum;
											//b->Enemigos[acum].PosicionTablero[3].Columna=x+2;
										}
									}
								}
							}
							printf("El barco %d Esta posicionado en:\n",acum+1);
							int k;
							for(k=0;k<Generico.Largo;k++)
							{
								printf("Fila %d ///// Columna %d\n",b->Enemigos[acum].PosicionesTablero[k][0],b->Enemigos[acum].PosicionesTablero[k][1]);
								//printf("Fila %d ///// Columna %d\n",b->Enemigos[acum].PosicionTablero[k].Fila,b->Enemigos[acum].PosicionTablero[k].Columna);
							}
							acum=acum+1;
							//printf("acum %d\n",acum);
							b->BarcosEnemigos+=1;
							b->ActualBarcosEnemigos+=1;
						}
					}
					//b->Dificultad = (int) malloc(sizeof(int));
					b->Dificultad=params.Dificultad;
					*statusCode = OK;
					b->BarcosJugador=0;
					b->ActualBarcosJugador=0;
					b->JuegoFinalizado=(int) malloc(sizeof(int));
					b->JuegoFinalizado=0;
					return b;
				}
				else
					*statusCode = NOT_ENOUGH_MEMORY;
				}
			else
				*statusCode = NOT_ENOUGH_MEMORY;
		}
		else
			*statusCode = WRONG_DIM;
	}
	else
		*statusCode = WRONG_DIM;
	
	return NULL;
}

void print(Board *b,int showComplete, code *statusCode)
{
	if (b!=NULL)
	{
		int i, j;
		if(showComplete==1)
		{
			for (i=0;i<b->n;i++)
			{
				printf("|");
				for (j=0;j<b->m;j++)
				{
					if (j==(b->m/2)){
						printf("*|");
					}
					printf("%c|",b->matriz[i][j]);
				}
				
				printf("|%d\n",i);			
			}
			printf(" ");
			for(j=0;j<b->m;j++)
			{
				if (j==(b->m/2))
				{
					printf("*|");
				}
				printf("%d|",j);
			}
			printf("*\n");	
			*statusCode = OK;
		}
		else if(showComplete==0) // solo se imprime la mitad del jugador
		{
			for (i=0;i<b->n;i++)
			{
				printf("|");
				for (j=0;j<b->m;j++)
				{
					if (j==(b->m/2)){
						printf("*|");
					}
					if(j>=b->m/2 && (b->matriz[i][j]=='N' || b->matriz[i][j]=='A' || b->matriz[i][j]=='P' || b->matriz[i][j]=='B' || b->matriz[i][j]=='S'))               // 
					{
						printf(" |",b->matriz[i][j]);
					}
					else
					{
						printf("%c|",b->matriz[i][j]);
					}
				}
				printf("|%d\n",i);				
			}
			printf(" ");
			for(j=0;j<b->m;j++)
			{
				if (j==(b->m/2))
				{
					printf("*|");
				}
				printf("%d|",j);
			}
			printf("*\n");
				
			*statusCode = OK;
		}
	}
	else
	{
		*statusCode = BOARD_NOT_FOUND;
		printf("No se ha encontrado un tablero para imprimir.\n");
	}
}
void destroyBoard(Board **b)
{
	Board *bTemp;

	bTemp = *b;

	int i;

	for (i=0; i<bTemp->m; i++)
		free(bTemp->matriz[i]);

	free(bTemp->matriz);

	free(bTemp);

	*b = NULL;
}

Params setParams(int Dificultad, code *statusCode)
{
	int i,NBNormal, NBAcorazados, NBPortaaviones, NBSubmarino, NBPiratas;
	int * CantidadxTipoBarco;
	Params params;
	if (Dificultad==1)
	{
		NBNormal=2;
		NBAcorazados=1;
		NBPortaaviones=1;
		NBSubmarino=1;
		NBPiratas=1;
	}
	else if (Dificultad==2)
	{
		NBNormal=3;
		NBAcorazados=2;
		NBPortaaviones=1;
		NBSubmarino=2;
		NBPiratas=2;	
	}
	else if (Dificultad==3)
	{
		NBNormal=3;
		NBAcorazados=3;
		NBPortaaviones=2;
		NBSubmarino=3;
		NBPiratas=3;	
	}
	else{
		printf("Dificultad incorrecta\n");
		*statusCode = WRONG_DIFFICULTY;
	}
	
	CantidadxTipoBarco = (int *) malloc(sizeof(int *));
	for(i=0; i<7; i++){
		CantidadxTipoBarco[i] = (int) malloc (sizeof(int));
	}
	
	CantidadxTipoBarco[0]=NBNormal;
	CantidadxTipoBarco[1]=NBAcorazados;
	CantidadxTipoBarco[2]=NBPortaaviones;
	CantidadxTipoBarco[3]=NBSubmarino;
	CantidadxTipoBarco[4]=NBPiratas;
	
	params.Dificultad =Dificultad;
	params.CantidadxTipoBarco = CantidadxTipoBarco;
	return params;
}
void putShip(Board *b, Position p, Ship s, code *statusCode)  // falta establecer jugador[x].PosicionesTablero[i][0y1]
{
	if (b!= NULL)
	{
		int i=0;
		int j=0;
		Ship Generico;
		Generico=s;
		Generico.comandante=J;
		//b->Jugador = (Ship *)malloc(7*sizeof(Ship));
		
		/*for(i=0;i<b->BarcosEnemigos;i++)
		{
			b->Jugador[i]=
		}*/
		//printf("JUGADOR %d\n",b->BarcosJugador);
		
		Generico.PosicionesTablero =(int **) malloc((b->BarcosEnemigos+1)*sizeof(int*));
			
		for(i=0;i<=b->BarcosEnemigos;i++){
			Generico.PosicionesTablero[i]= (int *) malloc((b->BarcosEnemigos+1)*sizeof(int));
		}	
		
		if(b->BarcosJugador==0)
		{
			b->Jugador = (Ship *) malloc((b->BarcosEnemigos+1)*sizeof(Ship));	
		}
		
		
		//printf("JUGADOR %d\n",b->BarcosJugador);
		
		
		/*if(b->BarcosJugador==0)
		{
			for(i=0;i<b->BarcosEnemigos;i++)
			{
				
				for(j=0;j<s.Largo;j++)
				{
					//b->Jugador[i].comandante=(Comandante) malloc(sizeof(Comandante));
					b->Jugador[i].PosicionesTablero[j]= malloc(sizeof(int));
					b->Jugador[i].PosicionesTablero[j]= malloc(sizeof(int));					
				}
			}
		}*/
		
//		b->Jugador[b->BarcosJugador]
		//b->Jugador[b->BarcosJugador].comandante=(Comandante) malloc(sizeof(Comandante));
		
		b->Jugador[b->BarcosJugador]=Generico;
		
		/*
		for(i=0;i<s.Largo;i++)
		{
			b->Jugador[b->BarcosJugador].PosicionesTablero[i][0]=(int) malloc(sizeof(int));
			b->Jugador[b->BarcosJugador].PosicionesTablero[i][1]=(int) malloc(sizeof(int));			
		}*/
			
		
		//printf("JUGADOR %d\n",b->BarcosJugador);
		
		//printf("BARCOS ENEMIGOS %d\n",b->BarcosEnemigos);
		
		//printf("Barcos Jugador %d\n",b->BarcosJugador);	
		//b->Jugador[b->BarcosJugador].comandante=J;
		
		if(b->BarcosJugador <= b-> BarcosEnemigos+1)
		{
			if(p.Fila>=0 && p.Fila<b->n) // Se verifica que sea una posicion valida dentro del tablero (A lo ancho).
			{
				if(p.Columna>=0 && p.Columna<b->m/2) // Se verifica que sea una posicion valida en la mitad del tablero correspondiente al jugador.
				{
					// Inicio verificacion si las posiciones adonde irA el barco estAn ocupadas.
					if(p.Fila==0)
					{
						if(b->matriz[p.Fila][p.Columna]==0)
						{
							if(b->matriz[p.Fila+1][p.Columna]==0 && s.Largo>2)
							{
								if(b->matriz[p.Fila+2][p.Columna]==0 && s.Largo>3)
								{
									if(b->matriz[p.Fila+3][p.Columna]==0 && s.Largo==4)
									{
										
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila+1;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila+2;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][0]=p.Fila+3;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][1]=p.Columna;
										

										b->matriz[p.Fila][p.Columna]=s.charBarco;
										b->matriz[p.Fila+1][p.Columna]=s.charBarco;
										b->matriz[p.Fila+2][p.Columna]=s.charBarco;
										b->matriz[p.Fila+3][p.Columna]=s.charBarco;
										
										
										b->BarcosJugador+=1;
										b->ActualBarcosJugador+=1;
										*statusCode = OK;
									}
									else
									{
										printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
										*statusCode = PUT_ERROR_OCUPPED;
									}
								}
								else if(b->matriz[p.Fila+2][p.Columna]==0 && s.Largo==3)
								{
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila+1;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila+2;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;
									
									
									b->matriz[p.Fila][p.Columna]=s.charBarco;
									b->matriz[p.Fila+1][p.Columna]=s.charBarco;
									b->matriz[p.Fila+2][p.Columna]=s.charBarco;
									b->BarcosJugador+=1;
									b->ActualBarcosJugador+=1;
									*statusCode = OK;
								}
								else
								{
									printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
									*statusCode = PUT_ERROR_OCUPPED;
								}
							}
							else if(b->matriz[p.Fila+1][p.Columna]==0 && s.Largo==2)
							{
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila+1;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
								
								b->matriz[p.Fila][p.Columna]=s.charBarco;
								b->matriz[p.Fila+1][p.Columna]=s.charBarco;
								b->BarcosJugador+=1;
								b->ActualBarcosJugador+=1;
								*statusCode = OK;
							}
							else
							{
								printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
								*statusCode = PUT_ERROR_OCUPPED;
							}
						}
						else
						{
							printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
							*statusCode = PUT_ERROR_OCUPPED;
						}
					
					}
					else if(p.Fila==b->n-1)
					{
						if(b->matriz[p.Fila][p.Columna]==0)
						{
							if(b->matriz[p.Fila-1][p.Columna]==0 && s.Largo>2)
							{
								if(b->matriz[p.Fila-2][p.Columna]==0 && s.Largo>3)
								{
									if(b->matriz[p.Fila-3][p.Columna]==0 && s.Largo==4)
									{
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila-2;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][0]=p.Fila-3;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][1]=p.Columna;
										
										
										b->matriz[p.Fila][p.Columna]=s.charBarco;
										b->matriz[p.Fila-1][p.Columna]=s.charBarco;
										b->matriz[p.Fila-2][p.Columna]=s.charBarco;
										b->matriz[p.Fila-3][p.Columna]=s.charBarco;
										b->BarcosJugador+=1;
										b->ActualBarcosJugador+=1;
										*statusCode = OK;
									}
									else
									{
										printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
										*statusCode = PUT_ERROR_OCUPPED;
									}
								}
								else if(b->matriz[p.Fila-2][p.Columna]==0 && s.Largo==3)
								{
									
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila-2;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;
										
									b->matriz[p.Fila][p.Columna]=s.charBarco;
									b->matriz[p.Fila-1][p.Columna]=s.charBarco;
									b->matriz[p.Fila-2][p.Columna]=s.charBarco;
									b->BarcosJugador+=1;
									b->ActualBarcosJugador+=1;
									*statusCode = OK;
								}
								else
								{
									printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
									*statusCode = PUT_ERROR_OCUPPED;
								}
							}
							else if(b->matriz[p.Fila-1][p.Columna]==0 && s.Largo==2)
							{
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
								
								b->matriz[p.Fila][p.Columna]=s.charBarco;
								b->matriz[p.Fila-1][p.Columna]=s.charBarco;
								b->BarcosJugador+=1;
								b->ActualBarcosJugador+=1;
								*statusCode = OK;
							}
							else
							{
								printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
								*statusCode = PUT_ERROR_OCUPPED;
							}
						}
						else
						{
							printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
							*statusCode = PUT_ERROR_OCUPPED;
						}
						
					}
					else
					{
						if(b->matriz[p.Fila][p.Columna]==0)
						{
							if(b->matriz[p.Fila-1][p.Columna]==0 && s.Largo>2)
							{
								if(b->matriz[p.Fila+1][p.Columna]==0 && s.Largo>3)
								{
									if(b->matriz[p.Fila+2][p.Columna]==0 && s.Largo==4)
									{
										
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
										b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
										b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila+1;
										b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][0]=p.Fila+2;
										b->Jugador[b->BarcosJugador].PosicionesTablero[3][1]=p.Columna;
										
										
										b->matriz[p.Fila][p.Columna]=s.charBarco;
										b->matriz[p.Fila-1][p.Columna]=s.charBarco;
										b->matriz[p.Fila+1][p.Columna]=s.charBarco;
										b->matriz[p.Fila+2][p.Columna]=s.charBarco;
										b->BarcosJugador+=1;
										b->ActualBarcosJugador+=1;
										*statusCode = OK;
									}
									else
									{
										printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
										*statusCode = PUT_ERROR_OCUPPED;
									}
								}
								else if(b->matriz[p.Fila+1][p.Columna]==0 && s.Largo==3)
								{
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
									b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
									b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][0]=p.Fila+1;
									b->Jugador[b->BarcosJugador].PosicionesTablero[2][1]=p.Columna;

									b->matriz[p.Fila][p.Columna]=s.charBarco;
									b->matriz[p.Fila-1][p.Columna]=s.charBarco;
									b->matriz[p.Fila+1][p.Columna]=s.charBarco;
									b->BarcosJugador+=1;
									b->ActualBarcosJugador+=1;
									*statusCode = OK;
								}
								else
								{
									printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
									*statusCode = PUT_ERROR_OCUPPED;
								}
							}
							else if(b->matriz[p.Fila-1][p.Columna]==0 && s.Largo==2)
							{
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][0]=p.Fila;
								b->Jugador[b->BarcosJugador].PosicionesTablero[0][1]=p.Columna;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][0]=p.Fila-1;
								b->Jugador[b->BarcosJugador].PosicionesTablero[1][1]=p.Columna;
										
								b->matriz[p.Fila][p.Columna]=s.charBarco;
								b->matriz[p.Fila-1][p.Columna]=s.charBarco;
								b->BarcosJugador+=1;
								b->ActualBarcosJugador+=1;
								*statusCode = OK;
							}
							else
							{
								printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
								*statusCode = PUT_ERROR_OCUPPED;
							}
						}
						else
						{
							printf("La posicion se encuentra ocupada, posicionamiento FALLIDO\n");
							*statusCode = PUT_ERROR_OCUPPED;
						}
					}			
				}
				else
				{
					printf("No es tu tablero, posicionamiento FALLIDO\n");
					*statusCode = WRONG_DIM;
				}
			}
			else
			{
				printf("La posicion no estA en el tablero, posicionamiento FALLIDO\n");
				*statusCode = WRONG_DIM;
			}
		}
		else
		{
			printf("No puedes tener mas de un barco que el enemigo, has alcanzado el limite\n");
			*statusCode = ERROR_MAX_SHIP_REACHED;
		}
		
	}
	else
	{
		*statusCode = BOARD_NOT_FOUND;
	}
}

Ship cfgShips(int Largo, int Ancho, int ATKEspecial, char charBarco, int DEF)
{
	Ship s;
	
	s.Largo=Largo;
	s.Ancho=Ancho;
	s.Vida=Largo*Ancho;
	s.TipoAtaque=ATKEspecial;
	s.charBarco=charBarco;
	s.Defensa=DEF;
	return s;
}

Position setPosition(int Fila, int Columna)
{
	Position p;
	p.Fila=Fila;
	p.Columna=Columna;
	return p;
}

int play(Board *b, Ship * ship,Position * pArray, code *statusCode)
{
	printf("****Comandante Barco %c \n",ship[0].comandante);
	if (b->UltimoJugador!=ship->comandante)
	{
		//printf("Puede realizar el ataque, no es el mismo LASTPLAYER\n");
		if (b!=NULL)
		{
			printf("JuegoFinalizado %d\n",b->JuegoFinalizado);
			if(b->JuegoFinalizado!=0)
			{
				printf("No se pueden realizar mas movimientos, el juego ha terminado: \n");
				if(b->JuegoFinalizado==1)
				{
					printf("El ganador de esta partida fue el Jugador\n");
				}
				else if(b->JuegoFinalizado==2)
				{
					printf("El ganador de esta partida fue el Enemigo\n");
				}
				*statusCode=ERROR_GAME_FINALIZED;
				return -1;
			}
			int k;
			for(k=1;k<=pArray[0].Fila;k++)
			{
				
				if ((pArray[k].Fila< b->n )&&(pArray[k].Columna < b->m ) && (pArray[k].Fila >= 0)&&(pArray[k].Columna >= 0))
				{
					
					if ((b->matriz[pArray[k].Fila][pArray[k].Columna]==N)||(b->matriz[pArray[k].Fila][pArray[k].Columna]==A)||(b->matriz[pArray[k].Fila][pArray[k].Columna]==P)||(b->matriz[pArray[k].Fila][pArray[k].Columna]==S)||(b->matriz[pArray[k].Fila][pArray[k].Columna]==B))
					{
						
						int z;
						if (ship->comandante==J && pArray[k].Columna >= b-> m/2)
						{
							printf("JUGADOR A ENEMIGO Se atacara la fila %d y la columna %d\n",pArray[k].Fila,pArray[k].Columna);
							z= BarcoAtacado(pArray[k], J, b);
							//printf("Jugador disparando a Enemigo al barco %d\n",z);
							if(b->Enemigos[z].Defensa==0)
							{
								b->Enemigos[z].Vida-=1;
								if(b->Enemigos[z].Vida==0)
								{
									b->matriz[pArray[k].Fila][pArray[k].Columna]=X; // El barco fue destruido.
									*statusCode = OK;
//									b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
									b->UltimoJugador=ship->comandante;
									b->ActualBarcosEnemigos-=1;
									printf("Has destruido un Barco Enemigo, restan %d\n",b->ActualBarcosEnemigos);
									if(b->ActualBarcosEnemigos==0)
									{
										printf("El juego ha finalizado, ha ganado el Jugador.\n");
										b->JuegoFinalizado=1;
									}
									//printf("El UltimoJugador es %c\n",b->UltimoJugador);
						
//									return 2;
								}
								else if(b->Enemigos[z].Vida!=0)
								{
									b->matriz[pArray[k].Fila][pArray[k].Columna]=O; // El disparo fue acertado, pero, el barco sigue con vida.
//									b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
									b->UltimoJugador=ship->comandante;
									//printf("El UltimoJugador es %c\n",b->UltimoJugador);
									
									*statusCode = OK;
//									return 1;
								}
								
							}
							else if(b->Enemigos[z].Defensa!=0)
							{
								b->Enemigos[z].Defensa-=1; // La defensa mitiga el danho 
								b->UltimoJugador=ship->comandante;
//								b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
								//printf("El UltimoJugador es %c\n",b->UltimoJugador);
								*statusCode=OK;
//								return 3;
							}						
						}
						else if(ship->comandante==E && pArray[k].Columna < b-> m/2)
						{
							printf("Enemigo a Jugador Se atacara la fila %d y la columna %d\n",pArray[k].Fila,pArray[k].Columna);
							z= BarcoAtacado(pArray[k], E, b);
							//printf("Enemigo disparando a Jugador al barco %d\n",z);
							
							if(b->Jugador[z].Defensa==0)
							{
								b->Jugador[z].Vida-=1;
								
								if(b->Jugador[z].Vida==0)
								{
									b->matriz[pArray[k].Fila][pArray[k].Columna]=X; // El barco fue destruido.
									*statusCode = OK;
									
//									b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
									b->UltimoJugador=ship->comandante;
									//printf("El UltimoJugador es %c\n",b->UltimoJugador);
									
									b->ActualBarcosJugador-=1;
									printf("Has destruido un Barco Jugador, restan %d\n",b->ActualBarcosJugador);
									if(b->ActualBarcosJugador==0)
									{
										printf("El juego ha finalizado, ha ganado el Enemigo.\n");
										b->JuegoFinalizado=2;
									}
									
									*statusCode = OK;
//									return 2;
								}
								else if(b->Jugador[z].Vida!=0)
								{
									b->matriz[pArray[k].Fila][pArray[k].Columna]=O; // El disparo fue acertado, pero, el barco sigue con vida.
//									b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
									b->UltimoJugador= ship->comandante;
									//printf("El UltimoJugador es %c\n",b->UltimoJugador);
									*statusCode = OK;
//									return 1;
								}
								
							}
							else if(b->Jugador[z].Defensa!=0)
							{
//								b->UltimoJugador = (Comandante) malloc(sizeof(Comandante));
								printf("Le has dado a un barco que posee defensa, le restan %d puntos de defensa\n",b->Jugador[z].Defensa);
								b->UltimoJugador=ship->comandante;
								//printf("El UltimoJugador es %c\n",b->UltimoJugador);
								b->Jugador[z].Defensa-=1; // La defensa mitiga el danho 
								printf("Le has dado a un barco que posee defensa, le restan %d puntos de defensa\n",b->Jugador[z].Defensa);
								*statusCode=OK;
//								return 3;
							}	
						}
						else{
							printf("No puedes atacar tu mismo tablero\n");
							//*statusCode=
						}
					}
					else if((b->matriz[pArray[k].Fila][pArray[k].Columna]==X)|| (b->matriz[pArray[k].Fila][pArray[k].Columna]==O)||(b->matriz[pArray[k].Fila][pArray[k].Columna]==W))
					{
						printf("Ya se ha efectuado un disparo en esta posicion\n");
					}
					else // SE puede agregar un else if con O X y # para prevenir que se dispare mas de una vez en la misma posicion
					{
						if(ship->comandante==J && pArray[k].Columna >= b-> m/2)
						{
							b->UltimoJugador=ship->comandante;
							b->matriz[pArray[k].Fila][pArray[k].Columna]=W;							
						}
						else if(ship->comandante==E && pArray[k].Columna < b-> m/2)
						{
							b->UltimoJugador=ship->comandante;
							b->matriz[pArray[k].Fila][pArray[k].Columna]=W;	
						}
//						return 0;
					}
				}
				else
				{
					*statusCode = WRONG_DIM;	
				}
			}
		}
		else
			*statusCode = ERROR;
	}
	else
	{
		*statusCode = ERROR_ITS_NOT_YOUR_TURN;
		printf("No es tu turno\n");
	}
}

int BarcoAtacado(Position p, Comandante comandante, Board *b) // El comandante corresponde al barco que realiza el Disparo.
{
	int i,j;
	if(comandante == J)
	{
		for(i=0;i<b->BarcosEnemigos;i++)
		{
			for(j=0;j<b->Enemigos[i].Largo;j++)
			{
				if(b->Enemigos[i].PosicionesTablero[j][0]==p.Fila && b->Enemigos[i].PosicionesTablero[j][1]==p.Columna)
				{
					//printf("Se va a atacar el barco %d\n",i);
					return i;
				}
			}
		}
	}
	else if(comandante == E)
	{
		//printf("Buscando en los barcos del Jugador\n");
		for(i=0;i<b->BarcosJugador;i++)
		{
			//printf("Analizando el barco %d\n",i);
			//printf("Largo Del Barco %d\n",b->Jugador[i].Largo);
			
			for(j=0;j<b->Jugador[i].Largo;j++)
			{
			//	printf("Analizando el barco %d en la posicion %d\n",i,j);
			//	printf("BARCO %d en %d,%d\n",i,b->Jugador[i].PosicionesTablero[j][0],b->Jugador[i].PosicionesTablero[j][1]);
				if(b->Jugador[i].PosicionesTablero[j][0]==p.Fila && b->Jugador[i].PosicionesTablero[j][1]==p.Columna)
				{
					//printf("Se va a atacar el barco %d\n",i);
					return i;
				}
			}
		}
		//printf("Agua\n");
	}
	return -1;
}

void saveBoard(Board *b, int * id, code *statusCode)
{
	if(b != NULL)
	{
		FILE * BSaved;
		int n1,m1,Dificultad1;
		n1=b ->n;
		m1=b->m;
		Dificultad1=b->Dificultad;
		
		//printf("n %d m %d dif %d id %d\n",n1,m1,Dificultad1,*id);
		BSaved=fopen("BoardsSaved.txt","a");
		if (BSaved==NULL)
		{
			*statusCode=ERROR_FILE_NOT_PERM;
		}
		else{
			//fprintf(BSaved,"ID %d: %d,%d,%d\n",*id,n1,m1,Dificultad1);
			*statusCode=OK;
		}
		//fprintf();
		fclose(BSaved);
		printf("Se ha Guardado de forma correcta el tablero con ID: %d\n",*id);
	}
	else
	{
		*statusCode = BOARD_NOT_FOUND;
	}
	
}
Board * loadBoard(int id, code * statusCode)
{
	FILE * BSaved;
	char strID[2], str1[1],str2[1],str3[1];
	BSaved=fopen("BoardsSaved.txt","r");
	int * ID1;
	int * n;
	int * m;
	int * Dificultad;
	int Encontrado =0;
	ID1 = malloc(sizeof(int));
	n = calloc(1,sizeof(int));
	m = calloc(1,sizeof(int));
	Dificultad = malloc(sizeof(int));
	Params params;
	if(BSaved!=NULL)
	{
		while(Encontrado!=1 && !feof(BSaved))
		{
			fscanf(BSaved,"%s %d %c %d %c %d %c %d",strID,ID1,str1,n,str2,m,str3,Dificultad);
			//printf("/////// %s %d %d %d %d \n",strID,*ID1,*n,*m,*Dificultad);
			if (*ID1==id)
			{
				printf("SON IGUALES %d %d\n",*ID1,id);
				Encontrado=1;	
			}
			
		}
		if(Encontrado==1)
		{
			Board * b;
			printf("El tablero ID: %d ha sido encontrado de forma exitosa\n.",id);
			params=setParams(*Dificultad,statusCode);
			b=createBoard(*n,*m,params,statusCode);	
			*statusCode=OK;
			fclose(BSaved);
			return b;
		}
		else{
			printf("El tablero ID: %d no existe.\n",id);
			*statusCode= ERROR_ID_NOT_FOUND;
			fclose(BSaved);
			return NULL;
		}
	}
	else{
		printf("No se ha podido acceder al archivo de forma exitosa\n");
		*statusCode=ERROR_FILE_NOT_PERM;
		fclose(BSaved);
		return NULL;
	}
}

int * generateID()
{
	time_t t;
	int *x;
	int y;
	x = malloc(sizeof(int));
	srand((unsigned) time(&t));
	y = rand();
	*x = rand();
	return x;
}

int checkBoard(Board * b, code *statusCode)
{
	bool TRUE;
	bool FALSE;
	if (b == NULL)
	{
		printf("No se encuentra el tablero\n");
		*statusCode =BOARD_NOT_FOUND;
		return FALSE;
	}
	else 
	{
		if (b->m<0 || ((b->m%2)!=0) || b->n < 0)
		{
			printf("%d,%d \n",b->n,b->m);
			printf("El tablero no posee las dimensiones correctas\n");
			*statusCode= WRONG_DIM;
			return FALSE;
		}	
		else
		{
			if(b->Dificultad <=0 ||  b->Dificultad >=4)
			{
				printf("El tablero posee una incorrecta dificultad\n");
				*statusCode=WRONG_DIFFICULTY;
				return FALSE;
			}
			else
			{
				if(b->BarcosEnemigos==0)
				{
					printf("El tablero no posee barcos enemigos\n");
					*statusCode=IMPOSSIBLE_VALID_BOARD;
					return FALSE;
				}
				else
				{
					printf("El tablero cuenta con todas las caracteristicas para ser considerado valido\n");
					*statusCode=OK;					
					return TRUE;					
				}
			}
			
		}
	}
}

Position * AtaquesMasivos(Ship s, Position p, Board * b)
{
	Position * pArray;
	int Disparos=0;
	int n1=b->n;
	int m1=b->m;
	int i;
	printf("EL TIPO DE ATK ES %d\n",s.TipoAtaque);
	if(s.TipoAtaque==0)
	{
		printf("ME CAI? FINAL1\n");
		pArray=malloc(2*sizeof(Position *));
		printf("ME CAI? FINAL1\n");
		pArray[0]=setPosition(1,1); //La posicion 0 del pArray contiene la cantidad de disparos a realizar. //AKI ESTA EL FALLO
		printf("ME CAI? FINAL1\n");
		pArray[1]=setPosition(p.Fila,p.Columna);
		printf("ME CAI? FINAL1\n");
		
		return pArray;
	}
	else if(s.TipoAtaque==1) // Ataque por fila
	{
		pArray=malloc((n1+1)*sizeof(Position *));
		printf("Ataque por fila\n");
		for(i=0;i<b->n;i++)
		{
			printf("Se atacaran las posiciones %d,%d\n",i,p.Columna);
			pArray[i+1]=setPosition(i,p.Columna);
			Disparos+=1;
		}
		pArray[0]=setPosition(Disparos,Disparos);
		return pArray;
	}
	else if(s.TipoAtaque==2)
	{
		printf("Ataque en Area 3x3\n");
		pArray=malloc(10*sizeof(Position*));
		pArray[0]=setPosition(9,9);
		pArray[1]=setPosition(p.Fila-1,p.Columna-1);
		pArray[2]=setPosition(p.Fila-1,p.Columna);
		pArray[3]=setPosition(p.Fila-1,p.Columna+1);
		pArray[4]=setPosition(p.Fila,p.Columna-1);
		pArray[5]=setPosition(p.Fila,p.Columna);
		pArray[6]=setPosition(p.Fila,p.Columna+1);
		pArray[7]=setPosition(p.Fila+1,p.Columna-1);
		pArray[8]=setPosition(p.Fila+1,p.Columna);
		pArray[9]=setPosition(p.Fila+1,p.Columna+1);
		return pArray;
		
	}
	else if(s.TipoAtaque==3) //Ataque por Columna
	{
		pArray=malloc((m1+1)*sizeof(Position *));
		for(i=0;i<b->m;i++)
		{
			pArray[i+1]=setPosition(p.Fila,i);
			Disparos+=1;
		}
		pArray[0]=setPosition(Disparos,Disparos);
		return pArray;
	}
	
}

int getScore(Game g)
{
	int Puntaje;
	int BJI = g.board.BarcosJugador;
	int BEI = g.board.BarcosEnemigos;
	int BAJ=g.board.ActualBarcosEnemigos;
	int BAE=g.board.ActualBarcosEnemigos;
	int Dif=g.board.Dificultad;
	Puntaje=1000*(BAJ-BAE)*Dif + (BJI-BEI) * 500;
	
	
	return Puntaje;
}
