/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define CANTIDAD 5

int main(void) {
    int numero, contador=0, acumulador=0;
    float promedio=0;

    for (contador=0; contador<CANTIDAD ; contador++) {
        printf("Ingrese un número: ");
        scanf("%i", &numero);
        acumulador += numero;
    }

    promedio = acumulador/CANTIDAD;

    printf("El promedio es : %.2f", promedio);
	return EXIT_SUCCESS;
}
