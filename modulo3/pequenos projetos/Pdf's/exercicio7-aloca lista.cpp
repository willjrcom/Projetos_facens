#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char *nome;
    char *curso;
}aluno;


void aloca_struct(aluno **p, int tam);

void aloca_char(char **pc, int taux);

void aloca_lista(char ***plista, int tlista);

void cadastro(aluno *p, int tam, char ***plista, int *tlista);

void mostra(aluno *p, int tam);

void mostra_lista(char **plista, int tlista);

void maiuscula(char *pc, int taux);

char* busca_lista(char **plista, int tlista, char *aux);


main()
{
	aluno *paluno = NULL;
	int cont = 0, clista = 0;
	char op, **lista = NULL;
	
	do
	{
		  aloca_struct(&paluno, cont + 1);
		  cadastro(paluno, cont, &lista, &clista);
		  cont++;
		  
		  printf("\nDeseja continuar: ");
		  scanf("%c", &op);
		  fflush(stdin);
		  
	}while(op != 'n' && op != 'N');
	
	mostra(paluno, cont);
}//main


void aloca_struct(aluno **p, int tam)
{
	if((*p = (aluno*) realloc(*p, tam * sizeof(aluno))) == NULL)
	  	exit(1);
}//aloca_struct


void aloca_char(char **pc, int taux)
{
	if((*pc = (char*) realloc(*pc, taux * sizeof(char))) == NULL)
	  	exit(1);
}//aloca_char


void aloca_lista(char ***plista, int tlista)
{
	if((*plista = (char**) realloc(*plista, tlista * sizeof(char*))) == NULL)
		exit(1);
}//aloca_lista


void cadastra_curso(char **plista, int tlista)
{
	int i,taux;
	char aux[20];
	
	printf("\nCadastro de Cursos\n");
	
	for(i = 0; i < tlista; i++)
	{
		*(plista + i) = NULL;	  // mostrar PPT
		
		printf("\nCurso: ");
		gets(aux);
		fflush(stdin);
		
		taux = strlen(aux) + 1;  //+1 por conta do \0
		maiuscula(aux, taux);
			
		aloca_char((plista + i), taux);
		strcpy(*(plista + i), aux);
	}//for 
}//cadastra_curso
	
	
void cadastro(aluno *p, int tam, char ***plista, int *tlista)
{
	printf("\ntlista: %i", *tlista);
	
	char aux[20];
	int taux;
	
	//nome
	printf("\nNome: ");
	gets(aux);
	fflush(stdin);
	
	taux = strlen(aux) + 1;  //+1 por conta do \0
	(p + tam)->nome = NULL;
	
	aloca_char( &((p + tam)->nome), taux);
	strcpy((p + tam)->nome, aux);
	//curso
	
	mostra_lista(*plista, *tlista);   //PONTO de ATENçÃo
	
	do
	{
		printf("\nCurso: ");
	  	gets(aux);
	  	fflush(stdin);
	  	
	  	taux = strlen(aux) + 1;  //+1 por conta do \0
	  	maiuscula(aux, taux);
	  	
	  	(p + tam)->curso = busca_lista(*plista, *tlista, aux);  // PONTO ATENçÃO
	  	
	  	if((p + tam)->curso == NULL)  //nao achou
	    {
		    aloca_lista(plista, *tlista + 1);
		    *(*plista + *tlista) = NULL;  //inicializando com NULL dentro da lista - mostrar PPT
		    
			aloca_char(*plista + *tlista, taux + 1);   //alocar espaço para curso através de lista
			strcpy( *(*plista + *tlista), aux);     //copia o curso
			
			(p + tam)->curso = *(*plista + *tlista);  //end. curso dentro da lista
			(*tlista)++;
	    }//if
	    
	  }while((p + tam)->curso == NULL);  //só sai qdo cadastrar algum curso existente
}//cadastro


void mostra(aluno *p, int tam)
{
	int i;
	
	for(i = 0; i < tam; i++)
	{
	  	printf("\nEstrutura %i", i); 
	  	printf("\nEndereco: %u - Conteudo: %u - Nome: %s\n", &(p + i)->nome, (p + i)->nome, (p + i)->nome);
	  	printf("\nEndereco: %u - Conteudo: %u - Curso: %s\n", &(p + i)->curso, (p + i)->curso, (p + i)->curso);
	}
	system("pause");
	
}//mostra


void mostra_lista(char **plista, int tlista)
{
	int i;
	
	for(i = 0; i < tlista; i++)  // mostra PPT
		printf("\nEndereco: %u - Conteudo: %u - Curso: %s\n", (plista + i), *(plista + i), *(plista + i));
		
}//mostra_lista
   
   
void maiuscula(char *p, int taux)
{
	int i;
	
	for(i = 0; i < taux; i++)
		if(*(p + i) >= 'a' && *(p + i) <= 'z')
	    	*(p + i) -= 32;
	    	
}//maiuscula


char* busca_lista(char **plista, int tlista, char *aux)
{
	int i;
	
	for(i = 0; i < tlista; i++)
		if(strcmp(*(plista + i), aux) == 0)  //achou
	    	return (*(plista + i));  //endereco do curso
	return NULL;
	
}//busca_lista


