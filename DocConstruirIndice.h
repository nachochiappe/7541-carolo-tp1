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
 * Emite el �ndice elaborado a un archivo de salida. El �ndice debe contener un listado
 * ordenado alfab�ticamente que indique claramente en qu� archivo se encuentra.
 *
 * Precondiciones:
 * - Documentador creado e inicializado.
 *
 * Postcondiciones:
 * - El archivo de salida �arch_indice� contiene el �ndice construido en formato html.
 * - Devuelve RES_OK en caso de que todo haya funcionado correctamente.
 * - Devuelve RES_ERROR, o la constante que se defina pertinentemente seg�n sea necesario
 * para el caso.
 *
 * Parametros:
 * - tda: el Documentador
 * - arch_indice: la ruta al archivo de salida donde deber� guardarse el �ndice construido
 */
int DocConstruirIndice (TDA_Doc* tda, char* arch_indice);

#endif /* DOCCONSTRUIRINDICE_H_ */
