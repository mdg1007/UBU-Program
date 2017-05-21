/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	Final.c
*
* DESCRIPCIÓN :
*   Do certain operations on a given file
*
* NOTAS :
*   This program is the solution to the proposed exercise
*   in the final week of the course 'Programación'
*   (programming) of Burgos University.
*
* AUTOR : Rodrigo Díaz	    FECHA INICIAL : 21 May 2017
*
* CAMBIOS:
* 1.0 [21MAY2017] - Versión inicial
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

typedef struct cars {
  char buying[MAX1];
  char maint[MAX2];
  char doors[MAX3];
  char persons[MAX4];
  char lug_boot[MAX5];
  char safety[MAX6];
  int class_value;
} cars;

int solicitaOpcionMenu();
void seleccionaOpcion(int);
int numeroFilas(FILE *);
int numeroCols(FILE *);
int numeroChar(FILE *);
int fileMax(FILE *);
void imprimeFila(FILE *);
void imprimeFile(FILE *);
void altaNuevaFila(FILE *);
void menuEscrituraFiles(int, cars[]);
void escrituraTxt(cars[], int);
void escrituraBin(cars[], int);
int cargaRegistro(FILE *);
int modificaClassValue(cars[], int, int);
int clean_stdin();

int main() {
  int selectedOption;
  do {
    FILE *f;
    f = fopen(FILENAME, "r");
    if (f!=NULL) {
      selectedOption = solicitaOpcionMenu();
      fclose(f);
      seleccionaOpcion(selectedOption);
    }
    else {
      selectedOption = 0;
      printf("ERROR LEYENDO ARCHIVO\n");
    }
  } while (selectedOption != 0);
  return 0;
}

int clean_stdin(){
  while(getchar() != '\n');
  return 1;
}

int solicitaOpcionMenu(){
  int option, read;
  char enter;
  printf("*********************************************************\n");
  printf("*                   SELECCIONAR OPCION                  *\n");
  printf("*-------------------------------------------------------*\n");
  printf("*  0.- Finalizar Ejecucion                              *\n");
  printf("*  1.- Numero de Filas del Fichero                      *\n");
  printf("*  2.- Numero de Columnas del Fichero                   *\n");
  printf("*  3.- Numero de Caracteres del Fichero                 *\n");
  printf("*  4.- Fila mas larga                                   *\n");
  printf("*  5.- Imprime Fila                                     *\n");
  printf("*  6.- Imprime Fichero                                  *\n");
  printf("*  7.- Alta nueva fila                                  *\n");
  printf("*  8.- Cargar en registro y asignar Valor a class_value *\n");
  printf("*********************************************************\n");
  while (1) {
    printf("Inserta numero de opcion: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Valor incorrecto, prueba de nuevo.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 8) {
      printf("Valor fuera de rango, prueba de nuevo.\n");
    }
    else {
      return option;
    }
  }
}

void seleccionaOpcion(int option) {
  FILE *f;
  switch (option) {
    case 1:
      f = fopen(FILENAME, "r");
      printf("Numero total de filas: %d\n\n", numeroFilas(f));
      fclose(f);
      break;
    case 2:
      f = fopen(FILENAME, "r");
      printf("Numero total de columnas: %d\n\n", numeroCols(f));
      fclose(f);
      break;
    case 3:
      f = fopen(FILENAME, "r");
      printf("Numero total de caracteres: %d\n\n", numeroChar(f));
      fclose(f);
      break;
    case 4:
      f = fopen(FILENAME, "r");
      printf("Fila mas larga: %d\n\n", fileMax(f));
      fclose(f);
      break;
    case 5:
      f = fopen(FILENAME, "r");
      imprimeFila(f);
      fclose(f);
      break;
    case 6:
      f = fopen(FILENAME, "r");
      imprimeFile(f);
      fclose(f);
      break;
    case 7:
      f = fopen(FILENAME, "a");
      altaNuevaFila(f);
      fclose(f);
      break;
    case 8:
      f = fopen(FILENAME, "r");
      printf("Filas cargadas: %d\n\n", cargaRegistro(f));
      fclose(f);
      break;
  }
}

