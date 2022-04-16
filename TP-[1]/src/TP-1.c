/*
 * Alumno: Facundo Del Canto
 * Division: 1F
 *
 * TP_LABORATORIO-1
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "menu.h"
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);

	int opcionIngresada;
	int banderaKmIngresado = 0;
	int banderaPrecioIngresado =0;
	int banderaAA =0;
	int banderaLatam=0;
	int banderaCalculosRealizados =0;
	int opcionSubMenu;
	float precioAerolineasA, precioLatam, kmIngresado, precioDebitoAA, precioDebitoLatam,
	precioCreditoAA, precioCreditoLatam, precioBTCAA, precioBTCLatam, precioUnitarioAA, precioUnitarioLatam, diferenciaPrecios;


	char salir;

	do{

		opcionIngresada=MenuOpciones();

		switch(opcionIngresada)
		{
		case 1:
			kmIngresado = IngresoYValidacionKm();
			banderaKmIngresado = 1;
		break;

		case 2:


				opcionSubMenu = SubMenuVuelos(precioAerolineasA , precioLatam);
				if(opcionSubMenu==1){
					precioAerolineasA = IngresarPrecio(opcionSubMenu);
					banderaAA= 1;

				} else{
					precioLatam = IngresarPrecio(opcionSubMenu);
					banderaLatam=1;
				}

				banderaPrecioIngresado = 1;



		break;

		case 3:

			if(banderaAA == 0 && banderaLatam == 1)
			{
				printf("ERROR!!! Falta ingresar precio de Aerolineas Argentinas\n\n");
			}
			else{
				if(banderaAA == 1 && banderaLatam == 0)
				{
					printf("ERROR!!! Falta ingresar precio de Latam\n\n");
				}
			}
			if (banderaKmIngresado == 1 && banderaPrecioIngresado == 1 && banderaAA == 1 && banderaLatam ==1){

				printf("CALCULANDO COSTOS CON DESCUENTO E INTERESES... \n\n");
				printf("ESPERE...\n");
				printf("... DESCUENTOS E INTERESES REALIZADOS CON EXITO...\n\n");

				precioDebitoAA = PagoDebito(precioAerolineasA);
				precioDebitoLatam = PagoDebito(precioLatam);
				precioCreditoAA = PagoCredito(precioAerolineasA);
				precioCreditoLatam = PagoCredito(precioLatam);
				precioBTCAA = PagoBTC(precioAerolineasA);
				precioBTCLatam = PagoBTC(precioLatam);
				precioUnitarioAA = CalculoPrecioUnitario(kmIngresado, precioAerolineasA);
				precioUnitarioLatam = CalculoPrecioUnitario(kmIngresado, precioLatam);
				diferenciaPrecios = CalcularDiferencia(precioAerolineasA, precioLatam);

				banderaCalculosRealizados = 1;

			} else{
					if(banderaKmIngresado == 1 && banderaPrecioIngresado == 0)
					{
						printf("ERROR!!! debe ingresar los precios de vuelos para calcular costos\n\n");
					}
					else{
						if(banderaKmIngresado == 0 && banderaPrecioIngresado ==1){

							printf("ERROR!!! debe ingresar los kilometros del vuelo para calcular costos\n\n");
						} else{
							if(banderaKmIngresado == 0 && banderaPrecioIngresado == 0)
							{
							printf("ERROR!!! no ingreso ningun dato para calcular, vuelva al menu principal...\n\n");
							}
						}
					}
			}

		break;

		case 4:
			if(banderaCalculosRealizados == 1){
			MostrarCalculos(precioAerolineasA, precioLatam, kmIngresado, precioDebitoAA, precioDebitoLatam,
	precioCreditoAA, precioCreditoLatam, precioBTCAA, precioBTCLatam, precioUnitarioAA, precioUnitarioLatam, diferenciaPrecios);
			} else {
				printf("No se realizaron los calculos para informar\n\n");
			}
		break;

		case 5:
			precioDebitoAA = PagoDebito(162965);
			precioDebitoLatam = PagoDebito(159339);
			precioCreditoAA = PagoCredito(162965);
			precioCreditoLatam = PagoCredito(159339);
			precioBTCAA = PagoBTC(162965);
			precioBTCLatam = PagoBTC(159339);
			precioUnitarioAA = CalculoPrecioUnitario(7090, 162965);
			precioUnitarioLatam = CalculoPrecioUnitario(7090, 159339 );
			diferenciaPrecios = CalcularDiferencia(162965, 159339 );
			MostrarCalculos(162965, 159339, 7090, precioDebitoAA, precioDebitoLatam,
	                       precioCreditoAA, precioCreditoLatam, precioBTCAA, precioBTCLatam,
						   precioUnitarioAA, precioUnitarioLatam, diferenciaPrecios);
		break;

		case 6:
			salir = 's';
			printf("MUCHAS GRACIAS POR UTILIZAR NUESTRO SERVICIO, VUELVA PRONTO!!\n\n");
		break;

		}

		system("pause");

	}while (salir!='s');

	return EXIT_SUCCESS;
}
