#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
	int num_casa;//linkar com imovel
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
	char sigla;//A - L
	int reg_loc;
}st_status_imovel; //status imovel


union un_dados
{
	char sigla;//A - 1
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


//Funções de Alocação:
void alocarStruct(st_prop **p, int t);
void alocarImovel(st_imovel **p, int t);
void alocarInt(int **p, int tam);

//Funções de Cadastrar:
void cadastrarProp(st_prop *p, int id);
void cadastrarImovel(st_imovel *p, int id, st_prop *proprietario, int qtde_prop);

//Funções de Verificar:
int verifProp();
int verifImo();

//Funções de Salvar
void salvarProp(st_prop *dados);
void gravaProp(st_prop *dados, int qreg);
void salvarImo(st_imovel *dados);

//Funções de Leitura
void LerProp(st_prop *p, int t);
void LerImo(st_imovel *p, int t);

//Funções de Busca:
int buscaProprietario(st_prop *proprietarios, int qreg, int num_reg);
int buscaImovel(st_imovel *imoveis, int qreg, int num_reg);

void mostraImovel(st_imovel *p);


/////////////////////////////////////////////////////main
int main()
{
	st_prop *prop = NULL;
	st_imovel *imovel = NULL;
	
	int op, Tusuario, Timoveis;
	static int Idprop = 1000, IdImo = 1000;
	
	alocarStruct(&prop, 1);
	Tusuario = verifProp();
	
	alocarImovel(&imovel, 1);
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
				"\n[1] - Cadastrar Proprietario"
				"\n[2] - Cadastrar imovel"
				"\n[3] - Usuarios cadastrados"
				"\n[4] - Imoveis cadastrados"
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
						alocarImovel(&imovel, Timoveis + 1);
					prop = NULL;
					alocarStruct(&prop, Tusuario + 1);
					cadastrarImovel(imovel + Timoveis, IdImo, prop, Tusuario);
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


/////////////////////////////////////////////////////alocacao
void alocarStruct(st_prop **p, int t)
{
	if((*p = (st_prop*)realloc(*p, t * sizeof(st_prop))) == NULL)
		exit(1);
}//ALOCA PROPRIETARIO


void alocarImovel(st_imovel **p, int t)
{
	if((*p = (st_imovel*) realloc(*p, t * sizeof(st_imovel))) == NULL)
		exit(1);
}//ALOCA IMOVEL


void alocarInt(int **p, int t)
{
	if((*p = (int*) realloc(*p, t * sizeof(int))) == NULL)
	{
		printf("\n\nErro ao alocar do tipo 'INT'\n\n");
		exit(1);
	}
}//ALOCA INT


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
	
	int i, j, num, listNumCasa[5], qtd_numIguais = 0;
	
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
	
	p->qtdCasas = 0;
		
	
	system("cls");
	
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
			"\nQtdCasas: %i\n\n", p->endereco.logradouro, p->endereco.bairro, p->endereco.cidade, p->endereco.estado, p->endereco.cep, p->qtdCasas);
		
	system("pause");
	
	salvarProp(p);
}//Realiza o Cadastro do Proprietário


