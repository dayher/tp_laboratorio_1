#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "input.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	pFile = fopen(path,"rt");

	parser_EmployeeFromText(pFile, pArrayListEmployee);

	fclose(pFile);

    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];
	Employee * newEmployee;

	// IMPORTANTE!!!! Obtener id de un archivo y no pedirselo al usuario

	getString("\nIngrese id:\n", idStr);

	// Solo para prueba esto!!!!

	getString("\nIngrese nombre:\n", nombre);
	getString("\nIngrese horas trabajadas:\n", hsStr);
	getString("\nIngrese sueldo:\n", sueldoStr);

	newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr);
	ll_add(pArrayListEmployee, newEmployee);

    return 0;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	char nombre[50], hsStr[50], sueldoStr[50];
	int index, len;
	Employee * aux;
	len = ll_len(pArrayListEmployee);

	do{
		index = getInt("\nIngrese posicion: ", 0, len );
	} while((aux = (Employee *)ll_get(pArrayListEmployee, index))==NULL);

	employee_getNombre(aux, nombre);

	printf("Modificar datos de %s?\n", nombre);

	if(!getInt("SI : 1 / NO : 0 \n",0,1)) return 1;

	getString("\nIngrese nombre:\n", nombre);
	getString("\nIngrese horas trabajadas:\n", hsStr);
	getString("\nIngrese sueldo:\n", sueldoStr);

	employee_setNombre(aux, nombre);
	employee_setHorasTrabajadas(aux, atoi(hsStr));
	employee_setSueldo(aux, atoi(sueldoStr));

    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	char nombre[50];
	int index, len;
	Employee * aux;

	len = ll_len(pArrayListEmployee);

	do{
		index = getInt("\nIngrese posicion: ", 0, len);
	} while((aux = (Employee *)ll_get(pArrayListEmployee, index))==NULL);

	employee_getNombre(aux, nombre);

	printf("Dar de baja a %s?\n", nombre);

	if(!getInt("SI : 1 / NO : 0 \n",0,1)) return 1;

	ll_remove(pArrayListEmployee, index); // Importante! si la llamada a esta funcion no libera la memoria hay que implementar otra

    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee * aux;
	char nombre[128];
    int i=0;
    while((aux = (Employee *) ll_get(pArrayListEmployee, i)) != NULL && i<11){
    	employee_getNombre(aux, nombre);
    	printf("%s\n", nombre); //		refactorizar para que sea funcion imprimir un empleado
    	i++;
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int order;

	order = 1;//getInt("\nIngrese orden: ", -1,1);

	ll_sort(pArrayListEmployee, &employee_compareByName, order);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	Employee * aux;
    int i=0;
    int id, sueldo, hs;
    char nombre[128];

    pFile = fopen(path, "wt");

    while((aux = (Employee *)ll_get(pArrayListEmployee, i)) != NULL && i<11){
    	employee_getNombre(aux, nombre);
    	employee_getId(aux, &id);
    	employee_getSueldo(aux, &sueldo);
    	employee_getHorasTrabajadas(aux, &hs);
    	fprintf(pFile, "%d,%s,%d,%d\n",id,nombre,hs,sueldo); //		refactorizar para que sea funcion imprimir un empleado IGUAL QUE EN LA  OTRA FUNCION
    	i++;
    }

	fclose(pFile);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 0;
}

