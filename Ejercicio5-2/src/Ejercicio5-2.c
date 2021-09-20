/*
 ============================================================================
 Name        : Ejercicio5-2.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : 	Pedir el ingreso de 10 números enteros entre -1000 y 1000. Determinar:
				Cantidad de positivos y negativos.
				Sumatoria de los pares.
				El mayor de los impares.
				Listado de los números ingresados.
				Listado de los números pares.
				Listado de los números de las posiciones impares.
				Se deberán utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define LONGITUD 10

void cargarVectorSecuencial(int vector[],unsigned longitud);
unsigned contarPositivos(int vector[],unsigned longitud);
unsigned contarNegativos(int vector[],unsigned longitud);
int sumarPares(int vector[],unsigned longitud);
int buscarMayorImpar(int vector[],unsigned longitud);
void imprimirVector(int vector[],unsigned longitud);
void imprimirValorPar(int vector[],unsigned longitud);
void imprimirPosicionImpar(int vector[],unsigned longitud);


int main(void) {
	int vector[LONGITUD];

	cargarVectorSecuencial(vector,LONGITUD);
	printf("La cantidad de números positivos es: %u\n",contarPositivos(vector,LONGITUD));
	printf("La cantidad de números negativos es: %u\n",contarNegativos(vector,LONGITUD));
	printf("La sumatoria de los números pares es: %i\n",sumarPares(vector, LONGITUD));
	printf("El mayor de los números impares es: %i\n",buscarMayorImpar(vector,LONGITUD));
	imprimirVector(vector,LONGITUD);
	imprimirValorPar(vector,LONGITUD);
	imprimirPosicionImpar(vector, LONGITUD);

	return EXIT_SUCCESS;
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
unsigned contarPositivos(int vector[],unsigned longitud){
	unsigned index=0, contador=0;

	for(index=0;index<longitud;index++){
		if(vector[index]>0) contador++;
	}
	return contador;
}
unsigned contarNegativos(int vector[],unsigned longitud){
	unsigned index=0, contador=0;

	for(index=0;index<longitud;index++){
		if(vector[index]<0) contador++;
	}
	return contador;
}
int sumarPares(int vector[],unsigned longitud){
	unsigned index=0, acumulador=0;

	for(index=0;index<longitud;index++){
		if(!(vector[index]%2)) acumulador+=vector[index];
	}
	return acumulador;
}
int buscarMayorImpar(int vector[],unsigned longitud){ //devuelve cero si no se ingresaron impares
	unsigned index, mayor=0;

	for(index=0;index<longitud;index++){
		if(vector[index]%2) {
			if(mayor==0){ // bandera primer impar
				mayor=vector[index];
			} else if (vector[index]>mayor){
				 mayor=vector[index];
			}
		}
	}
	return mayor;
}
void imprimirVector(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores ingresados:\n[\t");
	for(index=0;index<longitud;index++){
		printf("%i\t",vector[index]);
	}
	puts("]");
}
void imprimirValorPar(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores pares:\n[\t");
	for(index=0;index<longitud;index++){
		if(!(vector[index]%2))
		printf("%i\t",vector[index]);
	}
	puts("]");
}
void imprimirPosicionImpar(int vector[],unsigned longitud){
	unsigned index;
	printf("Valores en posiciones impares:\n[\t");
	for(index=0;index<longitud;index++){
		if(index%2)
		printf("%i\t",vector[index]);
	}
	puts("]");
}
