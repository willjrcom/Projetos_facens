//Eduardo de Oliveira Almeida, 190963
//William Alfred Gazal Júnior, 180037

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/////////////////////////////////////////////////////structs
////////////////////////// proprietario
typedef struct endereco
{
char  logradouro[80];  
char  bairro[20];  
char  CEP[10];  
char  cidade[20];  
char  estado[20];  
char  fone[15];  
char  cel[15];  
char  email[30]; 
}endereco; // endereco proprietario
	
	
typedef struct info_casa 
{
	int  num_casa;  
	char status_casa; 
}info_casa;  // status proprietario


typedef struct prop
{
	int   reg_prop;  
    char   nome[80];  
    char   CPF[15];  
    struct endereco end_prop;  
	int   qtde_casa; 
	struct info_casa casa[5];
}prop;  // cadastro completo proprietario


////////////////////////// imovel
typedef struct adress
{
	char  logradouro[80];  
	char  bairro[20];  
	char  CEP[10];  
	char  cidade[20]; 
}adress; //endereco imovel


typedef struct info_loc
{
	char  sigla; 
	int  reg_loc; 
}inf_loc;  //status imovel


union dados
{  
	char  sigla; 
	struct info_loc loc; 
}; 
 

typedef struct imovel
{  
	int   reg_imov;  // gerado automaticamente  
	struct adress  end_imov;  
	float   area;  
	int   quartos;  
	float   valor; 
	union dados  status; 
}imovel; 
 
 

//////////////////////locatario
typedef  struct locatario
{
	int   reg_loc;   // gerado automaticamente  
	char   nome[80];  
	char   CPF[15];  
	struct endereco end_loc;  
	int   reg_imov;  // registro imóvel – buscar no arq. Imóvel  
	int   dia_venc;  
	char   inicio[9];  
	char   termino[9]; 
}locatario; 
  

//Funcoes de Alocacao:
void alocarProp(prop **p, int t);
void alocarImovel(imovel **p, int t);
void alocarLocatario(locatario **p, int t);


//Funcoes de Cadastrar:
void cadastrarProp(prop *p, int id);
int cadastrarImovel(imovel *p, int id, prop *proprietario, int qtde_prop);
int cadastrarLocatario(locatario *p, int id, imovel *imovel, int qtde_imov, prop *proprietario, int qtde_prop);


//Funcoes de Verificar:
int verifProp();
int verifImo();
int verifLoc();


//Funcoes de Salvar:
void salvarProp(prop *dados);
void salvarImo(imovel *dados);
void salvarLoc(locatario *dados);


//Funcoes de Gravar:
void gravaProp(prop *dados, int qreg);
void gravaImo(imovel *dados, int qreg);
void gravaLoc(locatario *dados, int qreg);


//Funções de gravar com opção maleável:
void opGravaProp(prop *p,char *opcao, int indice);
void opGravaImov(imovel *p, char *opcao, int indice);
void opGravaLoc(locatario *p, char *opcao, int indice);


//Funcoes de Leitura
void LerProp(prop *p, int t);
void LerImo(imovel *p, int t);
void LerLoc(locatario *p, int t);


//Funcoes de Busca:
int buscaProprietario(prop *proprietarios, int qreg, int num_reg);
int buscaImovel(imovel *imoveis, int qreg, int num_reg);
int buscaImovelAlugado(imovel *imoveis, int qreg, int num_reg);
int buscaProprietarioPorImovel(prop *proprietarios, int qreg, int id_casa);
int buscaProprietarioPorImovelAlugado(prop *proprietarios, int qreg, int id_casa);
int buscaCasa(prop *proprietarios, int qreg, int i_prop, int id_casa);
int buscaCasaAlugado(prop *proprietarios, int qreg, int i_prop, int id_casa);
int buscaProprietarioPorCPF(prop *p, int qreg, char cpf[15]);
int buscaLocatarioPorCPF(locatario *p, int qreg, char cpf[15]);


//Funcoes de Mostra:
void mostraProp(prop *p, int qtd_Casas);
void mostraImovel(imovel *p);
void mostraLocatario(locatario *p);


//Funcoes de Relatorio
void relatorio(locatario *p, int qtde_loc);


//Funcoes de Termino de contrato
void terminoContrato(locatario *loc, int qtde_loc, imovel *imovel, int qtde_imov, prop *prop, int qtde_prop);


//Funcao desenvolvedor
void limparDados();


//Funcao calcular multa
int calcularMulta(char contrato[9], char atual[9]);


//Funções de Alterar o Cadastro:
void alteraProprietario(prop *p, int tam);
void alteraImovel(imovel *p, int tam);
void alteraLocatario(locatario *p, int tam);


/////////////////////////////////////////////////////main
int main()//funcao main
{
	prop *prop = NULL;
	imovel *imovel = NULL;
	locatario *locatario = NULL;
	
	int op, Tprop, Timoveis, Tlocatario, confLoc, confImov, op2, mostra = 0;
	static int Idprop = 1000, IdImo = 1000, IdLoc = 1000;
	
	alocarProp(&prop, 1);
	Tprop = verifProp();
	
	alocarImovel(&imovel, 1);
	Timoveis = verifImo();
	
	alocarLocatario(&locatario, 1);
	Tlocatario = verifLoc();
	
	if(Tprop != 0)
		Idprop += Tprop;
	
	if(Timoveis != 0)
		IdImo += Timoveis;
		
	if(Tlocatario != 0)
		IdLoc += Tlocatario;
		
	do
	{
		do
		{
			system("CLS");
			
			if(mostra == 1)
			{				
				printf("\nTotal proprietarios: %i", Tprop);
				printf("\nTotal imoveis: %i", Timoveis);
				printf("\nTotal locatarios: %i", Tlocatario);
				printf("\nId proprietario: %i", Idprop);
				printf("\nId imovel: %i", IdImo);
				printf("\nId locatario: %i\n", IdLoc);
			}
			
			printf("\n\t--- IMOBILIARIA ---");
			printf("\n-Menu-"
				"\n[1] - Cadastrar Proprietario"
				"\n[2] - Proprietarios cadastrados"
				"\n[3] - Cadastrar imovel"
				"\n[4] - Imoveis cadastrados"
				"\n[5] - Alugar Imovel"
				"\n[6] - Locatarios cadastrados"
				"\n[7] - Relatorio"
				"\n[8] - Termino de contrato"
				"\n[9] - Alterar cadastro"
				"\n[10] - Sair"
				"\n<1/../10>: ");
			scanf("%i", &op);
			fflush(stdin);
			
			switch(op)
			{
				case 11: mostra = 1;
				break;
			}
			system("CLS");
		}while(op < 0 || op > 10);
			
		switch(op)
		{		
			case 0: limparDados(); //opcao desenvolvedor
				break;
				
			case 1: if(Tprop != 0) 
						alocarProp(&prop, Tprop + 1);
						
					cadastrarProp(prop + Tprop, Idprop);
					Idprop++;
					Tprop++;
				break;
				
			case 2: LerProp(prop, Tprop);
				break;
				
			case 3: if(Timoveis != 0) 
						alocarImovel(&imovel, Timoveis + 1);
					
					confImov = 0;
					confImov = cadastrarImovel(imovel + Timoveis, IdImo, prop, Tprop);
					if(confImov == 1)
					{	
						IdImo++;
						Timoveis++;
					}
				break;
				
			case 4: LerImo(imovel, Timoveis);
				break;
				
			case 5:	if(Tlocatario != 0)
						alocarLocatario(&locatario,Tlocatario + 1);		
					
					confLoc = 0;
					confLoc = cadastrarLocatario(locatario + Tlocatario, IdLoc, imovel, Timoveis, prop, Tprop);
					if(confLoc == 1)
					{
						IdLoc++;
						Tlocatario++;
					}
				break;

			case 6: LerLoc(locatario, Tlocatario);
				break;
				
			case 7: relatorio(locatario, Tlocatario);
				break;
				
			case 8: terminoContrato(locatario, Tlocatario, imovel, Timoveis, prop, Tprop);
				break;
				
			case 9:
				do{
					system("cls");
					printf("\nAlterar:"
							"\n[1] - Proprietario"
							"\n[2] - Imovel"
							"\n[3] - Locatario"
							"\n[4] - Voltar"
							"\nOpcao<1/.../4>: ");
					fflush(stdin);
					scanf("%i", &op2);
					
					switch(op2){
						case 1: 
							if(Tprop != 0)
							{
								prop = NULL;
								alocarProp(&prop, Tprop);
							}
							alteraProprietario(prop, Tprop);
							break;
						
						case 2:
							if(Timoveis != 0)
							{
								imovel = NULL;
								alocarImovel(&imovel, Timoveis);
							}
							alteraImovel(imovel, Timoveis);
							break;
							
						case 3:
							if(Tlocatario != 0) 
							{
								locatario = NULL;
								alocarLocatario(&locatario, Tlocatario);
							}
							alteraLocatario(locatario, Tlocatario);
							break;
					}
				}while(op2 < 1 || op2 > 4);
				break;
				
			case 10: exit(1);
				break;
		}
	}while(1);
	
	return 0;
}


