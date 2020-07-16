#include <stdio.h>
#include <stdlib.h>

void fatorial(int x);

int main()
{
	int a;
	printf("Numero: ");
	scanf("%i",&a);
	
	a = fatorial(a);
	
	printf("\nResultado: %i",a);
	
	return 0;
}

int fatorial(int x)
{
	int a;
	
	if(x<1)
		return 1;
	
	else
		return a= x*fatorial(x-1);	
}
