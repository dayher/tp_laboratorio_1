/*
 ============================================================================
 Name        : TP1.c
 Author      : Dayher Marchan
 Version     : 2.0
 Copyright   :
 Description : Calculadora basica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

#define ENTRADA1 1
#define ENTRADA2 2
#define CALCULAR 3
#define	INFORMAR 4
#define SALIR 5
#define MAX_MENU 6

void mostrarMenu(double primero, double segundo);
int getInt(char mensaje []);
double getDouble(char mensaje[]);
void mostrarResultados(	double primero, double segundo ,
						double suma, double resta, double producto, double cociente,
						unsigned long factorial1, unsigned long factorial2);

int main(void)
{
	double primero = 0, segundo = 0;
	double suma, resta, producto, cociente;
	unsigned long factorial1, factorial2;
	int entrada1=0, entrada2=0, calcular=0;
	int opcion = MAX_MENU;

	while (opcion!=SALIR)
	{
		mostrarMenu(primero, segundo);

		opcion = getInt("\nIngrese una opcion: ");

		switch(opcion)
		{
			case ENTRADA1:
				primero = getDouble("Ingresar 1er operando A = ");
				entrada1 = 1;
				break;

			case ENTRADA2:
				segundo = getDouble("Ingresar 2do operando B = ");
				entrada2 = 1;
				break;

			case CALCULAR:
				if (entrada1 && entrada2) {
					suma = sumar(primero, segundo);
					resta = restar(primero, segundo);
					producto = multiplicar(primero, segundo);
					cociente = dividir(primero, segundo);
					factorial1 = factorial((unsigned)primero);
					factorial2 = factorial((unsigned)segundo);
					calcular = 1;
					printf("\n\nCalculos realizados\n");
				} else {
					printf("\n\nPrimero debe ingresar los operandos\n\n");
				}
				break;

			case INFORMAR:
				if(calcular) mostrarResultados(primero, segundo, suma, resta, producto, cociente, factorial1, factorial2);
				else printf("\n\nPrimero debe calcular los resultados\n\n");
				break;

			case SALIR:
				printf("\n\n********Salir*************\n\n");
				break;

			default:
				printf("\n\nOpcion Invalida\n\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}

void mostrarMenu(double primero, double segundo){
	printf("\n------------------------------------------------"
			"\n\t\tMENU:\n"
			"-----------------------------------------------\n"
			"\t%d. Ingresar 1er operando (A = %lf)\n"
			"\t%d. Ingresar 2do operando (B = %lf)\n"
			"\t%d. Calcular todas las operaciones\n"
			"\t%d. Informar resultados\n"
			"\t%d. Salir\n"
			"-----------------------------------------------\n",
			ENTRADA1, primero, ENTRADA2, segundo, CALCULAR, INFORMAR, SALIR);
}

int getInt(char mensaje[]){
	int retorno;
	printf(mensaje);
	scanf("%d",&retorno);
	fflush(stdin);
	return retorno;
}

double getDouble(char mensaje[]){
	double retorno;
	printf(mensaje);
	scanf("%lf",&retorno);
	fflush(stdin);
	return retorno;
}

void mostrarResultados(	double primero, double segundo ,
						double suma, double resta, double producto, double cociente,
						unsigned long factorial1, unsigned long factorial2)
{
	printf("\nEl resultado de A+B es: %lf", suma);
	printf("\nEl resultado de A-B es: %lf", resta);
	printf("\nEl resultado de A*B es: %lf", producto);
	if (segundo){
		printf("\nEl resultado de A/B es: %lf", cociente);
	} else {
		printf("\nNo es posible dividir por cero");
	}
	if(primero-(unsigned)primero || primero<0 || primero>15){
		printf("\nA No es un numero natural entre 0 y 15");
	} else {
		printf("\nEl factorial de A es: %ld",factorial1);
	}
	if(segundo-(unsigned)segundo || segundo<0 || segundo>15){
		printf("\nB No es un numero natural entre 0 y 15\n");
	} else {
		printf("\nEl factorial de B es: %ld\n",factorial2);
	}
}

