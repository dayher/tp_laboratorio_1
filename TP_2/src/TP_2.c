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

#define ELEMENTS 3
int main(void) {
	int r;
	char * names[]={"Dayher","Gonzalez","Gabriel","Gonzalez","Samanta","Callejas"};
	Employee arrayEmployees[ELEMENTS];
	r = initEmployees(arrayEmployees, ELEMENTS);
	addEmployee(arrayEmployees,ELEMENTS,names[0],names[1],350.5,3);
	addEmployee(arrayEmployees,ELEMENTS,names[2],names[3],530.5,2);
	addEmployee(arrayEmployees,ELEMENTS,names[4],names[5],550.5,1);
	//r = removeEmployee(arrayEmployees, ELEMENTS,20);
	r = sortEmployees(arrayEmployees, ELEMENTS, 1);
	r = printEmployees(arrayEmployees, ELEMENTS);
	return EXIT_SUCCESS;
}
//https://onlinegdb.com/75njo7rbFg
