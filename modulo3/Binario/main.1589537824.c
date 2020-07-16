#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	char nome[20];
	int idade;
	
}st_dados; 


void alocaStruct (st_dados **p, int t)
{
	if((*p = (st_dados *)realloc(*p, t * sizeof(st_dados))) == NULL)
		exit(1);
}


int verificar()
{
	FILE *fptr = NULL;
	long int cont = 0;
	
	if((fptr = fopen("arquivo.bin", "rb")) == NULL)
		return cont;
	else
	{
		fseek(fptr, 0, 2);
		cont = ftell(fptr)/ sizeof(st_dados);
		fclose(fptr);
		return cont;	
	}
}


void cadastro(st_dados *p)
{
	fflush(stdin);
	printf("\nNome: ");
	gets(p->nome);
	
	printf("\nIdade: ");
	scanf("%i", &(p->idade));
	fflush(stdin);
	
	gravar(p);
}


void gravar(st_dados *p)
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("arquivo.bin","ab+")) == NULL)
		printf("\nespaco insulficiente");
	else
		fwrite(p, sizeof(st_dados),1, fptr);
	
	fclose(fptr);
}


void mostrar(st_dados *p, int cont)
{
	FILE *fptr = NULL;
	int i;
	
	if((fptr = fopen("arquivo.bin", "rb")) == NULL)
		printf("\nespaco insulficiente");
	else
		for(i = 0; i<cont; i++)
		{
			fseek(fptr, i * sizeof(st_dados), 0);
			fread(p, sizeof(st_dados), 1, fptr);
			printf("\n\nNome: %s\nIdade: %i", p->nome, p->idade);
		}
	fclose(fptr);
}


int main()
{
	st_dados *dados = NULL;
	int cont, op;
	
	alocaStruct(&dados, 1);
	cont = verificar();

	do
	{
		alocaStruct(&dados, cont+1);
		cadastro(dados + cont);
		cont++;
		
		fflush(stdin);
		printf("\n\nsair <1>:");
		scanf("%i", &op);
		
	}while(op != 1);
	
	mostrar(dados, cont);
	
	return 0;
}

