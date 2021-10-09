/*
 * ArrayEmployees.c
 *
 *  Created on: 18 sep. 2021
 *      Author: dayher
 */

#include "ArrayEmployees.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "utn.h"

/** \brief 	To indicate that all position in the array are empty,
*			this function put the flag (isEmpty) in TRUE in all
*			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
	if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		list[i].isEmpty=1;
	}
return 0;
}

/*
* \brief 	add in a existing list of employees the values received as parameters
*			in the first empty position
* \param 	list employee*
* \param 	len int
* \param 	id int
* \param 	name[] char
* \param 	lastName[] char
* \param 	salary float
* \param 	sector int
* \return 	int Return (-1) if Error [Invalid length or NULL pointer or without
*			free space] - (0) if Ok
*/
int addEmployee(Employee* list, int len, int id , char name[],char lastName[],float salary,int sector)
{
	if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty){
			list[i].id= id;
			strcpy(list[i].lastName,lastName);
			strcpy(list[i].name,name);
			list[i].salary=salary;
			list[i].sector=sector;
			list[i].isEmpty=0;
			return 0;
		}
	}
return -1;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	if(list==NULL ||len<1 ) return -1;
	for(int i=0; i<len; i++){
		if(list[i].id==id && list[i].isEmpty==0) return i;
	}
return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int index;
	if(list==NULL ||len<1 ) return -1;
	index = findEmployeeById(list, len , id);
	if(index<0)
		return -1;
	list[index].isEmpty=1;
	return 0;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	Employee temp;
	if(list==NULL ||len<1 ) return -1;
	for(int i=1; i<len; i++){
		for(int j=0; j<len-i; j++){
			if((strcmp(list[j].lastName,list[j+1].lastName)*order)>0){
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			} else{
				if(strcmp(list[j].lastName,list[j+1].lastName)==0){
					if(list[j].sector>list[j+1].sector){
						temp=list[j];
						list[j]=list[j+1];
						list[j+1]=temp;
					}
				}
			}
		}
	}
return 0;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int len)
{
	int i, contadorEmpleados=0;
	if(list==NULL ||len<1 ) return -1;
	for(i=0;i<len;i++){
		if(list[i].isEmpty==0){
			contadorEmpleados++;
			printf("\n{id: %04d, salary: %.2f, sector: %02d, lastName: %s, name: %s}\n",list[i].id,list[i].salary,list[i].sector,list[i].lastName,list[i].name);
		}
	}
	printf("\nTotal Empleados: %d\n",contadorEmpleados);
	return 0;
}

int ingresarEmpleado(Employee* list, int len, int newId){
	int sector;
	char name[51];
	char lastName[51];
	float salary;

	getString("Ingrese nombre: ", name);
	getString("Ingrese apellido: ", lastName);
	salary = getFloat("Ingrese salario: ");
	sector = getInt("Ingrese sector: ");

	return addEmployee(list, len, newId, name, lastName, salary, sector);
}

int eliminarEmpleado(Employee* list, int len){
	int id;
	id = getInt("Ingrese id del empleado: ");
	return removeEmployee(list, len, id);
}

int modificarEmpleado(Employee* list, int len){
	int id, index;
	int sector;
	char name[51];
	char lastName[51];
	float salary;

	if(list==NULL ||len<1 ) return -1;

	id = getInt("Ingrese id del empleado: ");
	index = findEmployeeById(list, len, id);
	if(index<0){
		return -1;
	} else {
		getString("Ingrese nombre: ", name);
		getString("Ingrese apellido: ", lastName);
		salary = getFloat("Ingrese salario: ");
		sector = getInt("Ingrese sector: ");
//Esto debería ser otra función guardarDatosEmpleado(Employee * employee, int index, int id, char name[],char lastName[],float salary,int sector);
		strcpy(list[index].lastName,lastName);
		strcpy(list[index].name,name);
		list[index].salary = salary;
		list[index].sector = sector;
		return 0;
	}

	return -1;
}



int mostrarSalarioPromedio(Employee* list, int len){
	int i,contadorEmpleadosSobrePromedio=0, contadorEmpleados=0;
	float salarioPromedio=0, acumuladorSalario=0;

	if(list==NULL ||len<1 ) return -1;

	for(i=0;i<len;i++){
		if(list[i].isEmpty==0){
			contadorEmpleados++;
			acumuladorSalario+=list[i].salary;
			}
	}
	if (contadorEmpleados!=0) {
		salarioPromedio=acumuladorSalario/contadorEmpleados;
		for(i=0;i<len;i++){
				if(list[i].isEmpty==0 && list[i].salary > salarioPromedio){
					contadorEmpleadosSobrePromedio++;
				}
			}
		printf("\nTotal Salarios: %.2f\tSalario Promedio: %.2f\tEmpleados que superan el salario promedio: %d\n",acumuladorSalario,salarioPromedio,contadorEmpleadosSobrePromedio);
	}
	printf("\nTotal Empleados: %d\n",contadorEmpleados);

	return 0;
}

int ordenarEmpleadosApellidoSector(Employee* list, int len){
	int order;

	if(list==NULL ||len<1 ) return -1;

	order = getInt("\nIngrese orden: (1) --> A-Z  ó (-1) -->  Z-A\t:");

	return sortEmployees(list,len,order);
}









