//william junior 180037
#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *vetor)
{
	int i,j,aux;
	
	for(i=0; i<16; i++)
		for(j=0; j<16-i; j++)
			if( *(vetor+j) > *(vetor+j+1) )
			{
				aux = *(vetor+j+1);
				*(vetor+j+1) = *(vetor+j);
				*(vetor+j) = aux;
			}	
}
//-------------------------------------------------------------------------------------------------------------
void QuickSort(int *vetor, int inicio, int fim)
{
	int i, j, k, meio, aux;
	
	i = inicio;
	j = fim;	
	meio= *(vetor+( (inicio+fim) /2 ) );
	
	do
	{
		while( *(vetor+i) < meio )
			i++;
		
		while( *(vetor+j) > meio )
			j--;
			
		if(i <= j)
		{
			aux = *(vetor+i);
			*(vetor+i) = *(vetor+j);
			*(vetor+j) = aux;
			i++;
			j--;
		}
		
	}while(i <= j);
	
	
	if(inicio < j)
		QuickSort(vetor, inicio, j);
	
	if(i < fim)
		QuickSort(vetor, i, fim);
}
//-------------------------------------------------------------------------------------------------------------
int main()
{
	int vetor[16] = {3, 4, 9, 2, 5, 8, 2, 1, 7, 4, 6, 2, 9, 8, 5, 1};
	int op,a=0,i;
	
	
	printf("\tQual metodo voce deseja usar para ordenar:\n\n1 - Bubble Sort\n2 - Quick Sort\n opcao: ");
	
	do
	{
		if(a!=0)
			printf("opcao invalida!\nDigite novamente: ");
		scanf("%i", &op);
		a++;
	}while(op<1 || op>2);
	
	printf("\nVetor desordenado:\n");
	for(i=0; i<16; i++)
		printf(" - %i", *(vetor+i));
	
	if(op==1)
		BubbleSort(vetor);
		
	if(op==2)
		QuickSort(vetor, 0, 16);
	
	printf("\n\n\tVetor ordenado\n");
	
	for(i=0; i<16; i++)
		printf(" - %i", *(vetor+i));
	return 0;
}
