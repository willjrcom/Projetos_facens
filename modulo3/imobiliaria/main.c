#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////////////////////////////////////////structs
////////////////////////// proprietario
typedef struct 
{
	char logradouro[80];
	char bairro[20];
	char cep[10];
	char cidade[20];
	char estado[20];
	char telefone[15];
	char celular[15];
	char email[30];
}st_end_prop; // endereco proprietario
	
	
typedef struct
{
	int num_casa;
	char status_casa;
}st_status_prop; // status proprietario


typedef struct
{
	int id;
	char nome[80];
	char cpf[15];
	st_end_prop endereco;
	int qtdCasas;
	st_status_prop casa[5];
}st_prop; // cadastro completo proprietario


////////////////////////// imovel
typedef struct
{
	char logradouro[80];
	char bairro[20];
	char CEP[10];
	char cidade[20];
}st_end_imovel; //endereco imovel


typedef struct
{
	char sigla;
	int reg_loc;
}st_status_imovel; //status imovel


union un_dados
{
	char sigla;
	st_status_imovel locacao;
};


typedef struct
{
	int id; // gerado automaticamente
	st_end_imovel end_imovel;
	float area;
	int quartos;
	float valor;
	union un_dados status;
}st_imovel;


/////////////////////////////////////////////////////alocacao
void alocarStruct(st_prop **p, int t)
{
	if((*p = (st_prop*)realloc(*p, t * sizeof(st_prop))) == NULL)
		exit(1);
}


/////////////////////////////////////////////////////funcoes cadastro
void cadastrarProp(st_prop *p, int id)//opcao 1
{
	//nº do registro do proprietário (gerado automaticamente pelo sistema)
	//o nome, CPF
	//endereço: logradouro, bairro, cep, cidade, estado, telefone, celular, email
	//quantidade de imóveis do proprietário
	//a quantidade deve ser inicializada com zero
	//o imóvel – irá conter o número do registro do imóvel e o status [L]ivre ou [A]lugado
	system("cls");
	
	int i, num;
	
	p->id = id; //alterar valor do registro para o proximo cadastro
	
	fflush(stdin);
	printf("\n\tCadastro Proprietario:"
		   "\nID: %i", p->id);
	
	printf("\nDigite o nome: ");
	gets(p->nome);
	fflush(stdin); // receber nome do proprietario
	
	printf("\nDigite o CPF: ");
	gets(p->cpf);
	fflush(stdin); // receber cpf do proprietario
	
	printf("\nCelular: ");
	gets(p->endereco.celular);
	fflush(stdin); // receber celular do proprietario
	
	printf("\nTelefone: ");
	gets(p->endereco.telefone);
	fflush(stdin); // receber telefone do proprietario
	
	printf("\nEmail: ");
	gets(p->endereco.email);
	fflush(stdin); // receber email do proprietario
	
	printf("\nRua: ");
	gets(p->endereco.logradouro);
	fflush(stdin); // receber logradouro do proprietario
	
	printf("\nBairro: ");
	gets(p->endereco.bairro);
	fflush(stdin); // receber bairro do proprietario
	
	printf("\nCidade: ");
	gets(p->endereco.cidade);
	fflush(stdin); // receber cidade do proprietario
	
	printf("\nEstado: ");
	gets(p->endereco.estado);
	fflush(stdin); // receber estado do proprietario
	
	printf("CEP: ");
	gets(p->endereco.cep);
	fflush(stdin); //receber cep do proprietario
	
	
	do
	{
		fflush(stdin);
		printf("Qtd casas [1 - 5]: ");
		scanf("%i", &(p->qtdCasas));
		fflush(stdin);
	}while(p->qtdCasas < 1 || p->qtdCasas > 5); //limitar e receber qtd de casas do proprietario
	
	
	for(i = 0; i < p->qtdCasas; i++) //percorrer total de casas do proprietario
	{
			do
			{
				fflush(stdin);
				printf("\nReg casa: ");
				scanf("%i", &(p->casa[i].num_casa));
				fflush(stdin);
				
				num = p->casa[i].num_casa;
				
			}while(!(p->casa[i].num_casa - num == 0)); //limitar apenas a numeros e receber numero da casa i do proprietario
					
			do
			{
				fflush(stdin);
				printf("\nStatus: ");
				scanf("%c", &(p->casa[i].status_casa));
				fflush(stdin);
			}while(p->casa[0].status_casa != 'L' && p->casa[0].status_casa != 'A'); //limitar apenas a letra L ou A e receber status da casa i do proprietario
	}
	
	system("cls");
	
	prop(p);
	
	system("pause");
	
	salvarProp(p);
}//opcao 1


