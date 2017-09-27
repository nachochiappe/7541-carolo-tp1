/*
 * DocConstruirIndice.c
 *
 *  Created on: Sep 25, 2017
 *      Author: fernando
 */
#define MAX_LINEA 50
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "DocConstruirIndice.h"
#include "tp1.h"

int DocConstruirIndice (TDA_Doc* tda, char* arch_indice) {
	FILE *archivoIndice = fopen(arch_indice,"w");
	char	documento[MAX_LINEA];
	/*
	 * ENCABEZADO HTML
	 */
	fputs("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n", archivoIndice);
	fputs("<head>\n", archivoIndice);
	fputs("\t<META http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\">\n", archivoIndice);
	fputs("</head>\n", archivoIndice);
	/*
	 * CUERPO HTML
	 */
	fputs("<body>\n", archivoIndice);
	fputs("\t<div>\n", archivoIndice);
	fputs("\t\t<div>\n", archivoIndice);
	/*
	 * TITULO HTML
	 */
	fputs("<h1>&Iacute;ndice</h1>\n", archivoIndice);
	fputs("<hl />\n", archivoIndice);
	/*
	 * HYPERVINCULOS HTML
	 */
	fputs("<ul>\n", archivoIndice);

	/*
	 * GENERO "documento" para usarlo en la linea de cada hypervinculo del indice
	 */
	unsigned char longitud = strlen(arch_indice) - strlen(".idx.html");
	strncpy(documento, arch_indice, longitud);
	documento[longitud] = '\0';
	strcat(documento, ".html");
	/*
	 * genero cada linea
	 */
	for (unsigned int i = 0; i < tda->cant_bloques; i++) {
		fputs("\t\t\t<li><a href=\"", archivoIndice);
		fputs(documento, archivoIndice);
		fputs("#", archivoIndice);
		fputs((tda->bloque[i]).funcion, archivoIndice);
		fputs("\">", archivoIndice);
		fputs((tda->bloque[i]).funcion, archivoIndice);
		fputs("</a></li>", archivoIndice);
	}
	/*
	 * FIN DE ARCHIVO HTML
	 */
	fputs("</ul>", archivoIndice);
	fputs("\t</div>\n", archivoIndice);
	fputs("\t</div>\n", archivoIndice);
	fputs("</body>\n", archivoIndice);
	fputs("</html>", archivoIndice);
	fclose(archivoIndice);
	return (0);
}
