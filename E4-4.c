/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	E4-4.c
*
* DESCRIPCIÓN :
*		Pide dos numeros y dice si son numeros amigos o no.
*
* NOTAS :
*		Este programa resuelve la segunda parte de la cuarta
*		práctica de la asignatura Programación de UBU.
*
* AUTOR : Rodrigo Díaz			FECHA INICIAL : 20 Mar 2017
*
* CAMBIOS:
* 1.0 [20MAR2017] - Versión inicial
*/

#include <stdio.h>
#include <math.h>

int clean_stdin();
int capturaNumero();
int sumaDivisores(int);
_Bool compara(int, int);
void escribeResultado(_Bool, int, int);

int main(){
  int n1, n2;
  n1 = capturaNumero();
  n2 = capturaNumero();
  escribeResultado(compara(sumaDivisores(n1),n2), n1, n2);
  return 0;
}


int clean_stdin(){
  while(getchar() != '\n');
  return 1;
}

int capturaNumero(){
  int n1, leidos;
  char enter;
  while(1){
    printf("Introduce un numero positivo: ");
    leidos = scanf("%d%c",&n1,&enter);
    if(leidos != 2 || enter != '\n' || n1<0){
      printf("Valor incorrecto \n");
    clean_stdin();
    }else{
      return n1;
    }
  }
}

int sumaDivisores(int n1){
  int resultado = 0, indice = 1;
  for (indice; indice < n1; indice++ ){
    if ( n1%indice == 0){
      resultado += indice;
    }
  }
  return resultado;
}

_Bool compara(int n1, int n2){
  if(n1 == n2){
    return 1;
  }else{
    return 0;
  }
}

void escribeResultado(_Bool comparacion, int n1, int n2){
  if(comparacion){
    printf("%d y %d son numeros amigos\n", n1, n2);
  }else{
    printf("%d y %d no son numeros amigos\n", n1, n2);
  }
}