void cadastrarImovel(st_imovel *p, int id)//opcao 2
{
	system("cls");
	
	int i;
	
	p->id = id; //alterar valor do registro para o proximo cadastro
	
	fflush(stdin);
	printf("\n\tCadastro Imovel:"
		   "\nID: %i", p->id);
	
	printf("\nDigite o total de quartos: ");
	scanf("%i", &(p->quartos));
	fflush(stdin); // receber total de quartos do imovel
	
	printf("\nDigite a area total: ");
	scanf("%f", &(p->area));
	fflush(stdin); // receber cpf do imovel
	
	printf("\nValor do imovel: ");
	scanf("%f", &(p->valor));
	fflush(stdin); // receber celular do imovel
	
	printf("\nStatus de locacao: ");
	scanf("%i", &(p->status.locacao.reg_loc));
	fflush(stdin); // receber telefone do imovel
	
	printf("\nSigla: ");
	scanf("%c", &(p->status.locacao.sigla));
	fflush(stdin); // receber email do imovel
	
	printf("\nSigla: ");
	scanf("%c", &(p->status.sigla));
	fflush(stdin); // receber email do imovel
	
	printf("\nRua: ");
	gets(p->end_imovel.logradouro);
	fflush(stdin); // receber logradouro do imovel
	
	printf("\nBairro: ");
	gets(p->end_imovel.bairro);
	fflush(stdin); // receber bairro do imovel
	
	printf("\nCidade: ");
	gets(p->end_imovel.cidade);
	fflush(stdin); // receber cidade do imovel
	
	printf("CEP: ");
	gets(p->end_imovel.CEP);
	fflush(stdin); //receber cep do imovel
	
	
	imoveis(p);

	system("pause");
	
	salvarImo(p);	
}//opcao 2


/////////////////////////////////////////////////////funcoes arquivo
int verifProp()
{
	FILE *fptr = NULL;
	long int Tprop = 0;
	
	if((fptr = fopen("proprietario.bin", "rb")) == NULL)
		return Tprop;
	else
	{
		fseek(fptr, 0, 2);
		Tprop = ftell(fptr) / sizeof(st_prop);	
		fclose(fptr);
		
		return Tprop;
	}
}


int verifImo()
{
	FILE *fptr = NULL;
	long int Timo = 0;
	
	if((fptr = fopen("imovel.bin", "rb")) == NULL)
		return Timo;
	else
	{
		fseek(fptr, 0, 2);
		Timo = ftell(fptr) / sizeof(st_imovel);	
		fclose(fptr);
		
		return Timo;
	}
}


void salvarProp(st_prop *dados)
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("proprietario.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(st_prop), 1, fptr);
		fclose(fptr);
	}
}


void salvarImo(st_imovel *dados)
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("imovel.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(st_imovel), 1, fptr);
		fclose(fptr);
	}
}


