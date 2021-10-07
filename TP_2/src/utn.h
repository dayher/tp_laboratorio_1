/*
 * utn.h
 *
Version: 0.1 del 01 enero de 2016
Autor: Mauricio Dávila
Revisión: Ernesto Gigliotti
 */

#ifndef UTN_H_
#define UTN_H_



#endif /* UTN_H_ */


int getInt(char mensaje[]);
float getFloat(char mensaje[]);
char getChar(char mensaje[]);

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char str[]) ;
int esTelefono(char str[]);
int esAlfaNumerico(char str[]);
int esSoloLetras(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
