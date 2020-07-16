#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar(char *vetor)
{
	int i,j,k;
	char aux;
	
	printf("\n letra %c", (*(vetor+20*0)) );
	
	for(i=0; i<8; i++)
	{
		for(j=0; j<7; j++)
		{
			if( *(vetor+20*j) > *(vetor+20*j+20) )
			{
				
				//for(k=0; k<20; k++)
				{
					printf("oi");
					strcpy( aux              ,   *(vetor+20*j) );
    				strcpy( *(vetor+20*j)    ,   *(vetor+20*j+20) );
  					strcpy( *(vetor+20*j+20) ,   aux);
				}	
			}
		}
	}
}

int main()
{
	int i;
	char vetor[8][20]= {"kevin", "beto", "alberto", "otavio", "livia", "marcos", "ana", "neiva"};
	
	printf("Nomes desordenados:");
	for(i=0; i<8; i++)
		printf("\n%s", vetor+i);
		
	ordenar(vetor);
	
	printf("Nomes ordenados:");
	for(i=0; i<8; i++)
		printf("\n%s", vetor+i);
	return 0;
}
