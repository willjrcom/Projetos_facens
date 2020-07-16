//Danielle Zeferino RA:190275
//Emanuella Lopez Ferreira RA:190176

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct endereco{  
	char  logradouro[80];  
	char  bairro[20];  
	char  CEP[10];  
	char  cidade[20];  
	char  estado[20];  
	char  fone[15];  
	char  cel[15];  
	char  email[30]; 
}endereco; //Dados do usuario

typedef struct info_casa{  
	int  num_casa;  
	char  status_casa; 
}info_casa; 
 
typedef struct prop{  
	int   reg_prop;  
	char   nome[80];  
	char   CPF[15];  
 	endereco end_prop;  
	int   qtde_casa; 
	info_casa casa[5];  
}prop;

typedef struct adress{  
	char  logradouro[80];  
	char  bairro[20];  
	char  CEP[10];  
	char  cidade[20]; 
}adress; 
 
typedef struct info_loc{  
	char  sigla;  
	int  reg_loc; 
}info_loc; 

union dados{  
	char  sigla; 
	info_loc loc; 
}; 
 
typedef struct imovel{  
	int   reg_imov;  
	struct adress end_imov;  
	float   area;  
	int   quartos;  
	float   valor; 
	union dados  status; 
}imovel; 

typedef  struct locatario{  
int   reg_loc;   // gerado automaticamente  
char   nome_loc[80];  
char   CPF_loc[15];  
struct endereco end_loc;  
int   reg_imov_loc;  // registro imóvel – buscar no arq. Imóvel  
int   dia_venc;  
char   inicio[9];  
char   termino[9]; 
}locatario;


void aloca_prop(prop **p, int tam); //aloca espaço na memoria
void alocaImovel(imovel **p_imov, int tam); //aloca espaço na memoria
void aloca_loc(locatario **p_loc, int tam); //aloca espaço na memoria locatario
void cadastro_prop(prop *p);// cadastro de proprietario
void cadastro_imovel(imovel *p, prop *pp, int reg); //cadastrar o imovel a partir de um cpf existente
void cadastro_loc(locatario *p, prop *pp, imovel *pi); //cadastro de locatario
int verifica(); //verificar quantidade de proprietarios
int verificaimovel(); //verificar qtd de imoveis
int verifica_loc(); //verificar a qtd de locatarios
void grava_prop(prop *p, char *tipo, int qtd); // gravar no arquivo
void grava_imovel(imovel *p, char *tipo, int qtd); //gravar no arquivo
void grava_loc(locatario *p, char *tipo, int qtd); //gravar no arquivo locatario.bintro
void mostra(prop *p, int qtd, int num); //mostra o proprietario escolhido
void mostra_tudo(prop *p, int qtd); //mostra todos os proprietarios e seus imoveis
void mostra_imovel(imovel *p, int qtd, int num); //mostra o imovel desejado
void mostra_imovel_all(imovel *p, int qtd); //mostra todos os imoveis
void mostra_loc(locatario *p,int qtd, int num); //mostra o locatario desejado
void mostra_tudo_loc(locatario *p, int qtd); //mostra todos os locatarios
int busca_prop(prop *p, int qtd); //buscar proprietario pelo cpf
int busca_imovel(imovel *p, int qtd); //buscar imovel desejado
int busca_loc(locatario *p, int qtd); //buscar locatario
void altera_qtd_prop(prop *p, imovel *pi, int reg, int num); //funcao para aterar a quantidade de casas que o proprietario possui
void altera_loc(prop *p, imovel *pi, int reg_loc, int reg_imov);
int busca_imov_loc(imovel *p, int qtd, int reg_loc);

