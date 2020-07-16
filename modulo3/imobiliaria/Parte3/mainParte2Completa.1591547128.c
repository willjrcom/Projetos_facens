//Eduardo de Oliveira Almeida, 190963
//William Alfred Gazal Júnior, 180037

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

//////////////////////locatario
typedef  struct {
	int id;	// gerado automaticamente
	char nome[80];
	char CPF[15];
	st_end_prop end_loc;
	int reg_imov;	// registro imóvel –buscar no arq. Imóvel
	int dia_venc;
	char inicio[10];
	char termino[10];
}st_locatario;


//Funcoes de Alocacao:
void alocarProp(st_prop **p, int t);
void alocarImovel(st_imovel **p, int t);
void alocarInt(int **p, int tam);
void alocarLocatario(st_locatario **p, int t);

//Funcoes de Cadastrar:
void cadastrarProp(st_prop *p, int id);
int cadastrarImovel(st_imovel *p, int id, st_prop *proprietario, int qtde_prop);
int cadastrarLocatario(st_locatario *p, int id, st_imovel *imovel, int qtde_imov, st_prop *proprietario, int qtde_prop);

//Funcoes de Verificar:
int verifProp();
int verifImo();
int verifLoc();
int verifCpf(st_locatario *p, char cpf[15]);

//Funcoes de Salvar:
void salvarProp(st_prop *dados);
void salvarImo(st_imovel *dados);
void salvarLoc(st_locatario *dados);

//Funcoes de Gravar:
void gravaProp(st_prop *dados, int qreg);
void gravaImo(st_imovel *dados, int qreg);
void gravaLoc(st_locatario *dados, int qreg);

//Funcoes de Leitura
void LerProp(st_prop *p, int t);
void LerImo(st_imovel *p, int t);
void LerLoc(st_locatario *p, int t);

//Funcoes de Busca:
int buscaProprietario(st_prop *proprietarios, int qreg, int num_reg);
int buscaImovel(st_imovel *imoveis, int qreg, int num_reg);
int buscaImovelAlugado(st_imovel *imoveis, int qreg, int num_reg);
int buscaProprietarioPorImovel(st_prop *proprietarios, int qreg, int id_casa);
int buscaProprietarioPorImovelAlugado(st_prop *proprietarios, int qreg, int id_casa);
int buscaCasa(st_prop *proprietarios, int qreg, int i_prop, int id_casa);
int buscaCasaAlugado(st_prop *proprietarios, int qreg, int i_prop, int id_casa);

//Funcoes de Mostra:
void mostraProp(st_prop *p, int qtd_Casas);
void mostraImovel(st_imovel *p);
void mostraLocatario(st_locatario *p);

//Funcoes de Relatorio
void relatorio(st_locatario *p, int qtde_loc);

//Funcoes de Termino de contrato
void terminoContrato(st_locatario *loc, int qtde_loc, st_imovel *imovel, int qtde_imov, st_prop *prop, int qtde_prop);

//Funcao desenvolvedor
void limparDados();

//Funcao calcular multa
int calcularMulta(char contrato[9], char atual[9]);


/////////////////////////////////////////////////////main
int main()
{
	st_prop *prop = NULL;
	st_imovel *imovel = NULL;
	st_locatario *locatario = NULL;
	
	int op, Tprop, Timoveis, Tlocatario, confLoc, confImov;
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
			
			printf("\n\tImobiliaria");
			printf("\nTotal proprietarios: %i", Tprop);
			printf("\nTotal imoveis: %i", Timoveis);
			printf("\nTotal locatarios: %i", Tlocatario);
			printf("\nId proprietario: %i", Idprop);
			printf("\nId imovel: %i", IdImo);
			printf("\nId locatario: %i", IdLoc);
			
			printf("\n\tMenu opcoes:"
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
				break;
				
			case 10: exit(1);
				break;
		}
	}while(1);
	
	return 0;
}


/////////////////////////////////////////////////////alocacao
void alocarProp(st_prop **p, int t)
{
	if((*p = (st_prop*)realloc(*p, t * sizeof(st_prop))) == NULL)
		exit(1);
}//ALOCA PROPRIETARIO


