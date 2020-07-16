/*
RA 180037 William Alfred Gazal Junior
RA 190176 Emanuela Lopez
RA 190414 Gabriely Pelissen
RA 190275 Danielle Zeferino
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	char texto[80];//= "facens - computacao utiliza computadores";
	char busca[20];//="put";
	int i,j,k,t1,t2,total=0;
	
	printf("Digite o texto: ");
	gets(texto);
	
	printf("\nlocalizar: ");
	gets(busca);
	
	t1=strlen(texto);
	t2=strlen(busca);
	
	for(i=0; i<t1; i++)
		if(texto[i]==busca[0])
		
			for(j=0; j<t2; j++)
			{
				if(texto[i+j]==busca[j])
				{
					if(j==t2-1)
					{
						total++;
						printf("\n\nIndices: ");
						
						for(k=0; k<t2; k++)				
							printf("%i ",i+1+k);
					}	
				}
				else
					j=t2;
			}
			
	if(total==0)
		printf("\n\nnao houve ocorrencias.");
	else
		printf("\n\nTotal de ocorrencias: %i",total);
		
	getch();
		
	return 0;
}
