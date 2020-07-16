#include <stdio.h>
#include <stdlib.h>

#define n 2

void lerValores(int matriz[n][n])
{
	int i,j;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%i", *(matriz+i)+j );
}

int main()
{
	int matriz[n][n];
	int i,j;
	
	lerValores(matriz);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%i ", *(*(matriz+i)+j) );
			
		printf("\n");
	}
		
			
	return 0;
}
