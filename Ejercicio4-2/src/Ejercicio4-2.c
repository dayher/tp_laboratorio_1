/*
 ============================================================================
 Name        : Ejercicio4-2.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "conversion.h"
#include "validacion.h"

int main(void) {

	unsigned short opcion;
	float temperatura=0, resultado;

	puts("Ingrese una opción:\n 1--------fahrenheitAcelsius\n 2--------celsiusAfahrenheit\n");
	scanf("%hu", &opcion);

	puts("ingrese temperatura");
	scanf("%f",&temperatura);

	if(opcion==1){
		if(validarFahrenheit(temperatura)){
			resultado = fahrenheitAcelsius(temperatura);
		} else {
			puts("Temperatura inválida\n");
		}
	} else if (opcion==2){
		if(validarCelsius(temperatura)){
			resultado = celsiusAfahrenheit(temperatura);
		} else {
			puts("Temperatura inválida\n");
		}
	}

	printf("resultado: %.2f grados",resultado);

	return EXIT_SUCCESS;
}
