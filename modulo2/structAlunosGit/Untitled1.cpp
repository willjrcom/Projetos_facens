#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[30];
	int ra;
	
	struct
	{
		float *notas;
	};
}st_aluno;


void alocarStruct(st_aluno **texto, int t)
{
	if((*texto = (st_aluno *) realloc (*texto, t * sizeof(st_aluno))) == NULL)
		exit(1);
}

void alocarFloat(float **texto, int t)
{
	if((*texto = (float *) calloc(t, sizeof(float))) == NULL)
		exit(1);
}


int main()
{
	st_aluno *dados = NULL;
	char auxNome[30];
	int auxRa, cont = 0, op, totalNotas, i, j;
	
	do
	{
		alocarStruct(&dados, cont + 1);
		
		printf("\n\nNome: ");
		gets(auxNome);
		fflush(stdin);
		
		printf("\nRa: ");
		scanf("%i", &auxRa);
		fflush(stdin);
		
		strcpy(dados[cont].nome, auxNome);
		dados[cont].ra = auxRa;
		
		printf("\nnome: %s", dados[cont].nome);
		printf("\nra: %i", dados[cont].ra);	
		
		printf("\nTotal de notas: ");
		scanf("%i", &totalNotas);
		fflush(stdin);
		
		alocarFloat(&dados[cont].notas, totalNotas);
		dados[cont].notas[0] = totalNotas;
		
		for(i = 1; i <= dados[cont].notas[0]; i++)
		{
			printf("\nNotas %i:", i);
			scanf("%f", &dados[cont].notas[i]);
			fflush(stdin);
		}
		
		cont++;
		
		printf("\n0 - Sair\n1 - continuar\n<0/1>: ");
		fflush(stdin);
		scanf("%i", &op);
		fflush(stdin);
		
	}while(op != 0);
	
	for(i = 0; i < cont; i++)
	{
		printf("\n\n====================");
		printf("\nNome: %s", dados[i].nome);
		printf("\nRa: %i", dados[i].ra);
		printf("\n\nNotas:");
		
		for(j = 1; j <= dados[i].notas[0]; j++)
		{
			printf("\nNota %i: %f", j, dados[i].notas[j]);
		}
	}
	return 0;
}