int numeroFilas(FILE *f) {
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

int numeroCols(FILE *f) {
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

int numeroChar(FILE *f) {
  int charNum=0;
  fgetc(f);
  while (!feof(f)) {
    ++charNum;
    fgetc(f);
  }
  return charNum;
}

int fileMax(FILE *f) {
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

void imprimeFila(FILE *f) {
  int rowSelected = -1, rowNum = numeroFilas(f), read, currentRowCount = 0;
  char enter, c;
  while (rowSelected < 1) {
    printf("Inserta numero fila a imprimir: ");
    read = scanf("%d%c",&rowSelected,&enter);
    if(read != 2 || enter != '\n'){
      printf("Valor incorrecto, prueba de nuevo.\n");
      clean_stdin();
      rowSelected=-1;
    }
    else if (rowSelected < 1 || rowSelected > rowNum) {
      printf("Valor fuera de rango, prueba de nuevo.\n");
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

void imprimeFile(FILE *f) {
  char c;
  printf("---- CONTENIDO DEL FICHERO ----\n");
  c = fgetc(f);
  do {
    putchar(c);
    c = fgetc(f);
  } while (!feof(f));
  printf("\n-------------------------------\n\n");
}

void altaNuevaFila(FILE *f) {
  char buying[MAX1], maint[MAX2], doors[MAX3], persons[MAX4], lug_boot[MAX5], safety[MAX6];
  do {
    printf("Insertar valor buying: ");
    scanf("%s", buying);
  } while (strlen(buying)>MAX1);
  do {
    printf("Insertar valor maint: ");
    scanf("%s", maint);
  } while (strlen(maint)>MAX2);
  do {
    printf("Insertar valor doors: ");
    scanf("%s", doors);
  } while (strlen(doors)>MAX3);
  do {
    printf("Insertar valor persons: ");
    scanf("%s", persons);
  } while (strlen(persons)>MAX4);
  do {
    printf("Insertar valor lug_boot: ");
    scanf("%s", lug_boot);
  } while (strlen(lug_boot)>MAX5);
  do {
    printf("Insertar valor safety: ");
    scanf("%s", safety);
  } while (strlen(safety)>MAX6);
  fprintf(f, "%s,%s,%s,%s,%s,%s,-1", buying, maint, doors, persons, lug_boot, safety);
  printf("Fila añadida: %s,%s,%s,%s,%s,%s,-1\n", buying, maint, doors, persons, lug_boot, safety);
}

int cargaRegistro(FILE *f) {
  int numRows = numeroFilas(f), i, modified=0, notModified=0;
  cars car[numRows];
  for (i=0; i<numRows; i++) {
    fscanf(f, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%d\r\n", car[i].buying, car[i].maint, car[i].doors, car[i].persons, car[i].lug_boot, car[i].safety, &car[i].class_value);
    if (car[i].class_value == -1) {
      if (modificaClassValue(car, i, numRows)==1) {
        modified++;
      } else {
        notModified++;
      }
    }
  }
  printf("Numero de filas modificadas: %d\n", modified);
  printf("Numero de filas no modificadas: %d\n", notModified);
  menuEscrituraFiles(numRows, car);
  return sizeof(car)/sizeof(car[0]);
}

int modificaClassValue(cars *car, int i, int numRows) {
  int j;
  bool modified=false;
  for (j=0; j<numRows && !modified; j++) {
    if (j!=i && strcmp(car[j].buying,car[i].buying)==0 && strcmp(car[j].maint,car[i].maint)==0 && strcmp(car[j].doors,car[i].doors)==0 && strcmp(car[j].persons,car[i].persons)==0 && strcmp(car[j].lug_boot,car[i].lug_boot)==0 && strcmp(car[j].safety,car[i].safety)==0 && car[j].class_value!=-1) {
      car[i].class_value=car[j].class_value;
      modified=1;
    }
  }
  if (modified) {
    printf("Fila %d modificada: ", i);
  } else {
    printf("Fila %d no existe previamente en el archivo.", i);
  }
  printf("<%s,%s,%s,%s,%s,%s,%d>\n", car[i].buying, car[i].maint, car[i].doors, car[i].persons, car[i].lug_boot, car[i].safety, car[i].class_value);
  return modified;
}

void menuEscrituraFiles(int numRows, cars *car){
  int option, read;
  bool valid=false;
  char enter;
  printf("******************************\n");
  printf("*     ESCRIBIR A ARCHIVO     *\n");
  printf("*----------------------------*\n");
  printf("*  0.- Cancelar              *\n");
  printf("*  1.- Escribir .txt         *\n");
  printf("*  2.- Escribir .bin         *\n");
  printf("*  3.- Escribir ambos        *\n");
  printf("******************************\n");
  while (!valid) {
    printf("Insert option number: ");
    read = scanf("%d%c",&option,&enter);
    if(read != 2 || enter != '\n'){
      printf("Valor incorrecto, prueba de nuevo.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 3) {
      printf("Valor fuera de rango, prueba de nuevo.\n");
    } else {
      valid=true;
    }
  }
  switch (option) {
    case 1:
      escrituraTxt(car, numRows);
      break;
    case 2:
      escrituraBin(car, numRows);
      break;
    case 3:
      escrituraTxt(car, numRows);
      escrituraBin(car, numRows);
      break;
  }
}

void escrituraTxt(cars *car, int numRows){
  FILE *f;
  int i, read;
  char filename[10], extension[3], dot;
  bool valid=false;
  while (!valid) {
    printf("Insertar nombre de archivo txt: ");
    read = scanf("%[^.\n]%c%s", filename, &dot, extension);
    if (read != 3 || dot != '.') {
      printf("Formato incorrecto, prueba de nuevo.\n");
    }
    else if (strcmp(extension,"txt")!=0) {
      printf("Extension de archivo incorrecta, prueba de nuevo.\n");
    } else {
      strcat(filename, &dot);
      strcat(filename, extension);
      valid=true;
    }
    clean_stdin();
  }
  f=fopen(filename,"w");
  for (i=0; i<numRows; i++) {
    fprintf(f, "%s,%s,%s,%s,%s,%s,%d\n", car[i].buying, car[i].maint, car[i].doors, car[i].persons, car[i].lug_boot, car[i].safety, car[i].class_value);
  }
  fclose(f);
}

void escrituraBin(cars *car, int numRows){
  FILE *f;
  int i, read;
  char filename[10], extension[3], dot;
  bool valid=false;
  while (!valid) {
    printf("Insertar nombre de archivo bin: ");
    read = scanf("%[^.\n]%c%s", filename, &dot, extension);
    if (read != 3 || dot != '.') {
      printf("Formato incorrecto, prueba de nuevo.\n");
    }
    else if (strcmp(extension,"bin")!=0) {
      printf("Extension de archivo incorrecta, prueba de nuevo.\n");
    } else {
      strcat(filename, &dot);
      strcat(filename, extension);
      valid=true;
    }
    clean_stdin();
  }
  f=fopen(filename,"w");
  for (i=0; i<numRows; i++) {
    fprintf(f, "%s,%s,%s,%s,%s,%s,%d\n", car[i].buying, car[i].maint, car[i].doors, car[i].persons, car[i].lug_boot, car[i].safety, car[i].class_value);
  }
  fclose(f);
}
