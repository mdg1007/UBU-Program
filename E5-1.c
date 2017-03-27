/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E5-1.c
*
* DESCRIPTION :
*   Shows different propierties for a given file formatted file
*
* NOTES :
*   This program is the solution to the proposed exercise
*   in the seventh week of the course 'Programación'
*   (programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz	    START DATE : 27 Mar 2017
*
* CHANGES:
* 1.0 [27MAR2017] - Initial release
*/

#include <stdio.h>
#include <math.h>

int requestMenuOption();
void selectOption(int , FILE *);
int nRows(FILE *);
int nColumns(FILE *);
int nChars(FILE *);
int rowMax(FILE *);
void printRow(FILE *);
void printFile(FILE *);
int clean_stdin();

int main() {
  int selectedOption;
  do {
    FILE *f;
    f=fopen("car.txt", "r");
    
    if(f!=NULL){
      selectedOption = requestMenuOption();
    }
    else{
      selectedOption = 0;
      printf("ERROR READING FILE\n");
    }
    selectOption(selectedOption, f);
  } while (selectedOption != 0);
  return 0;
}


int clean_stdin(){
  while(getchar() != '\n');
  return 1;
}

int requestMenuOption(){
  int option, read;
  char enter;
  printf("******************************\n");
  printf("*      SELECT AN OPTION      *\n");
  printf("*----------------------------*\n");
  printf("*  0.- End Execution         *\n");
  printf("*  1.- Number of Rows        *\n");
  printf("*  2.- Number of Columns     *\n");
  printf("*  3.- Number of Characters  *\n");
  printf("*  4.- Longest Row           *\n");
  printf("*  5.- Print Row             *\n");
  printf("*  6.- Print File            *\n");
  printf("******************************\n");
  while(1){
    printf("Insert option number: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
    }
    else if (option<0 || option>6){
      printf("Value out of range, please try again.\n");
    }
    else {
      return option;
    }
  }
}

void selectOption(int option, FILE *f){
  switch (option){
    case 0:
      break;
    case 1:
      printf("Total number of rows: %d\n\n", nRows(f));
      break;
    case 2:
      printf("Total number of columns: %d\n\n", nColumns(f));
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
  }
}

int nRows(FILE *f){
  char c;
  int rowNum = 0;
  while(!feof(f)){
    c=fgetc(f);
    if(c=='\n'){
      ++rowNum;
      c=fgetc(f);
    }
  }
  return rowNum;
}

int nColumns(FILE *f){
  char c;
  int colNum=0;
  while(!feof(f)){
    c=fgetc(f);
    if(c==','){
      ++colNum;
      c=fgetc(f);
    }
    if(c=='\n'){
      c=fgetc(f);
    }
  }
  return colNum;
}
