/*
 * DocCrear.h
 *
 *  Created on: 27 Sep 2017
 *      Author: Yoel
 */

#ifndef DOCCREAR_H_
#define DOCCREAR_H_

#include "tp1.h"

int ParametroCrear(t_parametro* p);
int BloqueCrear(t_bloque* b);
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

#endif /* DOCCREAR_H_ */
