#include <stdio.h>
#include <stdlib.h>

void aloca(float *p[10], int tam)
{
	if((*p= (float *) malloc(tam * sizeof(float))) == NULL)
	{
		printf("memoria cheia");
		exit(1);
	}
	printf("\nEnd. alocacao %u",*p);	
}


int main()
{
	int *vetor = NULL,t,i;
	printf("digite o tamanho do vetor: ");
	
	scanf("%i", &t);
	vetor = (int *) malloc (t * sizeof(int));
	
	for(i=0; i<t; i++)
		scanf("%i",(vetor+i));

}
