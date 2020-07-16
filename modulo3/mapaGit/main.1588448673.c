#include <stdio.h>
#include <stdlib.h>


typedef struct
{
	char *Cidade;
	char *Bairro;
}st_dados;


void alocarStruct(st_dados **p, int t)
{
	if((*p = (st_dados*)realloc(*p, t * sizeof(st_dados))) == NULL)
	exit(1);
}


void alocarLista(char ***p, int t)
{
	if((*p = (char**)realloc(*p, t * sizeof(char*))) == NULL)
	exit(1);
}


void alocarChar(char **p, int t)
{
	if((*p = (char*)realloc(*p, t * sizeof(char))) == NULL)
	exit(1);
}


//opcao 2
void criarBairro(char **p, int *contBairro)
{
	char auxBairro[30];
	*(*p + *contBairro) = NULL;
	
	fflush(stdin);
	system("cls");
	printf("\nDigite o nome do bairro: ");
	gets(auxBairro);
	fflush(stdin);
	
	alocarChar(**p + *contBairro, strlen(auxBairro + 1));
	strcpy( *(*p + *contBairro), auxBairro); //era pra ser o bairro
	
	printf("%s", *(*p + *contBairro));
	printf("\nBairro cadastrado!\n\n");
	system("pause");
}


//opcao 3
void cadastrarRuas(char **p, int *contBairro)
{
	int i = 0, n, endP;
	char auxRua[50], auxRua1[50];
	
	system("cls");
	printf("\n\nBairros cadastrados:");
	
	while(*(*p + i))
	{
		i++;
		printf("\n%i - %s", i+1, *(*p + i - 1)); //era pra ser o bairro
		
	}
	printf("\nEscolha o N de um bairro acima: ");
	scanf("%i", &n);
	
	n -= 1;
	
	printf("\nBairro escolhido: %s\nCadastrar rua: ", *(p + n));
	scanf("%s", &auxRua);
	scanf("%s", &auxRua1);
	alocarChar( *(p + n), 2); //criar a alocacao do bairro
	
	
	//alocarChar( *(p + n) + 0), strlen(auxRua) + 1);
	//alocarChar( *(p + n) + 1), strlen(auxRua1) + 1);
	
	strcpy( *(p + n) + 0, auxRua); // era pra ser a rua
	strcpy( *(p + n) + 1, auxRua1); // era pra ser a rua
	
	system("pause");
	
	
}


//opcao 4
void mostrarEnd(char **p, int contBairro)
{
	int i, j, n;
	char auxRua[50];
	
	system("cls");
	printf("\n\nBairros cadastrados:");
	
	for(i = 0; i < contBairro; i++)
	{
		printf("\n%i - %s", i+1, (*(p + i))); //era pra ser o bairro
		for(j = 0; j < 2; j++)
			printf("\n%s", *(p + n) + j); // era pra ser a rua
	}
}


int main()
{
	st_dados *dados = NULL;
	char **lista = NULL;
	int op, contBairro = 0, contRua = 0;
	
	do
	{
		do
		{
			system("cls");
			printf("\tOpcoes:");
			printf("\n[1] - Cadastrar Cidade");
			printf("\n[2] - Cadastrar Bairro");
			printf("\n[3] - Cadastrar Rua");
			printf("\n[4] - Procurar Endereco");
			printf("\n[5] - Sair");
			printf("\n<1/2/3/4/5>: ");
			
			fflush(stdin);
			scanf("%i", &op);
			fflush(stdin);
				
		}while(op < 1 || op > 5);
	
		switch(op)
		{
			case 1: 
				break;
				
			case 2: 
				alocarLista(&lista, contBairro + 1);
				criarBairro(&lista , &contBairro);
				contBairro++;
				break;
				
			case 3: 
				cadastrarRuas(&lista, &contBairro);
				break;
				
			case 4: 
				mostrarEnd(&lista, &contBairro);
				break;
				
			case 5: 
				printf("\nPrograma finalizado com sucesso!");
				exit(1);
				break;
		}
		
	}while(op != 5);
	
	
	return 0;
}
