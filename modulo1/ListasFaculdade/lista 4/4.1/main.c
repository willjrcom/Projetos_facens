#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i, n,d;
	
	for (i=0;i<10;i++){
		
		printf("numero: ");
		scanf("%i",&n);
	
		d = n*2;
	
		printf("o dobro de %i eh: %i.\n", n,d);
	}
	getch();
	
	
	return 0;
}
