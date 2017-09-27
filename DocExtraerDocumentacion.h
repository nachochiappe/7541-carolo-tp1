/*
 * DocExtraerDocumentacion.h
 */

#ifndef DOCEXTRAERDOCUMENTACION_H_
#define DOCEXTRAERDOCUMENTACION_H_

int generarHTML (char *arch_salida, TDA_Doc *tda);
/*
 * Extrae la documentaci�n del archivo de entrada, concaten�ndola al archivo de salida.
 * No sobreescribe el archivo de salida.
 *
 * Precondiciones:
 * - Documentador creado e inicializado
 *
 * Postcondiciones:
 * - Devuelve RES_OK si pudo extraer la informaci�n a documentar del archivo_entrada,
 * escribi�ndola en el archivo_salida.
 * - Devuelve RES_ERROR en otro caso, o la constante que se defina pertinentemente.
 *
 * Parametros:
 * - tda: el Documentador a utilizar para extrae la informaci�n que se debe documentar
 * - arch_entrada: ruta al archivo de entrada del cual se desea extraer la documentaci�n.
 * - arch_salida: ruta al archivo de salida, en el cual se desea escribir la documentaci�n
 * obtenida del archivo de entrada, seg�n el formato especificado.
 */
int DocExtraerDocumentacion (TDA_Doc* tda, char* arch_entrada, char* arch_salida);

#endif /* DOCEXTRAERDOCUMENTACION_H_ */
