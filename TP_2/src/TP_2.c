/*
 ============================================================================
 Name        : TP_2.c
 Author      : Dayher Marchan
 Version     : 1.0
 Copyright   : 
 Description : 	Una empresa requiere un sistema para administrar su nómina de empleados.
 	 	 	 	Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"

#define ELEMENTS 1000
#define ALTA 1
#define BAJA 2
#define MODIFICACION 3
#define ORDENAR 4
#define LISTAR 5
#define SALARIOS 6
#define MAX_MENU 10
#define SALIR 0

int main(void) {
	size_t opcion=MAX_MENU;
	int newId=1000;
	Employee arrayEmployees[ELEMENTS];

	initEmployees(arrayEmployees, ELEMENTS);

	while(opcion!=SALIR){
		printf("\n"
				"%d) ALTA\n"
				"%d) BAJA\n"
				"%d) MODIFICACION\n"
				"%d) ORDENAR\n"
				"%d) LISTAR\n"
				"%d) SALARIOS\n"
				"%d) SALIR\n",
				ALTA,BAJA,MODIFICACION,ORDENAR,LISTAR,SALARIOS,SALIR);

		opcion = getInt("\nIngrese una opción:\t",SALIR,MAX_MENU);

		switch(opcion){
		case ALTA:
			if(!ingresarEmpleado(arrayEmployees,ELEMENTS,newId)){
				newId++;
				printf("\nAlta exitosa\n");
			} else {
				printf("No hay espacios disponibles\n");
			}
			break;
		case BAJA:
			if(eliminarEmpleado(arrayEmployees,ELEMENTS)){
				printf("No existe ningún empleado con el id ingresado\n");
			} else {
				printf("\nBaja exitosa\n");
			}
			break;
		case MODIFICACION:
			if(modificarEmpleado(arrayEmployees,ELEMENTS)){
				printf("No existe ningún empleado con el id ingresado\n");
			} else {
				printf("\nModificacion exitosa\n");
			}
			break;
		case ORDENAR:
			ordenarEmpleadosApellidoSector(arrayEmployees, ELEMENTS);
			printEmployees(arrayEmployees, ELEMENTS);
			break;
		case LISTAR:
			printEmployees(arrayEmployees, ELEMENTS);
			break;
		case SALARIOS:
			mostrarSalarioPromedio(arrayEmployees, ELEMENTS);
			break;
		case SALIR:
			printf("\nFIN\n\n");
			break;
		default:
			printf("Opción inválida");
			break;
		}
	}

	return EXIT_SUCCESS;
}