int main()
{
	prop *pp = NULL;
	imovel *pi = NULL;
	locatario *pl = NULL;
	int op, op2, op3, qtd, num;
	
	do{
		system("cls");
		printf("Menu\n1-Cadastro de proprietario\n2-Consulta de proprietario\n3-Cadastro de imovel\n4-Consulta de imovel\n5-Cadastro de locatario\n6-Consulta de locatario\n7-Sair\n");
		scanf("%i",&op);
		fflush(stdin);
		
		if(op > 7 || op < 1)
		{			
			printf("Opcao invalida!\nPor favor, escolha novamente!\n");
			system("PAUSE");	
		}		
			
		switch(op)
		{
			case 1: free(pp);
					pp = NULL;
					aloca_prop(&pp,1);//aloca espaço para proprietario
					cadastro_prop(pp);//cadastra propietario 
					break;
			
			case 2: 
					printf("[1] - Consulta parcial\n[2] - Consulta total\n");
					scanf("%i",&op2);
					fflush(stdin);
					
					if(op2 == 1)
					{						
						free(pp);
						qtd=verifica();
						pp = NULL;
						aloca_prop(&pp,qtd);
						num = busca_prop(pp,qtd);
						
							if(num == -1)
							{
								printf("CPF inexistente!");
							}
							else
							{								
								mostra(pp,qtd,num);
								system("PAUSE");
							}			
					}//if
					else if(op2 == 2)
					{
						free(pp);
						qtd=verifica();
						pp = NULL;
						aloca_prop(&pp,qtd);
						mostra_tudo(pp,qtd);
						system("PAUSE");
					}//else if
					else
					{
						printf("Opcao invalida!\n");
					}//else
					break;
					
			case 3:	free(pp);
					pp = NULL;
					qtd=verifica();
					aloca_prop(&pp,qtd);
					num = busca_prop(pp,qtd);
					
					free(pi);
					pi = NULL;
					alocaImovel(&pi,1);
					cadastro_imovel(pi,pp,num);
						
					break;
					
			case 4: printf("[1] - Consulta parcial\n[2] - Consulta total\n");
					scanf("%i",&op2);
					fflush(stdin);
					
					if(op2 == 1)
					{						
						free(pi);
						pi = NULL;
						qtd=verificaimovel();
						alocaImovel(&pi,qtd);
						num = busca_imovel(pi,qtd);
							if(num == -1)
							{
								printf("Imovel inexistente!");
							}
							else
							{	
								mostra_imovel(pi, qtd, num);	
							}	
						system("PAUSE");
					}//if
					else if(op2 == 2)
					{	
						free(pi);
						qtd=verificaimovel();
						pi = NULL;
						alocaImovel(&pi,qtd);
						mostra_imovel_all(pi, qtd);
						system("PAUSE");
					}//else if
					else
					{
						printf("Opcao invalida!\n");
					}//else	
					break;
					
			case 5: free(pp);
					pp = NULL;
					aloca_prop(&pp,1);
					
					free(pi);
					pi = NULL;
					alocaImovel(&pi,1);
					
					free(pl);
					pl = NULL;
					aloca_loc(&pl,1);//aloca espaço para locatario
					cadastro_loc(pl,pp,pi);//cadastra locatario
					
					break;	
					
			case 6: printf("[1] - Consulta parcial\n[2] - Consulta total\n");
					scanf("%i",&op3);
					fflush(stdin);
					
					if(op3 == 1)
					{						
						free(pl);
						pl = NULL;
						qtd=verifica_loc();
						aloca_loc(&pl,qtd);
						num = busca_loc(pl,qtd);
							if(num == -1)
							{
								printf("Locatario inexistente!");
							}
							else
							{	
								mostra_loc(pl, qtd, num);	
							}	
						system("PAUSE");
					}//if
					else if(op3 == 2)
					{	
						free(pl);
						qtd=verifica_loc();
						pl = NULL;
						aloca_loc(&pl,qtd);
						mostra_tudo_loc(pl, qtd);
						system("PAUSE");
					}//else if
					else
					{
						printf("Opcao invalida!\n");
					}//else	
					break;				
		}	
	}while(op!=7);
	
	getch();
	return 0;
}//fim da main

void aloca_prop(prop **p, int tam)//aloca proprietario
{
	if((*p=(prop*)realloc(*p,tam*sizeof(prop)))==NULL)
	{
		exit(1);
	}
}

void alocaImovel(imovel **p_imov, int tam)//aloca imovel
{
	if((*p_imov=(imovel*)realloc(*p_imov,tam*sizeof(imovel)))==NULL)
		exit(1);
}

void aloca_loc(locatario **p_loc, int tam) //aloca locatario
{
	if((*p_loc=(locatario*)realloc(*p_loc,tam*sizeof(locatario)))==NULL)
		exit(1);
}

