#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n;
	printf("numero: ");
	scanf("%i",&n);
	
	if(n>0){
		printf("positivo");
	}else if (n==0){
		printf("nulo");
	}else printf("negativo");
	
	getch();
	return 0;
}