void cadastrarImovel(st_imovel *p, int id, st_prop *proprietario, int qtde_prop)
{
	int num_reg, qtde_livres = 0, i_casas, LA;
	FILE *fptr = NULL;
	
	system("cls");
	
	int i;
	char status, op;
	
	p->id = id; //alterar valor do registro para o proximo cadastro
	
	fflush(stdin);
	printf("\n\tCadastro Imovel:"
		   "\nID: %i", p->id);
	
	printf("\nDigite o total de quartos: ");
	scanf("%i", &(p->quartos));
	fflush(stdin); // receber total de quartos do imovel
	
	printf("\nDigite a area total (m^2): ");
	scanf("%f", &(p->area));
	fflush(stdin); // receber area total do imovel
	
	printf("\nValor do imovel: ");
	scanf("%f", &(p->valor));
	fflush(stdin); // receber valor do imovel
	
	p->status.locacao.sigla = 'L';	//Começa com 'L'	
	
	printf("\nRua: ");
	gets(p->end_imovel.logradouro);
	fflush(stdin); // receber logradouro do imovel
	
	printf("\nBairro: ");
	gets(p->end_imovel.bairro);
	fflush(stdin); // receber bairro do imovel
	
	printf("\nCidade: ");
	gets(p->end_imovel.cidade);
	fflush(stdin); // receber cidade do imovel
	
	printf("\nCEP: ");
	gets(p->end_imovel.CEP);
	fflush(stdin); //receber cep do imovel
	
	do
	{
		printf("\nSituacao da casa"
				"\n[1] - Livre"
				"\n[2] - Alugada"
				"\n<1/2>:");
		scanf("%i", &LA);
	}while(LA != 1 && LA != 2);
	
	//Mostra os ids  e proprietários disponíveis:
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		for(i=0;i<qtde_prop;i++)
		{
			fseek(fptr, i * sizeof(st_prop), 0);
			fread(proprietario,sizeof(st_prop), 1, fptr);
					
				if((proprietario)->qtdCasas <= 5)
				{	
					qtde_livres +=1;				
					printf("\nId: %i\tNome: %s", (proprietario)->id, (proprietario)->nome);
				}
		}
		fclose(fptr);
	}
	
	if(qtde_livres == 0)
	{	
		printf("\n\nNao ha Proprietarios livres, todo o cadastro desse imovel sera perdido.\n\n");
		system("pause");
		return;
	}
	
	do
	{	
		//Id do proprietário:
		fflush(stdin);
		printf("\n\nDigite o Id do proprietario: ");
		scanf("%i", &num_reg);
		fflush(stdin);
		
		num_reg = buscaProprietario(proprietario, qtde_prop, num_reg);		//Verifcar se é possível atrelar o imóvel ao proprietário				
		op = 'N';
		
		//printf("Indice: %i", num_reg);
		
		if(num_reg != -1)
		{
			if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Proprietario\n\n");
			else
			{
				
				fread(proprietario,sizeof(st_prop), qtde_prop, fptr);
				fclose(fptr);
				
				i_casas = (proprietario+num_reg)->qtdCasas - 1;
				
				(proprietario + num_reg)->casa[i_casas].num_casa = p->id;
				/*
				if(LA == 1)
				{
					p->status.sigla = 'L'; //imovel
					(proprietario + num_reg)->casa[i_casas].status_casa = 'L'; //proprietario
				}
				else if(LA == 2)
				{
					p->status.sigla = 'A'; //imovel
					p->status.locacao.reg_loc = num_reg + 1; //imovel
					p->status.locacao.sigla = 'A'; //imovel
					
					(proprietario + num_reg)->casa[i_casas].status_casa = 'A'; //proprietario, salva o estado da casa
					(proprietario + num_reg)->casa[i_casas].num_casa = num_reg + 1; //proprietario, salva a posicao/n_casa do proprietario para printar
				}
				*/
				printf("\n\nqtd casas: %i",  (proprietario+num_reg)->qtdCasas);
				(proprietario + num_reg)->qtdCasas += 1;

				gravaProp(proprietario, qtde_prop);	
			}
		}		
		else{
		
				fflush(stdin);
				printf("\nId nao encontrado, deseja tentar novamente<S/N>: ");
				scanf("%c",&op);
				fflush(stdin);
				
				op = toupper(op);				
		}
	}while(op != 'N');
	
	
	
	if(num_reg != -1)//Se o registro não for Inválido:
	{
		printf("\n\tCadastro: "
				"\nID: %i"
				"\ntotal de quartos: %i"
				"\nDigite a area total: %.2f"
				"\nValor: %.2f"
				"\nStatus: %i"
				"\nSigla: %c"
				"\nSigla: %c", p->id, p->quartos, p->area, p->valor, p->status.locacao.reg_loc, p->status.locacao.sigla, p->status.sigla);
		
		printf("\n\n\tEndereco do imovel: "
				"\nLogradouro: %s"
				"\nBairro: %s"
				"\nCidade: %s"
				"\nCep: %s\n\n", p->end_imovel.logradouro, p->end_imovel.bairro, p->end_imovel.cidade, p->end_imovel.CEP);
	
		system("pause");
		
		salvarImo(p);	
	}
	
	else
	{
		printf("\nNao foi possivel realizar o cadastro por nao atrelar o imovel a um proprietario\n\n");
		system("pause");
	}
}//Realiza o Cadastro e atrelamento do Imovel ao Proprietario


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
}//Verifica se tem o arquivo 'proprietario.bin' e retorna a quantidade de proprietários nele


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
}//Verifica se tem o arquivo 'imovel.bin' e retorna a quantidade de imoveis nele


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
}//Salva só um proprietario


