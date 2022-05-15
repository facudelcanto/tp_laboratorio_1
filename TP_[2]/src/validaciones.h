/*
 * validaciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: Usuario
 */



#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos);
void pedirCadena (char mensaje1[],char mensaje2[],char stringIngresado [], int TAM);
int validarCadena(char cadena[],int tam);

#endif /* VALIDACIONES_H_ */
