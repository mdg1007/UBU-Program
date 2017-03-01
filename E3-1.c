/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E3-1.c
*
* DESCRIPTION :
*		Asks for a radius and prints the value of the perimeter
*		and area of a circle with the specified radius.
*
* PUBLIC FUNCTIONS :
*		int Section1( radius )
*		int Section2( radius )
*		int Section3( radius )
*		int Section4( radius )
*
* NOTES :
*		This program is the solution to the proposed exercise
*		in the third week of the class 'Programación'
*		(programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz			START DATE : 23 Feb 2017
*
* CHANGES:
* 1.1 [01MAR2017] - Corrected header format
* 1.0 [23FEB2017] - Initial release
*/

#define PI 3.141592
#include <stdio.h>

int Section1(float);
int Section2(float);
int Section3(float);
int Section4(float);
float Section2Perim(float);
float Section2Area(float);
float Section3Perim(float *);
float Section3Area(float *);
void Section4Perim(float);
void Section4Area(float);

int main(){
  float radius;
  printf("Insert radius: ");
  scanf("%g", &radius);
  Section1(radius);
  Section2(radius);
  Section3(radius);
  Section4(radius);
  return 0;
}

int Section1(float radius){
  printf("\n1.- The perimeter is: %.2f, the area is: %.2f\n", 2*PI*radius, PI*radius*radius);
  return 0;
}


int Section2(float radius){
  printf("\n2.- The perimeter is: %.2f, the area is: %.2f\n", Section2Perim(radius), Section2Area(radius));
  return 0;
}

float Section2Perim(float radius){
  return radius * 2 * PI;
}

float Section2Area(float radius){
  return radius * radius * PI;
}


int Section3(float radius){
  printf("\n3.- The perimeter is: %.2f, the area is: %.2f\n", Section3Perim(&radius), Section3Area(&radius));
  return 0;
}

float Section3Perim(float *radius){
  return (*radius) * 2 * PI;
}

float Section3Area(float *radius){
 return (*radius) * (*radius) * PI;
}


int Section4(float radius){
  Section4Perim(radius);
  Section4Area(radius);
  return 0;
}

void Section4Perim(float radius){
  printf("\n4.- The perimeter is: %.2f", radius * 2 * PI);
}

void Section4Area(float radius){
  printf(", the area is: %.2f.\n", radius * radius * PI);
}
