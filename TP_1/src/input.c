#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "input.h"

/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 *
 */
double getDouble(char mensaje[])
{
    double retorno;
    char input[256];
    int flag = 0;

    do{
    	getString(mensaje,input);
    	if (isFloat(input)){
    		sscanf(input,"%lf",&retorno);
    		flag = 1;
    	}
    } while(flag==0);

    return retorno;
}

float getFloat(char mensaje[],float min , float max)
{
    float auxiliar;
    char input[256];

    auxiliar = max+1.1;

    do{
    	getString(mensaje,input);
    	if (isFloat(input))sscanf(input,"%f",&auxiliar);
    } while(auxiliar>max || auxiliar<min);

    return auxiliar;
}


/**
 * \brief Solicita un n?mero al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El n?mero ingresado por el usuario
 *
 */
int getInt(char mensaje[],int min,int max)
{
	int auxiliar;
	char input[256];

	auxiliar = max+1;

	do{
		getString(mensaje,input);
		if(isInt(input))
			auxiliar=atoi(input);
	}
	while(auxiliar>max || auxiliar<min );

	return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es flotante
 * \param str Array con la cadena a ser analizada
 * \return 1 si es flotante y 0 si no lo es
 *
 */
int isFloat(char str[]){
	int i=0;
   while(str[i] != '\0')
   {
	   if((str[i] < '0' || str[i] > '9') && str[i]!='.' && str[i]!='-')
		   return 0;
	   i++;
   }
   return 1;
}

/**
* \brief Verifica si el valor recibido es entero
* \param str Array con la cadena a ser analizada
* \return 1 si es entero y 0 si no lo es
*
*/

int isInt(char str[])
{
 int i=0;
 while(str[i] != '\0')
 {
  if((str[i] < '0' || str[i] > '9') && str[i]!='-')
	  return 0;
  i++;
 }
 return 1;
}


/**
 * \brief Verifica si el valor recibido es num?rico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es n?merico y 0 si no lo es
 *
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
	size_t i = 0;
	char c;

	fflush(stdin);
    printf("%s",mensaje);
    fflush(stdout);
    while((c = getchar()) !=EOF && c!='\n' && i<256){
    	input[i++]=c;
    }
    input[i]='\0';
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto num?rico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargar? el texto ingresado
 * \return 1 si el texto contiene solo n?meros
 */
int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
