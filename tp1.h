/*
 * tp1.h
 *
 *  Created on: 7/9/2017
 *      Author: N67793
 */

#ifndef TP1_H_
#define TP1_H_

/*
 * Crea el documentador inicializando su estructura con los datos necesarios.
 *
 * Precondiciones:
 * - Documentador no creado
 *
 * Postcondiciones:
 * - Devuelve RES_OK si pudo crear el documentador.
 * - Devuelve RES_ERROR en otro caso, o la constante que se defina pertinentemente.
 *
 * Parametros:
 * - tda: el Documentador a crear
 */
int DocCrear (TDA_Doc* tda);

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

/*
 * Destruye el documentador vaciando previamente su estructura y liberando todos los recursos
 * en uso.
 *
 * Precondiciones:
 * - Documentador creado e inicializado
 *
 * Postcondiciones:
 * - Devuelve RES_OK si pudo destruir.
 * - Devuelve RES_ERROR en otro caso, o la constante que se defina pertinentemente.
 *
 * Parametros:
 * - tda: el Documentador
 */
int DocDestruir (TDA_Doc* tda);

#endif /* TP1_H_ */
