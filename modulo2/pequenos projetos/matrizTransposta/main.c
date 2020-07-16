#include <stdio.h>
#include <stdlib.h>

#define n 3
int main() {
	
	int m[n][n],i,j,aux;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			scanf("%i", &m[i][j]);
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
				printf("%i ",m[i][j]);
		}
		printf("\n");
	}	
	
	printf("\nTransposta:\n\n");
	
	for(i=0; i<n; i++)
	{
		for(j=i; j<n; j++)
		{
			aux = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] =aux;
		}
		printf("\n");
	}	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
				printf("%i ",m[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
