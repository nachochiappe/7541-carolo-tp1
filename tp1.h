/*
 * tp1.h
 *
 *  Created on: 7/9/2017
 *      Author: N67793
 */

#ifndef TP1_H_
#define TP1_H_

#define RES_OK 0
#define RES_ERROR -1
#define MAX_FUNCIONES 10
#define MAX_PARAM 10

typedef struct t_parametro {
	char param_nombre[30];
	char param_valor[100];
} t_parametro;

typedef struct t_bloque {
	char funcion[100];
	char descr[255];
	char autor[50];
	char fecha[15];
	char version[15];
	t_parametro param[MAX_PARAM];
	int cant_param;
	char devuelve[255];
	char pre[255];
	char pos[255];
} t_bloque;

typedef struct TDA_Doc {
	t_bloque bloque[MAX_FUNCIONES];
	int cant_bloques;
} TDA_Doc;

#endif /* TP1_H_ */
