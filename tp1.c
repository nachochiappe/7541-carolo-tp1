/*
 * tp1.c
 */

#include <string.h>
#include <stdio.h>

#include "tp1.h"
#include "DocCrear.h"
#include "DocExtraerDocumentacion.h"
#include "DocConstruirIndice.h"

int mostrarAyuda(){
	printf("Genera documentación del código fuente que se indique:\n\n");
	printf("MODO DE USO:\n         tp1.exe [-i][archivo entrada] [-o][archivo salida]\n");
	printf("O bien:  tp1.exe [-0][archivo salida] [-i][archivo entrada]\n\n");
	printf("Donde para el archivo de entrada deberá indicarse un archivo de código fuente que pueda leerse como archivo de texto (.c, .h, etc.),\n");
	printf("Y para el archivo de salida, deberá indicarse la dirección del archivo HTML de salida.\n");
	return (RES_OK);
}

int main (int argc, char *argv[]) {
	TDA_Doc tda;
	char arch_entrada[50];
	char arch_salida[50];
	char arch_indice[50];
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		mostrarAyuda();
		return(0);
	}
	else if (strcmp(argv[1], "-i") == 0) {
		strcpy(arch_entrada, argv[2]);
		if (strcmp(argv[3], "-o") == 0)
			strcpy(arch_salida, argv[4]);
		else return (-1);
	}
	else if (strcmp(argv[1], "-o") == 0) {
		strcpy(arch_salida, argv[2]);
		if (strcmp(argv[3], "-i") == 0)
			strcpy(arch_entrada, argv[4]);
		else return (-1);
	}
	else return (-1);

	strncpy(arch_indice, arch_salida, (strlen(arch_salida) - strlen(".html\0")));
	strcat(arch_indice, ".idx.html");

	DocCrear(&tda);
	DocExtraerDocumentacion(&tda, arch_entrada, arch_salida);
	DocConstruirIndice(&tda, arch_indice);
	DocDestruir(&tda);
	return (0);
}
