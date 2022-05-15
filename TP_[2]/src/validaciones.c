

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "menu.h"
#include "validaciones.h"

int utn_getNumero( int * pResultado, char * mensaje, char * mensajeError, int minimo, int maximo, int reintentos) {

	int ret;
	int num;
		while (reintentos>0)	{
				printf(mensaje);
					if (scanf("%d",&num)==1)
						{


						if (num<=maximo && num>=minimo)
			break ;
			}

			fflush(stdin);
			reintentos--;
			printf(mensajeError);
			}

			if (reintentos==0)	{
			ret=-1;

		}
			else
			{
			ret=0;
			*pResultado = num;
			}
			return ret;
			}
void pedirCadena (char mensaje1[],char mensaje2[],char stringIngresado [], int TAM)
{
	int x;
	printf("%s",mensaje1);
	fflush(stdin);
	scanf("%s",stringIngresado);
	x = validarCadena(stringIngresado,51);
	while(x == 1){
		printf("%s",mensaje2);
		fflush(stdin);
		scanf("%s",stringIngresado);
		x = validarCadena(stringIngresado,51);
	}
}
int validarCadena(char cadena[],int tam)
{
	int retorno;
	int i;
	for( i = 0; i < strlen(cadena); i++){
		cadena [i] = toupper(cadena[i]);
		if (!isalpha(cadena[i]) != 0 && cadena[i]!=' '){
			retorno = 1;
			break;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
