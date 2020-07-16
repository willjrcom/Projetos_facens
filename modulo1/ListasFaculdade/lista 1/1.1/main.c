#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int a;
	
	int b;
	printf("calcule o dobro do numero.\n\nnumero: ");
	scanf("%i",&a);
	

	b=a*2;
	printf("\ndobro: %i",b);
	getch();
	return 0;
}
