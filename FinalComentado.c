/*---------------------------------------------+
| Nombre: Final.c                              |
| Sinopsis:El programa muestra un menu con     |
|   las distintias opciones para manipular     |
|   y leer ficheros con datos formateados.     |
| Descripción de la ejecución del programa:    |
|    c:>Final                                  |
| Directivas de compilación:                   |
|   Compilar en modo ansi, con todos los       |
|   warnings activos.                          |
| Lista de códigos de salida de la aplicación: |
|   Devuelve 0.                                |
| Organización: alumnos ubu                    |
| Autor:                                       |
|   Rodrigo, Díaz García                       |
|   Diego, González Román                      |
| Fecha: 21-may-2017                           |
| Versión: v1.0                                |
| Lista de versiones:                          |
| v1 21-may-2017 versión inicial               |
| Información del copyright del programa:      |
|   Licencia pública MIT 2017                  |
+---------------------------------------------*/
/*Directivas al precompilador*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define FILENAME "car.txt" //Cte. de fichero
#define MAX1 6 //Cte. del 1er elemento
#define MAX2 6 //Cte. del 2do elemento
#define MAX3 5 //Cte. del 3er elemento
#define MAX4 5 //Cte. del 4to elemento
#define MAX5 6 //Cte. del 5to elemento
#define MAX6 5 //Cte. del 6to elemento

typedef struct cars { //Vector de registros cars
  char buying[MAX1];
  char maint[MAX2];
  char doors[MAX3];
  char persons[MAX4];
  char lug_boot[MAX5];
  char safety[MAX6];
  int class_value;
} cars;

 /* Declaraciones forward de las funciones*/
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
int modificaClassValue(cars[], int);
int clean_stdin();

/* Programa Principal */
int main() {
  int selectedOption=0;
  FILE *f;
  f = fopen(FILENAME, "r"); //Lectura adelantada del fichero
  if (f!=NULL) { //Comprobar que el archivo no esté vacio
    fclose(f);
    do { //Bucle hasta que se introduzca opción 0
      seleccionaOpcion(selectedOption); //Interpreta opción
      selectedOption = solicitaOpcionMenu(); //Pide opción
    } while (selectedOption != 0);
  } else {
    fclose(f);
    printf("ERROR LEYENDO ARCHIVO\n");
  }
  return 0;
}

/*-------------------------------------------------- clean_stdin -----
|  Función clean_stdin
|
|  Objetivo:  Limpia caracteres que se encuentren pendientes en
|      la entrada standard (stdin).
|
|  Parameteros:  Nada.
|
|  Devuelve:
|      int 1 -- Valor constante.
|
*-------------------------------------------------------------------*/
int clean_stdin(){
  while(getchar() != '\n');
  return 1;
}

/*------------------------------------------- solicitaOpcionMenu -----
|  Función solicitaOpcionMenu
|
|  Objetivo:  Muestra un menu en pantalla y espera un número
|      entre los valores 0 y 8, correspondientes a las
|      distintas funcionalidades del programa.
|
|  Parameteros:  Nada.
|
|  Devuelve:
|      int option -- Número elegido y comprobado.
|
*-------------------------------------------------------------------*/
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
    if(read != 2 || enter != '\n'){ //Si input incorrecto
      printf("Valor incorrecto, prueba de nuevo.\n");
      clean_stdin();
    }
    else if (option < 0 || option > 8) { //Si fuera de rango
      printf("Valor fuera de rango, prueba de nuevo.\n");
    }
    else {
      return option;
    }
  }
}

/*--------------------------------------------- seleccionaOpcion -----
|  Subrutina seleccionaOpcion
|
|  Objetivo:  Realiza distintas funciones dependiendo del
|      paramentro de entrada.
|
|  Parameteros:
|      int option -- número de opción elegida.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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

/*-------------------------------------------------- numeroFilas -----
|  Función numeroFilas
|
|  Objetivo:  Cuenta el número de filas en el fichero.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:
|      int rowNum -- número de filas.
|
*-------------------------------------------------------------------*/
int numeroFilas(FILE *f) {
  char c;
  int rowNum = 0;
  c = fgetc(f);
  while (!feof(f)) { //mientras no sea fin de archivo
    if (c == '\n') { //si es fin de linea
      ++rowNum; //aumentar numero de filas
      c = fgetc(f);
    }
    else {
      c = fgetc(f);
      if (feof(f)) //si el siguiente caracter es fin de archivo
        ++rowNum; //aumentar numero de filas
    }
  }
  rewind(f);
  return rowNum;
}

