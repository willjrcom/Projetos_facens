#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n;
	printf("numero: ");
	scanf("%i",&n);
	
	if(n>=0 && n<=9){
		printf("sim");
	}else printf("nao");
	getch();
	return 0;
}
