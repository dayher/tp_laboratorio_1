#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input.h"

/** \brief Crea un empleado con los datos ingresados como parametros.
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee * en caso de exito, NULL en caso de error
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee * newEmployee;

	if((newEmployee = employee_new())==NULL) return NULL; //validar

	employee_setId(newEmployee, atoi(idStr));
	employee_setNombre(newEmployee, nombreStr);
	employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
	employee_setSueldo(newEmployee, atoi(sueldoStr));

	return newEmployee;
}

/** \brief Pide memoria dinamica para un empleado .
 *
 * \param void
 * \return Employee * en caso de exito, NULL en caso de error
 *
 */
Employee* employee_new(){
	Employee * newEmployee;
	return newEmployee = (Employee *)malloc(sizeof(Employee));
}

/** \brief carga el dato recibido en la estructura empleado.
 *
 * \param Employee *
 * \param int id
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_setId(Employee* this,int id){
	if(this==NULL) return 1;
	this->id = id;
	return 0;
}

/** \brief Obtiene de la estructura referenciada en la direccion recibida como parametro.
 *
 * \param Employee *
 * \param int * id
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_getId(Employee* this,int* id){
	if(this==NULL || id == NULL) return 1;
	(*id) = this->id;
	return 0;
}

/** \brief carga el dato recibido en la estructura empleado.
 *
 * \param Employee *
 * \param char * nombre
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_setNombre(Employee* this,char* nombre){
	if(this==NULL || nombre == NULL) return 1;
	strcpy(this->nombre, nombre);
	return 0;
}

/** \brief Obtiene de la estructura referenciada en la direccion recibida como parametro.
 *
 * \param Employee *
 * \param int * nombre
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_getNombre(Employee* this,char* nombre){
	if(this==NULL || nombre == NULL) return 1;
	strcpy(nombre, this->nombre);
	return 0;
}

/** \brief carga el dato recibido en la estructura empleado.
 *
 * \param Employee *
 * \param int horas
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	if(this==NULL) return 1;
	this->horasTrabajadas = horasTrabajadas;
	return 0;
}

/** \brief Obtiene de la estructura referenciada en la direccion recibida como parametro.
 *
 * \param Employee *
 * \param int * horas
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	if(this==NULL || horasTrabajadas == NULL) return 1;
	(*horasTrabajadas) = this->horasTrabajadas;
	return 0;
}

/** \brief carga el dato recibido en la estructura empleado.
 *
 * \param Employee *
 * \param int sueldo
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_setSueldo(Employee* this,int sueldo){
	if(this==NULL) return 1;
	this->sueldo = sueldo;
	return 0;
}

/** \brief Obtiene de la estructura referenciada en la direccion recibida como parametro.
 *
 * \param Employee *
 * \param int * sueldo
 * \return 0 en caso de exito, 1 en caso de error
 *
 */
int employee_getSueldo(Employee* this,int* sueldo){
	if(this==NULL || sueldo == NULL) return 1;
	(*sueldo) = this->sueldo;
	return 0;
}

/** \brief Compara por el nombre dos empleados.
 *
 * \param void * primero
 * \param void * segundo
 * \return int 0 si son iguales, mayor que cero si el primero es mayor lexicograficamente.
 *
 */
int employee_compareByName(void * primero, void * segundo){

	char nombre1[128], nombre2[128];

	employee_getNombre((Employee*)primero, nombre1);
	employee_getNombre((Employee*)segundo, nombre2);

	//validar entrada
	return strcmp(nombre1,nombre2);
}

/** \brief Libera de memoria dinamica el espacio reservado para una estructura y lo fija a NULL.
 *
 * \param Employee *
 * \return void
 *
 */
void employee_delete(Employee * this){
	 if(this != NULL){
		 free(this);
		 this=NULL;
	 }
}

