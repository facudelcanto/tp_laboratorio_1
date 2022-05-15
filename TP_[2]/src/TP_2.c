

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "validaciones.h"

#define CANT 10

int main(void) {

	setbuf(stdout, NULL);

	ePassenger unPasajero[CANT];
	eTypePassenger typePassenger[3] = {{1,"TURISTA",1},
										{2,"EJECUTIVO",1},
										{3,"PREMIUM",1}};
	eStatusFlight statusFlight[3] = {{4,"ACTIVO",1},
									{5,"CANCELADO",1},
									{6,"DEMORADO",1}};


	int opcionMenu;
	int i;
	int cantidadDatos = 0;
	int banderaId = 1;
	int idBusqueda;
	int opcionMenuSecundario;
	int modificar;
	int remover;


	InitPassengers(unPasajero, CANT);



	do {

		opcionMenu = MainMenu();
		switch(opcionMenu){

					case 1:
						//AddPassengers(unPasajero,CANT);
						pedirDatos(unPasajero,typePassenger,statusFlight,CANT);
						cantidadDatos++;
					break;

					case 2:
						if(cantidadDatos>0){
								modificar = MenuModificar(unPasajero, typePassenger,statusFlight, CANT);
								if(modificar!=1){

									printf("No se encuentra pasajero ingresado, presione enter para volver al menu\n");
								}
								}else{
									printf("No hay pasajeros cargados\n");
								}
								system("pause");
					break;

					case 3:

						if(cantidadDatos>0){
						remover = RemovePassengers(unPasajero, typePassenger,statusFlight, CANT);
						if(remover !=0){

							printf("No se encuentra ID seleccionado\n");
						}
						}else{
								printf("No hay pasajeros cargados\n");
						}
						system("pause");

					break;

					case 4:
						if(cantidadDatos>0){

							MenuListar(unPasajero,CANT);
						}

					break;

					case 5:
						HardcodearPasajeros(unPasajero,CANT);
						cantidadDatos++;
					break;
			}

		system("pause");

	} while(opcionMenu!= 6);



return EXIT_SUCCESS;
}


