/*
 * DocExtraerDocumentacion.h
 */

#ifndef DOCEXTRAERDOCUMENTACION_H_
#define DOCEXTRAERDOCUMENTACION_H_

typedef struct TDA_Doc TDA_Doc;

int generarCabeceraHTML (FILE *arch_HTML, char *arch_salida);
int generarContenidoHTML (FILE *arch_HTML, char *arch_salida, TDA_Doc *tda);
int generarFinHTML (FILE *arch_HTML, char *arch_salida);
int DocExtraerDocumentacion(TDA_Doc *tda, char *arch_entrada, char *arch_salida);

#endif /* DOCEXTRAERDOCUMENTACION_H_ */
