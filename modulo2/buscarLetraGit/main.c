#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar(char *texto)
{
	int cont=0;
	for(;*texto;texto++) cont++;
	return cont;
}
int main()
{
	char texto[80], buscar[20];
	int t1,t2,i,j,k,total=0;
	
	printf("\nTexto: ");
	gets(texto);
	
	printf("\nBuscar: ");
	scanf("%s",&buscar);
	
	t1= contar(texto);
	t2= contar(buscar);
	
	for(i=0;i<t1;i++)
		if(texto[i]==buscar[0])
		
			for(j=0;j<t2;j++)
			{
				if(texto[j+i]==buscar[j])
				{
					if(j==t2-1)
					{
						total++;
						printf("\nindices: ");
						
						for(k=0;k<t2;k++)
							printf("%i ",i+k+1);
					}
				}
				else
					j=t2-1;
			}
	printf("\nTotal de ocorrencias: %i",total);
	return 0;
}
