#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	
	printf("calcular raiz e potencia.\n\ndigite o numero: ");
	scanf("%i", &a);
	
	b= sqrt(a);
	c= pow(a,8);
	
	printf("\na raiz e: %i\na potencia e: %i",b,c);
	
	getch();
	return 0;
}
