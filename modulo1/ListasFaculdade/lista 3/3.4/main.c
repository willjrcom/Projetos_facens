#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	
	printf("numeros repetidos.");
	scanf("%i %i %i",&a,&b,&c);
	
	if(a==b || a==c) printf ("%i eh repetido",a);
	else if(b==c) printf("%i eh repetido",b);
	return 0;
}
