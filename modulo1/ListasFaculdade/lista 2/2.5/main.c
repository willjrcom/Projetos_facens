#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	printf("Numero maior.\n");
	scanf("%i %i",&a,&b);
	
	if(a>b)printf("%i eh maior que %i.",a,b);
	else printf("%i eh maior que %i.",b,a);
	getch();
	return 0;
}
