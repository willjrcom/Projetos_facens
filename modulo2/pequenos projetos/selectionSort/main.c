//william junior 180037
#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *vetor)
{
	int i, j, min, aux;
	
	for(i=0; i<9; i++)
	{
		min=i;
		
		for(j= i+1; j<10; j++)
			if( *(vetor+j) > *(vetor+min) )
				min = j;
	
	if( *(vetor+i) != *(vetor+min))
	{
		aux= *(vetor+i);
		*(vetor+i) = *(vetor+min);
		*(vetor+min) = aux;
	}
	
	}
	
}
//------------------------------------------------------------
int main()
{
	int vetor[10] = { 2, 7, 3, 1, 6, 9, 11, 10, 4, 8};
	int i;
	
	printf("\tSelection sort\nVetor desordenado:\n");
	
	for(i=0; i<10; i++)
		printf(" - %i", *(vetor+i));
		
	SelectionSort(vetor);
	
	printf("\n\nVetor ordenado:\n");
	for(i=0; i<10; i++)
		printf(" - %i", *(vetor+i));
	return 0;
}
