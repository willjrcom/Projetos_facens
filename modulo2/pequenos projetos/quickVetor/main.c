//william junior 180037
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quick(char *vetor, int inicio, int fim)
{
	int i, j, aux, meio;
	
	i = inicio;
	j = fim;
	meio = *(vetor+ ( (inicio+fim) /2 ) );
	
	do
	{
		while( (*(vetor+i) < meio) && (i< fim))
			i++;
			
		while( (*(vetor+j) > meio) && (j > inicio))
			j--;
			
		if( i <= j)
		{
			aux = *(vetor+i);
			*(vetor+i) = *(vetor+j);
			*(vetor+j) = aux;
			i++;
			j--;
		}	
	}while(i <= j);
	
	if(j > inicio)
		quick(vetor, inicio, j);
		
	if(i < fim)
		quick(vetor, i, fim);
}

int main()
{
	char vetor[10] = "william";
	int t,i;
	t = strlen(vetor);
	
	printf("\tOrdenar Vetor em ordem crescente:\n\nVetor: %s\n", vetor);
	
	quick(vetor, 0, t);
	
	printf("\nVetor ordenado:");
	for(i=0; i<=t; i++)
		printf("%c", *(vetor+i));
	return 0;
}
