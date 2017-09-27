/*
 * DocExtraerDocumentacion.c
 */

#include <stdio.h>
#include <string.h>

#include "tp1.h"

int generarHTML (char *arch_entrada, char *arch_salida, TDA_Doc *tda) {

	FILE* arch_HTML = fopen(arch_salida, "w");

	/* CABECERA */

	fputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n", arch_HTML);
	fputs("<html>\n", arch_HTML);
	fputs("<head>\n", arch_HTML);
	fputs("\t<META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n", arch_HTML);
	fputs("</head>\n", arch_HTML);
	fputs("<body>\n", arch_HTML);
	fputs("\t<div>\n", arch_HTML);
	fputs("\t\t<div>\n", arch_HTML);
	fputs("\t\t\t<h1>Documentador</h1>\n", arch_HTML);
	fputs("\t\t\t<h2>", arch_HTML);
	fputs(arch_entrada, arch_HTML);
	fputs("</h2>\n", arch_HTML);

	/* CONTENIDO */

	for (unsigned int i = 0; i < (tda->cant_bloques); i++) {

		fputs("\t\t\t<h3>Funci&oacute;n: <a name=\"", arch_HTML);
		fputs((tda->bloque[i]).funcion, arch_HTML);
		fputs("\">", arch_HTML);
		fputs((tda->bloque[i]).funcion, arch_HTML);
		fputs("</a></h3>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Descripci&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).descr, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Autor</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).autor, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Fecha</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).fecha, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Version</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).version, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		for (unsigned int j = 0; j < (tda->bloque[i]).cant_param; j++) {
			fputs("\t\t\t<dl>\n\t\t\t\t<dt>Par&aacute;metro: ", arch_HTML);
			fputs(((tda->bloque[i]).param[j]).param_nombre, arch_HTML);
			fputs("</dt>\n\t\t\t\t<dd>", arch_HTML);
			fputs(((tda->bloque[i]).param[j]).param_valor, arch_HTML);
			fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);
		}

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Retorno</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).devuelve, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Pre-Condici&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).pre, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t\t<dl>\n\t\t\t\t<dt>Post-Condici&oacute;n</dt>\n\t\t\t\t<dd>", arch_HTML);
		fputs((tda->bloque[i]).pos, arch_HTML);
		fputs("</dd>\n\t\t\t</dl>\n", arch_HTML);

		fputs("\t\t</div>\n", arch_HTML);
	}

	/* FINAL */

	fputs("\t</div>\n", arch_HTML);
	fputs("</body>\n", arch_HTML);
	fputs("</html>\n", arch_HTML);

	fclose(arch_HTML);
	return (0);
}

int DocExtraerDocumentacion (TDA_Doc *tda, char *arch_entrada, char *arch_salida) {
	FILE *archivo;
	char linea[255];
	char *palabra_res;
	char *valor;
	char tiene_tokens = 0;
	unsigned char i = 0;
	unsigned char j;
	archivo = fopen(arch_entrada, "r");
	if (!archivo) return (RES_ERROR);
		else {
			while (fgets(linea, sizeof(linea), archivo)) {
				if (strncmp(linea, "/*", 2) == 0) {
					/* INICIO COMENTARIO */
					j = 0;
					while (fgets(linea, sizeof(linea), archivo)) {
						if ((strncmp(linea, "*/", 2) == 0) || (strncmp(linea, " */", 3) == 0)) {
							/* FIN COMENTARIO */
							if (tiene_tokens == 1) {
								i++;
								tda->cant_bloques = i;
							}
							tiene_tokens = 0;
							break;
						}
						else if (strncmp(linea, "@", 1) == 0) {
							tiene_tokens = 1;
							palabra_res = strtok(linea, " ");
							valor = strtok(NULL, "\0");
							if (strcmp(palabra_res, "@funcion") == 0) strcpy((tda->bloque[i]).funcion, valor);
							else if (strcmp(palabra_res, "@descr") == 0) strcpy((tda->bloque[i]).descr, valor);
							else if (strcmp(palabra_res, "@autor") == 0) strcpy((tda->bloque[i]).autor, valor);
							else if (strcmp(palabra_res, "@fecha") == 0) strcpy((tda->bloque[i]).fecha, valor);
							else if (strcmp(palabra_res, "@version") == 0) strcpy((tda->bloque[i]).version, valor);
							else if (strcmp(palabra_res, "@param") == 0) {
								valor = strtok(valor, " ");
								strcpy(((tda->bloque[i]).param[j]).param_nombre, valor);
								valor = strtok(NULL, "\0");
								strcpy(((tda->bloque[i]).param[j]).param_valor, valor);
								j++;
								(tda->bloque[i]).cant_param = j;
							}
							else if (strcmp(palabra_res, "@return") == 0) strcpy((tda->bloque[i]).devuelve, valor);
							else if (strcmp(palabra_res, "@pre") == 0) strcpy((tda->bloque[i]).pre, valor);
							else if (strcmp(palabra_res, "@pos") == 0) strcpy((tda->bloque[i]).pos, valor);
						}
					}
				}
			}
			fclose(archivo);
		}
	if (generarHTML(arch_entrada, arch_salida, tda) == 0) {
		return (RES_OK);
	}
	else return (RES_ERROR);
}
