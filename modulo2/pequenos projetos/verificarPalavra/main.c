#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
	char letra;
	int posicao[20];
	int cont;
}registros;
registros dados[5];
	
//------------------------------------------------------------------------------
void realocar(char **texto,int t)
{
	if( (*texto = (char *) realloc(*texto, t* sizeof(char))) == NULL)
	exit(1);
}
//------------------------------------------------------------------------------
void verificar(char *texto, int t)
{
	

}
//------------------------------------------------------------------------------
int main()
{

	char *texto = NULL,*vetor = NULL, palavra[20];
	int t=0, op=1, i,j;
	
	realocar(&texto, 1);
	*texto = '\0';
	
	
	printf("--------alocacao dinamica----------");
	while(op == 1)
	{
		printf("\nDigite uma palavra: ");
		gets(palavra);
		fflush(stdin);
		
		t+= strlen(palavra)+1;
		
		strcat(texto,"\n");
		strcat(texto,palavra);	
		
		printf("\nDeseja continuar <1 - sim / 2 - nao>: ");
		scanf("%i", &op);
		fflush(stdin);
	}	
	printf("\nVetor de palavras 2: %s\nTotal de caracteres %i\n", texto, t);

	int contador;
	char letra;
	
	for(j=0; j<5; j++)//contar letras
	{
		if(j == 0)	letra ='a';
		if(j == 1)	letra ='e';
		if(j == 2)	letra ='i';
		if(j == 3)	letra ='o';
		if(j == 4)	letra ='u';
		
		dados[j].cont = 0;
		
		contador=0;
				
		for(i=0; i<t; i++)//contar texto
			
			if( *(texto+i) == letra)
			{
				//dados[j].posicao[i]='\0';
				dados[j].cont += 1;
				dados[j].posicao[contador]= i;
			
				contador+=1;
			}
				
				
		dados[j].letra = letra;
	}
	
	for(i=0; i<5; i++)//mostrar letras
	{
		printf("\nLetra: %c apareceu %i vezes",dados[i].letra, dados[i].cont );
		if(dados[i].cont != 0)
			printf(" nas posicoes:");
			for(j = 0; j < dados[i].cont; j++) {
				printf(" %i", dados[i].posicao[j]);
			}
	}
		
	return 0;
}
//------------------------------------------------------------------------------
