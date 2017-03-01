/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	E3-3.c
*
* DESCRIPCIÓN :
*		Pide un número de 4 dígitos e imprime cada
*		dígito individualmente.
*
* FUNCIONES PÚBLICAS :
*		int Apartado1( numero )
*		int Apartado2( numero )
*		int Apartado3( numero )
*		int Apartado4( numero )
*
* NOTAS :
*		Este programa resuelve la tercera parte de la tercera
*		práctica de la asignatura Programación de UBU.
*
* AUTOR : Rodrigo Díaz			FECHA INICIAL : 1 Mar 2017
*
* CAMBIOS:
* 1.0 [01MAR2017] - Versión inicial
*/

#include <stdio.h>

int Apartado1(int);
int Apartado2(int);
int Apartado3(int);
int Apartado4(int);

int Apartado2Primero(int);
int Apartado2Segundo(int);
int Apartado2Tercero(int);
int Apartado2Cuarto(int);

int Apartado3Primero(int *);
int Apartado3Segundo(int *);
int Apartado3Tercero(int *);
int Apartado3Cuarto(int *);

void Apartado4Primero(int);
void Apartado4Segundo(int);
void Apartado4Tercero(int);
void Apartado4Cuarto(int);

int main(){
  int numero;
  printf("Insertar un número entre 1000 y 9999: ");
  scanf("%d", &numero);
  numero%=10000;
  Apartado1(numero);
  Apartado2(numero);
  Apartado3(numero);
  Apartado4(numero);
  return 0;
}

int Apartado1(int numero){
  printf("\n1.- | %d | %d | %d | %d |",numero/1000,numero%1000/100,numero%100/10,numero%10);
  return 0;
}


int Apartado2(int numero){
  printf("\n2.- | %d | %d | %d | %d |", Apartado2Primero(numero), Apartado2Segundo(numero), Apartado2Tercero(numero), Apartado2Cuarto(numero));
  return 0;
}

int Apartado2Primero(int numero){
  return numero/1000;
}

int Apartado2Segundo(int numero){
  return numero%1000/100;
}

int Apartado2Tercero(int numero){
  return numero%100/10;
}

int Apartado2Cuarto(int numero){
  return numero%10;
}


int Apartado3(int numero){
  printf("\n3.- | %d | %d | %d | %d |", Apartado3Primero(&numero), Apartado3Segundo(&numero), Apartado3Tercero(&numero), Apartado3Cuarto(&numero));
  return 0;
}

int Apartado3Primero(int *numero){
  return *numero/1000;
}

int Apartado3Segundo(int *numero){
  return *numero%1000/100;
}

int Apartado3Tercero(int *numero){
  return *numero%100/10;
}

int Apartado3Cuarto(int *numero){
  return *numero%10;
}

int Apartado4(int numero){ 
  Apartado4Primero(numero);
  Apartado4Segundo(numero);
  Apartado4Tercero(numero);
  Apartado4Cuarto(numero);
  return 0;
}

void Apartado4Primero(int numero){
  printf("\n4.- | %d |", numero/1000);
}

void Apartado4Segundo(int numero){
  printf(" %d |", numero%1000/100);
}

void Apartado4Tercero(int numero){
  printf(" %d |", numero%100%10);
}

void Apartado4Cuarto(int numero){
  printf(" %d |\n", numero%10);
}
