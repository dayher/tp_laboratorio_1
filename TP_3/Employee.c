#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input.h"

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee * newEmployee;

	newEmployee = employee_new(); //validar

	employee_setId(newEmployee, atoi(idStr));
	employee_setNombre(newEmployee, nombreStr);
	employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
	employee_setSueldo(newEmployee, atoi(sueldoStr));

	return newEmployee;
}

Employee* employee_new(){
	Employee * newEmployee;
	newEmployee = (Employee *)malloc(sizeof(Employee)); // validar
	return newEmployee;
}

int employee_setId(Employee* this,int id){
	this->id = id;
	return 0;
}
int employee_getId(Employee* this,int* id){
	(*id) = this->id;
	return 0;
}

int employee_setNombre(Employee* this,char* nombre){
	strcpy(this->nombre, nombre);
	return 0;
}
int employee_getNombre(Employee* this,char* nombre){
	strcpy(nombre, this->nombre);
	return 0;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	this->horasTrabajadas = horasTrabajadas;
	return 0;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	(*horasTrabajadas) = this->horasTrabajadas;
	return 0;
}

int employee_setSueldo(Employee* this,int sueldo){
	this->sueldo = sueldo;
	return 0;
}
int employee_getSueldo(Employee* this,int* sueldo){
	(*sueldo) = this->sueldo;
	return 0;
}

int employee_compareByName(void * primero, void * segundo){

	char nombre1[128], nombre2[128];

	employee_getNombre((Employee*)primero, nombre1);
	employee_getNombre((Employee*)segundo, nombre2);

	//validar entrada
	return strcmp(nombre1,nombre2);
}