/////////////////////////////////////////////////////alocacao
void alocarProp(prop **p, int t)//alocar proprietario
{
	if((*p = (prop*)realloc(*p, t * sizeof(prop))) == NULL)
		exit(1);
}//ALOCA PROPRIETARIO


void alocarImovel(imovel **p, int t)//alocar imovel
{
	if((*p = (imovel*) realloc(*p, t * sizeof(imovel))) == NULL)
		exit(1);
}//ALOCA IMOVEL


void alocarLocatario(locatario **p, int t)//alocar locatario
{
	if((*p = (locatario*) realloc(*p, t * sizeof(locatario))) == NULL)
		exit(1);
}//ALOCA LOCATÁRIO


/////////////////////////////////////////////////////funcoes cadastro
void cadastrarProp(prop *p, int id)//opcao 1: Realiza o Cadastro do Proprietário
{
	system("cls");
	
	int i, j, num, listNumCasa[5], qtd_numIguais = 0;
	
	p->reg_prop = id; //alterar valor do registro para o proximo cadastro
	
	fflush(stdin);
	printf("\n\tCadastro Proprietario:"
		   "\nID: %i", p->reg_prop);
	
	printf("\nDigite o nome: ");
	gets(p->nome);
	fflush(stdin); // receber nome do proprietario
	
	printf("\nDigite o CPF: ");
	gets(p->CPF);
	fflush(stdin); // receber cpf do proprietario
	
	printf("\nCelular: ");
	gets(p->end_prop.cel);
	fflush(stdin); // receber celular do proprietario
	
	printf("\nTelefone: ");
	gets(p->end_prop.fone);
	fflush(stdin); // receber telefone do proprietario
	
	printf("\nEmail: ");
	gets(p->end_prop.email);
	fflush(stdin); // receber email do proprietario
	
	printf("\nRua: ");
	gets(p->end_prop.logradouro);
	fflush(stdin); // receber logradouro do proprietario
	
	printf("\nBairro: ");
	gets(p->end_prop.bairro);
	fflush(stdin); // receber bairro do proprietario
	
	printf("\nCidade: ");
	gets(p->end_prop.cidade);
	fflush(stdin); // receber cidade do proprietario
	
	printf("\nEstado: ");
	gets(p->end_prop.estado);
	fflush(stdin); // receber estado do proprietario
	
	printf("CEP: ");
	gets(p->end_prop.CEP);
	fflush(stdin); //receber cep do proprietario
	
	p->qtde_casa = 0;
		
	system("cls");
	
	mostraProp(p, 0);
	
	system("pause");
	
	salvarProp(p);
}//Realiza o Cadastro do Proprietário


int cadastrarImovel(imovel *p, int id, prop *proprietario, int qtde_prop)//opcao 3: Realiza o Cadastro e atrelamento do Imovel ao Proprietario
{
	int num_reg, qtde_livres = 0, i_casas, i;
	FILE *fptr = NULL;
	char status, op;
	
	system("cls");
	
	p->reg_imov = id; //alterar valor do registro para o proximo cadastro
	
	fflush(stdin);
	printf("\n\tCadastro Imovel:"
		   "\nID: %i", p->reg_imov);
	
	printf("\nDigite o total de quartos: ");
	scanf("%i", &(p->quartos));
	fflush(stdin); // receber total de quartos do imovel
	
	printf("\nDigite a area total (m^2): ");
	scanf("%f", &(p->area));
	fflush(stdin); // receber area total do imovel
	
	printf("\nValor do imovel: ");
	scanf("%f", &(p->valor));
	fflush(stdin); // receber valor do imovel
	
	p->status.loc.reg_loc = id-999;
	p->status.loc.sigla = 'L';	//Começa com 'L'	
	
	printf("\nRua: ");
	gets(p->end_imov.logradouro);
	fflush(stdin); // receber logradouro do imovel
	
	printf("\nBairro: ");
	gets(p->end_imov.bairro);
	fflush(stdin); // receber bairro do imovel
	
	printf("\nCidade: ");
	gets(p->end_imov.cidade);
	fflush(stdin); // receber cidade do imovel
	
	printf("CEP: ");
	gets(p->end_imov.CEP);
	fflush(stdin); //receber cep do imovel
	
	printf("\n\n\tLista de Proprietarios:");
	
	//Mostra os ids  e proprietários disponíveis:
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietario, sizeof(prop), qtde_prop, fptr);
		fclose(fptr);
		
		for(i=0; i<qtde_prop; i++)	
			if((proprietario + i)->qtde_casa < 5)
			{	
				qtde_livres +=1;				
				printf("\nId: %i\tNome: %s", (proprietario + i)->reg_prop, (proprietario + i)->nome);
			}
	}
	
	if(qtde_livres == 0)
	{
		printf("\n\nNao ha Proprietarios livres, todo o cadastro desse imovel sera perdido.\n\n");
		system("pause");
		return 0;
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
		
		if(num_reg != -1)
		{
			if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Proprietario\n\n");
			else
			{	
				rewind(fptr);
				fread(proprietario, sizeof(prop), qtde_prop, fptr);
				fclose(fptr);
									
				i_casas = (proprietario + num_reg)->qtde_casa;
				((proprietario + num_reg)->casa + i_casas)->num_casa = p->reg_imov;
				((proprietario + num_reg)->casa + i_casas)->status_casa = 'L';
				(proprietario + num_reg)->qtde_casa += 1;

				gravaProp(proprietario, qtde_prop);
			}
		}	
			
		else
		{
			fflush(stdin);
			printf("\nId nao encontrado, deseja tentar novamente<S/N>: ");
			scanf("%c",&op);
			fflush(stdin);
				
			op = toupper(op);				
		}
	}while(op != 'N');
	
	if(num_reg != -1)
	{//Se o registro não for Inválido:	
		system("cls");
		mostraImovel(p);
	
		system("pause");
		
		salvarImo(p);	
		return 1;
	}
	
	else
	{
		printf("\nNao foi possivel realizar o cadastro por nao atrelar o imovel a um proprietario\n\n");
		system("pause");
		return 0;
	}
}//Realiza o Cadastro e atrelamento do Imovel ao Proprietario


