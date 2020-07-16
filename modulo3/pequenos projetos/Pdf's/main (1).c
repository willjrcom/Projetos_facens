#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
   char *nome;
   int *RA;
   float *nota;
   float media;
}aluno;


void cadastro(aluno *p, int tam);
void aloca_char(char **p, int tam);
void aloca_int(int **p, int tam);
void aloca_float(float **p, int tam);
void aloca_struct(aluno **P, int tam);
void mostra(aluno *p, int tam);


int main()
{
	aluno *pl = NULL;
	int cont = 0;
	char op;
	
	
	do{
		aloca_struct(&pl,cont+1);
		cadastro(pl + cont,cont);
		cont++;
		
		printf("Deseja continuar:\n");
		scanf("%c",&op);
		fflush(stdin);
		
	}while(op!= 'n' && op!='N');
	
	mostra(pl, cont);
}


void cadastro(aluno *p, int tam)
{
	
	char aux[20];
	int tam_aux;
	
	// Nome
	printf("\nNome: ");
	gets(aux);
	fflush(stdin);
	
	tam_aux = strlen(aux) + 1;
	p->nome = NULL;
	
	aloca_char(&(p->nome), tam_aux);
	strcpy(p->nome, aux);
	
	
	// RA
	p->RA = NULL;
	aloca_int( &(p->RA), 1);
	
	printf("\nRA: ");
	scanf("%i",&(p->RA));
	fflush(stdin);
	
	
	//1a Nota
	aloca_float( &(p->nota), 2);
	
	printf("\n1a nota: ");
	scanf("%f", &p->nota[0] );
	fflush(stdin);
	
	
	//2a Nota
	printf("\n2a nota: ");
	scanf("%f", &p->nota[1]);
	fflush(stdin);
}


void aloca_char(char **p, int tam)
{
	if((*p=(char*)realloc(*p,tam*sizeof(char)))==NULL)  
		exit(1);
}


void aloca_int(int **p, int tam)
{
	if((*p=(int*)realloc(*p,tam*sizeof(char))) == NULL)
		exit(1);
}


void aloca_float(float **p, int tam)
{
	if((*p=(float*)calloc(tam, sizeof(float))) == NULL)
		exit(1);
}


void aloca_struct(aluno **p, int tam)
{
	if((*p = (aluno*)realloc(*p,tam*sizeof(aluno))) == NULL)
		exit(1);
}


void mostra(aluno *p, int tam)
{
	int i;
	
	for(i=0; i<tam; i++)
	{
		printf("\n\tNome: %s\n",(p+i)->nome);
		printf("\nRA: %i",(p+i)->RA);
		printf("\n1a nota: %.2f",(p+i)->nota[0]);
		printf("\t2a nota: %.2f",(p+i)->nota[1]);
	}
}
