



#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXCHAR 51
#define LIBRE 0
#define OCUPADO 1


typedef struct{

	int id;
	char name[MAXCHAR];
	char lastname[MAXCHAR];
	float price;
	char flycode[10];
	int idTypePassenger;
	int idStatusFlight;
	int isEmpty;



}ePassenger;

typedef struct{

	int id;
	char descripcion[MAXCHAR];
	int isEmpty;

}eTypePassenger;

typedef struct{

	int id;
	char descripcion[MAXCHAR];
	int isEmpty;

}eStatusFlight;

static int ObtenerId();
static int ObtenerId(){
	static int idIncremental = 917;
	return idIncremental++;
}
void pedirDatos(ePassenger[],eTypePassenger[],eStatusFlight[], int);
int BuscarEspacioLibre(ePassenger[],int);
void ListTypePassenger(eTypePassenger[], int);
int InitPassengers(ePassenger* unPasajero, int);
void InformarPasajero(ePassenger[],eTypePassenger[],eStatusFlight[], int);
int RemovePassengers(ePassenger* unPasajero, eTypePassenger[],eStatusFlight[], int);
int AddPassenger (ePassenger* unPasajero, int CANT, int id, char name[],char lastname[],float price, char flycode[],int typePassenger, int statusFlight);
void HardcodearPasajeros (ePassenger unPasajero[], int);
int FindPassengerById(ePassenger* unPasajero, eTypePassenger* typePassenger, eStatusFlight* statusFlight, int);
void ListStatusFlight(eStatusFlight[], int);
int sortPassenger(ePassenger[], int CANT);
int PromedioPassengers(ePassenger* unPasajero, int CANT);
int SortPassengerFlyCode(ePassenger[], int CANT);
int SortPassenger(ePassenger[], int CANT);
#endif /* ARRAYPASSENGER_H_ */