int cadastrarLocatario(locatario *p, int id, imovel *imovel, int qtde_imov, prop *proprietario, int qtde_prop)//opcao 5: funcao para cadastrar Locatario
{
	int i, qtde_livres = 0, num_regProp, num_regImov, id_Imov, i_casas;
	char op;
	FILE *fptr = NULL;
	
	system("cls");
	
	p->reg_loc = id;
	fflush(stdin);
	printf("\n\tCadastro Locatario:"
		   "\nID: %i", p->reg_loc);
	
	printf("\nDigite o nome: ");
	gets(p->nome);
	fflush(stdin); // receber nome do locatário
	
	printf("\nDigite o CPF: ");
	gets(p->CPF);
	fflush(stdin); // receber cpf do locatário

	printf("\nCelular: ");
	gets(p->end_loc.cel);
	fflush(stdin); // receber celular do locatário
	
	printf("\nTelefone: ");
	gets(p->end_loc.fone);
	fflush(stdin); // receber telefone do locatário
	
	printf("\nEmail: ");
	gets(p->end_loc.email);
	fflush(stdin); // receber email do locatário
	
	printf("\nRua: ");
	gets(p->end_loc.logradouro);
	fflush(stdin); // receber logradouro do locatário
	
	printf("\nBairro: ");
	gets(p->end_loc.bairro);
	fflush(stdin); // receber bairro do locatário
	
	printf("\nCidade: ");
	gets(p->end_loc.cidade);
	fflush(stdin); // receber cidade do locatário
	
	printf("\nEstado: ");
	gets(p->end_loc.estado);
	fflush(stdin); // receber estado do locatário
	
	printf("CEP: ");
	gets(p->end_loc.CEP);
	fflush(stdin); //receber cep do locatário
	
	printf("\nDigite o dia de vencimento do Aluguel: ");
	scanf("%i", &(p->dia_venc) );
	fflush(stdin); // receber a data inicial do contrato
	
	printf("\nDigite a data de inicio do Contrato DD/MM/YYYY: ");
	gets(p->inicio);
	fflush(stdin); // receber a data inicial do contrato
	
	printf("\nDigite a data de Termino do Contrato DD/MM/YYYY: ");
	gets(p->termino);
	fflush(stdin); // receber a data final do contrato
	
	//Fazer a busca do registro dos imóveis livres:	
	if( (fptr = fopen("imovel.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Imovel\n\n");
	else
	{	
		rewind(fptr);
		fread(imovel, sizeof(imovel), qtde_imov, fptr);
		fclose(fptr);
		
		for(i = 0; i<qtde_imov; i++)
			if((imovel + i)->status.sigla == 'L')
			{	
				qtde_livres += 1;				
				printf("\nId: %i\tLogradouro: %s", (imovel + i)->reg_imov, (imovel + i)->end_imov.logradouro);
			}
	}
	
	if(qtde_livres == 0)
	{	
		printf("\n\nNao ha Imoveis livres, todo o cadastro desse locatario sera perdido.\n\n");
		system("pause");
		return 0;
	}
	
	do
	{	
		//Id do proprietário:
		fflush(stdin);
		printf("\n\nDigite o Id do Imovel: ");
		scanf("%i", &id_Imov);
		fflush(stdin);

		num_regImov = buscaImovel(imovel, qtde_imov, id_Imov);		//Verificar se é possível atrelar o Locatario ao Imóvel
		num_regProp = buscaProprietarioPorImovel(proprietario, qtde_prop, id_Imov);		//Faz a busca de um proprietário através do Id/Número de registro de um imóvel				
		op = 'N';
		
		if(num_regImov != -1 && num_regProp != -1)
		{
			fptr = NULL;
			
			//Altera o Imóvel:
			if( (fptr = fopen("imovel.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Imovel\n\n");
			else
			{
				rewind(fptr);
				fread(imovel, sizeof(imovel), qtde_imov, fptr);
				fclose(fptr);
				
				(imovel + num_regImov)->status.loc.sigla = 'A';				
				(imovel + num_regImov)->status.loc.reg_loc = p->reg_loc;				
				(imovel + num_regImov)->status.sigla = 'A';
				
				gravaImo(imovel, qtde_imov);
			}
			
			//Altera o Proprietário:
			if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Proprietario\n\n");
			else
			{
				rewind(fptr);
				fread(proprietario, sizeof(prop), qtde_prop, fptr);
				fclose(fptr);
									
				i_casas = buscaCasa(proprietario, qtde_prop, num_regProp, id_Imov);	//Faz a busca da casa do proprietário através do Id do Imóvel
								
				((proprietario + num_regProp)->casa + i_casas)->status_casa = 'A';
				p->reg_imov = id_Imov;			
				
				gravaProp(proprietario, qtde_prop);
			}
		}	
			
		else
		{
				fflush(stdin);
				printf("\nId nao encontrado, deseja tentar novamente<S/N>: ");
				scanf("%c",&op);
				fflush(stdin);
				
				op = toupper(op);				
		}
	}while(op != 'N');
	
	if(num_regImov != -1 && num_regProp != -1)
	{//Se o registro for válido:	
		system("pause");
		
		salvarLoc(p);	
	}
	
	else if(num_regProp == -1)
	{
		printf("\nNao foi possivel realizar o cadastro por nao atrelar o Locatario a um Proprietario\n\n");
		system("pause");
		return 0;
	}
	
	else
	{
		printf("\nNao foi possivel realizar o cadastro por nao atrelar o Locatario a um Imovel\n\n");
		system("pause");
		return 0;
	}
				
	system("cls");
	
	mostraLocatario(p);
	system("pause");
	return 1;
}


/////////////////////////////////////////////////////funcoes arquivo
int verifProp()//Verifica se tem o arquivo 'proprietario.bin' e retorna a quantidade de proprietários nele
{
	FILE *fptr = NULL;
	long int Tprop = 0;
	
	if((fptr = fopen("proprietario.bin", "rb")) == NULL)
		return Tprop;
	else
	{
		fseek(fptr, 0, 2);
		Tprop = ftell(fptr) / sizeof(prop);	
		fclose(fptr);
		
		return Tprop;
	}
}//Verifica se tem o arquivo 'proprietario.bin' e retorna a quantidade de proprietários nele


int verifImo()//Verifica se tem o arquivo 'imovel.bin' e retorna a quantidade de imoveis nele
{
	FILE *fptr = NULL;
	long int Timo = 0;
	
	if((fptr = fopen("imovel.bin", "rb")) == NULL)
		return Timo;
	else
	{
		fseek(fptr, 0, 2);
		Timo = ftell(fptr) / sizeof(imovel);	
		fclose(fptr);
		
		return Timo;
	}
}//Verifica se tem o arquivo 'imovel.bin' e retorna a quantidade de imoveis nele


int verifLoc()//Verifica se tem o arquivo 'locatario.bin' e retorna a quantidade de locatarios nele
{
	FILE *fptr = NULL;
	long int Tloc = 0;
	
	if((fptr = fopen("locatario.bin", "rb")) == NULL)
		return Tloc;
	else
	{
		fseek(fptr, 0, 2);
		Tloc = ftell(fptr) / sizeof(locatario);	
		fclose(fptr);
		
		return Tloc;
	}
}//Verifica se tem o arquivo 'locatario.bin' e retorna a quantidade de locatarios nele


void salvarProp(prop *dados)//funcao para gravar 1 proprietario
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("proprietario.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(prop), 1, fptr);
		fclose(fptr);
	}
}//Salva só um proprietario


void gravaProp(prop *dados, int qreg)//funcao para gravar todos proprietarios
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("proprietario.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados,sizeof(prop),qreg, fptr);	
		fclose(fptr);	
	}
}//Salva vários Proprietários sobrepondo o que tiver


void salvarImo(imovel *dados)//funcao para gravar 1 imovel
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("imovel.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(imovel), 1, fptr);
		fclose(fptr);
	}
}//Salva um Imovel


void gravaImo(imovel *dados, int qreg)//funcao para gravar todos imoveis
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("imovel.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(imovel), qreg, fptr);	
		fclose(fptr);
	}
		
}//Salva vários Imóveis sobrepondo o que tiver


