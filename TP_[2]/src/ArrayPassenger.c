

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#include "validaciones.h"
#include "menu.h"


int BuscarEspacioLibre(ePassenger unPasajero[], int CANT){

	int i;
	int indexLibre=-1;

	for(i=0;i<CANT;i++){

		if(unPasajero[i].isEmpty==LIBRE){

			indexLibre=i;
			break;
		}

	}

	return indexLibre;
}
int InitPassengers(ePassenger* unPasajero, int CANT) {

	int retorno =-1;

	int i;
	for( i=0; i<CANT; i++ ){
		if(unPasajero != NULL){

			unPasajero[i].isEmpty = LIBRE;

							retorno=0;
		}


			}

	return retorno;
}
void pedirDatos(ePassenger unPasajero[], eTypePassenger typePassenger[],eStatusFlight statusFlight[], int CANT){

	char name[MAXCHAR];
	char lastname[MAXCHAR];
	int price;
	char flyCode[MAXCHAR];
	int type;
	int status;
	int id;
	int i;
	int indexLibre;

	indexLibre = BuscarEspacioLibre(unPasajero,CANT);
	for(i=0;i<CANT;i++){
		if(indexLibre!=-1){

			id=ObtenerId();
			pedirCadena("Ingrese nombre del pasajero\n", "Error, caracter invalido\n", name, MAXCHAR);
			pedirCadena("Ingrese apellido del pasajero\n", "Error, caracter invalido\n", lastname, MAXCHAR);
			utn_getNumero(&price, "Ingrese el precio del vuelo:\n", "Error, numero invalido\n", 1,10000,CANT);
			pedirCadena("Ingrese el codigo del vuelo\n", "Error, caracter invalido\n", flyCode, MAXCHAR);
			ListTypePassenger(typePassenger, CANT);
			utn_getNumero(&type, "Ingrese el tipo de pasajero:\n", "Error, tipo incorrecto\n", 1,3,CANT);
			ListStatusFlight(statusFlight, CANT);
			utn_getNumero(&status, "Ingrese el estado del vuelo:\n", "Error, tipo incorrecto\n", 4,6,CANT);

			AddPassenger(unPasajero, CANT,id, name, lastname, price,flyCode,type,status);
			break;
		}



	}





}
void InformarPasajero(ePassenger unPasajero[], eTypePassenger typePassenger[],eStatusFlight statusFlight[], int CANT){
	int i;
	int j;
	int f;

	printf("\t| ID |    NOMBRE   |        APELLIDO  |  PRECIO | CODIGO VUELO   |   TIPO DE PASAJERO   | ESTADO DE VUEL  |\n");

	for(i=0;i<CANT;i++){
		printf("\t+---------------------------------------------------------------------------------------------------------+\n");

		if(unPasajero[i].isEmpty==OCUPADO)
			for(j=0;j<CANT;j++){

				if(unPasajero[i].idTypePassenger == typePassenger[j].id){
					for(f=0;f<CANT;f++){

						if(unPasajero[i].idStatusFlight == statusFlight[f].id){

							printf("%13d\t%10s\t%10s\t$%-5.2f\t%-5s\t%20s\t%10s\t\n", unPasajero[i].id,
																unPasajero[i].name, unPasajero[i].lastname,
																unPasajero[i].price, unPasajero[i].flycode, typePassenger[j].descripcion, statusFlight[f].descripcion);
						}
					}


				}
			}


	}

}
int RemovePassengers(ePassenger* unPasajero, eTypePassenger typePassenger[],eStatusFlight statusFlight[], int CANT){

	int retorno =-1;
	int idAux;
	int i;

	printf("Ingrese numero de ID del pasajero a eliminar\n\n");
	InformarPasajero(unPasajero, typePassenger, statusFlight, CANT);
	scanf("%d", &idAux);

	for(i=0;i<CANT;i++){

		if(idAux == unPasajero[i].id && unPasajero[i].isEmpty == OCUPADO){

			unPasajero[i].isEmpty = -1;
			retorno = 0;
			printf("Pasajero eliminado correcCANTente\n\n");

		}


	}


	return retorno;
}
int AddPassenger (ePassenger* unPasajero, int CANT, int id, char name[],char lastname[],float price, char flycode[],int typePassenger, int statusFlight){

	int estado = -1;
	int i;

		if(unPasajero!=NULL && CANT > 0){

			for (i  = 0; i < CANT ; i++){
						if (unPasajero[i].isEmpty  == LIBRE){
							unPasajero[i].isEmpty = OCUPADO;
							unPasajero[i].id=id;
							strcpy(unPasajero[i].name, name);
							strcpy(unPasajero[i].lastname, lastname);
							unPasajero[i].price = price;
							strcpy(unPasajero[i].flycode, flycode);
							unPasajero[i].idTypePassenger = typePassenger;
							unPasajero[i].idStatusFlight = statusFlight;
							estado = 0;
							break;
						}
					}
		}


	return estado;
}
void ListTypePassenger(eTypePassenger typePassenger[], int CANT){

	int i;

	for(i=0;i<3;i++){
		if(typePassenger[i].isEmpty == OCUPADO){

			printf("ID: %d\t\t Tipo de pasajero: %s\n", typePassenger[i].id, typePassenger[i].descripcion);
		}
	}


}
void HardcodearPasajeros(ePassenger unPasajero[], int CANT){

		ePassenger pasajeros[5] =

			{
						{912,"FACUNDO","DELCANTO",5000, "HSGFJ",3,4,1},
						{913,"JUANFER","QUINTERO",6000, "FHDJW",2,4,1},
						{914,"NACHO","FERNANDEZ",8200, "OEIRU",1,5,1},
						{915,"JONATHAN","MAIDANA",9999, "SJFUT",2,6,1},
						{916,"GONZALO","MARTINEZ",3200, "AAJWI",2,4,1}

			};




				for(int i=0;i<CANT;i++){
					if(unPasajero[i].isEmpty == LIBRE){
						unPasajero[i] = pasajeros[i];
					}

						}





}
int FindPassengerById(ePassenger* unPasajero, eTypePassenger* typePassenger,eStatusFlight* statusFlight, int CANT){

	int retorno = -1;
	int i;
	int idAux;


			if(unPasajero!=NULL && CANT > 0){
				printf("Ingrese ID de pasajero\n\n");
				InformarPasajero(unPasajero, typePassenger,statusFlight,CANT);
				scanf("%d", &idAux);
				for(i=0;i<CANT;i++){
					if(idAux == unPasajero[i].id){

						retorno = idAux;
					}



				}
			}




	return retorno;
}
void ListStatusFlight(eStatusFlight statusFlight[], int CANT){

	int i;

	for(i=0;i<3;i++){
		if(statusFlight[i].isEmpty == OCUPADO){

			printf("ID: %d\t Estado del vuelo: %s\n", statusFlight[i].id, statusFlight[i].descripcion);
		}
	}


}
int PromedioPassengers(ePassenger* unPasajero, int CANT){
	int retorno = -1;
	int i;
	float acum= 0;
	int cont = 0;
	float prom;
	int contProm= 0;

	if(unPasajero != NULL && CANT > 0){
		retorno = 0;
		for (i = 0 ; i < CANT; i++){
			if(unPasajero[i].isEmpty == OCUPADO){
				acum += unPasajero[i].price;
				cont++;
			}
		}
		prom = acum / cont;
	}
	for (i = 0; i < CANT ; i ++){
		if(unPasajero[i].isEmpty == OCUPADO && unPasajero[i].price > prom){
			contProm ++;
		}
	}
	printf("Total de valor de viajes ; %.2f\n",acum);
	printf("Promedio de los precios de viajes; %.2f\n",prom);
	printf("Cantidad de viajes que superan el precio promedio: %d\n",contProm);

	return retorno;

}
int SortPassengerFlyCode(ePassenger unPasajero[], int CANT) {



    ePassenger auxPass;
    int retorno=-1;

    if(unPasajero != NULL && CANT > 0)
    {
        for(int i=0; i < CANT - 1; i++)
        {
            for(int j=i+1; j < CANT; j++)
            {
                if(stricmp(unPasajero[i].flycode, unPasajero[j].flycode) > 0 || stricmp(unPasajero[i].flycode, unPasajero[j].flycode) == 0)
                {
                    auxPass = unPasajero[i];
                    unPasajero[i] = unPasajero[j];
                    unPasajero[j] = auxPass;
                    retorno= 0;
                }
            }
        }
    }
    return retorno;
}
int SortPassenger(ePassenger unPasajero[], int CANT)
{
    int retorno = -1;
    ePassenger auxPassenger;

    if(unPasajero != NULL && CANT > 0)
    {
        for(int i=0; i < CANT - 1; i++)
        {
            for(int j= i+1; j < CANT; j++)
            {
                if(strcmp(unPasajero[i].lastname, unPasajero[j].lastname) > 0 ||
                (strcmp(unPasajero[i].lastname, unPasajero[i].lastname) == 0
                && unPasajero[i].idTypePassenger > unPasajero[j].idTypePassenger))
                {
                	auxPassenger = unPasajero[i];
                	unPasajero[i] = unPasajero[j];
                	unPasajero[j] = auxPassenger;
                }else
                	if(strcmp(unPasajero[i].lastname, unPasajero[j].lastname) < 0 ||
                            (strcmp(unPasajero[i].lastname, unPasajero[i].lastname) == 0
                            && unPasajero[i].idTypePassenger < unPasajero[j].idTypePassenger))
                	{
                    	auxPassenger = unPasajero[i];
                    	unPasajero[i] = unPasajero[j];
                    	unPasajero[j] = auxPassenger;
                	}
            }
        }
        retorno = 0;
    }
    return retorno;
}
