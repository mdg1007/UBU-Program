/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	E3-1es.c
*
* DESCRIPCIÓN :
*		Pide un radio e imprime de 4 maneras distintas perimetro y area del circulo
*		con el radio especificado.
*
* FUNCIONES PÚBLICAS :
*		int Apartado1( radio )
*		int Apartado2( radio )
*		int Apartado3( radio )
*		int Apartado4( radio )
*
* NOTAS :
*		Este programa resuelve el ejercicio 1 de la tercera
*		práctica de la asignatura Programación de UBU.
*
* AUTOR : Rodrigo Díaz			FECHA INICIAL : 23 Feb 2017
*
* CAMBIOS:
* 1.0 [23FEB2017] - Versión inicial
*/

#define PI 3.141592
#include <stdio.h>

int Apartado1(float);
int Apartado2(float);
int Apartado3(float);
int Apartado4(float);
float Apartado2Perim(float);
float Apartado2Area(float);
float Apartado3Perim(float *);
float Apartado3Area(float *);
void Apartado4Perim(float);
void Apartado4Area(float);

int main(){
  float radio;
  printf("Inserte valor del radio: ");
  scanf("%g", &radio);
  Apartado1(radio);
  Apartado2(radio);
  Apartado3(radio);
  Apartado4(radio);
  return 0;
}

int Apartado1(float radio){
  printf("\n1.- El perimetro es: %.2f, el area es: %.2f\n", 2*PI*radio, PI*radio*radio);
  return 0;
}


int Apartado2(float radio){
  printf("\n2.- El perimetro es: %.2f, el area es: %.2f\n", Apartado2Perim(radio), Apartado2Area(radio));
  return 0;
}

float Apartado2Perim(float radio){
  return radio * 2 * PI;
}

float Apartado2Area(float radio){
  return radio * radio * PI;
}


int Apartado3(float radio){
  printf("\n3.- El perimetro es: %.2f, el area es: %.2f\n", Apartado3Perim(&radio), Apartado3Area(&radio));
  return 0;
}

float Apartado3Perim(float *radio){
  return (*radio) * 2 * PI;
}

float Apartado3Area(float *radio){
 return (*radio) * (*radio) * PI;
}


int Apartado4(float radio){
  Apartado4Perim(radio);
  Apartado4Area(radio);
  return 0;
}

void Apartado4Perim(float radio){
  printf("\n4.- El perimetro es %.2f", radio * 2 * PI);
}

void Apartado4Area(float radio){
  printf(", el area es: %.2f.\n", radio * radio * PI);
}
