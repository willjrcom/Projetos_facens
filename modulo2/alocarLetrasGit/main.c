//william junior 180037
//joel ribeiro 190304

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void aloca( char **texto, int t)
{
	if((*texto = (char *) realloc(*texto, t * sizeof(char))) == NULL)
	exit(1);
}
//--------------------------------------------------------------------------

void ler(char *texto, int t)
{
	printf("\nNome: ");
	gets(texto);
	fflush(stdin);
}
//-------------------------------------------------------------------------

void realocar(char *nomes, int t,char x, int n)
{
	int i;
	aloca(&nomes,t+1);
	
	for(i=t; i>=n; i--)
	{
		*(nomes+i+1)= *(nomes+i);
	}
	*(nomes+n)=x;
	
}
int main()
{
	char palavra[20],x, *nomes = NULL, op;
	int t=1,n;
	
	aloca(&nomes, t);
	*nomes = '\0';
	do
	{
		aloca(&nomes, t);
		
		ler(palavra,t);
		
		t+= strlen(palavra)+1;
		
		strcat(nomes, "\n");
		strcat(nomes, palavra);
		
		
		printf("\ndeseja continuar?  <s/n>: ");
		scanf("%c", &op);
		fflush(stdin);
		
	}while(op == 's' || op == 'S');
	
	printf("Lista de Nomes:\n%s\ntotal de caracteres: %i", nomes, strlen(nomes));
	
	do
	{
	printf("\n\nLetra a ser inserida: ");
	scanf("%c",&x);
	fflush(stdin);	
	
	printf("\nNa posicao: ");
	scanf("%i", &n);
	fflush(stdin);
	
	realocar(nomes, strlen(nomes), x,n);
	printf("Lista de Nomes:\n%s", nomes);
	
	printf("\ndeseja continuar?  <s/n>: ");
		scanf("%c", &op);
		fflush(stdin);
	}while(op == 's' || op == 'S');
	
	return 0;
}
