#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	Employee * newEmployee;

	 if (pFile==NULL || pArrayListEmployee==NULL) return 1;

	fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
	fflush(NULL);

	while(!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, hsStr, sueldoStr);
		fflush(NULL);
		newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListEmployee, newEmployee);
	}

    return 0;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  0 en caso de exito, 1 en caso de error
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int id, hs, sueldo;
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	Employee * newEmployee;
	char buffer[2];

	 if (pFile==NULL || pArrayListEmployee==NULL) return 1;

	while(!feof(pFile)){
		fflush(NULL);
		if((fread(&id,sizeof(int),1,pFile))!=1) return 1;

		if((fread(buffer,sizeof(char),1,pFile))!=1) return 1;

		if((fread(nombre,sizeof(char),128,pFile))!=128) return 1;

		if((fread(buffer,sizeof(char),1,pFile))!=1)return 1;

		if((fread(&hs,sizeof(int),1,pFile))!=1)return 1;

		if((fread(buffer,sizeof(char),1,pFile))!=1)return 1;

		if((fread(&sueldo,sizeof(int),1,pFile))!=1) return 1;

		itoa(id, idStr, 10);
		itoa(hs, hsStr, 10 );
		itoa(sueldo, sueldoStr, 10);

		newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
		ll_add(pArrayListEmployee, newEmployee);
	}
    return 0;
}

/** \brief Parsea los datos de la lista de Empleados al achivo de texto.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  0 en caso de exito, 1 en caso de error
 *
 */
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee){
	Employee * aux;
    int i=0;
    int id, sueldo, hs;
    char nombre[128];

    if (pFile==NULL || pArrayListEmployee==NULL) return 1;

    while((aux = (Employee *)ll_get(pArrayListEmployee, i)) != NULL){
    	employee_getNombre(aux, nombre);
    	employee_getId(aux, &id);
    	employee_getSueldo(aux, &sueldo);
    	employee_getHorasTrabajadas(aux, &hs);
    	fprintf(pFile, "%d,%s,%d,%d\n",id,nombre,hs,sueldo);
    	i++;
    }
	return 0;
}

/** \brief Parsea los datos de la lista de Empleados al achivo de binario.
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  0 en caso de exito, 1 en caso de error
 *
 */
int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int i =0;
	int id, hs, sueldo;
	char nombre [128];
	char delimitter[] = ",";

    Employee * aux;

    if (pFile==NULL || pArrayListEmployee==NULL) return 1;

   while(((aux = (Employee *)ll_get(pArrayListEmployee, i)) != NULL))
   {
		employee_getNombre(aux, nombre);
		employee_getId(aux, &id);
		employee_getSueldo(aux, &sueldo);
		employee_getHorasTrabajadas(aux, &hs);

		fwrite(&id,sizeof(int),1,pFile);

		fwrite(delimitter,sizeof(char),1,pFile);

		fwrite(nombre,sizeof(char),128,pFile);

		fwrite(delimitter,sizeof(char),1,pFile);

		fwrite(&hs,sizeof(int),1,pFile);

		fwrite(delimitter,sizeof(char),1,pFile);

		fwrite(&sueldo,sizeof(int),1,pFile);

		i++;
	}
	return 0;
}






