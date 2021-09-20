/*
 ============================================================================
 Name        : Ejercicio6-2.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : 	 Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
				 Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
				 (Como máximo 5 estructuras repetitivas).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 10

/* The compare argument is a pointer to the comparison function, which is called with two arguments that point
to the elements being compared. The application shall ensure that the function returns an integer less than, equal to,
or greater than 0, if the first argument is considered respectively less than, equal to, or greater than the second.
If two members compare as equal, their order in the sorted array is unspecified.*/

void cargarVectorSecuencial(int vector[],unsigned longitud);

void imprimirVector(int vector[],unsigned longitud);

void imprimirNegativos(int vector[],unsigned longitud);

void imprimirPositivos(int vector[],unsigned longitud);

int compare(const void *_a, const void *_b) {

        int *a, *b;

        a = (int *) _a;
        b = (int *) _b;

        return (*a - *b);
}

void cargarVectorSecuencial(int vector[],unsigned longitud){
	unsigned index;
	int numero;
	printf("Ingrese %u números enteros entre -1000 y 1000:\n",longitud);
	for(index=0;index<longitud;index++){
		do{
			setbuf(stdin,NULL);
			printf("[%u] : ",index+1);
			scanf("%i",&numero);
		} while (numero<-1000||numero>1000);
		vector[index]=numero;
	}
}
void imprimirVector(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores ingresados:\n[\t");
	for(index=0;index<longitud;index++){
		printf("%i\t",vector[index]);
	}
	puts("]");
}
void imprimirNegativosDecrecientes(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores negativos:\n[\t");
	for(index=1;index<=longitud;index++){
		if(vector[longitud-index]<0)
		printf("%i\t",vector[longitud-index]);
	}
	puts("]");
}

void imprimirPositivosCrecientes(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores positivos:\n[\t");
	for(index=0;index<longitud;index++){
		if(vector[index]>0)
		printf("%i\t",vector[index]);
	}
	puts("]");
}
int main () {

        int numbers[MAX_NUMBERS];

        cargarVectorSecuencial(numbers,MAX_NUMBERS);

        qsort(numbers, MAX_NUMBERS, sizeof(int), &compare);

        imprimirVector(numbers,MAX_NUMBERS);

        imprimirNegativosDecrecientes(numbers, MAX_NUMBERS);
        imprimirPositivosCrecientes(numbers, MAX_NUMBERS);

        return 0;
}
