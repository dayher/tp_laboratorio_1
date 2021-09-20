/*
 ============================================================================
 Name        : Ejercicio6-1.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : 	Disponemos de dos variables numéricas (a y b).
 	 	 	 	Realizar un algoritmo que permita el intercambio de valores de dichas variables.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void intercambiarNumeros(double * a, double * b);

int main(void) {
	double a=5.5, b=6.3;
	intercambiarNumeros(&a,&b);
	printf("a:%lf -- b:%lf\n",a,b);
}

void intercambiarNumeros(double * a, double * b){
	double auxiliar;
	auxiliar=*a;
	*a=*b;
	*b=auxiliar;
}
