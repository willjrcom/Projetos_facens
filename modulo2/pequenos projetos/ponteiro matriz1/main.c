#include <stdio.h>
#include <stdlib.h>

void receber(int matriz[5][5], int n)
{
	int i, j;
	
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			printf("[%i][%i]: ",i+1, j+1);
			scanf("%i", *(matriz+i)+j );
		}
			
}

void somar(int matriz[5][5], int n)
{
	int i, j,soma=0,cont=0;
	
	printf("\nDiagonal secundaria : ");
	
	for(i=0; i<n; i++)
		for(j=n-1-i; j>=0; j--)
		{	
			soma += *(*(matriz+i)+j) ;
			
			printf("\n - linha: %i, coluna: %i", i,j );	
			j=0;	
		}
	
	printf("\nsoma: %i",soma);
}
int main()
{
	int matriz[5][5],n,i,j;
	
	printf("Qual o tamanho da matriz: ");
	scanf("%i", &n);
	
	receber(matriz,n);
	
	printf("\nMatriz: \n");
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%i ", *(*(matriz+i)+j) );
		printf("\n");
	}
	
	somar(matriz,n);
	         
	return 0;
}
