#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"
#include <string.h>

int main()
{
	int opcion = 0;

	LinkedList* listaEmpleados = ll_newLinkedList();

    while(opcion!=10){

        printf("\n\t\t\tMENU\n"
        		"______________________________________________________________________________\n\n"
        		"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
        		"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
        		"3. Alta de empleado\n"
        		"4. Modificar datos de empleado\n"
        		"5. Baja de empleado\n"
        		"6. Listar empleados\n"
        		"7. Ordenar empleados\n"
        		"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
        		"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
        		"10. Salir\n"
        		"______________________________________________________________________________\n");
        opcion = getInt("\nIngrese una opcion:\t",1,10);

    	switch(opcion){
    				case 1:
    					if(!controller_loadFromText("data.csv",listaEmpleados)){
    						printf("\nCARGA EXITOSA\n");
    					} else {
    						printf("\nCARGA FALLIDA\n");
    					}
    					break;
    				case 2:
    					if(!controller_loadFromBinary("bindata.bin",listaEmpleados)){
    						printf("\nCARGA EXITOSA\n");
    					} else {
    						printf("\nCARGA FALLIDA\n");
    					}
    					break;
    				case 3:
    					if(!controller_addEmployee(listaEmpleados)){
    						printf("\nALTA EXITOSA\n");
    					} else {
    						printf("\nALTA FALLIDA\n");
    					}
    					break;
    				case 4:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					if(!controller_editEmployee(listaEmpleados)){
    						printf("\nMODIFICACION EXITOSA\n");
    					} else {
    						printf("\nMODIFICACION CANCELADA\n");
    					}
    					break;
    				case 5:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					if(!controller_removeEmployee(listaEmpleados)){
    						printf("\nBAJA EXITOSA\n");
    					} else {
    						printf("\nBAJA CANCELADA\n");
    					}
    					break;
    				case 6:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					controller_ListEmployee(listaEmpleados);
    					break;
    				case 7:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					controller_sortEmployee(listaEmpleados);
    					controller_ListEmployee(listaEmpleados);
    					break;
    				case 8:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					if(!controller_saveAsText("./prueba2.csv", listaEmpleados)){
    						printf("\nCARGA EXITOSA\n");;
    					} else {
    						printf("\nCARGA FALLIDA\n");
    					}
    					break;
    				case 9:
    					if(ll_len(listaEmpleados)<1){
    						printf("\nSIN ALTAS EN EL SISTEMA\n");
    						break;
    					}
    					if(!controller_saveAsBinary("bindata.bin", listaEmpleados)){
    						printf("\nCARGA EXITOSA\n");
    					} else {
    						printf("\nCARGA FALLIDA\n");
    					}
    					break;
    				case 10:
    					ll_deleteLinkedList(listaEmpleados);
    					printf("\n______________________________________________________________________________\n"
    							"\t\t\tFIN DEL PROGRAMA\n"
    							"______________________________________________________________________________\n");

    					break;
    				default:
    					printf("\nOpcion Invalida\n");

    					break;
    			}
    }

    return 0;
}

