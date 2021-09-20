/*
 ============================================================================
 Name        : Ejercicio6-3.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description :  Pedirle al usuario su nombre y apellido (en variables separadas, una para el nombre y otra para el apellido).
                Ninguna de las dos variables se puede modificar.
                Debemos lograr guardar en una tercer variable el apellido y el nombre con el siguiente formato:
                Por ejemplo:
                Si el nombre es juan ignacio y el apellido es gOmEz, la salida debería ser:
                Gomez, Juan Ignacio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int getString(char[], char[]);
int retornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]);
int formatearCadena(char cadena[]);

int main(void) {
	setbuf(stdout,NULL);
	char nombre[51];
	char apellido[51];
	char nombreCompleto[81];

	getString("Ingrese su nombre: ", nombre);
	getString("Ingrese su apellido: ",apellido);

	printf("\nEl nombre es: %s",nombre);
	printf("\nEl apellido es: %s",apellido);

	retornarNombreCompleto(nombre, apellido, nombreCompleto);

	printf("\nEl nombre completo es: %s", nombreCompleto);

	return EXIT_SUCCESS;
}

int getString(char mensaje[], char cadena[]){
	int retorno=0;

	if(mensaje!=NULL && cadena!=NULL){
		setbuf(stdin, NULL);
		printf("\n%s",mensaje);
		scanf("%[^\n]",cadena);
		retorno=1;
	}
	return retorno;
}

int retornarNombreCompleto(char nombre[], char apellido[], char nombreCompleto[]){

	int retorno=0;
	if(nombre!=NULL && apellido!=NULL && nombreCompleto!=NULL){
		strcpy(nombreCompleto, apellido);
		strcat(nombreCompleto,", ");
		strcat(nombreCompleto,nombre);
		formatearCadena(nombreCompleto);
		retorno=1;
	}
	return retorno;
}
int formatearCadena(char cadena[]){
	int tam, retorno=0;
	tam=strlen(cadena);
	//strlwr(cadena);

	if(cadena!=NULL){
		for(int i=0;i<tam;i++){
			if(i==0 || cadena[i-1]==32){
				cadena[i]=toupper(cadena[i]);
			}
		}
		retorno=1;
	}
	return retorno;
}
