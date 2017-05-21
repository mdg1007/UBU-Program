/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	Final.c
*
* DESCRIPTION :
*   Do certain operations on a given file
*
* NOTES :
*   This program is the solution to the proposed exercise
*   in the final week of the course 'Programación'
*   (programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz	    START DATE : 21 May 2017
*
* CHANGES:
* 1.0 [21MAY2017] - Initial release
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "car.txt"
#define MAX1 6
#define MAX2 6
#define MAX3 5
#define MAX4 5
#define MAX5 6
#define MAX6 5

struct car {
  char buying[MAX1];
  char maint[MAX2];
  char doors[MAX3];
  char persons[MAX4];
  char lug_boot[MAX5];
  char safety[MAX6];
  int class_value;
};
typedef struct {
  struct car nomap;
} cars;

int requestMenuOption();
void selectOption(int);
int nRows(FILE *);
int nColumns(FILE *);
int nChars(FILE *);
int rowMax(FILE *);
void printRow(FILE *);
void printFile(FILE *);
void newRow(FILE *);
void fileWriteMenu(int, cars[]);
void writeTXT(cars[], int);
void writeBIN(cars[], int);
int loadRegister(FILE *);
int modifyClassValue(cars[], int, int);
int clean_stdin();

int main() {
  int selectedOption;
  do {
    FILE *f;
    f = fopen(FILENAME, "r");
    if (f!=NULL) {
      selectedOption = requestMenuOption();
      fclose(f);
      selectOption(selectedOption);
    }
    else {
      selectedOption = 0;
      printf("ERROR READING FILE\n");
    }
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
  printf("*  7.- New Row               *\n");
  printf("*  8.- Modify Class Value    *\n");
  printf("******************************\n");
  while (1) {
    printf("Insert option number: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 8) {
      printf("Value out of range, please try again.\n");
    }
    else {
      return option;
    }
  }
}

void selectOption(int option) {
  FILE *f;
  switch (option) {
    case 0:
      break;
    case 1:
      f = fopen(FILENAME, "r");
      printf("Total number of rows: %d\n\n", nRows(f));
      fclose(f);
      break;
    case 2:
      f = fopen(FILENAME, "r");
      printf("Total number of columns: %d\n\n", nColumns(f));
      fclose(f);
      break;
    case 3:
      f = fopen(FILENAME, "r");
      printf("Total number of characters: %d\n\n", nChars(f));
      fclose(f);
      break;
    case 4:
      f = fopen(FILENAME, "r");
      printf("Longest row: %d\n\n", rowMax(f));
      fclose(f);
      break;
    case 5:
      f = fopen(FILENAME, "r");
      printRow(f);
      fclose(f);
      break;
    case 6:
      f = fopen(FILENAME, "r");
      printFile(f);
      fclose(f);
      break;
    case 7:
      f = fopen(FILENAME, "a");
      newRow(f);
      fclose(f);
      break;
    case 8:
      f = fopen(FILENAME, "r");
      printf("Rows loaded: %d\n\n", loadRegister(f));
      fclose(f);
      break;
  }
}

int nRows(FILE *f) {
  char c;
  int rowNum = 0;
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
  rewind(f);
  return rowNum;
}

int nColumns(FILE *f) {
  char c;
  int colNum = 0;
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
  return colNum;
}

int nChars(FILE *f) {
  int charNum=0;
  fgetc(f);
  while (!feof(f)) {
    ++charNum;
    fgetc(f);
  }
  return charNum;
}

int rowMax(FILE *f) {
  char c;
  int tempMax = 0, currentRowCount = 0, currentRowPos = 0, tempMaxPos = 0;
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
  return tempMaxPos;
}

void printRow(FILE *f) {
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
  rewind(f);
  while (!feof(f) && currentRowCount < rowSelected - 1) {
    if (c == '\n') {
      ++currentRowCount;}
    c = fgetc(f);
  }
  while (!feof(f) && c != '\n') {
    putchar(c);
    c = fgetc(f);
  }
  printf("\n\n");
}

void printFile(FILE *f) {
  char c;
  printf("---- FILE CONTENTS ----\n");
  c = fgetc(f);
  do {
    putchar(c);
    c = fgetc(f);
  } while (!feof(f));
  printf("\n-----------------------\n\n");
}

void newRow(FILE *f) {
  char buying[MAX1], maint[MAX2], doors[MAX3], persons[MAX4], lug_boot[MAX5], safety[MAX6];
  do {
    printf("Insert value buying: ");
    scanf("%s", buying);
  } while (strlen(buying)>MAX1);
  do {
    printf("Insert value maint: ");
    scanf("%s", maint);
  } while (strlen(maint)>MAX2);
  do {
    printf("Insert value doors: ");
    scanf("%s", doors);
  } while (strlen(doors)>MAX3);
  do {
    printf("Insert value persons: ");
    scanf("%s", persons);
  } while (strlen(persons)>MAX4);
  do {
    printf("Insert value lug_boot: ");
    scanf("%s", lug_boot);
  } while (strlen(lug_boot)>MAX5);
  do {
    printf("Insert value safety: ");
    scanf("%s", safety);
  } while (strlen(safety)>MAX6);
  fprintf(f, "%s,%s,%s,%s,%s,%s,-1", buying, maint, doors, persons, lug_boot, safety);
  printf("Appended to file: %s,%s,%s,%s,%s,%s,-1\n", buying, maint, doors, persons, lug_boot, safety);
}

int loadRegister(FILE *f) {
  int numRows = nRows(f), i, modified=0, notModified=0;
  cars car[numRows];
  for (i=0; i<numRows; i++) {
    fscanf(f, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%d\r\n", car[i].nomap.buying, car[i].nomap.maint, car[i].nomap.doors, car[i].nomap.persons, car[i].nomap.lug_boot, car[i].nomap.safety, &car[i].nomap.class_value);
    if (car[i].nomap.class_value == -1) {
      if (modifyClassValue(car, i, numRows)==1) {
        modified++;
      } else {
        notModified++;
      }
    }
  }
  printf("# of Rows modified: %d\n", modified);
  printf("# of Rows not modified: %d\n", notModified);
  fileWriteMenu(numRows, car);
  return sizeof(car)/sizeof(car[0]);
}

int modifyClassValue(cars *car, int i, int numRows) {
  int j;
  bool modified=false;
  for (j=0; j<numRows && !modified; j++) {
    if (j!=i && strcmp(car[j].nomap.buying,car[i].nomap.buying)==0 && strcmp(car[j].nomap.maint,car[i].nomap.maint)==0 && strcmp(car[j].nomap.doors,car[i].nomap.doors)==0 && strcmp(car[j].nomap.persons,car[i].nomap.persons)==0 && strcmp(car[j].nomap.lug_boot,car[i].nomap.lug_boot)==0 && strcmp(car[j].nomap.safety,car[i].nomap.safety)==0 && car[j].nomap.class_value!=-1) {
      car[i].nomap.class_value=car[j].nomap.class_value;
      modified=1;
    }
  }
  if (modified) {
    printf("Modified row %d: ", i);
  } else {
    printf("Unmodified row %d: ", i);
  }
  printf("<%s,%s,%s,%s,%s,%s,%d>\n", car[i].nomap.buying, car[i].nomap.maint, car[i].nomap.doors, car[i].nomap.persons, car[i].nomap.lug_boot, car[i].nomap.safety, car[i].nomap.class_value);
  return modified;
}

void fileWriteMenu(int numRows, cars *car){
  int option, read;
  bool valid=false;
  char enter;
  printf("******************************\n");
  printf("*        WRITE TO FILE       *\n");
  printf("*----------------------------*\n");
  printf("*  0.- Cancel                *\n");
  printf("*  1.- Write to .txt         *\n");
  printf("*  2.- Write to .bin         *\n");
  printf("*  3.- Write to both         *\n");
  printf("******************************\n");
  while (!valid) {
    printf("Insert option number: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Incorrect value, please try again.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 3) {
      printf("Value out of range, please try again.\n");
    } else {
      valid=true;
    }
  }
  switch (option) {
    case 1:
      writeTXT(car, numRows);
      break;
    case 2:
      writeBIN(car, numRows);
      break;
    case 3:
      writeTXT(car, numRows);
      writeBIN(car, numRows);
      break;
  }
}

void writeTXT(cars *car, int numRows){
  FILE *f;
  int i, read;
  char filename[10], extension[3], dot;
  bool valid=false;
  while (!valid) {
    printf("Insert filename: ");
    read = scanf("%[^.\n]%c%s", filename, &dot, extension);
    if(read != 3 || dot != '.'){
      printf("Incorrect input, please try again.\n");
      clean_stdin();
    }
    else if (strcmp(extension,"txt")!=0) {
      printf("Incorrect extension, please try again.\n");
    } else {
      strcat(filename, &dot);
      strcat(filename, extension);
      valid=true;
    }
  }
  f=fopen(filename,"w");
  for (i=0; i<numRows; i++) {
    fprintf(f, "%s,%s,%s,%s,%s,%s,%d\n", car[i].nomap.buying, car[i].nomap.maint, car[i].nomap.doors, car[i].nomap.persons, car[i].nomap.lug_boot, car[i].nomap.safety, car[i].nomap.class_value);
  }
  fclose(f);
}

void writeBIN(cars *car, int numRows){
  FILE *f;
  int i, read;
  char filename[10], extension[3], dot;
  bool valid=false;
  while (!valid) {
    printf("Insert filename: ");
    read = scanf("%[^.\n]%c%s", filename, &dot, extension);
    if(read != 3 || dot != '.'){
      printf("Incorrect input, please try again.\n");
      clean_stdin();
    }
    else if (strcmp(extension,"bin")!=0) {
      printf("Incorrect extension, please try again.\n");
    } else {
      strcat(filename, &dot);
      strcat(filename, extension);
      valid=true;
    }
  }
  f=fopen(filename,"w");
  for (i=0; i<numRows; i++) {
    fprintf(f, "%s,%s,%s,%s,%s,%s,%d\n", car[i].nomap.buying, car[i].nomap.maint, car[i].nomap.doors, car[i].nomap.persons, car[i].nomap.lug_boot, car[i].nomap.safety, car[i].nomap.class_value);
  }
  fclose(f);
}
