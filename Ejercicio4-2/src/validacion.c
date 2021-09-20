/*
 * validacion.c
 *
 *  Created on: 31 ago. 2021
 *      Author: dayher
 */
#include "validacion.h"

int validarCelsius (float temperatura){
	if(temperatura>MAYOR_CELSIUS && temperatura<MENOR_CELSIUS) return 1;
	return 0;
}
int validarFahrenheit (float temperatura){
	if(temperatura>MAYOR_FAHRENHEIT && temperatura<MENOR_FAHRENHEIT) return 1;
		return 0;
}
