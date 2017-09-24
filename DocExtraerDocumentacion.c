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
	char autor[50];
	char fecha[15];
	char version[15];
	char param_nombre[50];
	char param_valor[255];
	char devuelve[255];
	char pre[255];
	char pos[255];
} TDA_Doc;

int generarCabeceraHTML (FILE *arch_HTML, char *arch_salida) {
	arch_HTML = fopen(arch_salida, "a");
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
	arch_HTML = fopen(arch_salida, "a");

	fputs("\t\t<div>\n", arch_HTML);

	fputs("\t\t\t<h1>Titulo</h1>\n", arch_HTML);

	fputs("\t\t\t<h2>Subtitulo</h2>\n", arch_HTML);

	fputs("\t\t\t<h3>Funci&oacute;n: <a name=\"", arch_HTML);
	fputs(tda->funcion, arch_HTML);
	fputs("\">", arch_HTML);
	fputs(tda->funcion, arch_HTML);
	fputs("</a></h3>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Descripci&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->descr, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Autor</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->autor, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Fecha</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->fecha, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Version</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->version, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Par&aacute;metro: ", arch_HTML);
	fputs(tda->param_nombre, arch_HTML);
	fputs("</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->param_valor, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Retorno</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->devuelve, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Pre-Condici&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->pre, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t\t<dl>\n\t\t\t\t<dt>Post-Condici&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
	fputs(tda->pos, arch_HTML);
	fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

	fputs("\t\t</div>\n", arch_HTML);
	fclose(arch_HTML);
	return (0);
}

int generarFinHTML (FILE *arch_HTML, char *arch_salida) {
	arch_HTML = fopen(arch_salida, "a");
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
	arch_HTML = fopen(arch_salida, "w");
	if (generarCabeceraHTML(arch_HTML, arch_salida) != 0) return RES_ERROR;
	else
	if (!archivo) return (-1);
		else {
			while (fgets(linea, sizeof(linea), archivo)) {
				if (strncmp(linea, "/*", 2) == 0) {
					/* INICIO COMENTARIO */
					while (fgets(linea, sizeof(linea), archivo)) {
						if ((strncmp(linea, "*/", 2) == 0) || (strncmp(linea, " */", 3) == 0)) {
							/* FIN COMENTARIO */
							/* CONSTRUIR HTML */
							if (generarContenidoHTML(arch_HTML, arch_salida, tda) == 0) {
								if (generarFinHTML(arch_HTML, arch_salida) != 0)
									return RES_ERROR;
							}
							else return RES_ERROR;
							break;
						}
						else if (strncmp(linea, "@", 1) == 0) {
							palabra_res = strtok(linea, " ");
							valor = strtok(NULL, "\0");
							if (strcmp(palabra_res, "@funcion") == 0) strcpy(tda->funcion, valor);
							else if (strcmp(palabra_res, "@descr") == 0) strcpy(tda->descr, valor);
							else if (strcmp(palabra_res, "@autor") == 0) strcpy(tda->autor, valor);
							else if (strcmp(palabra_res, "@fecha") == 0) strcpy(tda->fecha, valor);
							else if (strcmp(palabra_res, "@version") == 0) strcpy(tda->version, valor);
							//else if (strcmp(palabra_res, "@param") == 0)  strcpy(tda->param_nombre, valor);
							else if (strcmp(palabra_res, "@param") == 0) {
								valor = strtok(valor, " ");
								strcpy(tda->param_nombre, valor);
								valor = strtok(NULL, "\0");
								strcpy(tda->param_valor, valor);
							}
							else if (strcmp(palabra_res, "@return") == 0) strcpy(tda->devuelve, valor);
							else if (strcmp(palabra_res, "@pre") == 0) strcpy(tda->pre, valor);
							else if (strcmp(palabra_res, "@pos") == 0) strcpy(tda->pos, valor);
							}
						}
					}
				}
			}
	fclose(archivo);
	return (0);
}
