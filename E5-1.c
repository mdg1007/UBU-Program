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
* 1.0 [29MAR2017] - Initial release
*/

#include <stdio.h>
#include <math.h>

int requestMenuOption();
void selectOption(int);
int nRows();
int nColumns();
int nChars();
int rowMax();
void printRow();
void printFile();
int clean_stdin();

int main() {
  int selectedOption;
  do {
    FILE *f;
    f = fopen("car.txt", "r");
    if (f!=NULL) {
      selectedOption = requestMenuOption();
    }
    else {
      selectedOption = 0;
      printf("ERROR READING FILE\n");
    }
    fclose(f);
    selectOption(selectedOption);
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
  while (1) {
    printf("Insert option number: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 6) {
      printf("Value out of range, please try again.\n");
    }
    else {
      return option;
    }
  }
}

void selectOption(int option) {
  switch (option) {
    case 0:
      break;
    case 1:
      printf("Total number of rows: %d\n\n", nRows());
      break;
    case 2:
      printf("Total number of columns: %d\n\n", nColumns());
      break;
    case 3:
      printf("Total number of characters: %d\n\n", nChars());
      break;
    case 4:
      printf("Longest row: %d\n\n", rowMax());
      break;
    case 5:
      printRow();
      break;
    case 6:
      printFile();
      break;
  }
}

int nRows() {
  char c;
  int rowNum = 0;
  FILE *f;
  f = fopen("car.txt", "r");
  c = fgetc(f);
  while (!feof(f)) {
    if (c == '\n') {
      ++rowNum;
      c = fgetc(f);
    }
    else {
      c = fgetc(f);
      if (feof(f))
        ++rowNum;
    }
  }
  fclose(f);
  return rowNum;
}

int nColumns() {
  char c;
  int colNum = 0;
  FILE *f;
  f = fopen("car.txt", "r");
  c = fgetc(f);
  while (!feof(f)) {
    if (c == ',' || c == '\n') {
      ++colNum;
      c = fgetc(f);
    }
    else {
      c = fgetc(f);
      if (feof(f)) {
        ++colNum;
      }
    }
  }
  fclose(f);
  return colNum;
}

int nChars() {
  char c;
  int charNum=0;
  FILE *f;
  f = fopen("car.txt", "r");
  c = fgetc(f);
  while (!feof(f)) {
    ++charNum;
    c = fgetc(f);
  }
  fclose(f);
  return charNum;
}

int rowMax() {
  char c;
  int tempMax = 0, currentRowCount = 0, currentRowPos = 0, tempMaxPos = 0;
  FILE *f;
  f = fopen("car.txt", "r");
  while (!feof(f)) {
    c = fgetc(f);
    if (c == '\n' || feof(f)) {
      ++currentRowPos;
      if (currentRowCount > tempMax) {
        tempMax = currentRowCount;
        tempMaxPos = currentRowPos;
      }
      currentRowCount = 0;
    }
    else {
      ++currentRowCount;
    }
  }
  fclose(f);
  return tempMaxPos;
}

void printRow() {
  FILE *f;
  f = fopen("car.txt", "r");
  int rowSelected = -1, rowNum = nRows(f), read, currentRowCount = 0;
  char enter, c;
  while (rowSelected < 1) {
    printf("Insert row number to print: ");
    read = scanf("%d%c",&rowSelected,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
      rowSelected=-1;
    }
    else if (rowSelected < 1 || rowSelected > rowNum) {
      printf("Value out of range, please try again.\n");
      rowSelected=-1;
    }
  }
  fclose(f);
  f = fopen("car.txt", "r");
  while (!feof(f) && currentRowCount < rowSelected - 1) {
    if (c == '\n') {
      ++currentRowCount;}
    c = fgetc(f);
  }
  while (!feof(f) && c != '\n') {
    putchar(c);
    c = fgetc(f);
  }
  fclose(f);
  printf("\n\n");
}

void printFile() {
  FILE *f;
  char c;
  f = fopen("car.txt", "r");
  printf("---- FILE CONTENTS ----\n");
  c = fgetc(f);
  do {
    putchar(c);
    c = fgetc(f);
  } while (!feof(f));
  fclose(f);
  printf("\n-----------------------\n\n");
}
