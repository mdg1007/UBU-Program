/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	Exam-1.c
*
* DESCRIPTION :
*   Three functions with the following objective:
*		1- Return taxicab distance between 2 3D points
*   2- Print a formatted equivalent of cents.
*   3- Return the equivalence in cents of the previous format.
*
* PUBLIC FUNCTIONS :
*		double Section1( x1, y1, z1, x2, y2, z2 )
*		void Section2( cents )
*		long Section3()
*
* NOTES :
*		This program is the solution to the first exam of the
*   course 'Programación' (programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz			START DATE : 11 Mar 2017
*
* CHANGES:
* 1.0 [11MAR2017] - Initial release
*/

#include <stdio.h>

double Section1(double, double, double, double, double, double);
void Section2(long);
long Section3();

int main(){
  double x1, y1, z1, x2, y2, z2;
  long cents;
  
  //first section
  printf("\n1.- * * * Manhattan - Taxicab * * *\nInsert first point coordinates (x,y,z) separated by commas: ");
  scanf("%lf,%lf,%lf",&x1,&y1,&z1);
  printf("Insert second point coordinates (x,y,z) separated by commas: ");
  scanf("%lf,%lf,%lf",&x2,&y2,&z2);
  printf("The Manhattan distance is: %g.\n\n",Section1(x1, y1, z1, x2, y2, z2));
  
  //second section
  printf("2.- * * * Cents to Euros * * *\nInsert the ammount of cents: ");
  scanf("%ld",&cents);
  Section2(cents);
  
  //third section
  printf("3.- * * * Euros to Cents * * *\n");
  cents = Section3();
  printf("Equivalent in cents: %ld\n\n", cents);
  
  return 0;
}

double Section1(double x1, double y1, double z1, double x2, double y2, double z2){
  return fabs(x2-x1) + fabs(y2-y1) + fabs(z2-z1);
}

void Section2(long cents){
  printf("Equivalent in euros: %01d %03d %03d,%02d €\n\n",(int)(cents%100000000000/100000000),(int)(cents%100000000/100000),(int)(cents%100000/100),(int)(cents%100));
}

long Section3(){
  unsigned millions, thousands, units, cents;
  printf("Insert formatted ammount of euros: ");
  scanf("%d %d %d,%d", &millions, &thousands, &units, &cents);
  return (unsigned long long)millions * 100000000 + thousands * 100000 + units * 100 + cents;
}
