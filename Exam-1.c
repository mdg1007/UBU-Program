/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO : Exam-1.c
*
* DESCRIPCIÓN :
*   Tres funciones que cumplan los siguientes objetivos:
*   1- Devuelve la distancia Manhattan entre 2 puntos tridimensionales.
*   2- Imprime la equivalencia formateada de centimos.
*   3- Devuelve la equivalencia en céntimos del formato anterior.
*
* FUNCIONES PÚBLICAS :
*       double Apartado1( x1, y1, z1, x2, y2, z2 )
*       void Apartado2( centimos )
*       long Apartado3()
*
* NOTAS :
*   El uso de librerias esta prohibido a excepción de stdio.h.
*   Este programa resuelve el primer examen de la asignatura
*   Programación de UBU.
*
* AUTOR : Rodrigo Díaz         FECHA INICIAL : 11 Mar 2017
*
* CAMBIOS:
* 1.0 [11MAR2017] - Versión inicial
*/
 
#include <stdio.h>
 
double Apartado1(double, double, double, double, double, double);
void Apartado2(long);
long Apartado3();
 
int main(){
  double x1, y1, z1, x2, y2, z2;
  long centimos;
 
  //Primer Apartado
  printf("\n1.- * * * Distancia Manhattan * * *\nInsertar coordenadas del primer punto (x,y,z) separado por comas: ");
  scanf("%lf,%lf,%lf",&x1,&y1,&z1);
  printf("Insertar coordenadas del segundo punto (x,y,z) separado por comas: ");
  scanf("%lf,%lf,%lf",&x2,&y2,&z2);
  printf("La distancia Manhattan es: %g.\n\n",Apartado1(x1, y1, z1, x2, y2, z2));
 
  //Segundo Apartado
  printf("2.- * * * Centimos a Euros * * *\nInsertar la cantidad en centimos: ");
  scanf("%ld",&centimos);
  Apartado2(centimos);
 
  //Tercer Apartado
  printf("3.- * * * Euros a Centimos * * *\n");
  centimos = Apartado3();
  printf("Equivalencia en centimos: %ld\n\n", centimos);
 
  return 0;
}
 
double Apartado1(double x1, double y1, double z1, double x2, double y2, double z2){
  double distancia;
  distancia  = x2-x1 < 0 ? x1-x2 : x2-x1;
  distancia += y2-y1 < 0 ? y1-y2 : y2-y1;
  distancia += z2-z1 < 0 ? z1-z2 : z2-z1;
  return distancia;
}
 
void Apartado2(long centimos){
  printf("Equivalencia en euros: %01d %03d %03d,%02d \u20AC\n\n",(int)(centimos%100000000000/100000000),(int)(centimos%100000000/100000),(int)(centimos%100000/100),(int)(centimos%100));
}
 
long Apartado3(){
  int millones, miles, unidades, centimos;
  printf("Insertar euros formateados: ");
  scanf("%d %d %d,%d", &millones, &miles, &unidades, &centimos);
  return (long)millones * 100000000 + miles * 100000 + unidades * 100 + centimos;
}
