/*
 * menu.h
 *
 *  Created on: 20 abr. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "validaciones.h"
#ifndef MENU_H_
#define MENU_H_

int MainMenu();
int MenuModificar(ePassenger[], eTypePassenger[],eStatusFlight[], int);
int MenuListar(ePassenger[], int CANT);
#endif /* MENU_H_ */