void alocarImovel(st_imovel **p, int t){
	if((*p = (st_imovel*) realloc(*p, t * sizeof(st_imovel))) == NULL)
		exit(1);
}//ALOCA IMOVEL


void alocarLocatario(st_locatario **p, int t){
	if((*p = (st_locatario*) realloc(*p, t * sizeof(st_locatario))) == NULL)
		exit(1);
}//ALOCA LOCATÁRIO


void alocarInt(int **p, int t){
	if((*p = (int*) realloc(*p, t * sizeof(int))) == NULL){
		printf("\n\nErro ao alocar do tipo 'INT'\n\n");
		exit(1);
	}
}//ALOCA INT


/////////////////////////////////////////////////////funcoes cadastro
void cadastrarProp(st_prop *p, int id)//opcao 1
{
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
	
	mostraProp(p, 0);
	
	system("pause");
	
	salvarProp(p);
}//Realiza o Cadastro do Proprietário


int cadastrarImovel(st_imovel *p, int id, st_prop *proprietario, int qtde_prop)
{
	int num_reg, qtde_livres = 0, i_casas, i;
	FILE *fptr = NULL;
	char status, op;
	
	system("cls");
	
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
	
	p->status.locacao.reg_loc = id-999;
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
	
	printf("CEP: ");
	gets(p->end_imovel.CEP);
	fflush(stdin); //receber cep do imovel
	
	printf("\n\n\tLista de Proprietarios:");
	
	//Mostra os ids  e proprietários disponíveis:
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietario, sizeof(st_prop), qtde_prop, fptr);
		fclose(fptr);
		
		for(i=0; i<qtde_prop; i++)	
			if((proprietario + i)->qtdCasas < 5)
			{	
				qtde_livres +=1;				
				printf("\nId: %i\tNome: %s", (proprietario + i)->id, (proprietario + i)->nome);
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
		
		//printf("\nNum_reg: %i", num_reg);
		//printf("Indice: %i", num_reg);
		
		if(num_reg != -1)
		{
			if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Proprietario\n\n");
			else
			{	
				rewind(fptr);
				fread(proprietario, sizeof(st_prop), qtde_prop, fptr);
				fclose(fptr);
									
				i_casas = (proprietario + num_reg)->qtdCasas;
				//printf("\n\ni_casas: %i", i_casas);
				((proprietario + num_reg)->casa + i_casas)->num_casa = p->id;
				((proprietario + num_reg)->casa + i_casas)->status_casa = 'L';
				(proprietario + num_reg)->qtdCasas += 1;

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


int cadastrarLocatario(st_locatario *p, int id, st_imovel *imovel, int qtde_imov, st_prop *proprietario, int qtde_prop)
{
	int i, qtde_livres = 0, num_regProp, num_regImov, id_Imov, i_casas, conf = 0;
	char op;
	FILE *fptr = NULL;
	
	system("cls");
	
	p->id = id;
	fflush(stdin);
	printf("\n\tCadastro Locatario:"
		   "\nID: %i", p->id);
	
	printf("\nDigite o nome: ");
	gets(p->nome);
	fflush(stdin); // receber nome do locatário
	
	do
	{
		printf("\nDigite o CPF: ");
		gets(p->CPF);
		fflush(stdin); // receber cpf do locatário
		
		//conf = verifCpf(p, p->CPF);
		
		//if(conf == 1)
			//printf("\nCpf ja existente, digite novamente!");
		
	}while(conf == 1);
	
	printf("\nCelular: ");
	gets(p->end_loc.celular);
	fflush(stdin); // receber celular do locatário
	
	printf("\nTelefone: ");
	gets(p->end_loc.telefone);
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
	gets(p->end_loc.cep);
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
		fread(imovel, sizeof(st_imovel), qtde_imov, fptr);
		fclose(fptr);
		
		for(i=0; i<qtde_imov; i++)
			if((imovel + i)->status.sigla == 'L')
			{	
				qtde_livres += 1;				
				printf("\nId: %i\tLogradouro: %s", (imovel + i)->id, (imovel + i)->end_imovel.logradouro);
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
		
		
		//printf("\nIndice Im: %i\tIndice Prop: %i", num_regImov, num_regProp);
		
		if(num_regImov != -1 && num_regProp != -1)
		{
			fptr = NULL;
			
			//Altera o Imóvel:
			if( (fptr = fopen("imovel.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Imovel\n\n");
			else
			{
				rewind(fptr);
				fread(imovel, sizeof(st_imovel), qtde_imov, fptr);
				fclose(fptr);
				
				(imovel + num_regImov)->status.locacao.sigla = 'A';				
				(imovel + num_regImov)->status.locacao.reg_loc = p->id;				
				(imovel + num_regImov)->status.sigla = 'A';
				
				gravaImo(imovel, qtde_imov);
			}
			
			//Altera o Proprietário:
			if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
				printf("\n\nErro ao abrir o Proprietario\n\n");
			else
			{
				rewind(fptr);
				fread(proprietario, sizeof(st_prop), qtde_prop, fptr);
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
	return 1;
}


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


int verifLoc()
{
	FILE *fptr = NULL;
	long int Tloc = 0;
	
	if((fptr = fopen("locatario.bin", "rb")) == NULL)
		return Tloc;
	else
	{
		fseek(fptr, 0, 2);
		Tloc = ftell(fptr) / sizeof(st_locatario);	
		fclose(fptr);
		
		return Tloc;
	}
}//Verifica se tem o arquivo 'locatario.bin' e retorna a quantidade de locatarios nele


int verifCpf(st_locatario *p, char cpf[15])
{
	FILE *fptr = NULL;
	int i = 0;
	
	if((fptr = fopen("locatario.bin", "rb")) == NULL)
		return 0;
	else
	{
		while(!feof(p))
		{
			fseek(fptr, i * sizeof(st_locatario), 0);
			fread(p, sizeof(st_locatario), 1, fptr);
			
			if(strcmp(p, cpf) == 0)
			{
				fclose(fptr);
				return 1;
			}
			i++;
			p++;	
		}
		fclose(fptr);
	}
}//buscar cpf


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


void gravaImo(st_imovel *dados, int qreg)
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("imovel.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados,sizeof(st_imovel), qreg, fptr);	
		fclose(fptr);
	}
		
}//Salva vários Imóveis sobrepondo o que tiver


void salvarLoc(st_locatario *dados)
{
	FILE *fptr = NULL;
	
	if((fptr = fopen("locatario.bin", "ab+")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(st_locatario), 1, fptr);
		fclose(fptr);
	}
}//Salva um Locatário


void gravaLoc(st_locatario *dados, int qreg)
{
	FILE *fptr = NULL;
	
	if( (fptr = fopen("locatario.bin","wb")) == NULL)
		printf("\nSem armazenamento disponivel!");
	else
	{
		fwrite(dados, sizeof(st_locatario), qreg, fptr);
		fclose(fptr);	
	}		
}//Salva vários Locatários sobrepondo o que tiver


// Funções de Leitura:
void LerProp(st_prop *p, int t)//opcao 3
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
			fread(p, sizeof(st_prop), t, fptr);
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
						if(strcmp(cpf, p->cpf) == 0)
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

void LerImo(st_imovel *p, int t)//opcao 4
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
			fread(p, sizeof(st_imovel), t, fptr);
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
					
					else if(op2 == 2 && p->status.locacao.sigla == 'A')
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
						if(strcmp(bairro, p->end_imovel.bairro) == 0 )
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


void LerLoc(st_locatario *p, int qreg)//opcao 5
{
	int i, j, op, op1 = 1;
	char cpf[15];
	
	FILE *fptr = NULL;
				
	if((fptr = fopen("locatario.bin","rb")) == NULL)
		printf("\nArquivo inexistente!");
	else
	{				
		rewind(fptr);
		fread(p, sizeof(st_locatario), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			mostraLocatario(p + i);
	}	
	printf("\n");
	system("pause");
}//Mostra os Locatários


void relatorio(st_locatario *p, int qtde_loc)//opcao 7
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
		fread(p, sizeof(st_locatario), qtde_loc, fptr);
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


void terminoContrato(st_locatario *loc, int qtde_loc, st_imovel *imovel, int qtde_imov, st_prop *prop, int qtde_prop)//opcao 8
{
	int i, j, multa, num_regImov, num_regProp, i_casas;
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
			fread(loc, sizeof(st_locatario), qtde_loc, fptr);
			fclose(fptr);
			
			for(i = 0; i < qtde_loc; i++)
				if(strcmp((loc + i)->CPF, cpf) == 0)
				{
					mostraLocatario(loc + i);
					break;
				}
					
			printf("\nDeseja confirmar o cpf? <S/N>: ");
			scanf("%c", &op);
			
			op = toupper(op);
			
			if(op == 'S')
			{
				printf("\n\nDigite a data atual DD/MM/YYYY: ");
				fflush(stdin);
				gets(termino);
				fflush(stdin);
				
				multa = calcularMulta((loc + i)->termino, termino);
				
				num_regImov = buscaImovelAlugado(imovel, qtde_imov, (loc + i)->id);						//Verificar se é possível atrelar o Locatario ao Imóvel
				num_regProp = buscaProprietarioPorImovelAlugado(prop, qtde_prop, (loc + i)->id);		//Faz a busca de um proprietário através do Id/Número de registro de um imóvel				
				i_casas = buscaCasaAlugado(prop, qtde_prop, num_regProp, (imovel + num_regImov)->id);			//Faz a busca da casa do proprietário através do Id do Imóvel
				
				printf("\nNum imovel: %i", num_regImov);
				printf("\nNum prop: %i", num_regProp);
				printf("\ni_casas: %i\n", i_casas);
				
				//os valores abaixo nao estao alterando
				(imovel + num_regImov)->status.sigla = 'L';
				(imovel + num_regImov)->status.locacao.sigla = 'L';
				(imovel + num_regImov)->status.locacao.reg_loc = '\0';
				( (prop + num_regProp)->casa + i_casas)->status_casa = 'L';
				( (prop + num_regProp)->casa + i_casas)->num_casa = '\0';
				
				/*
				printf("\ncpf: %s\n", (loc + i)->CPF);
				
				for(j = 0; j < 15; j++)
					strcpy(( (loc + i)->CPF + j), '\0');
					
				((loc + i)->CPF + j) = '@';
				*/
				if(multa == 1)
					printf("\nMulta no valor de: R$%.2f", (imovel + num_regImov)->valor);
					
			}
		}
	}while(op == 'N');
	
	system("pause");
}


int calcularMulta(char contrato[9], char atual[9])
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
	
	printf("\ndata contrato: %i/%i/%i", dia, mes, ano);
	printf("\ndata atual: %i/%i/%i\n", dia1, mes1, ano1);

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


void limparDados()
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
int buscaProprietario(st_prop *proprietarios, int qreg, int num_reg)
{
	int i;
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(st_prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)
			if( (proprietarios + i)->id == num_reg)
				return i;
	}
	return -1;	//NÃO ENCOTROU O PROPRIETÁRIO
}//Busca Proprietário através do Id


int buscaImovel(st_imovel *imoveis, int qreg, int num_reg)
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("imovel.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(imoveis, sizeof(st_imovel), qreg, fptr);
		fclose(fptr);
			
		for(i = 0; i < qreg; i++)
			if((imoveis + i)->id == num_reg && (imoveis + i)->status.sigla == 'L')	
				return i;	
	}
	return -1;	//NÃO ENCOTROU O IMÓVEL
}//Busca Imóvel através do Id


int buscaImovelAlugado(st_imovel *imoveis, int qreg, int num_reg)
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("imovel.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(imoveis, sizeof(st_imovel), qreg, fptr);
		fclose(fptr);
			
		for(i = 0; i < qreg; i++)
			if((imoveis + i)->id == num_reg && (imoveis + i)->status.sigla == 'A')	
				return i;	
	}
	return -1;	//NÃO ENCOTROU O IMÓVEL
}//Busca Imóvel através do Id


int buscaProprietarioPorImovel(st_prop *proprietarios, int qreg, int id_casa)
{
	int i, j;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(st_prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			for(j = 0; j < 5; j++)
				if( ((proprietarios + i)->casa + j)->num_casa == id_casa && ((proprietarios + i)->casa + j)->status_casa == 'L') 
					return i;
	}
	return -1;  //NÃO ENCOTROU O PROPRIETÁRIO
}//Busca o índice do proprietário em relação ao id da casa


int buscaProprietarioPorImovelAlugado(st_prop *proprietarios, int qreg, int id_casa)
{
	int i, j;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("\n\nErro ao abrir o Proprietario\n\n");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(st_prop), qreg, fptr);
		fclose(fptr);
		
		for(i = 0; i < qreg; i++)	
			for(j = 0; j < 5; j++)
				if( ((proprietarios + i)->casa + j)->num_casa == id_casa && ((proprietarios + i)->casa + j)->status_casa == 'A') 
					return i;
	}
	return -1;  //NÃO ENCOTROU O PROPRIETÁRIO
}//Busca o índice do proprietário em relação ao id da casa


int buscaCasa(st_prop *proprietarios, int qreg, int i_prop, int id_casa)
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(st_prop), qreg, fptr);
		fclose(fptr);

		for(i = 0; i < 5; i++)
			if( ((proprietarios + i_prop)->casa + i)->num_casa == id_casa && ((proprietarios + i_prop)->casa + i)->status_casa == 'L')
			    return i;
	}	
	return -1;	//NÃO ENCOTROU A CASA
}//Busca o índice da casa em relação ao proprietário


