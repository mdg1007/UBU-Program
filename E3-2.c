/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	E3-2.c
*
* DESCRIPCIÓN :
*		Pide una cantidad de segundos e imprime el equivalente
*		en horas, minutos y segundos.
*
* FUNCIONES PÚBLICAS :
*		int Apartado1( segundos )
*		int Apartado2( segundos )
*		int Apartado3( segundos )
*		int Apartado4( segundos )
*
* NOTAS :
*		Este programa resuelve la segunda parte de la tercera
*		práctica de la asignatura Programación de UBU.
*
* AUTOR : Rodrigo Díaz			FECHA INICIAL : 1 Mar 2017
*
* CHANGES:
* 1.1 [01MAR2017] - Eliminada redundancia
* 1.0 [01MAR2017] - Versión inicial
*/

#include <stdio.h>

int Apartado1(int);
int Apartado2(int);
int Apartado3(int);
int Apartado4(int);
int Apartado2Horas(int);
int Apartado2Minutos(int);
int Apartado2Segundos(int);
int Apartado3Horas(int *);
int Apartado3Minutos(int *);
int Apartado3Segundos(int *);
void Apartado4Horas(int);
void Apartado4Minutos(int);
void Apartado4Segundos(int);

int main(){
  int segundos;
  printf("Inserte segundos: ");
  scanf("%d", &segundos);
  Apartado1(segundos);
  Apartado2(segundos);
  Apartado3(segundos);
  Apartado4(segundos);
  return 0;
}

int Apartado1(int segundos){
  printf("\n1.- %d horas, %d minutos y %d segundos",segundos/3600,segundos%3600/60,segundos%60);
  return 0;
}


int Apartado2(int segundos){
  printf("\n2.- %d horas, %d minutos y %d segundos", Apartado2Horas(segundos), Apartado2Minutos(segundos), Apartado2Segundos(segundos));
  return 0;
}

int Apartado2Horas(int segundos){
  return segundos/3600;
}

int Apartado2Minutos(int segundos){
  return segundos%3600/60;
}

int Apartado2Segundos(int segundos){
  return segundos%60;
}


int Apartado3(int segundos){
  printf("\n3.- %d horas, %d minutos y %d segundos", Apartado3Horas(&segundos), Apartado3Minutos(&segundos), Apartado3Segundos(&segundos));
  return 0;
}

int Apartado3Horas(int *segundos){
  return *segundos/3600;
}

int Apartado3Minutos(int *segundos){
  return *segundos%3600/60;
}

int Apartado3Segundos(int *segundos){
  return *segundos%60;
}


int Apartado4(int segundos){ 
  Apartado4Horas(segundos);
  Apartado4Minutos(segundos);
  Apartado4Segundos(segundos);
  return 0;
}

void Apartado4Horas(int segundos){
  printf("\n4.- %d horas, ", segundos/3600);
}

void Apartado4Minutos(int segundos){
  printf("%d minutos y ", segundos%3600/60);
}

void Apartado4Segundos(int segundos){
  printf("%d segundos\n", segundos%60);
}
