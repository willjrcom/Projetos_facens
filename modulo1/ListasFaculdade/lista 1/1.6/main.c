#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int a,b,c;
printf("calcular a area do triangulo.\n\nbase: ");
scanf("%i",&a);
printf("altura: ");
scanf("%i",&b);
c = a*b/2;
printf("\no valor da area e: %i",c);
getch();
	return 0;
}
