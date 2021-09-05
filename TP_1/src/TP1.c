/*
 ============================================================================
 Name        : TP1.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int main(void) {
	double primero, segundo;
	puts("Ingresar 1er operando A=");
	scanf("%lf",&primero);
	puts("\nIngresar 2do operando B=");
	scanf("%lf",&segundo);
	printf("\nEl resultado de A+B es: %lf",sumar(primero,segundo));
	printf("\nEl resultado de A-B es: %lf",restar(primero,segundo));
	printf("\nEl resultado de A*B es: %lf",multiplicar(primero,segundo));
	printf("\nEl resultado de A/B es: %lf",dividir(primero,segundo));
	printf("\nEl factorial de %Ld y ",factorial((unsigned)primero));
	printf("El factorial de %u \n",(unsigned)segundo);
	return EXIT_SUCCESS;
}
