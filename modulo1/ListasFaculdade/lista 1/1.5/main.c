#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int a,b,resto,final;

	printf("divisao\n\ndigite o primeiro valor: ");
	scanf("%i",&a);

	printf("digite o segundo valor: ");
	scanf("%i",&b);

	final = a/b;
	resto= a%b;
	printf("\no valor de a / b = %i\nO resto e: %i",final,resto);
	getch();
	return 0;
}
