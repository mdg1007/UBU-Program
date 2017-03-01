/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E3-2.c
*
* DESCRIPTION :
*		Asks for an ammount of seconds and prints the equivalent
*		in hours, minutes and seconds.
*
* PUBLIC FUNCTIONS :
*		int Section1( seconds )
*		int Section2( seconds )
*		int Section3( seconds )
*		int Section4( seconds )
*
* NOTES :
*		This program is the solution to the proposed exercise
*		in the fourth week of the class 'Programación'
*		(programming) of Burgos University.
*
* AUTHOR : Rodrigo Díaz			START DATE : 1 Mar 2017
*
* CHANGES:
* 1.1 [01MAR2017] - Removed redundancy
* 1.0 [01MAR2017] - Initial release
*/

#include <stdio.h>

int Section1(int);
int Section2(int);
int Section3(int);
int Section4(int);
int Section2Hours(int);
int Section2Minutes(int);
int Section2Seconds(int);
int Section3Hours(int *);
int Section3Minutes(int *);
int Section3Seconds(int *);
void Section4Hours(int);
void Section4Minutes(int);
void Section4Seconds(int);

int main(){
  int seconds;
  printf("Insert seconds: ");
  scanf("%d", &seconds);
  Section1(seconds);
  Section2(seconds);
  Section3(seconds);
  Section4(seconds);
  return 0;
}

int Section1(int seconds){
  printf("\n1.- %d hours, %d minutes and %d seconds",seconds/3600,seconds%3600/60,seconds%60);
  return 0;
}


int Section2(int seconds){
  printf("\n2.- %d hours, %d minutes and %d seconds", Section2Hours(seconds), Section2Minutes(seconds), Section2Seconds(seconds));
  return 0;
}

int Section2Hours(int seconds){
  return seconds/3600;
}

int Section2Minutes(int seconds){
  return seconds%3600/60;
}

int Section2Seconds(int seconds){
  return seconds%60;
}


int Section3(int seconds){
  printf("\n3.- %d hours, %d minutes and %d seconds", Section3Hours(&seconds), Section3Minutes(&seconds), Section3Seconds(&seconds));
  return 0;
}

int Section3Hours(int *seconds){
  return *seconds/3600;
}

int Section3Minutes(int *seconds){
  return *seconds%3600/60;
}

int Section3Seconds(int *seconds){
  return *seconds%60;
}


int Section4(int seconds){ 
  Section4Hours(seconds);
  Section4Minutes(seconds);
  Section4Seconds(seconds);
  return 0;
}

void Section4Hours(int seconds){
  printf("\n4.- %d hours, ", seconds/3600);
}

void Section4Minutes(int seconds){
  printf("%d minutes and ", seconds%3600/60);
}

void Section4Seconds(int seconds){
  printf("%d seconds\n", seconds%60);
}