void grava_prop(prop *p, char *tipo, int qtd)//grava proprietario 
{
	FILE *fptr=NULL; //ponteiro para arquivo
	
	if((fptr=fopen("proprietario.bin",tipo))==NULL) 
	{		
		printf("Erro ao abrir o arquivo!");	
	}
	else
	{		
		fwrite(p,sizeof(prop),qtd,fptr); //armazena no arquivo 
	}
  		
	fclose(fptr);
}

void grava_loc(locatario *p, char *tipo, int qtd)
{
	FILE *fptr=NULL;
	
	if((fptr=fopen("locatario.bin",tipo))==NULL)
	{
		printf("Erro ao abrir o arquivo!");
	}
	else
	{
		fwrite(p,sizeof(locatario),qtd,fptr);
	}
	
	fclose(fptr);
}

int  verifica() //verifica proprietario 
{
	long int cont=0;
	FILE *fptr=NULL; //ponteiro para arquivo
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	{
		return cont;	
	}
	else
	{		
		fseek(fptr,0,2);  
		cont = ftell(fptr)/sizeof(prop);
		fclose(fptr);
		return cont; 
    }
}

int verificaimovel()//função que verifica imovel
{
	long int cont=0;
	FILE *fptr=NULL; //ponteiro para arquivo
	if((fptr=fopen("imovel.bin","rb"))==NULL)
	{		
		return cont;	
	}//if
	
	else
	{
		fseek(fptr,0,2);  
		cont = ftell(fptr)/sizeof(imovel);
		fclose(fptr);
		return cont; 
	}//else
}

int verifica_loc()
{
	long int cont=0;
	FILE *fptr=NULL;
	
	if((fptr=fopen("locatario.bin","rb"))==NULL)
	{
		return cont;
	}
	else
	{
		fseek(fptr,0,2);
		cont = ftell(fptr)/sizeof(locatario);
		fclose(fptr);
		return cont;
	}
}
 
void cadastro_prop(prop *p)//cadastro do proprietario
{
	int qtd;
	
	qtd = verifica();
	p->reg_prop = qtd + 1;
	
	printf("Registro: %i\n",p->reg_prop);
	printf("Nome do proprietario:\n");
	gets(p->nome);
	fflush(stdin);
	
	printf("Digite o CPF:\n");
	gets(p->CPF);
	fflush(stdin);
	
	printf("\nEndereco\n");
	printf("Digite o logradouro:\n");
	gets(p->end_prop.logradouro);
	fflush(stdin);
	
	printf("Digite o bairro:\n");
	gets(p->end_prop.bairro);
	fflush(stdin);
	
	printf("Digite o CEP:\n");
	gets(p->end_prop.CEP);
	fflush(stdin);
	
	printf("Digite a cidade:\n");
	gets(p->end_prop.cidade);
	fflush(stdin);
	
	printf("Digite o estado:\n");
	gets(p->end_prop.estado);
	fflush(stdin);
	
	printf("Digite o numero de telefone:\n");
	gets(p->end_prop.fone);
	fflush(stdin);
	
	printf("Digite o numero de celular:\n");
	gets(p->end_prop.cel);
	fflush(stdin);
	
	printf("Digite o email:\n");
	gets(p->end_prop.email);
	fflush(stdin);
	
	p->qtde_casa = 0;
	
	grava_prop(p,"ab",1);	
}//cadastro  

void mostra(prop *p, int qtd, int num)//mostra dados do proprietario
{
	int i,j;
	FILE *fptr=NULL;//ponteiro para arquivo
	
	system("cls");//limpa tela
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	else
	{
	  fread(p,sizeof(prop),qtd,fptr);	
	  fclose(fptr);
	  printf("\nNome\nCPF\tLogradouro\tBairro\tCEP\tCidade\tEstado\tFone\tCelular\tEmail\tQtd. de casas\t\n");
	  printf("\n\tNome:%s\n\t CPF:%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%i\t\n",(p+num)->nome,(p+num)->CPF,(p+num)->end_prop.logradouro,(p+num)->end_prop.bairro,(p+num)->end_prop.CEP,(p+num)->end_prop.cidade,(p+num)->end_prop.estado,(p+num)->end_prop.fone,(p+num)->end_prop.cel,(p+num)->end_prop.email,(p+num)->qtde_casa);
	  
	  for(j=0;j<(p+num)->qtde_casa;j++)
		{
		  	printf("\n\tCasa: %i\n\tStatus: %c\n",(p+num)->casa[j].num_casa,(p+num)->casa[j].status_casa);
		}
	}//else
	  
	printf("\n\n\n");
}//mostra

