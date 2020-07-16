#include <stdio.h>
#include <stdlib.h>

int main()
{	
	int n,e;
	
	printf("Numero: ");
	scanf("%i",&n);
	
	printf("\nExpoente: ");
	scanf("%i",&e);
	
	printf("%i",pot(n,e));
	return 0;
}

int pot(int num, int exp)
{		
	if(exp==0)
		return 1;
	else
		num = num * pot(num, exp-1);
	
	
}
