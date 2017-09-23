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

int generarCabeceraHTML (FILE *arch_HTML, char *arch_salida) {
	arch_HTML = fopen(arch_salida, "r+");
	fputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n", arch_HTML);
	fputs("<html>\n", arch_HTML);
	fputs("<head>\n", arch_HTML);
	fputs("\t<META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n", arch_HTML);
	fputs("</head>\n", arch_HTML);
	fputs("<body>\n", arch_HTML);
	fputs("\t<div>\n", arch_HTML);
	fclose(arch_HTML);
	return (0);
}

int generarContenidoHTML (FILE *arch_HTML, char *arch_salida, TDA_Doc *tda) {
	arch_HTML = fopen(arch_salida, "r+");
	fputs("<h3>Funci&oacute;n: <a name=�[valor]�>[valor]</a></h3>", arch_HTML);
	fputs("<dl>\n<dt>\nDescripci&oacute;n</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nAutor</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nFecha</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nVersion</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nPar&aacute;metro: [nombre]</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nRetorno</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nPre-Condici&oacute;n</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fputs("<dl>\n<dt>\nPost-Condici&oacute;n</dt>\n<dd>[valor]</dd>\n</dl>\n", arch_HTML);
	fclose(arch_HTML);
	return (0);
}

int generarFinHTML (FILE *arch_HTML, char *arch_salida) {
	arch_HTML = fopen(arch_salida, "r+");
	fputs("\t</div>\n", arch_HTML);
	fputs("</body>\n", arch_HTML);
	fputs("</html>\n", arch_HTML);
	fclose(arch_HTML);
	return (0);
}

int DocExtraerDocumentacion (TDA_Doc *tda, char *arch_entrada, char *arch_salida) {
	FILE *archivo;
	FILE *arch_HTML;
	char linea[255];
	char *palabra_res;
	char *valor;
	archivo = fopen(arch_entrada, "r");
	arch_HTML = fopen(arch_entrada, "w");
	if (generarCabeceraHTML(arch_HTML, arch_salida) != 0) return RES_ERROR;
	else
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
							if (strcmp(palabra_res, "@funcion") == 0) strcpy(tda->funcion, valor);
							else if (strcmp(palabra_res, "@descr") == 0) strcpy(tda->descr, valor);
							else if (strcmp(palabra_res, "@autor") == 0) strcpy(tda->autor, valor);
							else if (strcmp(palabra_res, "@fecha") == 0) strcpy(tda->fecha, valor);
							else if (strcmp(palabra_res, "@version") == 0) strcpy(tda->version, valor);
							else if (strcmp(palabra_res, "@param") == 0) strcpy(tda->param, valor);
							else if (strcmp(palabra_res, "@devuelve") == 0) strcpy(tda->devuelve, valor);
							else if (strcmp(palabra_res, "@pre") == 0) strcpy(tda->pre, valor);
							else if (strcmp(palabra_res, "@pos") == 0) strcpy(tda->pos, valor);
							}
						}
					}
				/* CONSTRUIR HTML */
				if (generarContenidoHTML(arch_HTML, arch_salida, tda) == 0) {
					if (generarFinHTML(arch_HTML, arch_salida) != 0)
						return RES_ERROR;
				}
				else return RES_ERROR;
				}
			}
	fclose(archivo);
	return (0);
}
