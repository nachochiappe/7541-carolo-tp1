#include <stdio.h>
#include <string.h>

#include "tp1.h"

int ParametroCrear(t_parametro* p){
	char vacio[2] = "\0";
	strcpy(p -> param_nombre, vacio);
	strcpy(p -> param_valor, vacio);
	return (RES_OK);
}

int BloqueCrear(t_bloque* b){
	char vacio[2] = "\0";
	t_parametro p;
	ParametroCrear(&p);
	strcpy(b -> autor, vacio);
	strcpy(b -> descr, vacio);
	strcpy(b -> devuelve, vacio);
	strcpy(b -> fecha, vacio);
	strcpy(b -> funcion, vacio);
	strcpy(b -> pos, vacio);
	strcpy(b -> pre, vacio);
	strcpy(b -> version, vacio);
	b -> cant_param = MAX_PARAM;
	for (int var = 0; var < b -> cant_param; ++var) {
		b -> param[var] = p;
	}
	return (RES_OK);
}

int DocCrear(TDA_Doc* doc){
	t_bloque b;
	BloqueCrear(&b);
	doc -> cant_bloques = MAX_FUNCIONES;
	for (int var = 0; var < doc -> cant_bloques; ++var) {
		doc -> bloque[var] = b;
	}
	return (RES_OK);
}

int DocDestruir(TDA_Doc* doc){
	DocCrear(doc);
	return (RES_OK);
}


