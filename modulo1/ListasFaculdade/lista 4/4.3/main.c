#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int n,i;
	
	for(i=0;i<10;i++){
		printf("numero: ");
		scanf("%i",&n);
		if(n<0)printf("negativo\n");
		else if(n==0)printf("nulo\n");
		else printf("positivo\n");
	}
	getch();
	return 0;
}
