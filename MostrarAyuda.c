#include <stdio.h>
#include <string.h>

#include "tp1.h"

int mostrarAyuda(){
	printf("Genera documentaci�n del c�digo fuente que se indique:\n\n");
	printf("MODO DE USO:\n         tp1.exe [-i][archivo entrada] [-o][archivo salida]\n");
	printf("O bien:  tp1.exe [-0][archivo salida] [-i][archivo entrada]\n\n");
	printf("Donde para el archivo de entrada deber� indicarse un archivo de c�digo fuente que pueda leerse como archivo de texto (.c, .h, etc.),\n");
	printf("Y para el archivo de salida, deber� indicarse la direcci�n del archivo HTML de salida.\n");
	return RES_OK;
}


