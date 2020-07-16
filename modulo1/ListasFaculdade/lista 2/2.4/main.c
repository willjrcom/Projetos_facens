#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int p1,p2,m;
	printf("p1: ");
	scanf("%i",&p1);
	
	printf("p2: ");
	scanf("%i",&p2);
	
	m= (p1+p2)/2;
	
	if(m>=5)printf("aprovado");
	else printf("faltou %i pontos",5-m);
	getch();
	return 0;
}
