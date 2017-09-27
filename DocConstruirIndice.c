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
int DocConstruirIndice (TDA_Doc* tda, char* arch_indice) {
	FILE *archivoIndice = fopen(arch_indice,"w");
	char	documento[MAX_LINEA],
			lineaIndice[MAX_LINEA];
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
	strncpy(documento, arch_indice,(strlen(arch_indice)-strlen(".idx.html\0")));
	strcat(documento, ".html");
	/*
	 * genero cada linea
	 */
	for(int bloqueActual=0; bloqueActual < tda->cant_bloques;bloqueActual++) {
		strcpy(lineaIndice,"<li><a href=\"");
		strcat(lineaIndice,documento);
		strcat(lineaIndice,"#");
		strcat(lineaIndice,tda->bloque[bloqueActual].funcion);
		strcat(lineaIndice,"\">");
		strcat(lineaIndice,tda->bloque[bloqueActual].funcion);
		strcat(lineaIndice,"</a></li>");
		fputs(lineaIndice,archivoIndice);
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
	return 0;
}
