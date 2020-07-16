#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	int n, i, t ;
	printf("numero: ");
	scanf("%i",&n);
	
	for(i=1;i<=10;i++){
		t = n*i;
		printf("%i x %i = %i.\n",n,i,t);
	}
	getch();
	return 0;
}
