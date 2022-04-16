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

/// NO RECIBE NINGUN DATO, MUESTRA EL MENU PRINCIPAL DE OPCIONES Y DEVUELVE LA OPCION ELEGIDA.
int MenuOpciones(){

	int opcionIngresada;

	    printf("1- Ingresar kilometros \n");
		printf("2- ingresar precio de vuelos \n");
		printf("3- Calcular todos los costos \n");
		printf("4- Informar Resultados \n");
		printf("5- Carga forzada de datos \n");
		printf("6- finalizar \n");
		printf("seleccione la opcion deseada: \n");
		scanf("%d", &opcionIngresada);


	return opcionIngresada;
}
/// NO RECIBE NINGUN DATO, MUESTRA EL SUBMENU DE AEROLINEAS Y DEVUELVE LA OPCION ELEGIDA.
int SubMenuVuelos(){

	int opcion;

	printf("Ingrese la opcion deseada\n");
	printf("1- Aerolineas Argentinas\n");
	printf("2- Latam\n");
	scanf("%d", &opcion);

	return opcion;

}
/// RECIBE LA OPCION ELEGIDA DEL SUBMENU Y DEVUELVE EL PRECIO INGRESADO A CADA AEROLINEA.
float IngresarPrecio(int opcionElegida){

	float precioIngresado;
		if(opcionElegida==1)
		{
			printf("Ingrese el precio de Aerolineas Argentina: \n");
			scanf("%f", &precioIngresado);

		} else{
			printf("Ingrese el precio de Latam: \n");
			scanf("%f", &precioIngresado);
		}

		return precioIngresado;
}
/// NO RECIBE NADA, DEVUELVE LA CANTIDAD DE KILOMETROS INGRESADOS, YA VALIDADOS MEDIANTE UNA CONDICION.
float IngresoYValidacionKm(){

	float kmIngresado;

	printf("Ingrese los Km deseados: \n");
	scanf("%f", &kmIngresado);
		if(kmIngresado <=0)
		{
			printf("Ingrese una cantidad de KMs validos\n");
			scanf("%f", &kmIngresado);
		}

		return kmIngresado;
}

/// RECIBE 12 DATOS DE DIFERENTES METODOS DE PAGO, Y SOLO MUESTRA RESULTADOS.
void MostrarCalculos(float precioAerolineasA, float precioLatam, float kmIngresado, float precioDebitoAA, float precioDebitoLatam,
	                 float precioCreditoAA, float precioCreditoLatam, float precioBTCAA, float precioBTCLatam,
	                 float precioUnitarioAA, float precioUnitarioLatam, float diferenciaPrecios){

	printf("Kms Ingresados: %.2f\n\n", kmIngresado);
	printf("Precio Aerolineas: $%.2f\n", precioAerolineasA);
	printf("a) Precio con tarjeta de debito: $%.2f\n", precioDebitoAA);
	printf("b) Precio con tarjeta de credito: $%.2f\n", precioCreditoAA);
	printf("c) Precio pagando con bitcoin: $%.5f\n", precioBTCAA);
	printf("d) Mostrar precio unitario: $%.2f\n\n", precioUnitarioAA);
	printf("Precio Latam: $%.2f\n", precioLatam);
	printf("a) Precio con tarjeta de debito: $%.2f\n", precioDebitoLatam);
	printf("b) Precio con tarjeta de credito: $%.2f\n", precioCreditoLatam);
	printf("c) Precio pagando con bitcoin: $%.5f\n", precioBTCLatam);
	printf("d) Mostrar precio unitario: $%.2f\n\n", precioUnitarioLatam);
	printf("La diferencia de precio es: $%.2f\n", diferenciaPrecios);

}
