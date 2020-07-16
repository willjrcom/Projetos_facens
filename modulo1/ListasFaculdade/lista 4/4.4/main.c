#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int n1,n2,i;
	
	printf("numero 1: ");
	scanf("%i",&n1);
	
	printf("numero 2: ");
	scanf("%i",&n2);
	
	
	for (n1+=1; n1<n2; n1++){
		printf("%i\n",n1);
	}
	getch();
	return 0;
}
