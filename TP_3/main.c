#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include <string.h>

#define SALIR 10

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	int opcion = 0;

	LinkedList* listaEmpleados = ll_newLinkedList();

    opcion = getInt("Ingrese una opcion\n",1,10);


    while(opcion!=SALIR){
    	switch(opcion){
    				case 1:
    					controller_loadFromText("data.csv",listaEmpleados); // validar carga y no cargar 2 veces el mismo archivo
    					break;
    				case 2:
    					controller_addEmployee(listaEmpleados);
    					break;
    				case 3:
    					printf("Proximamente opcion 3!\n");
    					break;
    				case 4:
    					controller_removeEmployee(listaEmpleados);
    					break;
    				case 5:
    					controller_editEmployee(listaEmpleados);
    					break;

    				case 6: // validar que se haya cargado en opcion 1 o 2
    					controller_ListEmployee(listaEmpleados);
    					break;
    				case 7:
    					controller_sortEmployee(listaEmpleados);
    					break;
    				case 8:
    					controller_saveAsText("./prueba2.csv", listaEmpleados);
    					break;
    				case 9:
    					break;
    				case SALIR: //liberar memoria!
    					printf("\nSalir\n");
    					break;
    				default:
    					printf("\nOpcion Invalida\n");
    					break;
    			}
    	opcion = getInt("Ingrese una opcion\n",1,10);
    }

    return 0;
}

