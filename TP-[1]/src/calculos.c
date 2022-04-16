
/*
 * Alumno: Facundo Del Canto
 * Division: 1F
 *
 * TP_LABORATORIO-1
 *
 *
 * */

#include "calculos.h"

/// RECIBE EL PRECIO INGRESADO, Y DEVUELVE EL PRECIO CON DEBITO MEDIANTE UN CALCULO.
float PagoDebito(float precioIngresado){

	float precioDebito;

	precioDebito=precioIngresado-(precioIngresado*0.10);

	return precioDebito;
}
/// RECIBE EL PRECIO INGRESADO, Y DEVUELVE EL PRECIO CON CREDITOMEDIANTE UN CALCULO.
float PagoCredito(float precioIngresado){

	float precioCredito;

	precioCredito= precioIngresado+(precioIngresado*0.25);

	return precioCredito;
}
/// RECIBE EL PRECIO INGRESADO, Y DEVUELVE EL PRECIO CON BITCOIN MEDIANTE UN CALCULO.
float PagoBTC(float precioIngresado){

	float precioBTC;

	precioBTC = precioIngresado/4674936.27;

	return precioBTC;
}
/// RECIBE EL PRECIO INGRESADO Y LOS KILOMETROS INGRESADOS, Y DEVUELVE EL PRECIO UNITARIO MEDIANTE UN CALCULO.
float CalculoPrecioUnitario(float kmIngresado, float precioIngresado){


	float precioUnitario;

	precioUnitario = precioIngresado/kmIngresado;

	return precioUnitario;
}
///RECIBE DOS PRECIOS, Y DEVUELVE LA DIFERENCIA ENTRE ELLOS MEDIANTE UN CALCULO.
float CalcularDiferencia(float precioAerolineasA, float precioLatam){

	float diferencia;

	if(precioAerolineasA > precioLatam){
		diferencia = precioAerolineasA - precioLatam;
	}else{
		diferencia = precioLatam - precioAerolineasA;
	}

	return diferencia;
}
