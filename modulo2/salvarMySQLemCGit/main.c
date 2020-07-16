#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <conio.h>


//Struct
typedef struct
{
	char *nomeAluno;
	char *nomeEscola;
	int ra;
	float *notas;
	float mediaAluno;
}st_escola;


//alocação dinamica
void alocarChar(char **texto, int t)
{
	if((*texto = (char *) malloc(t * sizeof(char))) == NULL)
	{
		printf("\nMemoria insuficiente para alocar char!");
		exit(1);
	}	
}


void alocarFloat(float **numeros, int t)
{
	if((*numeros = (float *) calloc(t, sizeof(float))) == NULL)
	{
		printf("\nMemoria insuficiente para alocar float!");
		exit(1);
	}
}


void alocarStructEs(st_escola **structTxt, int t)
{
	if((*structTxt = (st_escola *) realloc(*structTxt, t * sizeof(st_escola))) == NULL)
	{
		printf("\nMemoria insuficiente para alocar struct!");
		exit(1);
	}
}


//Arquivos
void criarProjetoMySQL()
{
	DIR *dir;
		
		dir = opendir("PROJETO_MySQL");
		
		if(dir == NULL)
			system("mkdir PROJETO_MySQL");
		
	FILE* criar;
	criar = fopen("PROJETO_MySQL//criarDados.sql","r");
	
	if(criar == NULL)
	{
		criar = fopen("PROJETO_MySQL//criarDados.sql","w");
		
		fprintf(criar, "\nCREATE DATABASE PROJETO_STRUCT_C;"
				  	   "\n\nUSE PROJETO_STRUCT_C;");
	
		fprintf(criar, "\n\nCREATE TABLE DADOS("
							"\n\tNOME VARCHAR(50),"
							"\n\tESCOLA VARCHAR(30),"
							"\n\tRA VARCHAR(6) UNIQUE,"
							"\n\tMEDIA FLOAT(5)"
							"\n\t);");
	}
	fclose(criar);
}


void adicionarValoresMySql(char nome[50], char escola[30], int ra, float media)
{
	FILE* salvar;
	salvar = fopen("PROJETO_MySQL//lerDados.sql", "a");
	
	if(salvar == NULL)
	{
		salvar = fopen("PROJETO_MySQL//lerDados.sql", "w");
		//fprintf(salvar, "\nUSE PROJETO_STRUCT_C;");
	}
	
	//salvar = fopen("PROJETO_MySQL//lerDados.sql", "a");
	fprintf(salvar, "\nINSERT INTO DADOS VALUES('%s', '%s', '%i', '%.2f');\n", nome, escola, ra, media);
	fclose(salvar);
}


void readme()
{
	FILE* leia;
	leia = fopen("PROJETO_MySQL//README.txt", "w");
	fprintf(leia, "Seja bem vindo!"
				"\nEste programa cria um banco de dados em MySQL"
				"\nPara utiliza-lo:" 
				"\n- Instale o MySQL Server"
				"\n\n- Execute os seguintes arquivos dentro do prompt de comando do MySQL:"
				"\n- criarDados.sql"
				"\n- lerDados.sql"
				"\n\nCopyright: William Junior"
				"\nRA: 180037 - Facens - Sorocaba-SP");
	fclose(leia);	
}


int main()
{
	st_escola *dados = NULL;
	int totalAlunos = 0, totalNotas = 0, i, j, op, contMedia;
	int auxRa, tNome, tEscola;
	float auxNotas = 0;
	char auxNome[30], auxEscola[30];
	
	criarProjetoMySQL();
	readme();
	
	printf("--------- Registro de Dados Escolar ---------");
	
	do
	{
		alocarStructEs(&dados, totalAlunos+1);
		
		printf("\n\nDigite o nome do aluno: ");
		gets(auxNome);
		fflush(stdin);
		
		printf("\n\nDigite o nome da escola: ");
		gets(auxEscola);
		fflush(stdin);
		
		printf("\n\nDigite RA do aluno: ");
		scanf("%i", &dados[totalAlunos].ra);
		fflush(stdin);
		
		printf("\n\nDigite o total de notas que serao salvas: ");
		scanf("%i", &totalNotas);
		fflush(stdin);
		
		alocarFloat(&dados[totalAlunos].notas, totalNotas); //alocar espaco necessario de cada variavel
		alocarChar (&dados[totalAlunos].nomeAluno, strlen(auxNome));
		alocarChar (&dados[totalAlunos].nomeEscola, strlen(auxEscola));
		
		strcpy(dados[totalAlunos].nomeAluno, auxNome);	//salvar strings auxiliares na struct
		strcpy(dados[totalAlunos].nomeEscola, auxEscola);
		
		dados[totalAlunos].notas[0] = totalNotas;	//a primeira variavel representa o total de notas seguintes do aluno
		dados[totalAlunos].mediaAluno = 0;
		contMedia = 0;
		
		for(i = 1; i <= dados[totalAlunos].notas[0]; i++)
		{
			printf("\nNota %i: ", i);
			scanf("%f", &dados[totalAlunos].notas[i]);
			fflush(stdin);
			
			dados[totalAlunos].mediaAluno += dados[totalAlunos].notas[i];
			contMedia++;
		}
		dados[totalAlunos].mediaAluno /= contMedia;
		
		adicionarValoresMySql(auxNome, auxEscola, dados[totalAlunos].ra, dados[totalAlunos].mediaAluno);
		
		totalAlunos++;
		do
		{
			printf("Deseja continuar? <0 - nao/1 - sim>: ");
			scanf("%i", &op);
			fflush(stdin);	
			
		}while( op < 0 || op > 1);
	}while(op != 0);
	
	system("CLS");
	
	//i representa o aluno
	//j representa as notas
	for(i = 0; i< totalAlunos; i++)
	{
		printf("\n\n====================================");
		printf("\n\tAluno: %s", dados[i].nomeAluno);
		printf("\nEscola: %s", dados[i].nomeEscola);
		printf("\nRA: %i", dados[i].ra);
		printf("\nTotal de notas: %.0f\n", dados[i].notas[0] );
		
		for(j = 1; j <= dados[i].notas[0]; j++)
			printf("\nNota %i: %.2f", j, dados[i].notas[j]);
		
		printf("\nMedia geral: %.2f", dados[i].mediaAluno);	 
	}
	system("PAUSE");
	return 0;
}
