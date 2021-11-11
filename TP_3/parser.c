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

    return 0;
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
	int id, hs, sueldo;
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	Employee * newEmployee, aux;

	do {
		if(fread(&aux,sizeof(Employee),1,pFile)<1) break;

		employee_getId(&aux,&id);
		employee_getNombre(&aux,nombre);
		employee_getHorasTrabajadas(&aux,&hs);
		employee_getSueldo(&aux,&sueldo);

		itoa(id, idStr, 10); // validar contra null
		itoa(hs, hsStr, 10 );
		itoa(sueldo, sueldoStr, 10);

		newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListEmployee, newEmployee);

	} while(!feof(pFile));


    return 0;
}
