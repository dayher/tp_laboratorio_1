/*
 ============================================================================
 Name        : TP1.c
 Author      : Dayher Marchan
 Version     : 2.0
 Copyright   :
 Description : Calculadora básica
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include "input.h"

int main(void)
{
	double primero = 0, segundo = 0;
	double calculadoA, calculadoB;
	double suma, resta, producto, cociente;
	unsigned long factorial1, factorial2;
	int entrada1=0, entrada2=0, calcular=0;
	int opcion = 0;

	while (opcion!=5)
	{
		mostrarMenu(primero, segundo);

		opcion = getInt("\nIngrese una opción: ", 0 ,5);

		switch(opcion)
		{
			case 1:
				primero = getDouble("Ingresar 1er operando A = ");
				entrada1 = 1;
				break;
			case 2:
				segundo = getDouble("Ingresar 2do operando B = ");
				entrada2 = 1;
				break;
			case 3:
				if (entrada1 && entrada2) {
					calcularResultados(primero, segundo, &suma, &resta, &producto, &cociente, &factorial1, &factorial2);
					calculadoA=primero;
					calculadoB=segundo;
					calcular = 1;
				} else {
					printf("\n\nPrimero debe ingresar los operandos\n\n");
				}
				break;
			case 4:
				if(calcular){
					mostrarResultados(calculadoA, calculadoB, suma, resta, producto, cociente, factorial1, factorial2);

				} else {
					printf("\n\nPrimero debe calcular los resultados\n\n");
				}
				break;
			case 5:
				printf("\n\n********Salir*************\n\n");
				break;

			default:
				printf("\n\nOpcion Inválida\n\n");
				break;
		}
	}
	return EXIT_SUCCESS;
}
