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
	int totalMaquinas = 0;
	FILE *fptr = NULL;

	if((verif = fopen("totalMaquinas.txt", "rb")) == NULL)
		return totalMaquinas;
	else
	{
	
		fseek(fptr, 0, 2);
		totalMaquinas = ftell(fptr) / sizeof(st_servidor);	
		fclose(fptr);
		
		return totalMaquinas;
	}
}


void cadastro(st_servidor *dados, int totalMaquinas)
{
	char auxNome[30], auxIp[20], auxCaminho[300], opIp;
	
	dados->nomeMaquina = NULL;
	dados->ipMaquina = NULL;
	dados->caminhoMaquina = NULL;
	
	system("CLS");
	printf("\n----- Cadastrar Maquina -----");
	
	printf("\n\nNome da maquina: ");
	gets(auxNome);
	
	do
	{
		printf("\nDeseja adicionar o Ip da maquina? <s/n>: ");
		opIp = getch();

	}while(opIp != 's' && opIp != 'S' && opIp != 'N' && opIp != 'n');
	
	
	if(opIp == 's' || opIp == 'S')
	{
		printf("\nNumero do Ip: ");
		scanf("%s", &auxIp);
		
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
	
	alocarChar(&dados->nomeMaquina, strlen(auxNome)+1);
	alocarChar(&dados->caminhoMaquina, strlen(auxCaminho)+1);
	
	strcpy( dados->nomeMaquina , auxNome);
	strcpy( dados->caminhoMaquina , auxCaminho);
	
	tratarCaminho(dados);
	salvarCsv(dados);
	
	printf("\n%s", dados->nomeMaquina);
	printf("\n%s", dados->ipMaquina);
	printf("\n%s", dados->caminhoMaquina);
	printf("\nPressione qualquer tecla...");
	
	getch();
}


void salvarCsv(st_servidor *dados)
{
	FILE* csv;
	csv = fopen("dados.csv", "a+b");

	fprintf(csv, "%s,%s,%s,\n", dados->nomeMaquina, dados->ipMaquina, dados->caminhoMaquina);
	fclose(csv);
}


void tratarCaminho(st_servidor *dados)
{
//	//PCLAB04-PC\\Users\\Public\\Documents\\Online.txt			depois
//	\\PCLAB04-PC\Users\Public\Documents\Online.txt				antes

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


void lerDados(st_servidor *dadosSalvos, int totalMaquinas)
{
	int i, cont = 0;
	char auxNome[30], auxIp[20], auxCaminho[300];

	FILE *salvar;
	salvar = fopen("dados.csv", "rb");
	
	while(!feof(salvar))
	{	
		for(i = 0; i < 3; i++)
		{
			if(i == 0)
			{
				fscanf(salvar,"%[^,]", &auxNome);
				printf("parou");
				fflush(stdin);
				
				alocarChar(&((dadosSalvos+cont)->nomeMaquina), strlen(auxNome) + 1);
				printf("parou1");
				
				strcpy((dadosSalvos+cont)->nomeMaquina, auxNome);
				printf("parou2");
			}
								
			if(i == 1)
			{
				fscanf(salvar,"%s[^,]", &auxIp);
				fflush(stdin);
				
				alocarChar(&((dadosSalvos+cont)->ipMaquina), strlen(auxIp) + 1);
					
				strcpy((dadosSalvos+cont)->ipMaquina, auxIp);
			}
	
			if(i == 2)
			{
				fscanf(salvar,"%s[^,]", &auxCaminho);
				fflush(stdin);
				
				alocarChar(&((dadosSalvos+cont)->caminhoMaquina), strlen(auxCaminho) + 1);	
				
				strcpy((dadosSalvos+cont)->caminhoMaquina, auxCaminho);
			}
		}
		
		if(cont != totalMaquinas)
			cont++;
	}
	fclose(salvar);
	//ptr = strtok(texto, ";");
	
}


void maquinas(st_servidor *dados, int totalMaquinas)
{
	int i, j;
	
	printf("\tPCs Online");
	for(j = totalMaquinas - 1; j >= 0; j--)
	{
		printf("\n\nPC: %s", dados[j].nomeMaquina);
			
		FILE *pc;
		pc = fopen(dados[j].caminhoMaquina, "rb");
	
		if(pc == NULL)
			printf("\n---Offline!\n");
		else
			printf("\n---Online!\n");
		
		fclose(pc);	
	}
	
	for(i = 0; i < 3; i++)
	{
		sleep(3);
		printf(".");
	}	
	system("CLS");
}


int main()
{
	st_servidor *dados = NULL;
	st_servidor *dadosSalvos = NULL;
	int op, op1;
	int totalMaquinas;
	
	totalMaquinas = verificarTotalMaquinas();
	lerDados(dadosSalvos, totalMaquinas);
	do
	{
		do
		{
			//system("CLS");
			
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
			case 1: alocarStruct(&dados, totalMaquinas+1);
					cadastro(dados + totalMaquinas, totalMaquinas);
					totalMaquinas++;
				break;
			case 2: maquinas(dadosSalvos, totalMaquinas);
				break;
			case 3: exit(1);
				break;
		}
	}while(1);
}
