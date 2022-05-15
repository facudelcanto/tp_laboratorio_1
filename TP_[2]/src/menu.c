#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "validaciones.h"

int MainMenu(){

	int opcionElegida;

			printf("***MENU PRINCIPAL***\n");
			printf("-----------------------\n\n");
			printf("1. Altas");
			printf("\n2. Modificar");
			printf("\n3. Bajas");
			printf("\n4. Informar");
			printf("\n5. Carga forzada de datos");
			printf("\n6. Salir");
			printf("\nOpcion: ");
			scanf("%d", &opcionElegida);


	return opcionElegida;
}
int MenuModificar(ePassenger unPasajero[], eTypePassenger typePassenger[],eStatusFlight statusFlight[], int CANT){

	int opcionElegida;
	int idAux;
	int i;
	int retorno;
	char newname[MAXCHAR];
	char newlastname[MAXCHAR];
	int newprice;
	int newtype;
	char newflycode[MAXCHAR];

		printf("\n***MENU MODIFICAR***\n");
		printf("-----------------------\n\n");
		idAux = FindPassengerById(unPasajero, typePassenger,statusFlight,CANT);


	for(i=0;i<CANT;i++){

		if(idAux == unPasajero[i].id){

			printf("¿Que desea modificar?\n");
			printf("1. Nombre\n");
			printf("2. Apellido\n");
			printf("3. Precio\n");
			printf("4. Tipo de pasajero\n");
			printf("5. Codigo de vuelo\n");
			scanf("%d", &opcionElegida);

			switch(opcionElegida){

			case 1:
				pedirCadena("Ingrese nuevo nombre de pasajero", "Error, caracter invalido", newname, CANT );
				strcpy(unPasajero[i].name, newname);
				printf("Nombre modificado con exito\n");

			break;

			case 2:
				pedirCadena("Ingrese nuevo apellido de pasajero", "Error, caracter invalido", newlastname, CANT );
				strcpy(unPasajero[i].lastname, newlastname);
				printf("Apellido modificado con exito\n");
			break;

			case 3:
				utn_getNumero(&newprice, "Ingrese el nuevo precio del vuelo:\n", "Error, numero invalido\n", 1,10000,CANT);
				unPasajero[i].price = newprice;
				printf("Precio modificado con exito\n");
			break;

			case 4:
				ListTypePassenger(typePassenger, CANT);
				utn_getNumero(&newtype, "Ingrese el nuevo tipo de pasajero:\n", "Error, numero invalido\n", 1,3,CANT);
				unPasajero[i].idTypePassenger = newtype;
				printf("Tipo de pasajero modificado con exito\n");

			break;

			case 5:
				pedirCadena("Ingrese nuevo codigo de vuelo", "Error, caracter invalido", newflycode, CANT );
				strcpy(unPasajero[i].flycode, newflycode);
				printf("Codigo de vuelo modificado con exito\n");

			break;

			}

			retorno =1;
		}


	}

	return retorno;
}
int MenuListar(ePassenger unPasajero[], int CANT){

	int retorno;
	int opcionElegida;

	printf("Seleccione la opcion que desee listar\n");
	printf("1. Listar alfabeticamente por apellido y tipo de pasajero\n");
	printf("2. Total y promedio de los precios de los pasajes y pasajeros que superan el promedio\n");
	printf("3. Listar pasajeros por codigo de vuelo y estados de vuelo 'ACTIVO'\n");
	scanf("%d", &opcionElegida);

	switch (opcionElegida){

	case 1:
		SortPassenger(unPasajero,CANT);
		break;

	case 2:
		PromedioPassengers(unPasajero, CANT);
		break;

	case 3:
		SortPassengerFlyCode(unPasajero, CANT);
		break;




	}
	return retorno;
}


