#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct 
{
	char *nomeMaquina;
	char *ipMaquina;
	char *caminhoMaquina;
} st_servidor;


void alocarStruct(st_servidor **texto, int t)
{
	if((*texto = (st_servidor *)realloc(*texto, t * sizeof(st_servidor))) == NULL)
		exit(1);
}

void alocarChar(char **texto, int t)
{
	if((*texto = (char *)realloc(*texto, t * sizeof(char))) == NULL)
		exit(1);
}

int verificarTotalMaquinas()
{
	FILE *fptr = NULL;
	long int totalMaquinas = 0;
	
	if((fptr = fopen("dados.bin", "rb")) == NULL)
		return totalMaquinas;
	else
	{
		fseek(fptr, 0, 2);
		totalMaquinas = ftell(fptr) / sizeof(st_servidor);	
		fclose(fptr);
		
		return totalMaquinas;
	}
}

void salvarDados(st_servidor *dados)
{
	size_t length;
	FILE *fptr = NULL;
	
	if((fptr = fopen("dados.bin", "ab")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else{
		
		length = strlen(dados->caminhoMaquina)+1;
		fwrite(&length, sizeof(length), 1, fptr);
		fwrite(dados->caminhoMaquina, 1, length ,fptr);
		
		length = strlen(dados->ipMaquina)+1;
		fwrite(&length, sizeof(length), 1, fptr);
		fwrite(dados->ipMaquina, 1, length, fptr);
		
		length = strlen(dados->nomeMaquina)+1;
		fwrite(&length, sizeof(length), 1, fptr);
		fwrite(dados->nomeMaquina, 1, length, fptr);
		
	}
	fclose(fptr);
	
}

void tratarCaminho(st_servidor *dados)
{
	int i, j, cont = 1;
	
	if(dados->caminhoMaquina[0] == '\\')
		dados->caminhoMaquina[0] = '/';

	if(dados->caminhoMaquina[1] == '\\')
		dados->caminhoMaquina[1] = '/';

	for(i = 2; i < strlen(dados->caminhoMaquina); i++)
		if(dados->caminhoMaquina[i] == '\\')
		{
			alocarChar(&dados->caminhoMaquina, strlen(dados->caminhoMaquina) + cont++);
			
			for(j = strlen(dados->caminhoMaquina) + cont + 1; j > i; j--)
				dados->caminhoMaquina[j+1] = dados->caminhoMaquina[j];
		}
		
	for(j = 2; j < strlen(dados->caminhoMaquina) + cont + 1; j++)
		if(dados->caminhoMaquina[j] == '\\')
		{
			dados->caminhoMaquina[j] = '/';
			dados->caminhoMaquina[j+1] = '/';
		}
}


void cadastro(st_servidor *dados)
{
	int i;
	char auxNome[30], auxIp[20], auxCaminho[300], opIp;
	
	dados->nomeMaquina = NULL;
	dados->ipMaquina = NULL;
	dados->caminhoMaquina = NULL;
	
	system("CLS");
	printf("\n----- Cadastrar Maquina -----");
	
	printf("\n\nNome da maquina: ");
	gets(auxNome);
	fflush(stdin);
	
	do
	{
		printf("\nDeseja adicionar o Ip da maquina? <s/n>: ");
		opIp = getch();
		fflush(stdin);

	}while(opIp != 's' && opIp != 'S' && opIp != 'N' && opIp != 'n');
	
	
	if(opIp == 's' || opIp == 'S')
	{

		printf("\nNumero do Ip: ");
		scanf("%s", auxIp);
		fflush(stdin);
		
		alocarChar(&dados->ipMaquina, strlen(auxIp)+1);
		
		dados->ipMaquina = auxIp;
	}
	else
	{
		alocarChar(&dados->ipMaquina, 12);
		strcpy(dados->ipMaquina, "000.000.0.0");
	}
		
	printf("\nDigite o caminho de acordo com o exemplo:\n\n \\\\NOME_MAQUINA\\USUARIO\\PUBLIC\\PASTA\\ONLINE.TXT\n *nao utilize espacos*\n--> ");
	scanf("%s", &auxCaminho);
	fflush(stdin);
	
	alocarChar(&dados->nomeMaquina, strlen(auxNome)+1);
	alocarChar(&dados->caminhoMaquina, strlen(auxCaminho)+1);
	
	strcpy( dados->nomeMaquina , auxNome);
	strcpy( dados->caminhoMaquina , auxCaminho);
	
	tratarCaminho(dados);
	salvarDados(dados);
	
	printf("\nMaquina: %s", dados->nomeMaquina);
	printf("\nIP: %s", dados->ipMaquina);
	printf("\nCaminho: %s", dados->caminhoMaquina);
	printf("\nPressione qualquer tecla...");
	
	getch();
}


void lerDados(st_servidor *p, int totalMaquinas)
{
	int i;
	size_t length;
	FILE *fptr = NULL;
	
	if((fptr = fopen("dados.bin", "rb")) == NULL)
		printf("\nArquivo inexistente!\n");
		
	else
		for(i = 0; i<totalMaquinas; i++)
		{
			fseek(fptr, i * sizeof(st_servidor), 0);
			
			fread(&length, sizeof(length), 1, fptr);
			p->caminhoMaquina = malloc(length);
			fread(p->caminhoMaquina, 1, length, fptr);
			
			fread(&length, sizeof(length), 1, fptr);
			p->ipMaquina = malloc(length);
			fread(p->ipMaquina, 1, length, fptr);
			
			fread(&length, sizeof(length), 1, fptr);
			p->nomeMaquina = malloc(length);
			fread(p->nomeMaquina, 1, length, fptr);
			
			if(p->nomeMaquina != NULL)
			{
				printf("\n\n\tMaquina %i", i+1);
				printf("\n Nome: ");
				puts(p->nomeMaquina);
				printf("\n IP: %s\n Caminho: %s\n\n", p->ipMaquina, p->caminhoMaquina);	
			}
			
		}
	fclose(fptr);
	system("pause");
}

int main()
{
	st_servidor *dados = NULL;
	int op, op1;
	int totalMaquinas;
	
	alocarStruct(&dados, 1);
	
	totalMaquinas = verificarTotalMaquinas();
	
	//if(totalMaquinas != 0)
	//	alocarStruct(&dados, totalMaquinas);
			
	do
	{
		do
		{
			system("CLS");
			
			printf("\n\tMenu de opcoes"
				"\n1 - Cadastrar Maquina"
				"\n2 - Verificar maquinas Online"
				"\n3 - Sair"
				"\n<1/2/3>: ");
			scanf("%i", &op);
			fflush(stdin);
			
			system("CLS");
		}while(op < 1 || op >3);
			
		switch(op)
		{
			case 1: 
					cadastro(dados);
					totalMaquinas++;
				break;
				
			case 2: lerDados(dados, totalMaquinas);
				break;
				
			case 3: exit(1);
				break;
		}
	}while(1);
}