/*--------------------------------------------------- numeroCols -----
|  Función numeroCols
|
|  Objetivo:  Cuenta el número de columnas en el fichero.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:
|      int colNum -- número de columnas.
|
*-------------------------------------------------------------------*/
int numeroCols(FILE *f) {
  char c;
  int colNum = 0;
  c = fgetc(f);
  while (!feof(f)) {
    if (c == ',' || c == '\n') { //Si es una coma o final de linea.
      ++colNum; //aumentar numero de columnas
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

/*--------------------------------------------------- numeroChar -----
|  Función numeroChar
|
|  Objetivo:  Cuenta el número de caracteres en el fichero.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:
|      int charNum -- número de caracteres.
|
*-------------------------------------------------------------------*/
int numeroChar(FILE *f) {
  int charNum=0;
  fgetc(f);
  while (!feof(f)) {
    ++charNum;
    fgetc(f);
  }
  return charNum;
}

/*------------------------------------------------------ fileMax -----
|  Función fileMax
|
|  Objetivo:  Calcula la fila con el mayor número de caracteres.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:
|      int tempMaxPos -- Posición de la linea (comenzando por 1).
|
*-------------------------------------------------------------------*/
int fileMax(FILE *f) {
  char c;
  int tempMax = 0, currentRowCount = 0, currentRowPos = 0, tempMaxPos = 0;
  while (!feof(f)) {
    c = fgetc(f);
    if (c == '\n' || feof(f)) {
      ++currentRowPos;
      if (currentRowCount > tempMax) { //Si la linea actual es la mayor
        tempMax = currentRowCount; //Guardar nuevo máximo
        tempMaxPos = currentRowPos; //Guardar posicion del nuevo máximo
      }
      currentRowCount = 0;
    }
    else {
      ++currentRowCount;
    }
  }
  return tempMaxPos;
}

/*-------------------------------------------------- imprimeFila -----
|  Subrutina imprimeFila
|
|  Objetivo:  Pide el número de una fila y muestra su contenido.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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
  rewind(f); //Vuelve al principio del archivo
  while (!feof(f) && currentRowCount < rowSelected - 1) { //Hasta llegar a la fila deseada
    if (c == '\n') {
      ++currentRowCount;
    }
    c = fgetc(f);
  }
  while (!feof(f) && c != '\n') { //Por cada caracter en la fila
    putchar(c); //Imprime el caracter
    c = fgetc(f);
  }
  printf("\n\n");
}

/*-------------------------------------------------- imprimeFile -----
|  Subrutina imprimeFile
|
|  Objetivo:  Muestra todo el contenido del fichero.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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

/*------------------------------------------------ altaNuevaFila -----
|  Subrutina altaNuevaFila
|
|  Objetivo:  Pide 6 valores, correspondientes a las columnas del
|      fichero, despues añade una nueva linea al archivo, con cada
|      valor y en el septimo pone un -1.
|
|  Parameteros:
|      FILE *f -- Archivo a ser modificado.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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
  fprintf(f, "%s,%s,%s,%s,%s,%s,-1", buying, maint, doors, persons, lug_boot, safety); //Añade linea al fichero
  printf("Fila añadida: %s,%s,%s,%s,%s,%s,-1\n", buying, maint, doors, persons, lug_boot, safety);
}

/*------------------------------------------------ cargaRegistro -----
|  Función cargaRegistro
|
|  Objetivo:  Lee el fichero y guarda cada linea válida cada
|      elemento en un vector de registros. Si una linea tiene
|      un class_value de -1, esta es modificada.
|
|  Parameteros:
|      FILE *f -- Archivo a ser leido.
|
|  Devuelve:
|      int numero -- Número de lineas válidas leidas
|
*-------------------------------------------------------------------*/
int cargaRegistro(FILE *f) {
  int numRows = numeroFilas(f), i, modified=0, notModified=0;
  cars car[numRows];
  for (i=0; i<numRows; i++) { //Por cada linea
    fscanf(f, "%[^','],%[^','],%[^','],%[^','],%[^','],%[^','],%d\r\n", car[i].buying, car[i].maint, car[i].doors, car[i].persons, car[i].lug_boot, car[i].safety, &car[i].class_value);
    /* Si está formateada correctamente, guarda valores en vector de registros */
    if (car[i].class_value == -1) { //Si el class_value es -1
      if (modificaClassValue(car, i)==1) { //Si se modifica correctamente el class_value
        modified++;
      } else {
        notModified++;
      }
    }
  }
  printf("Numero de filas modificadas: %d\n", modified);
  printf("Numero de filas no modificadas: %d\n", notModified);
  menuEscrituraFiles(numRows, car); //Guardar vector
  return sizeof(car)/sizeof(car[0]);
}

/*------------------------------------------- modificaClassValue -----
|  Función modificaClassValue
|
|  Objetivo:  Modifica el valor class_value de un registro.
|      Para ello, busca en el vector una linea que tenga los 6
|      primeros valores iguales que el objetivo. Y le asgina el
|      último valor a class_value.
|
|  Parameteros:
|      cars *car -- Vector de registros que contenga los datos.
|      int i -- Posición del V.R. a ser modificada.
|
|  Devuelve:
|      bool modified -- Si se ha modificado el valor o no.
|
*-------------------------------------------------------------------*/
int modificaClassValue(cars *car, int i) {
  int j;
  bool modified=false;
  for (j=0; j<sizeof(car)/sizeof(car[0]) && !modified; j++) {
    if (j!=i && strcmp(car[j].buying,car[i].buying)==0 && strcmp(car[j].maint,car[i].maint)==0 && strcmp(car[j].doors,car[i].doors)==0 && strcmp(car[j].persons,car[i].persons)==0 && strcmp(car[j].lug_boot,car[i].lug_boot)==0 && strcmp(car[j].safety,car[i].safety)==0 && car[j].class_value!=-1) {
      /* Si los 6 primeros valores coinciden, y no es la misma fila */
      car[i].class_value=car[j].class_value; //Copia en valor del encontrado en el objetivo
      modified=true;
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

/*------------------------------------------- menuEscrituraFiles -----
|  Subrutina menuEscrituraFiles
|
|  Objetivo:  Muestra un menu en pantalla y espera un número
|      entre los valores 0 y 3, 0 para salir, 1 para guardar V.R.
|      en fichero .txt, 2 en .bin y 3 en .txt y .bin.
|
|  Parameteros:
|      int numRows -- Número de lineas.
|      cars *car -- Vector de registros que contenga los datos.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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

/*------------------------------------------------- escrituraTxt -----
|  Subrutina escrituraTxt
|
|  Objetivo:  Guarda el vector de registros en un fichero .txt,
|      del cual se pide un nombre de archivo. Si este no existe,
|      crea el fichero.
|
|  Parameteros:
|      cars *car -- Vector de registros que contenga los datos.
|      int numRows -- Número de lineas.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
void escrituraTxt(cars *car, int numRows){
  FILE *f;
  int i, read;
  char filename[10], extension[3], dot;
  bool valid=false;
  while (!valid) {
    printf("Insertar nombre de archivo txt: ");
    read = scanf("%[^.\n]%c%s", filename, &dot, extension);
    /* leer archivo y extensión separados por un punto */
    if (read != 3 || dot != '.') {
      printf("Formato incorrecto, prueba de nuevo.\n");
    }
    else if (strcmp(extension,"txt")!=0) { //Si la extensión no es txt
      printf("Extension de archivo incorrecta, prueba de nuevo.\n");
    } else {
      strcat(filename, &dot); //filename+=.
      strcat(filename, extension); //filename+=txt
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

/*------------------------------------------------- escrituraBin -----
|  Subrutina escrituraBin
|
|  Objetivo:  Guarda el vector de registros en un fichero .bin,
|      del cual se pide un nombre de archivo. Si este no existe,
|      crea el fichero.
|
|  Parameteros:
|      cars *car -- Vector de registros que contenga los datos.
|      int numRows -- Número de lineas.
|
|  Devuelve:  Nada
|
*-------------------------------------------------------------------*/
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
