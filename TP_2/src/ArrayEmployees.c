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
int addEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector)
{
	if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty){
			list[i].id=i+1;
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
		if(list[i].id==id) return i;
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
	if(list==NULL ||len<1 ) return -1;
		for(int i=0; i<len; i++){
			if(list[i].id==id) {
				list[i].isEmpty=1;
				return 0;
			}
		}
return -1;
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
			if(strcmp(list[j].lastName,list[j+1].lastName)>0){
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
	if(list==NULL ||len<1 ) return -1;
	for(int i=0;i<len;i++){
		printf("{id: %04d, salary: %.2f, sector: %02d, lastName: %s, name: %s}\n",list[i].id,list[i].salary,list[i].sector,list[i].lastName,list[i].name);
	}
	return 0;
}
