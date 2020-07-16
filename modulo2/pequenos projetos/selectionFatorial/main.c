//william junior 180037
#include <stdio.h>
#include <stdlib.h>

void Selection(int *vetor, int t,int i)
{
	int j, min, aux;
	
	min = i;
		
	for(j=i+1; j<t; j++)
		if( *(vetor+j) < *(vetor+min))
			min = j;
		
	if( *(vetor+i) != *(vetor+min))
	{
		aux = *(vetor+i);
		*(vetor+i) = *(vetor+min);
		*(vetor+min) = aux;
	}
	if(t != i)
		Selection(vetor, t, i+1);
}

int main()
{
	int vetor[10] = {9, 1, 8, 2, 7, 3, 6, 4, 5, 10};
	int i;
	
	printf("\tSeletion Sort Recursiva");
	printf("\nvetor desorganizado:\n");
	
	for(i=0; i<10; i++)
		printf(" - %i", *(vetor+i));
		
	Selection(vetor,10,0);
	
	printf("\n\nvetor organizado:\n");
	for(i=0; i<10; i++)
		printf(" - %i", *(vetor+i));
		
	return 0;
}
