#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	Employee * newEmployee;
	int i = 20;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);

	while(i--) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
		newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListEmployee, newEmployee);
	}

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
