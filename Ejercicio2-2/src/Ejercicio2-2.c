/*
 ============================================================================
 Name        : 	Ejercicio2-2.c
 Author      :	Dayher Marchan
 Version     : 	1.0
 Description : 	Ingresar 10 números enteros, distintos de cero. Mostrar:
				Cantidad de pares e impares.
				El menor número ingresado.
				De los pares el mayor número ingresado.
				Suma de los positivos.
				Producto de los negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 10

int main(void) {

	int numero, contador=0, contadorPar=0, contadorImpar=0,
		menor, mayor, sumaPositivos=0, productoNegativos=1;


	for(contador=0; contador<CANTIDAD;contador++){
		printf("Ingrese un número distinto de cero: ");
		scanf("%i",&numero);

		while(numero==0){
			printf("Ingrese un número DISTINTO de cero (0): ");
			scanf("%i",&numero);
		}

		if (numero%2){
			contadorImpar++;
		} else {
			if(contadorPar){
				if(numero>mayor) mayor=numero;
			} else {
				mayor=numero;
			}
			contadorPar++;
		}

		if (contador){
			if (numero<menor) menor=numero;
		} else {
			menor=numero;
		}

		if (numero>0){
			sumaPositivos+=numero;
		} else {
			productoNegativos*=numero;
		}
	}
	printf("\nCantidad de pares: %d e impares: %d\n",contadorPar,contadorImpar);
	printf("Menor número ingresado: %d\nDe los pares el mayor número ingresado: %d\n", menor, mayor);
	printf("Suma de positivos: %d Producto de negativos: %d\n", sumaPositivos, productoNegativos);
	return EXIT_SUCCESS;
}
