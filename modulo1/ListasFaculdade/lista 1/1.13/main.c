#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int dias,p,total;
	
	printf("calcular salario\n\ndias trabalhados: ");
	scanf("%i",&dias);
	
	total = dias*35;
	total = total-(total*0.08);
	
	printf("voce vai receber: R$%i,00",total);
	getch();
	return 0;
}
