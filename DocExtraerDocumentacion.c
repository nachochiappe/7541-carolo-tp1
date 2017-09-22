/*
 * DocExtraerDocumentacion.c
 */

#include <stdio.h>
#include <string.h>

#define RES_OK 0
#define RES_ERROR -1

typedef struct TDA_Doc {
	char funcion[255];
	char descr[255];
	char autor[255];
	char fecha[255];
	char version[255];
	char param[255];
	char devuelve[255];
	char pre[255];
	char pos[255];
} TDA_Doc;

int DocExtraerDocumentacion (TDA_Doc *tda, char *arch_entrada, char *arch_salida) {
	FILE *archivo;
	char linea[255];
	char *palabra_res;
	char *valor;
	archivo = fopen(arch_entrada, "r");
	if (!archivo) return (-1);
		else {
			while (fgets(linea, sizeof(linea), archivo)) {
				if (strncmp(linea, "/*", 2) == 0) {
					/* INICIO COMENTARIO */
					while (fgets(linea, sizeof(linea), archivo)) {
						if ((strncmp(linea, "*/", 2) == 0) || (strncmp(linea, " */", 3) == 0))
							/* FIN COMENTARIO */
							break;
						else if (strncmp(linea, "@", 1) == 0) {
							palabra_res = strtok(linea, " ");
							valor = strtok(NULL, "\0");
							if (strcmp(palabra_res, "@funcion") == 0) strcpy(tda.funcion, valor);
							else if (strcmp(palabra_res, "@descr") == 0) strcpy(tda.descr, valor);
							else if (strcmp(palabra_res, "@autor") == 0) strcpy(tda.autor, valor);
							else if (strcmp(palabra_res, "@fecha") == 0) strcpy(tda.fecha, valor);
							else if (strcmp(palabra_res, "@version") == 0) strcpy(tda.version, valor);
							else if (strcmp(palabra_res, "@param") == 0) strcpy(tda.param, valor);
							else if (strcmp(palabra_res, "@devuelve") == 0) strcpy(tda.devuelve, valor);
							else if (strcmp(palabra_res, "@pre") == 0) strcpy(tda.pre, valor);
							else if (strcmp(palabra_res, "@pos") == 0) strcpy(tda.pos, valor);
							}
						}
					}
				}
			}
	fclose(archivo);
	return (0);
}
