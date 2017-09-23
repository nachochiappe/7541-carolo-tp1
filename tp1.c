/*
 * tp1.c
 */

#include <string.h>
#include <stdio.h>

#include "DocExtraerDocumentacion.h"

int main (int argc, char *argv[]) {
	TDA_Doc *tda;
	char arch_entrada[50];
	char arch_salida[50];
	char arch_indice[50];
	if (strcmp(argv[1], "-h") == 0) return(0); //ACA HAY QUE LLAMAR A MOSTRARAYUDA()
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
	DocExtraerDocumentacion(&tda, arch_entrada, arch_salida);
	/*
	if (DocCrear(&tda) == 0) {
		if (DocExtraerDocumentacion(&tda, arch_entrada, arch_salida) == 0) {
			if (DocConstruirIndice(&tda, arch_indice) != 0) {
				printf("No se pudo construir el índice.\n");
				return (-1);
			}
		}
		else {
			printf("No se pudo extraer la documentación.\n");
			return (-1);
		}
	}
	else {
		printf("No se pudo crear el documentador.\n");
		return (-1);
	}
	if (DocDestruir(&tda) != 0) {
		printf("No se pudo destruir el TDA.\n");
		return (-1);
	}
	*/
	return (0);
}
