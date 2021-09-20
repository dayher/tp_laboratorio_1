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

#define ELEMENTS 1000

int main(void) {
	int r;
	r = initEmployees(arrayEmployees, ELEMENTS);
	r = removeEmployee(arrayEmployees, ELEMENTS,20);
	r = sortEmployeeByName(arrayEmployees, ELEMENTS, 1);
	r = printEmployees(arrayEmployees, ELEMENTS);
	return EXIT_SUCCESS;
}
https://onlinegdb.com/75njo7rbFg
