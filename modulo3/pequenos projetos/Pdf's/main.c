#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	char *nome;
	int conta;
	float saldo;
}st_cliente;

//alocacao
void alocaStruct(st_cliente **texto, int t)
{
	if((*texto = (st_cliente *) realloc(*texto, t * sizeof(st_cliente))) == NULL)
	exit(1);
}


void alocaChar(char **texto, int t)
{
	if((*texto = (char *) realloc(*texto, t * sizeof(char))) == NULL)
	exit(1);
}


void cadastro(st_cliente *dados, int totalClientes)
{
	static int numConta = 1000;
	char auxNome[30];
	dados->nome = NULL;
	
	printf("\n\n\nCliente %i \nDigite o nome do cliente: ", totalClientes+1);
	gets(auxNome);
	fflush(stdin);
	
	alocaChar( &(dados->nome), (strlen(auxNome)+1) );
	
	strcpy( (dados->nome) , auxNome);
	dados->conta = numConta;

	printf("\nConta criada com sucesso!");
	printf("\nNome: %s", dados->nome);
	printf("\nConta: %i", dados->conta);
	printf("\nSaldo: R$ %.2f", dados->conta);
	
	numConta++;
}


void saque(st_cliente *dados)
{
	float auxSaque;
	
	printf("Digite o valor que deseja sacar: ");
	scanf("%f", &auxSaque);
	
	if( dados->saldo - auxSaque >= 0 )
		dados->saldo -= auxSaque;
	else
		printf("\nSaldo insuficiente");
	
	printf("\nSaldo: R$ %.2f", dados->saldo);
}


void deposito(st_cliente *dados)
{
	float auxDeposito;
	
	printf("Digite o valor que deseja depositar: ");
	scanf("%f", &auxDeposito);
	
	dados->saldo += auxDeposito;
	
	printf("\nSaldo: R$ %.2f", dados->saldo);
}


int main()
{
	st_cliente *dados = NULL;
	int totalClientes = 0, op, op1;
	
	printf("\tRegistro Bancario");
	
	do
	{
	alocaStruct( &dados, totalClientes+1);
	cadastro( (dados+totalClientes), totalClientes);
	
	do
	{
		printf("\n\nOpcoes do cliente:\n1 - Saque\n2 - Deposito\n3- Sair\n<1/2/3>: ");
		scanf("%i", &op1);
		fflush(stdin);
		
		switch(op1)
		{
			case 1: saque(dados+totalClientes);
				break;
			case 2: deposito(dados+totalClientes);
				break;
		}
			
	}while(op1 != 3);
	
	printf("\nOpcoes de cadastro: \n1 - Continuar cadastros\n2 - Buscar cliente\n3 - Sair\n<1/2/3>: ");
	scanf("%i", &op);
	fflush(stdin);
	
	totalClientes++;
	
	}while(op != 3 || totalClientes == 10);
	
	return 0;
}