void salvarLoc(locatario *dados)//funcao para gravar 1 locatario
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("locatario.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(locatario), 1, fptr);
		fclose(fptr);
	}
}//Salva um Locatário


void gravaLoc(locatario *dados, int qreg)//funcao para gravar todos locatarios
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("locatario.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(locatario), qreg, fptr);
		fclose(fptr);	
	}		
}//Salva vários Locatários sobrepondo o que tiver


void opGravaProp(prop *p, char *opcao, int indice)//funcao para alterar apenas 1 proprietario
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("proprietario.bin", opcao)) == NULL)
		printf("\nErro ao abrir proprietario.bin");
	else
	{
		if(strcmp(opcao,"rb+") == 0)
			fseek(fptr, indice * sizeof(prop), 0);
			
		fwrite(p, sizeof(prop), 1, fptr);
		fclose(fptr);
	}
	
}


void opGravaImov(imovel *p, char *opcao, int indice)//funcao para alterar apenas 1 imovel
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("imovel.bin", opcao)) == NULL)
		printf("\nErro ao abrir imovel.bin");
	else
	{
		if(strcmp(opcao,"rb+") == 0)
			fseek(fptr, indice * sizeof(imovel), 0);
			
		fwrite(p, sizeof(imovel), 1, fptr);
		fclose(fptr);
	}
}


void opGravaLoc(locatario *p, char *opcao, int indice)//funcao para alterar apenas 1 locatario
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("locatario.bin", opcao)) == NULL)
		printf("\nErro ao abrir locatario.bin");
	else
	{
		if(strcmp(opcao,"rb+") == 0)
			fseek(fptr, indice * sizeof(locatario), 0);
			
		fwrite(p, sizeof(locatario), 1, fptr);
		fclose(fptr);
	}
}


