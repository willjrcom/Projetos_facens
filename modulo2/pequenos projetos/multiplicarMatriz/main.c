#include <stdio.h>
#include <stdlib.h>

int main() {
	int m1[2][2], m2[2][2], m3[2][2], i, j, k, sum;
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Elemento a%i%i da matriz A: ", i+1, j+1);
			scanf("%i", &m1[i][j]);
		}
	}

	// pega os valores do teclado para montar a matriz B
	printf("\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("Elemento b%i%i da matriz B: ", i+1, j+1);
			scanf("%i", &m2[i][j]);
		}
	}
	
	//calcula a matriz C=AxB
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			for(k=0; k<2; k++)
			{
				sum += m1[i][k] * m2[k][j];
			}
			m3[i][j]=sum;
			sum=0;
		}
	}

	// imprime a matriz A
	printf("\nMatriz A\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%i  ", m1[i][j]);
		}
		printf("\n");
	}

	// imprime a matriz B
	printf("\nMatriz B\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%i  ", m2[i][j]);
		}
		printf("\n");
	}

	// imprime a matriz C
	printf("\nMatriz C=AxB\n");
	for(i=0; i<2; i++)
	{
		for(j=0; j<2; j++)
		{
			printf("%i  ", m3[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	return 0;
	}	
