/*
 * biblioteca.c
 *
 *  Created on: 1 sep. 2021
 *      Author: dayher
 */

#include "biblioteca.h"
#include <stdio.h>

void mostrarMenu(double primero, double segundo){
	printf("\n------------------------------------------------"
			"\n\t\tMENU:\n"
			"-----------------------------------------------\n"
			"\t1. Ingresar 1er operando (A = %lf)\n"
			"\t2. Ingresar 2do operando (B = %lf)\n"
			"\t3. Calcular todas las operaciones\n"
			"\t4. Informar resultados\n"
			"\t5. Salir\n"
			"-----------------------------------------------\n", primero, segundo);
	fflush(NULL);
}

void calcularResultados(double primero, double segundo ,
						double* suma, double *resta, double* producto, double* cociente,
						unsigned long* factorial1, unsigned long* factorial2)
{
	if(suma!=NULL && resta!=NULL && producto!=NULL && cociente!=NULL && factorial1!=NULL && factorial2!=NULL)
	{
		*suma = sumar(primero, segundo);
		*resta = restar(primero, segundo);
		*producto = multiplicar(primero, segundo);

		if (segundo){
			(*cociente) = dividir(primero, segundo);
		}
		if(!(primero-(unsigned)primero || primero<0 || primero>15)){
			*factorial1 = factorial((unsigned)primero);
		}
		if(!(segundo-(unsigned)segundo || segundo<0 || segundo>15)){
			*factorial2 = factorial((unsigned)segundo);
		}
		printf("\n\nCalculos realizados\n");
	}
}

void mostrarResultados(	double primero, double segundo ,
						double suma, double resta, double producto, double cociente,
						unsigned long factorial1, unsigned long factorial2)
{
	printf("\nA=%lf\tB=%lf\n", primero, segundo);
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
		printf("\nB No es un número natural entre 0 y 15\n");
	} else {
		printf("\nEl factorial de B es: %ld\n",factorial2);
	}
}

double sumar(double primero, double segundo){
	double resultado;
	resultado = primero + segundo;
	return resultado;
}

double restar(double primero, double segundo){
	double resultado;
	resultado = primero - segundo;
	return resultado;
}

double multiplicar(double primero, double segundo){
	double resultado;
	resultado = primero * segundo;
	return resultado;
}
double dividir(double primero, double segundo){
	double resultado;
	resultado = primero / segundo;
	return resultado;
}
unsigned long factorial(unsigned numero){

	unsigned long resultado=1;
	unsigned contador=0;

	if(numero==0 || numero==1){
		return resultado;
	} else {
		for(contador=numero;contador>1;contador--){
			resultado*=contador;
		}
		return resultado;
	}
}
