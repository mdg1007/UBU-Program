/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E3-3.c
*
* DESCRIPTION :
*		Asks for a 4-digit integer and prints each individual digit.
*
* PUBLIC FUNCTIONS :
*		int Section1( number )
*		int Section2( number )
*		int Section3( number )
*		int Section4( number )
*
* NOTES :
*		This program is the solution to the proposed exercise
*		in the fourth week of the class 'Programación'
*		(programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz			START DATE : 1 Mar 2017
*
* CHANGES:
* 1.0 [01MAR2017] - Initial release
*/

#include <stdio.h>

int Section1(int);
int Section2(int);
int Section3(int);
int Section4(int);

int Section2First(int);
int Section2Second(int);
int Section2Third(int);
int Section2Fourth(int);

int Section3First(int *);
int Section3Second(int *);
int Section3Third(int *);
int Section3Fourth(int *);

void Section4First(int);
void Section4Second(int);
void Section4Third(int);
void Section4Fourth(int);

int main(){
  int number;
  printf("Insert a number between 1000 and 9999: ");
  scanf("%d", &number);
  number%=10000;
  Section1(number);
  Section2(number);
  Section3(number);
  Section4(number);
  return 0;
}

int Section1(int number){
  printf("\n1.- | %d | %d | %d | %d |",number/1000,number%1000/100,number%100/10,number%10);
  return 0;
}


int Section2(int number){
  printf("\n2.- | %d | %d | %d | %d |", Section2First(number), Section2Second(number), Section2Third(number), Section2Fourth(number));
  return 0;
}

int Section2First(int number){
  return number/1000;
}

int Section2Second(int number){
  return number%1000/100;
}

int Section2Third(int number){
  return number%100/10;
}

int Section2Fourth(int number){
  return number%10;
}


int Section3(int number){
  printf("\n3.- | %d | %d | %d | %d |", Section3First(&number), Section3Second(&number), Section3Third(&number), Section3Fourth(&number));
  return 0;
}

int Section3First(int *number){
  return *number/1000;
}

int Section3Second(int *number){
  return *number%1000/100;
}

int Section3Third(int *number){
  return *number%100/10;
}

int Section3Fourth(int *number){
  return *number%10;
}

int Section4(int number){ 
  Section4First(number);
  Section4Second(number);
  Section4Third(number);
  Section4Fourth(number);
  return 0;
}

void Section4First(int number){
  printf("\n4.- | %d |", number/1000);
}

void Section4Second(int number){
  printf(" %d |", number%1000/100);
}

void Section4Third(int number){
  printf(" %d |", number%100%10);
}

void Section4Fourth(int number){
  printf(" %d |\n", number%10);
}
