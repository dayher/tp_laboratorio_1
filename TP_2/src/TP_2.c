/*
 ============================================================================
 Name        : TP_2.c
 Author      : Dayher Marchan
 Version     :
 Copyright   : 
 Description : 	Una empresa requiere un sistema para administrar su nómina de empleados.
 	 	 	 	Se sabe que dicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "utn.h"

#define ELEMENTS 3
#define ALTA 1
#define BAJA 2
#define MODIFICACION 3
#define ORDENAR 4
#define LISTAR 5
#define SALARIOS 6
#define SALIR 0

int main(void) {
	size_t opcion;
	int newId=1000;

	Employee arrayEmployees[ELEMENTS];
	initEmployees(arrayEmployees, ELEMENTS);

	//MENU
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

		opcion = getInt("\nIngrese una opción:\t");

		switch(opcion){
		case ALTA:
			if(!ingresarEmpleado(arrayEmployees,ELEMENTS,newId)){
				newId++;
			} else {
				printf("No hay espacios disponibles\n");
			}
			break;
		case BAJA:
			if(eliminarEmpleado(arrayEmployees,ELEMENTS)){
				printf("No existe ningún empleado con el id ingresado\n");
			}
			break;
		case MODIFICACION:
			if(modificarEmpleado(arrayEmployees,ELEMENTS)){
				printf("No existe ningún empleado con el id ingresado\n");
			}
			break;
		case ORDENAR:
			sortEmployees(arrayEmployees, ELEMENTS, -1);
			break;
		case LISTAR:
			printEmployees(arrayEmployees, ELEMENTS);
			break;
		case SALARIOS:
			calcularSalarioPromedio(arrayEmployees, ELEMENTS);
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
//https://onlinegdb.com/75njo7rbFg
//https://onlinegdb.com/bSd7j7WDB
//https://onlinegdb.com/YiLA9chb2
//https://onlinegdb.com/X_p7RRLOh
