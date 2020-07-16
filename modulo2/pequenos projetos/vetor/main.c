#include <stdio.h>
#include <stdlib.h>

int main() 
{
	int vetor[2][2], i, j,t;
	
	for (i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
		printf("\nDigite o vetor %i-%i: ",i+1, j+1);
		scanf("%i",&vetor[i][j]);
		}
		
	}
	
	for (i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		
		t+=vetor[i][j];
	}
		printf("%i",t);
	
	return 0;
}