// Funções de Leitura:
void LerProp(prop *p, int t)//opcao 2: ler todos proprietarios ou opcoes selecionadas
{
	int i, j, op, op1 = 1;
	char cpf[15];
	
	FILE *fptr = NULL;
	
	do
	{		
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
			rewind(fptr);
			fread(p, sizeof(prop), t, fptr);
			fclose(fptr);
			
			if(op == 1)
				for(i = 0; i < t; i++)						
					mostraProp(p + i, j);
			
			else
			{
				do
				{
					printf("\nBuscar CPF: ");
					gets(cpf);
					
					for(i = 0; i < t; i++)	
						if(strcmp(cpf, p->CPF) == 0)
						{
							mostraProp(p + i, j);
							op1 = 0;
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
		}
	}
	printf("\n");
	system("pause");
}//Mostra os Proprietários com os filtros desejados


void LerImo(imovel *p, int t)//opcao 4: ler todos imoveis ou opcoes selecionadas
{
	int i, j, qtd_quartos, falha, op, op2;
	float area;
	char bairro[20];
	FILE *fptr = NULL;
	
	do{		
		printf("\nMenu de busca:"
				"\n[1] - Total"
				"\n[2] - Por Area Util"
				"\n[3] - Por Quantidade de Quartos"
				"\n[4] - Por Bairro"
				"\n[5] - Voltar"
				"\n<1/.../4>: ");
		scanf("%i", &op);
		fflush(stdin);
		
		system("cls");
	}while(op < 1 || op > 5);
	
	
	if( op != 5 )
	{	
		if((fptr = fopen("imovel.bin","rb")) == NULL)
			printf("\nArquivo inexistente!");
		else
		{
			rewind(fptr);
			fread(p, sizeof(imovel), t, fptr);
			fclose(fptr);
			
			if(op == 1)
			{
				do
				{		
					printf("\nStatus do Imovel:"
							"\n[1] - [L]ivre"
							"\n[2] - [A]lugado"
							"\n<1/2>: ");
					scanf("%i", &op2);
					fflush(stdin);
					
					system("cls");
				}while(op2 < 1 || op2 > 2);
							
				for(i = 0; i < t; i++)
				{				
					if(op2 == 1 && p->status.sigla == 'L')				
						mostraImovel(p + i);
					
					else if(op2 == 2 && p->status.loc.sigla == 'A')
						mostraImovel(p + i);
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
						if(area == p->area)
						{
							mostraImovel(p + i);														
							falha = 0;
						}
			
					if(falha == 1)
					{
						do{
							fflush(stdin);
							printf("\nArea nao encontrada!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha != 1)
								printf("\nDigite uma opcao valida\n");
								
						}while(falha != 0 && falha != 1);
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
						if(qtd_quartos == p->quartos )
						{
							mostraImovel(p + i);											
							falha = 0;
						}
					
					if(falha == 1)
					{
						do{
							fflush(stdin);
							printf("\nQuantidade de quartos nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha != 1)
								printf("\nDigite uma opcao valida\n");
								
						}while(falha != 0 && falha != 1);
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
						if(strcmp(bairro, p->end_imov.bairro) == 0 )
						{
							mostraImovel(p + i);													
							falha = 0;
						}
					
					if(falha == 1)
						do
						{
							fflush(stdin);
							printf("\nBairro nao encontrado!\nDeseja continuar? <0 - nao/1 - sim>: ");
							scanf("%i", &falha);
							fflush(stdin);
						
							if(falha != 0 && falha != 1)
								printf("\nDigite uma opcao valida\n");
								
						}while(falha != 0 && falha != 1);
				}while(falha == 1);
			}
		}
	}
	printf("\n");
	system("pause");
}//Mostra os Imóveis com os filtros desejados


void LerLoc(locatario *p, int qreg)//opcao 6: ler todos locatarios ou opcoes selecionadas
{
	int i, j, op, op1 = 1;
	char cpf[15];
	
	FILE *fptr = NULL;
				
	if((fptr = fopen("locatario.bin","rb")) == NULL)
		printf("\nArquivo inexistente!");
	else
	{				
		rewind(fptr);
		fread(p, sizeof(locatario), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			mostraLocatario(p + i);
	}	
	printf("\n");
	system("pause");
}//Mostra os Locatários


void relatorio(locatario *p, int qtde_loc)//opcao 7: mostrar relatorio dos locatarios selecionados pelo dia
{
	int i, dia, cont = 0;
	FILE *fptr = NULL;
	
	do
	{
		printf("Digite o dia: ");
		fflush(stdin);
		scanf("%i", &dia);
		fflush(stdin);
	}while(dia < 1 || dia > 31);
	
	if((fptr = fopen("locatario.bin","rb")) == NULL)
		printf("\nArquivo inexistente!\n");
	else
	{
		rewind(fptr);
		fread(p, sizeof(locatario), qtde_loc, fptr);
		fclose(fptr);
			
		printf("\n\tDia %i", dia);
	
		for(i = 0; i < qtde_loc; i++)
			if((p + i)->dia_venc == dia)
			{
				mostraLocatario(p + i);
				cont ++;
			}
		if(cont == 0)
		
			printf("\nSem imoveis no dia escolhido\n");
	}
	system("pause");
}


void terminoContrato(locatario *loc, int qtde_loc, imovel *imovel, int qtde_imov, prop *prop, int qtde_prop)//opcao 8: finalizar o contrato do locatario e alterar registro
{
	int i, j, multa, num_regImov, num_regProp, i_casas, cont = 0;
	char cpf[15], op, termino[9];
	FILE *fptr;
	
	do
	{
		system("cls");
		
		printf("Termino de contrato\n");
		printf("\nDigite o cpf: ");
		fflush(stdin);
		gets(cpf);
		fflush(stdin);
			
		if((fptr = fopen("locatario.bin", "rb")) == NULL)
			printf("\nArquivo inexistente!\n");
		else
		{
			rewind(fptr);
			fread(loc, sizeof(locatario), qtde_loc, fptr);
			fclose(fptr);
			
			for(i = 0; i < qtde_loc; i++)
				if(strcmp((loc + i)->CPF, cpf) == 0)
				{
					mostraLocatario(loc + i);
					cont++;
					break;
				}
				
			if(cont != 0)
			{
				printf("\nDeseja confirmar o cpf? <S/N>: ");
				scanf("%c", &op);
				
				op = toupper(op);
			}
			if(cont == 0)
				printf("\nCpf nao encontrado!\n");
				
			else if(op == 'S' && cont != 0)
			{
				printf("\n\nDigite a data atual DD/MM/YYYY: ");
				fflush(stdin);
				gets(termino);
				fflush(stdin);
				
				multa = calcularMulta((loc + i)->termino, termino);
				
				num_regImov = buscaImovelAlugado(imovel, qtde_imov, (loc + i)->reg_loc);						//Verificar se é possível atrelar o Locatario ao Imóvel
				num_regProp = buscaProprietarioPorImovelAlugado(prop, qtde_prop, (loc + i)->reg_loc);		//Faz a busca de um proprietário através do Id/Número de registro de um imóvel				
				i_casas = buscaCasaAlugado(prop, qtde_prop, num_regProp, (imovel + num_regImov)->reg_imov);			//Faz a busca da casa do proprietário através do Id do Imóvel
				
				//os valores abaixo nao estao alterando
				(imovel + num_regImov)->status.sigla = 'L';
				(imovel + num_regImov)->status.loc.sigla = 'L';
				( (prop + num_regProp)->casa + i_casas)->status_casa = 'L';

				(loc + i)->reg_imov = 0;
				
				for(j = 0; j < 15; j++)
					( (loc + i)->CPF[j]) = '\0';
					
				((loc + i)->CPF[0]) = '@';
				
				if(multa == 1)
					printf("\nMulta no valor de: R$%.2f\n", (imovel + num_regImov)->valor);
				
				gravaProp(prop, qtde_prop);
				gravaImo(imovel, qtde_imov);
				gravaLoc(loc, qtde_loc);
			}
			op = 'S';
		}
	}while(op == 'N');
	
	system("pause");
}


int calcularMulta(char contrato[9], char atual[9])// funcao que calcula a diferenca de datas utilizando comparacao de indices
{
	int dia, dia1; //01
	int mes, mes1; //34
	int ano, ano1; //6789
	int conf = 0;
	
	//contrato
	dia = ((int)(contrato[0]) - 48) * 10 ;
	dia += (int)(contrato[1]) - 48;
	
	mes = ((int)(contrato[3]) - 48) * 10 ;
	mes += (int)(contrato[4]) - 48;
	
	ano = ((int)(contrato[6]) - 48) * 1000;
	ano += ((int)(contrato[7]) - 48) * 100;
	ano += ((int)(contrato[8]) - 48) * 10;
	ano += (int)(contrato[9]) - 48;
	
	//atual
	dia1 = ((int)(atual[0]) - 48) * 10 ;
	dia1 += (int)(atual[1]) - 48;
	
	mes1 = ((int)(atual[3]) - 48) * 10 ;
	mes1 += (int)(atual[4]) - 48;
	
	ano1 = ((int)(atual[6]) - 48) * 1000;
	ano1 += ((int)(atual[7]) - 48) * 100;
	ano1 += ((int)(atual[8]) - 48) * 10;
	ano1 += (int)(atual[9]) - 48;
	
	if(ano >= ano1)
	{
		if(mes >= mes1)
			if(dia > dia1)
				printf("\nAVISO\nO contrato ainda nao esta vencido\nSera aplicada uma multa no valor de um aluguel\n\n", conf++);
		
		if(ano > ano1)
			printf("\nAVISO\nO contrato ainda nao esta vencido\nSera aplicada uma multa no valor de um aluguel\n\n", conf++);
	}
	return conf;
}


void limparDados()//modo desenvolvedor para apagar dados
{
	FILE *fptr;
	
	system("cls");
	
	if((fptr = fopen("proprietario.bin", "w")) == NULL) 
		printf("\nProprietario indisponivel!\n");
	if((fptr = fopen("imovel.bin", "w")) == NULL) 
		printf("\nImovel indisponivel!\n");
	if((fptr = fopen("locatario.bin", "w")) == NULL) 
		printf("\nLocatario indisponivel!\n");
		
	system("pause");
}


//Funções de Busca:
int buscaProprietario(prop *proprietarios, int qreg, int num_reg)//funcao para retornar o indice do proprietario
{
	int i;
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)
			if( (proprietarios + i)->reg_prop == num_reg)
				return i;
	}
	return -1;	//NÃO ENCOTROU O PROPRIETÁRIO
}//Busca Proprietário através do Id


int buscaImovel(imovel *imoveis, int qreg, int num_reg)//funcao para retornar o indice do imovel livre
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("imovel.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(imoveis, sizeof(imovel), qreg, fptr);
		fclose(fptr);
			
		for(i = 0; i < qreg; i++)
			if((imoveis + i)->reg_imov == num_reg && (imoveis + i)->status.sigla == 'L')	
				return i;	
	}
	return -1;	//NÃO ENCOTROU O IMÓVEL
}//Busca Imóvel através do Id


int buscaImovelAlugado(imovel *imoveis, int qreg, int num_reg)//funcao para retornar o indice do imovel alugado
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("imovel.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(imoveis, sizeof(imovel), qreg, fptr);
		fclose(fptr);
			
		for(i = 0; i < qreg; i++)
			if((imoveis + i)->reg_imov == num_reg && (imoveis + i)->status.sigla == 'A')	
				return i;	
	}
	return -1;	//NÃO ENCOTROU O IMÓVEL
}//Busca Imóvel através do Id


int buscaProprietarioPorImovel(prop *proprietarios, int qreg, int id_casa)//funcao para retornar o indice do proprietario do imovel alugado livre
{
	int i, j;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			for(j = 0; j < 5; j++)
				if( ((proprietarios + i)->casa + j)->num_casa == id_casa && ((proprietarios + i)->casa + j)->status_casa == 'L') 
					return i;
	}
	return -1;  //NÃO ENCOTROU O PROPRIETÁRIO
}//Busca o índice do proprietário em relação ao id da casa


int buscaProprietarioPorImovelAlugado(prop *proprietarios, int qreg, int id_casa)//funcao para retornar o indice do proprietario do imovel alugado
{
	int i, j;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			for(j = 0; j < 5; j++)
				if( ((proprietarios + i)->casa + j)->num_casa == id_casa && ((proprietarios + i)->casa + j)->status_casa == 'A') 
					return i;
	}
	return -1;  //NÃO ENCOTROU O PROPRIETÁRIO
}//Busca o índice do proprietário em relação ao id da casa


int buscaCasa(prop *proprietarios, int qreg, int i_prop, int id_casa)//funcao para retornar o indice da casa livre
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(prop), qreg, fptr);
		fclose(fptr);

		for(i = 0; i < 5; i++)
			if( ((proprietarios + i_prop)->casa + i)->num_casa == id_casa && ((proprietarios + i_prop)->casa + i)->status_casa == 'L')
			    return i;
	}	
	return -1;	//NÃO ENCOTROU A CASA
}//Busca o índice da casa em relação ao proprietário


