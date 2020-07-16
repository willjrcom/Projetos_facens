//William Junior 180037
//Pablo Moral 190142

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	int codigo;
	char nome[100]; 
	float salario; 
	float bonus; 
	int idade; 
	char sexo; 
}st_funcionario;


void alocarStruct(st_funcionario **texto, int t)
{
	if((*texto = (st_funcionario*) realloc(*texto, t * sizeof(st_funcionario))) == NULL)
		exit(1);
}


void cadastro(st_funcionario *dados)
{
	static int codigo = 1000;
	system("cls");
	
	dados->codigo = codigo++;
	
	printf("\nNome: ");
	scanf("%s[^ ]", &(dados->nome));
	fflush(stdin);
	
	printf("\nSalario: ");
	scanf("%f", &(dados->salario));
	fflush(stdin);
	
	printf("\nIdade: ");
	scanf("%i", &(dados->idade));
	fflush(stdin);
	
	printf("\nSexo: <M/F>: ");
	scanf("%c", &(dados->sexo));
	fflush(stdin);
	
	dados->bonus = 0;
}


void calculo(st_funcionario *dados, int totalCadastros)
{
	int codigo, i;
	
	system("cls");
	
	printf("\nCodigo de cadastro: ");
	scanf("%i", &codigo);
	
	for(i = 0; i < totalCadastros; i++)
		if(codigo == ((dados + i)->codigo))
		{
			dados += i;
			dados->bonus = (dados->salario) * 0.1;
			
			printf("\nNome: %s\nCodigo: %i\nSalario: %.2f\nBonus: %.2f\nSalario + bonus: %.2f\n", dados->nome, dados->codigo, dados->salario, (dados->salario) * 0.1, dados->bonus + dados->salario);
			
			system("PAUSE");
		}		
}


void mulheres(st_funcionario *dados, int totalCadastros)
{
	int i;
	
	system("cls");
	
	for(i = 0; i < totalCadastros; i++)
		if((dados + i)->sexo == 'f')
		{
			printf("\n\n---------------------------------------------------");
			printf("\n\tNome: %s\nCodigo: %i\nSalario: %.2f\nBonus: %.2f\nSalario + bonus: %.2f\n", (dados + i)->nome, (dados + i)->codigo, (dados + i)->salario, ((dados + i)->salario) * 0.1, (dados + i)->bonus + (dados + i)->salario);
		}
	system("pause");
}


void media(st_funcionario *dados, int totalCadastros)
{
	int i;
	float media = 0;
	
	system("cls");
	
	for(i = 0; i < totalCadastros; i++)
	{
		media += (dados + i)->salario;
	}
	media /= totalCadastros;
	
	for(i = 0; i < totalCadastros; i++)
		if((dados + i)->salario >= media)
		{
			printf("\n\n---------------------------------------------------");
			printf("\n\tNome: %s\nCodigo: %i\nSalario: %.2f\nBonus: %.2f\nSalario + bonus: %.2f\n", (dados + i)->nome, (dados + i)->codigo, (dados + i)->salario, ((dados + i)->salario) * 0.1, (dados + i)->bonus + (dados + i)->salario);
		}
	system("pause");
}


int main()
{
	st_funcionario *dados = NULL;
	int op, totalCadastros = 0;
	
	do
	{
		printf("--- Sistema de controle de Funcionarios ---");
		printf("\n\n[1] - Cadastro de funcionario"
				"\n[2] - Calculo de bonificacao"
				"\n[3] - Exibir apenas as mulheres"
				"\n[4] - Funcionario(as) com salario maior que a media"
				"\n[5] - Sair"
				"\nOpcao: ");
		scanf("%i", &op);
			
			switch(op)
			{
				case 1:
					alocarStruct(&dados, totalCadastros + 1);
					cadastro(dados + totalCadastros);
					totalCadastros++;
					break;
					
				case 2:
					calculo(dados, totalCadastros);
					break;
				case 3:
					mulheres(dados, totalCadastros);
					break;
				case 4:
					media(dados, totalCadastros);
					break;
				case 5:
					return 0;
					break;
			};
		
		system("cls");
		
	}while(op != 5 );
	
	return 0;
}
