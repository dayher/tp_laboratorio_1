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
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	if((pFile = fopen(path,"rb"))==NULL) return 1;

	if(parser_EmployeeFromText(pFile, pArrayListEmployee)) return 1;

	fclose(pFile);

    return 0;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	if((pFile = fopen(path,"rb"))==NULL) return 1;

	if(parser_EmployeeFromBinary(pFile, pArrayListEmployee)) return 1;

	fclose(pFile); //validar

    return 0;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char idStr[50], nombre[50], hsStr[50], sueldoStr[50];

	Employee * newEmployee;

	if(pArrayListEmployee == NULL) return 1;

	while(!getStringLetras("\nIngrese nombre:\n", nombre));
	while(!getStringNumeros("\nIngrese horas trabajadas:\n", hsStr));
	while(!getStringNumeros("\nIngrese sueldo:\n", sueldoStr));
	controller_getNewId(idStr);

	if((newEmployee = employee_newParametros(idStr, nombre, hsStr, sueldoStr))==NULL) return 1;
	ll_add(pArrayListEmployee, newEmployee);

    return 0;
}
/** \brief Obtiene un nuevo Id de un archivo y modifica su valor en el archivo para el siguiente uso
 *
 * \param idStr char * almacena como string el id del archivi en la referencia
 * \return int el id obtenido en caso de exito, -1 en caso de error
 *
 */

int controller_getNewId(char * idStr){
	int id = -1;
	FILE * pFile;

	if(idStr == NULL) return id;

	pFile = fopen("newId.txt","r+");
	fgets(idStr,10,pFile);
	fseek(pFile,0,SEEK_SET);
	id = atoi(idStr);
	fprintf(pFile,"%d",id+1);
	fclose(pFile);
	return id;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	char nombre[50], hsStr[50], sueldoStr[50];
	int index=0, idAux, id;
	Employee * aux;
	int existeId =0;

	if(pArrayListEmployee == NULL) return 1;

	id = getInt("\nIngrese id: ", 1, 10000000 );

	while((aux = (Employee *)ll_get(pArrayListEmployee, index++))!=NULL){
		employee_getId(aux,&idAux);
		if (id==idAux) {
			existeId =1;
			break;
		}
	}
	if(!existeId) {
		printf("\nId no existe\n");
		return 1;
	}

	employee_getNombre(aux, nombre);

	printf("Modificar datos de %s?\n", nombre);

	if(!getInt("SI : 1 / NO : 0 \n",0,1)) return 1;

	while(!getStringLetras("\nIngrese nombre:\n", nombre));
	while(!getStringNumeros("\nIngrese horas trabajadas:\n", hsStr));
	while(!getStringNumeros("\nIngrese sueldo:\n", sueldoStr));

	employee_setNombre(aux, nombre);
	employee_setHorasTrabajadas(aux, atoi(hsStr));
	employee_setSueldo(aux, atoi(sueldoStr));

    return 0;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	char nombre[50];
	int index=0, id, idAux;
	Employee * aux;
	int existeId = 0;

	if(pArrayListEmployee == NULL) return 1;

	id = getInt("\nIngrese id: ", 1, 10000000 );

	while((aux = (Employee *)ll_get(pArrayListEmployee, index++))!=NULL){
		employee_getId(aux,&idAux);
		if (id==idAux) {
			existeId = 1;
			break;
		}
	}
	if(!existeId) {
		printf("\nId no existe\n");
		return 1;
	}

	employee_getNombre(aux, nombre);

	printf("Dar de baja a %s?\n", nombre);

	if(!getInt("SI : 1 / NO : 0 \n",0,1)) return 1;

	ll_remove(pArrayListEmployee, --index); // Importante! si la llamada a esta funcion no libera la memoria hay que implementar otra

	employee_delete(aux);

    return 0;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee * aux;
	int id, hs, sueldo;
	char nombre[128];
    int i=0;

    if(pArrayListEmployee == NULL) return 1;

    printf("\n\t\t\tLISTADO:\n\n"
    		"\t ID \t|\t      NOMBRE       |\t HORAS \t|\t SUELDO\n"
    		"______________________________________________________________________________\n");
    while((aux = (Employee *) ll_get(pArrayListEmployee, i)) != NULL){
    	employee_getId(aux, &id);
    	employee_getNombre(aux, nombre);
    	employee_getHorasTrabajadas(aux, &hs);
    	employee_getSueldo(aux, &sueldo);
    	printf("\t%d\t|\t%-20s|\t%d\t|\t%d\n", id,nombre,hs,sueldo);
    	i++;
    }
    return 0;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int order;

	if(pArrayListEmployee == NULL) return 1;

	order = 1;//getInt("\nIngrese orden: ", -1,1);

	ll_sort(pArrayListEmployee, &employee_compareByName, order);

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	if(path == NULL || pArrayListEmployee == NULL) return 1;

	if((pFile = fopen(path,"w")) == NULL) return 1;

	if(parser_TextFromEmployee(pFile , pArrayListEmployee)){
		fclose(pFile);
		return 1;
	}
	if(fclose(pFile)==EOF) return 1;

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 en caso de exito, 1 en caso de error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE * pFile;

	if(path == NULL || pArrayListEmployee == NULL) return 1;

	if((pFile = fopen(path,"wb")) == NULL) return 1;

	if(parser_BinaryFromEmployee(pFile , pArrayListEmployee)){
		fclose(pFile);
		return 1;
	}
	if(fclose(pFile)==EOF) return 1;

  return 0;
}