int buscaCasaAlugado(prop *proprietarios, int qreg, int i_prop, int id_casa)//funcao para retornar o indice da casa alugada
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(prop), qreg, fptr);
		fclose(fptr);

		for(i = 0; i < 5; i++)
			if( ((proprietarios + i_prop)->casa + i)->num_casa == id_casa && ((proprietarios + i_prop)->casa + i)->status_casa == 'A')
			    return i;
	}	
	return -1;	//NÃO ENCOTROU A CASA
}//Busca o índice da casa em relação ao proprietário


int buscaProprietarioPorCPF(prop *p, int qreg, char cpf[15])//funcao utilizada para economizar linhas no printf dentro do codigo
{
	int i, i_prop = -1;
	FILE *fptr = NULL;	
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		for(i = 0; i < qreg; i++)
		{
			fseek(fptr, i * sizeof(prop), 0);
			fread(p, sizeof(prop), 1, fptr);
			
			if(strcmp(cpf, p->CPF) == 0)
			{
				i_prop = i;
				i = qreg;
				break;
			}
		}
		fclose(fptr);
	}
	return i_prop;
}


int buscaLocatarioPorCPF(locatario *p, int qreg, char cpf[15])//funcao para evitar repetir o cpf
{
	int i, i_prop = -1;
	FILE *fptr = NULL;
		
	system("cls");
	
	if( (fptr = fopen("locatario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Locatario.bin\n\n");
	else
	{
		for(i = 0; i < qreg; i++)
		{
			fseek(fptr, i * sizeof(locatario), 0);
			fread(p, sizeof(locatario), 1, fptr);
			
			if(strcmp(cpf, p->CPF) == 0)
			{
				i_prop = i;
				i = qreg;
				break;
			}
		}
		fclose(fptr);
	}
	return i_prop;
}


//Funções de Mostrar:
void mostraProp(prop *p, int qtd_Casas)//funcao utilizada para economizar linhas no printf dentro do codigo
{
	int j;
	
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\tCadastro: "
			"\nID: %i"
			"\nNome: %s"
			"\nCpf: %s"
			"\nCelular: %s"
			"\nTelefone: %s"
			"\nEmail: %s", p->reg_prop, p->nome, p->CPF, p->end_prop.cel, p->end_prop.fone, p->end_prop.email);
			
	printf("\n\n\tEndereco do proprietario: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nEstado: %s"
			"\nCep: %s"
			"\nQtdCasas: %i", p->end_prop.logradouro, p->end_prop.bairro, p->end_prop.cidade, p->end_prop.estado, p->end_prop.CEP, p->qtde_casa);
					
	for(j = 0; j < p->qtde_casa; j++) //percorrer total de casas do proprietario
	{
		printf("\n\n\tImovel: %i", j+1);
		printf("\nNumero casa: %i", (p->casa + j)->num_casa );
		printf("\nStatus: %c\n", (p->casa + j)->status_casa );
	}
	printf("\n");
}


void mostraImovel(imovel *p)//funcao utilizada para economizar linhas no printf dentro do codigo
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\nImovel: "
			"\nID: %i"
			"\nTotal de quartos: %i"
			"\nArea total: %.2f m^2"
			"\nValor: %.2f"
			"\nStatus: %i"
			"\nSigla: %c"
			"\nSigla: %c", p->reg_imov, p->quartos, p->area, p->valor, p->status.loc.reg_loc, p->status.loc.sigla, p->status.sigla);

	printf("\n\n\tEndereco do imovel: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nCep: %s\n\n", p->end_imov.logradouro, p->end_imov.bairro, p->end_imov.cidade, p->end_imov.CEP);	
}//Mostra os dados de um imóvel


