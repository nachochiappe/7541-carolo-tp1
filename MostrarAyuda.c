#include <stdio.h>
#include <string.h>

#include "tp1.h"

int mostrarAyuda(){
	printf("Genera documentación del código fuente que se indique:\n\n");
	printf("MODO DE USO:\n         tp1.exe [-i][archivo entrada] [-o][archivo salida]\n");
	printf("O bien:  tp1.exe [-0][archivo salida] [-i][archivo entrada]\n\n");
	printf("Donde para el archivo de entrada deberá indicarse un archivo de código fuente que pueda leerse como archivo de texto (.c, .h, etc.),\n");
	printf("Y para el archivo de salida, deberá indicarse la dirección del archivo HTML de salida.\n");
	return RES_OK;
}


