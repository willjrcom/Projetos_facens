#include <stdio.h>
#include <stdlib.h>

int soma(int n, int n1)
{
	if(n1==0)
	return 0;
	else
	return n = n + soma(n, n1-1);
}


int main()
{
	int n,n1;
	
	printf("Numero: ");
	scanf("%i",&n);
	
	printf("\nNumero 2: ");
	scanf("%i",&n1);
	
	printf("%i", soma(n,n1) );
	return 0;
}