void mostraLocatario(locatario *p)//funcao utilizada para economizar linhas no printf dentro do codigo
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\nLocatario: "
			"\nID: %i"
			"\nNome: %s"
			"\nCpf: %s"
			"\nID do Imovel: %i"
			"\nDia Vencimento: %i"
			"\nData de Inicio: %s"
			"\nData de Termino: %s\n", p->reg_loc, p->nome, p->CPF, p->reg_imov, p->dia_venc, p->inicio, p->termino);
			
	printf("\n\n\tEndereco do locatario: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nEstado: %s"
			"\nCep: %s\n\n", p->end_loc.logradouro, p->end_loc.bairro, p->end_loc.cidade, p->end_loc.estado, p->end_loc.CEP);
}//Mostra os dados de um imóvel


//Funções de alterar:
void alteraProprietario(prop *p, int tam)//altera variaveis do proprietario definidas pelo usuario
{
	int i, j, i_prop, campo;
	char cpf[15], op;
	
	FILE *fptr = NULL;
	do{
		//Recebe e verifica o CPF:
		do{
			
			fflush(stdin);
			printf("\nBuscar CPF: ");		
			gets(cpf);
			
			i_prop = buscaProprietarioPorCPF(p, tam, cpf);
			
			op = 'y';
			
			if(i_prop == -1)
			{
				do
				{				
					
					printf("\nCpf invalido, pesquisar novamente<S/N>: ");
					fflush(stdin);
					scanf("%c", &op);
					
					if(op != 'S' && op != 's' && op != 'N' && op != 'n')
						printf("\nOpcao invalida!\n\n");
				}while(op != 'S' && op != 's' && op != 'N' && op != 'n');
			}
		}while(op == 'S' || op == 's');	
		
		if(op == 'N' || op == 'n')	
			return;
		
		op = 'n';
	
		system("cls");
		do
		{
			mostraProp(p + i_prop, (p + i_prop)->qtde_casa);
			printf("\n\nEscolha um campo para alterar:"
				"\n[1]  - Nome"
				"\n[2]  - CPF"
				"\n[3]  - Logradouro"
				"\n[4]  - Bairro"
				"\n[5]  - Cidade"
				"\n[6]  - Estado"
				"\n[7]  - CEP"
				"\n[8]  - E-mail"
				"\n[9]  - Telefone"
				"\n[10] - Celular"
				"\n[11] - Voltar para o Menu"
				"\n\nOpcao<1/.../10>: ");
			fflush(stdin);
			scanf("%i", &campo);
			
			if(campo < 1 || campo > 11)	
				printf("\nCampo invalido, digite um calor possivel\n");
		}while(campo < 1 || campo > 11);
		
		switch(campo)
		{
			case 1:
				fflush(stdin);
				printf("\nNovo Nome: ");  
				gets(p->nome);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nNome Alterado com SUCESSO\n\n");
				break;
				
			case 2:								
				fflush(stdin);
				printf("\nNovo CPF: ");  
				gets(p->CPF);					
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nCPF Alterado com SUCESSO\n\n");
				break;
				
			case 3:
				fflush(stdin);
				printf("\nNovo Logradouro: ");  
				gets(p->end_prop.logradouro);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nLogradouro Alterado com SUCESSO\n\n");
				break;
				
			case 4:
				fflush(stdin);
				printf("\nNovo Bairro: ");  
				gets(p->end_prop.bairro);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nBairro Alterado com SUCESSO\n\n");
				break;
				
			case 5:
				fflush(stdin);
				printf("\nNova Cidade: ");  
				gets(p->end_prop.cidade);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nCidade Alterada com SUCESSO\n\n");
				break;
				
			case 6:
				fflush(stdin);
				printf("\nNovo Estado: ");  
				gets(p->end_prop.estado);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nEstado Alterado com SUCESSO\n\n");
				break;
				
			case 7:
				fflush(stdin);
				printf("\nNovo CEP: ");  
				gets(p->end_prop.estado);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nCEP Alterado com SUCESSO\n\n");
				break;
				
			case 8:
				fflush(stdin);
				printf("\nNovo E-mail: ");  
				gets(p->end_prop.email);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nE-mail Alterado com SUCESSO\n\n");
				break;
				
			case 9:
				fflush(stdin);
				printf("\nNovo Telefone: ");  
				gets(p->end_prop.fone);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nTelefone Alterado com SUCESSO\n\n");
				break;
				
			case 10:
				fflush(stdin);
				printf("\nNovo Celular: ");  
				gets(p->end_prop.cel);
				
				opGravaProp(p,"rb+", i_prop);
				printf("\nCelular Alterado com SUCESSO\n\n");
				break;
				
			default:
				fflush(stdin);
				system("cls");
				printf("\n\n\n\n");
				system("pause");
				break;				
		}
		
		mostraProp(p + i_prop, (p + i_prop)->qtde_casa);
		do
		{	
			printf("\nDeseja alterar mais um campo <S/N>: ");
			fflush(stdin);
			scanf("%c", &op);
			
			if(op != 's' && op != 'S' && op != 'N' && op != 'n')
				printf("\nDigite um campo valido\n\n");
		}while(op != 's' && op != 'S' && op != 'N' && op != 'n');
	}while(op == 'S' || op == 's');
	
	printf("\n\n");
	system("pause");
}


void alteraImovel(imovel *p, int tam)//altera variaveis do imovel definidas pelo usuario
{
	
	int i, j, i_imovel, campo, id_imovel;
	char op;
	
	FILE *fptr = NULL;
	do
	{
		//Recebe e verifica o id do imóvel:
		do
		{
			
			fflush(stdin);
			printf("\nBuscar registro do Imovel: ");		
			scanf("%i", &id_imovel);
			
			i_imovel = buscaImovel(p, tam, id_imovel);
			
			op = 'y';
			if(i_imovel == -1)
			{
				do
				{				
					
					printf("\nCpf invalido, pesquisar novamente<S/N>: ");
					fflush(stdin);
					scanf("%c", &op);
					
					if(op != 'S' && op != 's' && op != 'N' && op != 'n')
						printf("\nOpcao invalida!\n\n");
				}while(op != 'S' && op != 's' && op != 'N' && op != 'n');
			}
		}while(op == 'S' || op == 's');	
		
		if(op == 'N' || op == 'n')		
			return;
		
		op = 'n';
	
		system("cls");
		do
		{
			mostraImovel(p + i_imovel);
			printf("\n\nEscolha um campo para alterar:"
				"\n[1] - Total de quartos"
				"\n[2] - Area total"
				"\n[3] - Valor"
				"\n[4] - Logradouro"
				"\n[5] - Bairro"
				"\n[6] - Cidade"
				"\n[7] - Cep"
				"\n[8] - Voltar para o Menu"
				"\n\nOpcao<1/.../8>: ");
			fflush(stdin);
			scanf("%i", &campo);
			
			if(campo < 1 || campo > 8)		
				printf("\nCampo invalido, digite um calor possivel\n");
		}while(campo < 1 || campo > 8);
		
		switch(campo)
		{
			case 1:
				fflush(stdin);
				printf("\nNova quantidade de quartos: ");  
				scanf("%i", &(p->quartos));
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nQuantidade de Quartos Alterada com SUCESSO\n\n");
				break;
			
			case 2:								
				fflush(stdin);
				printf("\nNova area total: ");  
				scanf("%f", &(p->area));	
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nArea Total Alterada com SUCESSO\n\n");
				break;
			
			case 3:
				fflush(stdin);
				printf("\nNovo Valor: ");  
				scanf("%f", &(p->valor));
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nValor Alterado com SUCESSO\n\n");
				break;
			
			case 4:
				fflush(stdin);
				printf("\nNovo Logradouro: ");  
				gets(p->end_imov.logradouro);
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nLogradouro Alterado com SUCESSO\n\n");
				break;
			
			case 5:
				fflush(stdin);
				printf("\nNovo Bairro: ");  
				gets(p->end_imov.bairro);
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nBairro Alterado com SUCESSO\n\n");
				break;
			
			case 6:
				fflush(stdin);
				printf("\nNova Cidade: ");  
				gets(p->end_imov.cidade);
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nCidade Alterada com SUCESSO\n\n");
				break;			
			
			case 7:
				fflush(stdin);
				printf("\nNovo CEP: ");  
				gets(p->end_imov.CEP);
				
				opGravaImov(p,"rb+", i_imovel);
				printf("\nCEP Alterado com SUCESSO\n\n");
				break;	
						
			default:
				fflush(stdin);
				system("cls");				
				system("pause");
				break;				
		}
		
		mostraImovel(p + i_imovel);
		do
		{
			
			printf("\nDeseja alterar mais um campo <S/N>: ");
			fflush(stdin);
			scanf("%c", &op);
			
			if(op != 's' && op != 'S' && op != 'N' && op != 'n')	
				printf("\nDigite um campo valido\n\n");
		}while(op != 's' && op != 'S' && op != 'N' && op != 'n');
	}while(op == 'S' || op == 's');
	
	printf("\n\n");
	system("pause");
}


