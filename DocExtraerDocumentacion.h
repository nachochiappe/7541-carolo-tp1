/*
 * DocExtraerDocumentacion.h
 */

#ifndef DOCEXTRAERDOCUMENTACION_H_
#define DOCEXTRAERDOCUMENTACION_H_

int generarHTML (char *arch_salida, TDA_Doc *tda);
/*
 * Extrae la documentación del archivo de entrada, concatenándola al archivo de salida.
 * No sobreescribe el archivo de salida.
 *
 * Precondiciones:
 * - Documentador creado e inicializado
 *
 * Postcondiciones:
 * - Devuelve RES_OK si pudo extraer la información a documentar del archivo_entrada,
 * escribiéndola en el archivo_salida.
 * - Devuelve RES_ERROR en otro caso, o la constante que se defina pertinentemente.
 *
 * Parametros:
 * - tda: el Documentador a utilizar para extrae la información que se debe documentar
 * - arch_entrada: ruta al archivo de entrada del cual se desea extraer la documentación.
 * - arch_salida: ruta al archivo de salida, en el cual se desea escribir la documentación
 * obtenida del archivo de entrada, según el formato especificado.
 */
int DocExtraerDocumentacion (TDA_Doc* tda, char* arch_entrada, char* arch_salida);

#endif /* DOCEXTRAERDOCUMENTACION_H_ */
