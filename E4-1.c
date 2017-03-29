/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FILENAME :	E4-1.c
*
* DESCRIPTION :
*   Asks for the 3 coefficients (a,b,c) of a quadratic equation
*   and writes the solution to screen.
*
* NOTES :
*   This program is the solution to the proposed exercise
*   in the fourth week of the course
*   'Programación' (programming) of Burgos University.
*
* AUTHOR : Rodrigo Día      START DATE : 8 Mar 2017
*
* CHANGES:
* 1.0 [10MAR2017] - Initial release
*/

#include <stdio.h>
#include <math.h>

void  readCoefficients(float *, float *, float *);
int determineType(float, float, float);
void showResult(int, float, float, float);
int calculateRoot(float, float, float);

int main(){
	float a, b, c;
	readCoefficients(&a, &b, &c);
	showResult(determineType(a, b, c), a, b, c);
	return 0;
}

void readCoefficients(float *a, float *b, float *c){
	printf("Insert the coefficients a, b, c separated by commas\n");
	scanf("%f,%f,%f", &*a,&*b,&*c);
}

int determineType(float a, float b, float c){
	int tipo=3;
	if(a==0){
		if(b==0){
			tipo=1;
		}else{
			tipo=2;
		}
	}
	return tipo;
}

void showResult(int tipo, float a, float b, float c){
	float root;
	if(tipo==1){
		if(c==0){
			printf("Zero polynomial");
		}else{
			printf("Degree 0 polynomial");
		}
	}else{
		if(tipo==2){
			printf("Degree 1 polynomial, solution x=%g",-c/b);
		}else{
			printf("Degree 2 polynomial, solution x=");
			root=calculateRoot(a,b,c);
			if(root==0){
				printf("=%g\n",-b/pow(b,2));
			}else{
				if(root>0){
					if(b==0){
						printf("\u00B1%g",(-b+sqrt(root))/(2*a));
					}else{
						printf("%g, x=%g",(-b+sqrt(root))/(2*a),(b+sqrt(root))/(2*a));
					}
				}else{
					printf("%.3g\u00B1%.3gi",-b/(2*a),sqrt(-root)/(2*a));
				}
			}
		}
	}
	printf("\n");
}

int calculateRoot(float a, float b,float c){
	return pow(b,2)-4*a*c;
}