void alteraLocatario(locatario *p, int tam)//altera variaveis do locatario definidas pelo usuario
{
	int i, j, i_loc, campo;
	char cpf[15], op;
	
	FILE *fptr = NULL;
	do
	{
		//Recebe e verifica o CPF:
		do
		{	
			fflush(stdin);
			printf("\nBuscar CPF: ");		
			gets(cpf);
			
			i_loc = buscaLocatarioPorCPF(p, tam, cpf);
			
			op = 'y';
			
			if(i_loc == -1)
			{
				do
				{				
					
					printf("\nCpf invalido, pesquisar novamente<S/N>: ");
					fflush(stdin);
					scanf("%c", &op);
					
					if(op != 'S' && op != 's' && op != 'N' && op != 'n')	
						printf("\nOpcao invalida!\n\n");
				}while(op != 'S' && op != 's' && op != 'N' && op != 'n');
			}
		}while(op == 'S' || op == 's');	
		
		if(op == 'N' || op == 'n')		
			return;
		
		op = 'n';

		system("cls");
		
		do
		{
			mostraLocatario(p + i_loc);
			printf("\n\nEscolha um campo para alterar:"
				"\n[1]  - Nome"
				"\n[2]  - CPF"
				"\n[3]  - Logradouro"
				"\n[4]  - Bairro"
				"\n[5]  - Cidade"
				"\n[6]  - Estado"
				"\n[7]  - CEP"
				"\n[8]  - E-mail"
				"\n[9]  - Telefone"
				"\n[10] - Celular"
				"\n[11] - Dia Vencimento"
				"\n[12] - Data Inicio"
				"\n[13] - Data Termino"
				"\n[14] - Voltar par o Menu"
				"\n\nOpcao<1/.../14>: ");
			fflush(stdin);
			scanf("%i", &campo);
			
			if(campo < 1 || campo > 14)		
				printf("\nCampo invalido, digite um calor possivel\n");
		}while(campo < 1 || campo > 14);
		
		switch(campo)
		{
			case 1:
				fflush(stdin);
				printf("\nNovo Nome: ");  
				gets(p->nome);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nNome Alterado com SUCESSO\n\n");
				break;
				
			case 2:								
				fflush(stdin);
				printf("\nNovo CPF: ");  
				gets(p->CPF);					
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nCPF Alterado com SUCESSO\n\n");
				break;
				
			case 3:
				fflush(stdin);
				printf("\nNovo Logradouro: ");  
				gets(p->end_loc.logradouro);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nLogradouro Alterado com SUCESSO\n\n");
				break;
				
			case 4:
				fflush(stdin);
				printf("\nNovo Bairro: ");  
				gets(p->end_loc.bairro);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nBairro Alterado com SUCESSO\n\n");
				break;
				
			case 5:
				fflush(stdin);
				printf("\nNova Cidade: ");  
				gets(p->end_loc.cidade);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nCidade Alterada com SUCESSO\n\n");
				break;
				
			case 6:
				fflush(stdin);
				printf("\nNovo Estado: ");  
				gets(p->end_loc.estado);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nEstado Alterado com SUCESSO\n\n");
				break;
				
			case 7:
				fflush(stdin);
				printf("\nNovo CEP: ");  
				gets(p->end_loc.estado);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nCEP Alterado com SUCESSO\n\n");
				break;
				
			case 8:
				fflush(stdin);
				printf("\nNovo E-mail: ");  
				gets(p->end_loc.email);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nE-mail Alterado com SUCESSO\n\n");
				break;
				
			case 9:
				fflush(stdin);
				printf("\nNovo Telefone: ");  
				gets(p->end_loc.fone);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nTelefone Alterado com SUCESSO\n\n");
				break;
				
			case 10:
				fflush(stdin);
				printf("\nNovo Celular: ");  
				gets(p->end_loc.cel);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nCelular Alterado com SUCESSO\n\n");
				break;
				
			case 11:
				fflush(stdin);
				printf("\nNovo dia de vencimento: ");  
				scanf("%i", &(p->dia_venc));
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nDia de Vencimento Alterado com SUCESSO\n\n");
				break;
				
			case 12:
				fflush(stdin);
				printf("\nNova Data de inicio: ");  
				gets(p->inicio);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nData de inicio Alterado com SUCESSO\n\n");
				break;
				
			case 13:
				fflush(stdin);
				printf("\nNova Data de termino: ");  
				gets(p->termino);
				
				opGravaLoc(p,"rb+", i_loc);
				printf("\nData de Termino Alterado com SUCESSO\n\n");
				break;
				
			default:
				fflush(stdin);
				system("cls");				
				system("pause");
				
				return;				
		}
		
		system("pause");
		system("cls");		
				
		mostraLocatario(p + i_loc);
		
		do
		{
			
			printf("\nDeseja alterar mais um campo <S/N>: ");
			fflush(stdin);
			scanf("%c", &op);
			
			if(op != 's' && op != 'S' && op != 'N' && op != 'n')	
				printf("\nDigite um campo valido\n\n");
		}while(op != 's' && op != 'S' && op != 'N' && op != 'n');
	}while(op == 'S' || op == 's');
	
	printf("\n\n");
	system("pause");
}

