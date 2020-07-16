#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[20];
	int idade;
	int ra;
}st_aluno;

void aloca(st_aluno **texto, int t)
{
	if((*texto = (st_aluno *) realloc(*texto, t * sizeof(st_aluno))) == NULL)
	exit(1);
}

int main()
{
	st_aluno *v_aluno = NULL;
	char v_nome[20];
	int v_idade;
	int v_ra;
	int contador = 0;
	int op = 1, i;
	
	do{
		
		aloca(&v_aluno, contador+1);
		contador += 1;
		
		printf("\nAluno %i\nDigite o nome: ", contador);
		gets(v_nome);
		fflush(stdin);
		
		printf("Digite a idade: ");
		scanf("%i", &v_idade);
		fflush(stdin);
		
		printf("Digite o ra: ");
		scanf("%i", &v_ra);
		fflush(stdin);
		
		strcpy(v_aluno[contador-1].nome, v_nome);
		v_aluno[contador-1].idade = v_idade;
		v_aluno[contador-1].ra = v_ra;
	
		printf("Deseja continuar? <0 - nao/1 - sim>: ");
		scanf("%i", &op);
		fflush(stdin);
	
	}while(op != 0);
	
	for(i=0; i<contador; i++)
		printf("\n\nNome: %s\nIdade: %i\nRA: %i", v_aluno[i].nome, v_aluno[i].idade, v_aluno[i].ra);
	
	return 0;
}
/*
strcpy(v_aluno.nome, "will");
	v_aluno.idade = 20;
	v_aluno.ra = 180037;
*/
