/*
 * DocConstruirIndice.h
 *
 *  Created on: Sep 25, 2017
 *      Author: fernando
 */



#ifndef DOCCONSTRUIRINDICE_H_
#define DOCCONSTRUIRINDICE_H_

#include "tp1.h"

/*
 * Emite el índice elaborado a un archivo de salida. El índice debe contener un listado
 * ordenado alfabéticamente que indique claramente en qué archivo se encuentra.
 *
 * Precondiciones:
 * - Documentador creado e inicializado.
 *
 * Postcondiciones:
 * - El archivo de salida “arch_indice” contiene el índice construido en formato html.
 * - Devuelve RES_OK en caso de que todo haya funcionado correctamente.
 * - Devuelve RES_ERROR, o la constante que se defina pertinentemente según sea necesario
 * para el caso.
 *
 * Parametros:
 * - tda: el Documentador
 * - arch_indice: la ruta al archivo de salida donde deberá guardarse el índice construido
 */
int DocConstruirIndice (TDA_Doc* tda, char* arch_indice);

#endif /* DOCCONSTRUIRINDICE_H_ */
