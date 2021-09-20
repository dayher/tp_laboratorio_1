/*
 ============================================================================
 Name        : Ejercicio5-3.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : 	Realizar un programa que permita el ingreso de 10 números enteros distintos de cero.
 	 	 	 	La carga deberá ser aleatoria (todos los elementos se inicializan en cero por default).
 	 	 	 	Determinar el promedio de los positivos, y del menor de los negativos la suma de los
 	 	 	 	antecesores (Según la recta numérica de los reales, hasta llegar a cero).
				Utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LONGITUD 10

void cargarVectorAleatorio(int vector[],unsigned longitud);
void ingresarValorAleatorio(int vector[], unsigned longitud);
void inicializarVector(int vector[], unsigned longitud,int valor);
unsigned promediarPositivos(int vector[], unsigned longitud);
int sumarNegativosAntecesoresMinimo(int vector[],unsigned longitud);


int main(void) {

	int sumaAntecesores, vector[LONGITUD];
	unsigned promedioPositivos;

	inicializarVector(vector,LONGITUD,0);
	cargarVectorAleatorio(vector,LONGITUD);

	if(	(promedioPositivos = promediarPositivos(vector,LONGITUD))	){
		printf("El promedio de los números positivos es: %u\n", promedioPositivos);
	} else {
		printf("No ingresó números positivos");
	}

	if(	(sumaAntecesores = sumarNegativosAntecesoresMinimo(vector,LONGITUD))	){
		printf("La suma de los negativos antecesores al menor es: %i\n",sumaAntecesores);
	} else {
		printf("No ingresó números negativos");
	}

	return EXIT_SUCCESS;
}

void ingresarValorAleatorio(int vector[], unsigned longitud){
	unsigned posicion;
	int numero;
	do{
				setbuffer(stdin,NULL,1);
				printf("Ingrese posición (entre 1 y %u) : ",longitud);
				scanf("%u",&posicion);
			}
			while(posicion>longitud || posicion<1);

			do{
				setbuffer(stdin,NULL,1);
				printf("Ingrese un número entero distinto de cero : ");
				scanf("%i",&numero);
			}
			while(!numero);
			vector[posicion-1]=numero;
}

void cargarVectorAleatorio(int vector[],unsigned longitud){
	unsigned contador=0;
	for(contador=0;contador<longitud;contador++){
		ingresarValorAleatorio(vector,longitud);
	}
}
void inicializarVector(int vector[], unsigned longitud ,int valor){
	unsigned contador=0;
	for(contador=0;contador<longitud;contador++){
		vector[contador]=valor;
	}
}
unsigned promediarPositivos(int vector[], unsigned longitud){
	unsigned contador=0, contadorPositivos=0, acumulador=0, promedio;

	for(contador=0;contador<longitud;contador++){
		if((vector[contador])>0){
		acumulador+=vector[contador];
		contadorPositivos++;
		}
	}
	return promedio=acumulador/contadorPositivos;
}
int sumarNegativosAntecesoresMinimo(int vector[],unsigned longitud){
	int acumuladorAntecesores=0, minimo = 0;
	int contador=0;
	for(contador=0;contador<longitud;contador++){
		if(vector[contador]<minimo) minimo=vector[contador];
	}
	for(contador=0;contador<longitud;contador++){
		if(vector[contador]<0 && vector[contador]>minimo) acumuladorAntecesores+=vector[contador];
	}
	return acumuladorAntecesores;
}
