#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float r,p,pi;
	pi=3.14;

	printf("calcular perimetro do triangulo.\n\nraio: ");
	scanf("%f", &r);

	p = 2 * pi * r ;

	printf("\no perimetro e: %f", p);
	getch();
	
	return 0;
}
