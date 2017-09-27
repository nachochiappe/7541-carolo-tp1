/*
 * tp1.c
 */

#include <string.h>
#include <stdio.h>

#include "tp1.h"
<<<<<<< HEAD
//#include "DocCrear.h"
=======
#include "DocCrear.h"
>>>>>>> 2bd05e3c8b973faa7d00ed0b583aa8827ad74689
#include "DocExtraerDocumentacion.h"
#include "DocConstruirIndice.h"
/*#include "DocDestruir.h"*/

int main (int argc, char *argv[]) {
	TDA_Doc tda;
	char arch_entrada[50];
	char arch_salida[50];
	char arch_indice[50];
<<<<<<< HEAD
=======
	char *valor;
>>>>>>> 2bd05e3c8b973faa7d00ed0b583aa8827ad74689
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0) {
		/*mostrarAyuda();*/
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

<<<<<<< HEAD
	strncpy(arch_indice, arch_salida,(strlen(arch_salida)-strlen(".html\0")));
	strcat(arch_indice, ".idx.html");

	//DocCrear(&tda);
=======
	strcpy(arch_indice, arch_salida);
	valor = strtok(arch_indice, ".html");
	strcpy(arch_indice, valor);
	strcat(arch_indice, ".idx.html");

	DocCrear(&tda);
>>>>>>> 2bd05e3c8b973faa7d00ed0b583aa8827ad74689
	DocExtraerDocumentacion(&tda, arch_entrada, arch_salida);
	DocConstruirIndice(&tda, arch_indice);
	/*DocDestruir(&tda);*/
	return (0);
}
