#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int hn = 10;
	int he = 15;
	int hnt,het,total,dias;
	
	printf("calcular salario\n\nhorario normal trabalhado: ");
	scanf("%i",&hnt);
	
	printf("hora extra: ");
	scanf("%i",&het);
	
	total = (hn*hnt)+(he*het);
	dias = hnt +het;
	
	printf("\nvoce trabalhou %i dias e recebeu R$%i,00 reais.",dias,total);
	getch();
	return 0;
}