int buscaCasaAlugado(st_prop *proprietarios, int qreg, int i_prop, int id_casa)
{
	int i;	
	FILE *fptr = NULL;		
	
	if( (fptr = fopen("proprietario.bin", "rb")) == NULL)
		printf("Erro ao abrir o arquivo");
	else
	{
		rewind(fptr);
		fread(proprietarios, sizeof(st_prop), qreg, fptr);
		fclose(fptr);

		for(i = 0; i < 5; i++)
			if( ((proprietarios + i_prop)->casa + i)->num_casa == id_casa && ((proprietarios + i_prop)->casa + i)->status_casa == 'A')
			    return i;
	}	
	return -1;	//NÃO ENCOTROU A CASA
}//Busca o índice da casa em relação ao proprietário


//Funções de Mostrar:
void mostraProp(st_prop *p, int qtd_Casas)
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
		printf("\nNumero casa: %i", (p->casa + j)->num_casa );
		printf("\nStatus: %c\n", (p->casa + j)->status_casa );
	}
	printf("\n");
}


void mostraImovel(st_imovel *p)
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\Imovel: "
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
			"\nCep: %s\n\n", p->end_imovel.logradouro, p->end_imovel.bairro, p->end_imovel.cidade, p->end_imovel.CEP);	
}//Mostra os dados de um imóvel


void mostraLocatario(st_locatario *p)
{
	printf("\n\n\n||--------------------------------------------------------------------||\n");
	printf("\n\Locatario: "
			"\nID: %i"
			"\nNome: %s"
			"\nCpf: %s"
			"\nID do Imovel: %i"
			"\nDia Vencimento: %i"
			"\nData de Inicio: %s"
			"\nData de Termino: %s\n", p->id, p->nome, p->CPF, p->reg_imov, p->dia_venc, p->inicio, p->termino);
			
	printf("\n\n\tEndereco do locatario: "
			"\nLogradouro: %s"
			"\nBairro: %s"
			"\nCidade: %s"
			"\nEstado: %s"
			"\nCep: %s\n\n", p->end_loc.logradouro, p->end_loc.bairro, p->end_loc.cidade, p->end_loc.estado, p->end_loc.cep);
}//Mostra os dados de um imóvel

