/*
 * tp1.h
 *
 *  Created on: 7/9/2017
 *      Author: N67793
 */

#ifndef TP1_H_
#define TP1_H_

typedef struct t_parametro {
	char param_1[256];
	char param_2[256];
	char param_3[256];
	char param_4[256];
	char param_5[256];
	char param_6[256];
	char param_7[256];
	char param_8[256];
	char param_9[256];
	char param_10[256];
} t_parametro;

typedef struct TDA_Doc {
	char funcion[31];
	char descr[256];
	char autor[21];
	char fecha[11];
	char version[11];
	t_parametro param;
	char devuelve[256];
	char pre[256];
	char pos[256];
} TDA_Doc;

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