void mostra_loc(locatario *p,int qtd, int num)
{
	int i,j;
	FILE *fptr=NULL;//ponteiro para arquivo
	
	system("cls");//limpa tela
	
	if((fptr=fopen("locatario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	else
	{
	  fread(p,sizeof(locatario),qtd,fptr);	
	  fclose(fptr);
	  
	  printf("\nRegistro\tNome\tCPF\tLogradouro\tBairro\tCEP\tCidade\tEstado\tFone\tCelular\tEmail\tRegistro do imovel\n");
	  printf("\n%i\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%i\n",(p+num)->reg_loc,(p+num)->nome_loc,(p+num)->CPF_loc,(p+num)->end_loc.logradouro,(p+num)->end_loc.bairro,(p+num)->end_loc.CEP,(p+num)->end_loc.cidade,(p+num)->end_loc.estado,(p+num)->end_loc.fone,(p+num)->end_loc.cel,(p+num)->end_loc.email,(p+num)->reg_imov_loc);
	  
	}//else

	printf("\n\n\n");
}
void mostra_tudo(prop *p, int qtd)
{
	int i, j;
	FILE *fptr=NULL;//ponteiro para arquivo
	
	system("cls");
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	else
	{
	  	fread(p,sizeof(prop),qtd,fptr);	
  		fclose(fptr);
  		
	  for(i=0;i<qtd;i++)
	  {
	  	
	  	printf("\n\n\tNome:%s\n\tCPF:%s\n\tLogradouro:%s\n\tBairro:%s\n\tCEP:%s\n\tCidade:%s\n\tEstado:%s\n\tFone:%s\n\tCelular:%s\n\tEmail:%s\n\tQuantidade de casas:%i\n\t",(p+i)->nome,(p+i)->CPF,(p+i)->end_prop.logradouro,(p+i)->end_prop.bairro,(p+i)->end_prop.CEP,(p+i)->end_prop.cidade,(p+i)->end_prop.estado,(p+i)->end_prop.fone,(p+i)->end_prop.cel,(p+i)->end_prop.email,(p+i)->qtde_casa);
	  	
		  	for(j=0;j<(p+i)->qtde_casa;j++)
		  	{
		  		printf("\n\tCasa: %i\n\tStatus: %c\n",(p+i)->casa[j].num_casa,(p+i)->casa[j].status_casa);  //mostra a quantidade de casas que o proprietario possui
		    }//for
	  }//for
	}//else
	  
	printf("\n\n\n");
} 
void mostra_tudo_loc(locatario *p, int qtd)
{
	int i, j;
	FILE *fptr=NULL;//ponteiro para arquivo
	
	system("cls");
	
	if((fptr=fopen("locatario.bin","rb"))==NULL)
		printf("Arquivo inexistente!");
	else
	{
	  	fread(p,sizeof(locatario),qtd,fptr);	
  		fclose(fptr);
  		
	  for(i=0;i<qtd;i++)
	  {
	  	
			printf("\n\n\tNome:%s\n\tCPF:%s\n\tLogradouro:%s\n\tBairro:%s\n\tCEP:%s\n\tCidade:%s\n\tEstado:%s\n\tFone:%s\n\tCelular:%s\n\tEmail:%s\n\tRegistro do imovel: %i\n",(p+i)->nome_loc,(p+i)->CPF_loc,(p+i)->end_loc.logradouro,(p+i)->end_loc.bairro,(p+i)->end_loc.CEP,(p+i)->end_loc.cidade,(p+i)->end_loc.estado,(p+i)->end_loc.fone,(p+i)->end_loc.cel,(p+i)->end_loc.email, (p+i)->reg_imov_loc);
	 	  	
	  }//for
	}//else
	  
	printf("\n\n\n");
}

int busca_prop(prop *p, int qtd)//Função para a busca do proprietario com o CPF
{
	FILE *fptr=NULL;//ponteiro para arquivo
	char aux[20];
	int i;
	
	printf("Digite o CPF do proprietário a ser consultado:\n");
	gets(aux);
	fflush(stdin);
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	{
		printf("Arquivo inexistente!");	
	}//if
	else
	{		
		for(i=0;i<qtd;i++)
		{
			fseek(fptr, i * sizeof(prop), 0); //posiciona a partir do início em cada elemento
			fread(p, sizeof(prop), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
			
			if(strcmp(aux,p->CPF)==0)
			{	
				return i;
			}//if
		}//for
	}//else
		
	fclose(fptr);
	return -1;
}

int busca_loc(locatario *p, int qtd)
{
	FILE *fptr=NULL;//ponteiro para arquivo
	char aux[20];
	int i;
	
	printf("Digite o CPF do locatario a ser consultado:\n");
	gets(aux);
	fflush(stdin);
	
	if((fptr=fopen("locatario.bin","rb"))==NULL)
	{
		printf("Arquivo inexistente!");	
	}//if
	else
	{		
		for(i=0;i<qtd;i++)
		{
			fseek(fptr, i * sizeof(locatario), 0); //posiciona a partir do início em cada elemento
			fread(p, sizeof(locatario), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
			
			if(strcmp(aux,p->CPF_loc)==0)
			{	
				return i;
			}//if
		}//for
	}//else
		
	fclose(fptr);
	return -1;
}

void cadastro_imovel(imovel *p, prop *pp, int reg)//Função para cadastro do Imovel
{
	int qtd; 
	
	qtd=verificaimovel();
	
	p->reg_imov = qtd + 1;

	printf("Endereco:\n");
	printf("Digite o logradouro:\n");
	gets(p->end_imov.logradouro);
	fflush(stdin);
	
	printf("Digite o bairro:\n");
	gets(p->end_imov.bairro);
	fflush(stdin);
	
	printf("Digite o CEP:\n");
	gets(p->end_imov.CEP);
	fflush(stdin);
	
	printf("Digite a cidade:\n");
	gets(p->end_imov.cidade);
	fflush(stdin);
	
	printf("Area util:\n");
	scanf("%f",&(p->area));
	fflush(stdin);
	
	printf("Digite a quantidade de quartos:\n");
	scanf("%i",&(p->quartos));
	fflush(stdin);

	printf("Digite o valor do aluguel:\n");
	scanf("%f",&(p->valor));
	fflush(stdin);	
	
	p->status.sigla = 'L'; //Salva o imovel como Livre 
	p->status.loc.sigla = 'L';
	p->status.loc.reg_loc = 0;
	
	grava_imovel(p,"ab",1);
	
	altera_qtd_prop(pp, p, reg, qtd);
	
}

void grava_imovel(imovel *p, char *tipo, int qtd)//Grava imovel na memória
{
	FILE *fptr=NULL;
	
	if((fptr=fopen("imovel.bin",tipo))==NULL)
	{
		printf("Erro ao abrir o arquivo!");
	}
	
	else
	{		
		fwrite(p,sizeof(imovel),qtd,fptr);
	}
  		
	fclose(fptr);
}

int busca_imovel(imovel *p, int qtd)//Função para a busca dos imoveis
{
	FILE *fptr=NULL;
	int i,op,auxquartos;
	char auximov[20];
	float aux;
	
	printf("\nOpcoes\n[1]-Area util\n[2]-Quantidade de quartos\n[3]-Bairro dos imoveis que deseja alugar\n");
	scanf("%i",&op);
	fflush(stdin);
	
	if((fptr=fopen("imovel.bin","rb"))==NULL)
	{
		printf("Arquivo inexistente!\n\n");	
	}//if
	
	else
	{	
		switch(op){	
			case 1:
				printf("\nDigite a area util: ");
				scanf("%f",&aux);
				fflush(stdin);
				
				for(i=0;i<qtd;i++)
				{
					fseek(fptr, i * sizeof(imovel), 0); //posiciona a partir do início em cada elemento
					fread(p, sizeof(imovel), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
						
					if(aux - (p->area) == 0)
					{
							return i;
					}//if
				}//for
				break;
			
			case 2:
				printf("\nDigite a quantidade de quartos: ");
				scanf("%i",&auxquartos);
				fflush(stdin);
				
				for(i=0;i<qtd;i++)
				{
					fseek(fptr, i * sizeof(imovel), 0); //posiciona a partir do início em cada elemento
					fread(p, sizeof(imovel), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
					
					if(auxquartos == p->quartos)
					{
						return i;
					}//if
				}//for
				break;
				
			case 3:
				printf("\nDigite o bairro dos imoveis que deseja alugar: ");
				gets(auximov);
				fflush(stdin);
				
				for(i=0;i<qtd;i++)
				{
					fseek(fptr, i * sizeof(imovel), 0); //posiciona a partir do início em cada elemento
					fread(p, sizeof(imovel), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
					
					printf("%s\n",p->end_imov.bairro); //mostra o que leu do arquivo
					if(strcmp(auximov,p->end_imov.bairro)==0)
					{
						return i;
					}//if
				}//for
				break;
		}//switch
	}//else
	
	fclose(fptr);
	return -1;
}

void mostra_imovel(imovel *p, int qtd, int num)//funçõo para mostrar parcialmente o imovel
{
	int i;
	FILE *fptr=NULL;
	
	system("cls");
	
	if((fptr=fopen("imovel.bin","rb"))==NULL)
	{	
		printf("Arquivo inexistente!");		
	}//if
	else
	{		
	  fread(p,sizeof(imovel),qtd,fptr);	
	  fclose(fptr);
	  
	  printf("Registro: %i\nLogradouro: %s\nBairro: %s\nCEP: %s\nCidade: %s\nArea util: %.2f\nQuantidade de quartos: %i\nValor: RS %.2f\nStatus: %c - %i\n",(p+num)->reg_imov, (p+num)->end_imov.logradouro,(p+num)->end_imov.bairro,(p+num)->end_imov.CEP, (p+num)->end_imov.cidade, (p+num)->area, (p+num)->quartos,(p+num)->valor, (p+num)->status.sigla, (p+num)->status.loc.reg_loc);
	}//else
	printf("\n\n\n");
}

void mostra_imovel_all(imovel *p, int qtd)//Função que mostra todas as caracteristicas do imovel até o valor
{
	int i;
	FILE *fptr=NULL;
	
	system("cls");
	
	if((fptr=fopen("imovel.bin","rb"))==NULL)
	printf("Arquivo inexistente!");
	else
	{	
	fread(p,sizeof(imovel),qtd,fptr);	
  	fclose(fptr);
  		
	for(i=0;i<qtd;i++)
	{
	  	printf("Registro: %i\nLogradouro: %s\nBairro: %s\nCEP: %s\nCidade: %s\nArea util: %.2f\nQuantidade de quartos: %i\nValor: RS %.2f\nStatus: %c\n",(p+i)->reg_imov, (p+i)->end_imov.logradouro,(p+i)->end_imov.bairro,(p+i)->end_imov.CEP, (p+i)->end_imov.cidade, (p+i)->area, (p+i)->quartos, (p+i)->valor ,(p+i)->status.sigla);
	}//for
	}//else
	printf("\n\n\n");
}

void altera_qtd_prop(prop *p, imovel *pi, int reg, int num) //função que altera a quantidade inicial de imovel cadastrados no CPF para 1 e permite cadastrar ate 5 imoveis no mesmo CPF e por fim mostra a quantidade total 
{
	int qtd,i;
	FILE *fptr = NULL;
	
	qtd = verifica();
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	else
	{  
	  	fread(p,sizeof(prop),qtd,fptr);	
  		fclose(fptr);
	
		if((p+reg)->qtde_casa < 5)
		{			
			(p+reg)->qtde_casa +=1;
			i = (p+reg)->qtde_casa -1;
			(p+reg)->casa[i].num_casa = (pi+num)->reg_imov;		
			(p+reg)->casa[i].status_casa = 'L';
			
			grava_prop(p,"wb",qtd);	
		}//if
		else
		{
			printf("Esse proprietário já tem o numero maximo de imoveis!\n");
		}//else
	}//else
}

void cadastro_loc(locatario *p, prop *pp, imovel *pi)
{
	int qtd, num, qtdI;
	
	qtd = verifica_loc();
	qtdI = verificaimovel();
	
	p->reg_loc = qtd + 1;
	
	printf("Registro: %i\n",p->reg_loc);
	
	printf("Nome do locatario:\n");
	gets(p->nome_loc);
	fflush(stdin);
	
	printf("Digite o CPF:\n");
	gets(p->CPF_loc);
	fflush(stdin);
	
	printf("\nEndereco\n");
	printf("Digite o logradouro:\n");
	gets(p->end_loc.logradouro);
	fflush(stdin);
	
	printf("Digite o bairro:\n");
	gets(p->end_loc.bairro);
	fflush(stdin);
	
	printf("Digite o CEP:\n");
	gets(p->end_loc.CEP);
	fflush(stdin);
	
	printf("Digite a cidade:\n");
	gets(p->end_loc.cidade);
	fflush(stdin);
	
	printf("Digite o estado:\n");
	gets(p->end_loc.estado);
	fflush(stdin);
	
	printf("Digite o numero de telefone:\n");
	gets(p->end_loc.fone);
	fflush(stdin);
	
	printf("Digite o numero de celular:\n");
	gets(p->end_loc.cel);
	fflush(stdin);
	
	printf("Digite o email:\n");
	gets(p->end_loc.email);
	fflush(stdin);
	
	printf("Digite o dia de vencimento:\n");
	scanf("%i",&(p->dia_venc));
	fflush(stdin);
	
	printf("Inicio do contrato: dd/mm/aa\n");
	gets(p->inicio);
	fflush(stdin);
	
	printf("Fim do contrato: dd/mm/aa\n");
	gets(p->termino);
	fflush(stdin);
	
	do{
		mostra_imovel_all(pi,qtdI);
		printf("\n\nEscolha o imovel desejado:\n\n");
		num = busca_imov_loc(pi, qtdI,p->reg_loc);
	
		if(num == -1)
			printf("Imovel nao encontrado!");
		else if(num == -2)
			printf("Imovel indisponível!");
		else{
		
			p->reg_imov_loc = num+1;
			altera_loc(pp,pi,p->reg_loc,num+1);
		}
		system("pause");
	}while(num==-1 || num==-2);

	grava_loc(p,"ab",1);	
}

int busca_imov_loc(imovel *p, int qtd, int reg_loc){
	
	int op, i, j;
	FILE *fptr =NULL;
	
	printf("Digite o registro do imovel:\n");
	scanf("%i",&op);
	
	
	if((fptr=fopen("imovel.bin","rb"))==NULL)
	{
		printf("Arquivo inexistente!\n\n");	
	}//if
	
	else
	{	

		for(i=0;i<qtd;i++)
		{
			fseek(fptr, i * sizeof(imovel), 0); //posiciona a partir do início em cada elemento
			fread(p, sizeof(imovel), 1, fptr); //lê 1 de cada vez, pois só tenho 1 espaço alocado
			
			if((p+i)->reg_imov == op)
			{
				if((p+i)->status.sigla == 'A')
				{
					return -2;
					
				}else{
					
					rewind(fptr);
					fread(p,sizeof(imovel),qtd,fptr);	
  					fclose(fptr);	
					
					(p+i)->status.sigla = 'A';
					(p+i)->status.loc.sigla = 'A';
					(p+i)->status.loc.reg_loc = reg_loc;
					
					grava_imovel(p,"wb",qtd);
					return i;
				}
			}
		}
		
	}
	
	return -1;
}

void altera_loc(prop *p, imovel *pi, int reg_loc, int reg_imov)
{
	int qtd, i, j, prop, casa;
	FILE *fptr = NULL;
	
	qtd = verifica();
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	else
	{  

		for(i=0;i<qtd;i++){
			
			fseek(fptr, i * sizeof(imovel), 0); //posiciona a partir do início em cada elemento
			fread(p, sizeof(imovel), 1, fptr); 

			
			for(j=0;j<5;j++)
			{
				if((p+i)->casa[j].num_casa == reg_imov)
				{
					prop = i;
					casa = j;
					break;

				}
			}
		}
	}
	
	if((fptr=fopen("proprietario.bin","rb"))==NULL)
	  printf("Arquivo inexistente!");
	  
	else{
		rewind(fptr);
		fread(p,sizeof(prop),qtd,fptr);	
  		fclose(fptr);
  					
		(p+prop)->casa[casa].status_casa = 'A';
		grava_prop(p,"wb",qtd);	
	}
	

}

