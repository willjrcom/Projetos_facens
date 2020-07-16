#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a,b;
	printf("digite um numero: ");
	scanf("%i",&a);
	
	a += 0b0100;
	printf("%i",a);
	return 0;
}
