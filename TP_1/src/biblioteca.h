/*
 * biblioteca.h
 *
 *  Created on: 1 sep. 2021
 *      Author: dayher
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_



#endif /* BIBLIOTECA_H_ */

double sumar(double a, double b);
double restar(double a, double b);
double multiplicar(double a, double b);
double dividir(double a, double b);
unsigned long factorial(unsigned n);

void mostrarMenu(double primero, double segundo);
void mostrarResultados(	double primero, double segundo ,
						double suma, double resta, double producto, double cociente,
						unsigned long factorial1, unsigned long factorial2);
void calcularResultados(double primero, double segundo ,
						double *suma, double *resta, double *producto, double *cociente,
						unsigned long *factorial1, unsigned long *factorial2);