void gravaProp(st_prop *dados, int qreg)
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("proprietario.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados,sizeof(st_prop),qreg, fptr);
		fclose(fptr);	
	}
}//Salva vários Proprietários sobrepondo o que tiver


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
}//Salva um Imovel


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
				"\n[3] - Voltar"
				"\n<1/2/3>: ");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
	}while(op < 1 || op > 3);
	
	if(op != 3)
	{			
		if((fptr = fopen("proprietario.bin","rb")) == NULL)
			printf("\nArquivo inexistente!");
		else
		{	
			if(op == 1)
				for(i = 0; i < t; i++)
				{
					fseek(fptr, i * sizeof(st_prop), 0);
					fread(p, sizeof(st_prop), 1, fptr);
					
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
	}
	
	printf("\n");
	system("pause");
}//Mostra os Proprietários com os filtros desejados


void LerImo(st_imovel *p, int t)//opcao 4
{
	/*Total (status):
	• o usuário deverá escolher entre status (L ou A)
	 mostrar nº de registro, endereço, área útil, quantidade de quartos e se for o caso: mostrar as tabelas 
	
	Parcial:
	o usuário deverá entrar com a área útil ou quantidade de quartos ou bairro dos imóveis que deseja alugar
	mostrar nº do registro, área útil (em m2), quantidade de quartos, endereço e valor do aluguel dos imóveis livres 
	 
	 */
	int i, j, qtd_quartos, falha, op, op2;
	float area;
	char bairro[20];
	FILE *fptr = NULL;
	
	do
	{		
		printf("\nMenu de busca:"
				"\n[1] - Total"
				"\n[2] - Por Area Util"
				"\n[3] - Por Quantidade de Quartos"
				"\n[4] - Por Bairro"
				"\n[5] - Voltar"
				"\n<1/.../5>: ");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
	}while(op < 1 || op > 5);
	
	if( op != 5)
	{
		if((fptr = fopen("imovel.bin","rb")) == NULL)
			printf("\nArquivo inexistente!");
		else
		{
			if(op == 1)
			{
				do
				{		
					printf("\nStatus do Imovel:"
							"\n[1] - [L]ivre"
							"\n[2] - [A]lugado"
							"\n<1/2>: ");
					scanf("%i", &op);
					fflush(stdin);
					
					system("cls");
				}while(op < 1 || op > 2);
							
				for(i = 0; i < t; i++)
				{					
					fseek(fptr, i * sizeof(st_imovel), 0);
					fread(p, sizeof(st_imovel), 1, fptr);
					
					if(op==1 && p->status.sigla == 'L')				
						mostraImovel(p);
						
					else if(op == 2 && p->status.locacao.sigla == 'A')
						mostraImovel(p);
				}
			}		
				
			else if(op == 2)
			{	
				falha = 1;
				
				do
				{
					system("cls");
					
					printf("\nBuscar Area: ");
					fflush(stdin);
					scanf("%f", &area);
					
					
					for(i = 0; i < t; i++)
					{
						fseek(fptr, i * sizeof(st_imovel), 0);
						fread(p, sizeof(st_imovel), 1, fptr);
						
						if(area == p->area)
						{
							mostraImovel(p);														
							falha = 0;
						}
					}
					if(falha == 1)
					{
						do{
							fflush(stdin);
							printf("\nArea nao encontrada!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha !=1) 
								printf("\nDigite uma opcao valida\n");
						}while(falha != 0 && falha !=1);
					}	
				}while(falha == 1);
			}
			
			else if(op == 3)
			{	
				falha = 1;
				
				do
				{
					system("cls");
					
					printf("\nBuscar Quantidade de Quartos: ");
					fflush(stdin);
					scanf("%i", &qtd_quartos);
					
					
					for(i = 0; i < t; i++)
					{
						fseek(fptr, i * sizeof(st_imovel), 0);
						fread(p, sizeof(st_imovel), 1, fptr);
						
						if(qtd_quartos == p->quartos)
						{
							mostraImovel(p);													
							falha = 0;
						}
					}
					if(falha == 1)
					{
						do
						{
							fflush(stdin);
							printf("\nQuantidade de quartos nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha !=1)
								printf("\nDigite uma opcao valida\n");
						}while(falha != 0 && falha !=1);
					}
				}while(falha == 1);
			}
			
			else if(op == 4)
			{	
				falha = 1;
				
				do
				{
					system("cls");
					
					fflush(stdin);
					printf("\nBuscar Bairro: ");					
					gets(bairro);
					
					for(i = 0; i < t; i++)
					{
						fseek(fptr, i * sizeof(st_imovel), 0);
						fread(p, sizeof(st_imovel), 1, fptr);
						
						if(strcmp(bairro, p->end_imovel.bairro) == 0)
						{
							mostraImovel(p);												
							falha = 0;
						}
					}
					
					if(falha == 1)
					{
						do
						{
							fflush(stdin);
							printf("\nBairro nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha !=1)
								printf("\nDigite uma opcao valida\n");
						}while(falha != 0 && falha !=1);
					}
				}while(falha == 1);
			}
			fclose(fptr);
		}
	}
	
	printf("\n");
	system("pause");
}//Mostra os Imóveis com os filtros desejados

//Funções de Busca:
int buscaProprietario(st_prop *proprietarios, int qreg, int num_reg)
{
	int i;
	FILE *fptr;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		fread(proprietarios,sizeof(st_prop), qreg, fptr);
		fclose(fptr);
		
		for(i=0;i<qreg;i++)
			if( (proprietarios+i)->id == num_reg)
				return i;
	}
	return -1;	//NÃO ENCOTROU O PROPRIETÁRIO
}//Busca Proprietário


int buscaImovel(st_imovel *imoveis, int qreg, int num_reg)
{
	int i;
	
	for(i=0;i<qreg;i++)
		if( (imoveis+i)->id == num_reg)
			return i;
	return -1;	//NÃO ENCOTROU O IMÓVEL
}//Busca Imóvel através do Id


//Funções de Mostrar:
void mostraImovel(st_imovel *p)
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\tCadastro: "
			"\nID: %i"
			"\nTotal de quartos: %i"
			"\nArea total: %.2f m^2"
			"\nValor: %.2f"
			"\nStatus: %i"
			"\nSigla: %c"
			"\nSigla: %c", p->id, p->quartos, p->area, p->valor, p->status.locacao.reg_loc, p->status.locacao.sigla, p->status.sigla);

	printf("\n\n\tEndereco do imovel: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nCep: %s", p->end_imovel.logradouro, p->end_imovel.bairro, p->end_imovel.cidade, p->end_imovel.CEP);	
}//Mostra os dados de um imóvel

