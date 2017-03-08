/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* FICHERO :	E4-1.c
*
* DESCRIPCIÓN :
*		Pide los 3 valores(a,b,c) de una ecuación a*x^2 + b*x + c = 0
*		e imprime el resultado de la incognita x.
*
* NOTAS :
*		Este programa resuelve la primera parte de la cuarta
*		práctica de la asignatura Programación de UBU.
*
* AUTOR : Rodrigo Díaz			FECHA INICIAL : 8 Mar 2017
*
* CAMBIOS:
* 1.0 [08MAR2017] - Versión inicial
*/

#include <stdio.h>
#include <math.h>

void  leeCoeficientes(float *, float *, float *);
int determinaTipo(float, float, float);
int calculaRadicando(float, float, float);
void muestraResultado(int, float, float, float);

int main(){
	float a, b, c;
	leeCoeficientes(&a, &b, &c);
	muestraResultado(determinaTipo(a, b, c), a, b, c);
	return 0;
}

void leeCoeficientes(float *a, float *b, float *c){
	printf("Introduce valores a, b, c separados por comas\n");
	scanf("%f,%f,%f", &*a,&*b,&*c);
}

int determinaTipo(float a, float b, float c){
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

void muestraResultado(int tipo, float a, float b, float c){
	float radicando;
	printf("Es una ecuacion de ");
	if(tipo==1){
		printf("grado cero");
		if(c!=0){
			printf(" invalida");
		}
	}else{
		if(tipo==2){
			printf(" primer grado con solucion x=%g",-c/b);
		}else{
			printf(" segundo grado con solucion x=");
			radicando=calculaRadicando(a,b,c);
			if(radicando==0){
				printf("=%g\n",-b/pow(b,2));
			}else{
				if(radicando>0){
					if(b==0){
						printf("\u00B1%g",(-b+sqrt(radicando))/(2*a));
					}else{
						printf("%g, x=%g",(-b+sqrt(radicando))/(2*a),(b+sqrt(radicando))/(2*a));
					}
				}else{
					printf("%.3g\u00B1%.3gi",-b/(2*a),sqrt(-radicando)/(2*a));
				}
			}
		}
	}
	printf("\n");
}

int calculaRadicando(float a, float b,float c){
	return pow(b,2)-4*a*c;
}
