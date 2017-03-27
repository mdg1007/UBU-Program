/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E5-1.c
*
* DESCRIPTION :
*		Shows different propierties for a given file formatted file
*
* NOTES :
*		This program is the solution to the proposed exercise
*		in the seventh week of the course 'Programación'
*   (programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz			START DATE : 27 Mar 2017
*
* CHANGES:
* 1.0 [27MAR2017] - Initial release
*/

#include <stdio.h>
#include <math.h>

int requestMenuOption();
void selectOption(int );
int nRows(FILE *);
int nColumns(FILE *);
int nChars(FILE *);
int rowMax(FILE*);
void printRow(FILE *);
void printFile(FILE*);
int clean_stdin();

int main(){
  int n1, n2;
  n1 = getNumber();
  n2 = getNumber();
  printResult(compare(addDivisors(n1),n2), n1, n2);
  return 0;
}


int clean_stdin(){
  while(getchar() != '\n');
  return 1;
}

int getNumber(){
  int n1, leidos;
  char enter;
  while(1){
    printf("Insert whole integer: ");
    leidos = scanf("%d%c",&n1,&enter);
    if(leidos != 2 || enter != '\n' || n1<0){
      printf("Incorrect value, try again\n");
    clean_stdin();
    }else{
      return n1;
    }
  }
}

int addDivisors(int n1){
  int result = 0, index = 1;
  for (index; index < n1; index++ ){
    if ( n1%index == 0){
      result += index;
    }
  }
  return result;
}

_Bool compare(int n1, int n2){
  if(n1 == n2){
    return 1;
  }else{
    return 0;
  }
}

void printResult(_Bool comparison, int n1, int n2){
  if(comparison){
    printf("%d y %d are amicable numbers\n", n1, n2);
  }else{
    printf("%d y %d aren't amicable numbers\n", n1, n2);
  }
}