void LerProp(st_prop *p, int t)//opcao 3
{
	/*
	Total:
	mostrar nº de registro, nome, CPF, endereço, quantidade de imóveis e se for o caso: mostrar as tabelas o Parcial 
	
	Parcial:
	o usuário deverá entrar com o CPF do proprietário
	mostrar nº de registro, nome, endereço, quantidade de imóveis e se for o caso: mostrar as tabelas 
	*/
 
	int i, j, op, op1 = 1;
	char cpf[15];
	
	FILE *fptr = NULL;
	
	do{		
		printf("\nMenu de busca:"
				"\n[1] - Total"
				"\n[2] - Por CPF"
				"\n<1/2>: ");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
	}while(op < 1 || op > 2);
	
	
	if((fptr = fopen("proprietario.bin","rb")) == NULL)
		printf("\nArquivo inexistente!");
	else
	{	
		if(op == 1)
			for(i = 0; i < t; i++)
			{
				fseek(fptr, i * sizeof(st_prop), 0);
				fread(p, sizeof(st_prop), 1, fptr);
				
				prop(p);
			}
		else
		{
			do
			{
				printf("\nBuscar CPF: ");
				gets(cpf);
				
				for(i = 0; i < t; i++)
				{
					fseek(fptr, i * sizeof(st_prop), 0);
					fread(p, sizeof(st_prop), 1, fptr);
					
					if(strcmp(cpf, p->cpf) == 0)
					{
						prop(p);
						op1 = 0;
					}
				}
				if(op1 == 1)
				{
					fflush(stdin);
					printf("\nCPF nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
					scanf("%i", &op1);
					fflush(stdin);
				}
			}while(op1 == 1);
		}
		fclose(fptr);
	}
	printf("\n");
	system("pause");
}//opcao 3


void LerImo(st_imovel *p, int t)//opcao 4
{
	/*Total (status):
	• o usuário deverá escolher entre status (L ou A)
	 mostrar nº de registro, endereço, área útil, quantidade de quartos e se for o caso: mostrar as tabelas 
	
	Parcial:
	o usuário deverá entrar com a área útil ou quantidade de quartos ou bairro dos imóveis que deseja alugar
	mostrar nº do registro, área útil (em m2), quantidade de quartos, endereço e valor do aluguel dos imóveis livres  
	*/
	
	int i, j, op, op1 = 1;
	char texto[30];
	
	FILE *fptr = NULL;
	
	do{
		printf("\nMenu de busca:"
				"\n[1] - Total"
				"\n[2] - Registro"
				"\n[3] - Por area"
				"\n[4] - Qtd de quartos"
				"\n[5] - endereco"
				"\n<1/../5>: ");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
	}while(op < 1 || op > 2);

	
	
	if((fptr = fopen("imovel.bin","rb")) == NULL)
		printf("\nArquivo inexistente!");
	else
	{
		if(op == 1)
			for(i = 0; i < t; i++)
			{
				fseek(fptr, i * sizeof(st_imovel), 0);
				fread(p, sizeof(st_imovel), 1, fptr);
				
				imoveis(p);
			}
			
		else if(op == 2)
			do
			{
				printf("\nBuscar Registro: ");
				gets(texto);
				
				for(i = 0; i < t; i++)
				{
					fseek(fptr, i * sizeof(st_prop), 0);
					fread(p, sizeof(st_prop), 1, fptr);
					
					if(strcmp(texto, p->status.locacao.reg_loc) == 0)
					{
						prop(p);
						op1 = 0;
					}
				}
				if(op1 == 1)
				{
					fflush(stdin);
					printf("\nCPF nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
					scanf("%i", &op1);
					fflush(stdin);
				}
			}while(op1 == 1);
			
		else if(op == 3)
			do
			{
				printf("\nBuscar Area: ");
				gets(cpf);
				
				for(i = 0; i < t; i++)
				{
					fseek(fptr, i * sizeof(st_prop), 0);
					fread(p, sizeof(st_prop), 1, fptr);
					
					if(strcmp(texto, p->) == 0)
					{
						prop(p);
						op1 = 0;
					}
				}
				if(op1 == 1)
				{
					fflush(stdin);
					printf("\nCPF nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
					scanf("%i", &op1);
					fflush(stdin);
				}
			}while(op1 == 1);
			
		else if(op == 4)
			do
			{
				printf("\nBuscar CPF: ");
				gets(cpf);
				
				for(i = 0; i < t; i++)
				{
					fseek(fptr, i * sizeof(st_prop), 0);
					fread(p, sizeof(st_prop), 1, fptr);
					
					if(strcmp(cpf, p->cpf) == 0)
					{
						prop(p);
						op1 = 0;
					}
				}
				if(op1 == 1)
				{
					fflush(stdin);
					printf("\nCPF nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
					scanf("%i", &op1);
					fflush(stdin);
				}
			}while(op1 == 1);
			
			
		fclose(fptr);
	}
	printf("\n");
	system("pause");
}//opcao 4


void prop(st_prop *p)
{
	int j;
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\tCadastro: "
			"\nID: %i"
			"\nNome: %s"
			"\nCpf: %s"
			"\nCelular: %s"
			"\nTelefone: %s"
			"\nEmail: %s", p->id, p->nome, p->cpf, p->endereco.celular, p->endereco.telefone, p->endereco.email);
		
	printf("\n\n\tEndereco do proprietario: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nEstado: %s"
			"\nCep: %s"
			"\nQtdCasas: %i", p->endereco.logradouro, p->endereco.bairro, p->endereco.cidade, p->endereco.estado, p->endereco.cep, p->qtdCasas);
				
	for(j = 0; j < p->qtdCasas; j++) //percorrer total de casas do proprietario
	{
		printf("\n\n\tImovel: %i", j+1);
		printf("\nNumero casa: %i", p->casa[j].num_casa );
		printf("\nStatus: %c\n", p->casa[j].status_casa );
	}
}


void imoveis(st_imovel *p)
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
				printf("\n\tCadastro: "
						"\nID: %i"
						"\nTotal de quartos: %i"
						"\nArea total: %.2f m^2"
						"\nValor do aluguel: %.2f"
						"\nStatus: %i"
						"\nSigla: %c"
						"\nSigla: %c", p->id, p->quartos, p->area, p->valor, p->status.locacao.reg_loc, p->status.locacao.sigla, p->status.sigla);
		
				printf("\n\n\tEndereco do imovel: "
						"\nLogradouro: %s"
						"\nBairro: %s"
						"\nCidade: %s"
						"\nCep: %s", p->end_imovel.logradouro, p->end_imovel.bairro, p->end_imovel.cidade, p->end_imovel.CEP);
}


/////////////////////////////////////////////////////main
int main()
{
	st_prop *prop = NULL;
	st_imovel *imovel = NULL;
	
	int op, Tusuario, Timoveis;
	static int Idprop = 1000, IdImo = 1000;
	
	alocarStruct(&prop, 1);
	Tusuario = verifProp();
	
	alocarStruct(&imovel, 1);
	Timoveis = verifImo();
	
	if(Tusuario != 0)
		Idprop += Tusuario;
	
	if(Timoveis != 0)
		IdImo += Timoveis;
		
	do
	{
		do
		{
			system("CLS");
			
			printf("\n\tImobiliaria");
			printf("\nTotal proprietarios: %i", Tusuario);
			printf("\nTotal imoveis: %i", Timoveis);
			printf("\nId proprietario: %i", Idprop);
			printf("\nId imovel: %i", IdImo);
			
			printf("\n\tMenu:"
				"\n[1] - Cadastrar Proprietario OK"
				"\n[2] - Cadastrar imovel OK"
				"\n[3] - Usuarios cadastrados OK"
				"\n[4] - Imoveis cadastrados OK"
				"\n[5] - Sair"
				"\n<1/../5>: ");
			scanf("%i", &op);
			fflush(stdin);
			
			system("CLS");
		}while(op < 1 || op > 5);
			
		switch(op)
		{
			case 1: if(Tusuario != 0) 
						alocarStruct(&prop, Tusuario + 1);
					cadastrarProp(prop + Tusuario, Idprop);
					Idprop++;
					Tusuario++;
				break;
				
			case 2: if(Timoveis != 0) 
						alocarStruct(&imovel, Timoveis + 1);
					cadastrarImovel(imovel + Timoveis, IdImo);
					IdImo++;
					Timoveis++;
				break;
				
			case 3: LerProp(prop, Tusuario);
				break;
				
			case 4: LerImo(imovel, Timoveis);
				break;
				
			case 5: exit(1);
				break;
		}
	}while(1);
	
	return 0;
}
