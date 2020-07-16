#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <dirent.h>

	//area de vendas
	int Fpagamento, cartao, senha, i = 0, n = 1;
	float total=0, troco, totalVendas=0;
	char caminho[30];
	
	//area de login
	char dt[20], dc[20], dia[20], mes[10], ano[10];
	int pedido=0;
	
	//funcoes fopen
	void menu();
	void salvarPedidoTxt();
	void salvarprodutoTxt();
	void salvarprecoTxt();
	void salvarTotalTxt();
	void salvarCodigoTxt();
	void LerTotalTxt();
	void LerCodigoTxt();
	
	//funcoes opcoes
	void vendas();
	void repetir();
	void totalvendas();
	void SalvarSenha();
		
//--------------------------------------------------------------------------------------------------------
	void login()
	{	
		int  usuario, usuario_, senha1, senha_;
		
		system("cls");
		
		//ler senha
		FILE* senha;
		senha = fopen("DADOS/Senha.txt", "r");
		fclose(senha);
		
		if (senha == NULL)
		{
			printf("\n\tPrograma de vendas\n\n");
			printf("\tSeja bem vindo! \nSeu login e senha sao pre-definidos inicialmente.\n");
				   
			FILE* senha;
			senha = fopen("DADOS/Senha.txt", "w");
			fprintf(senha,"123 123");
			fclose(senha);
	
			printf("\nLogin: 123\nSenha: 123\n\n");
			printf("Pressione ENTER para continuar.");
			
			getch();
			system("cls");
		}
		
		printf("\n\tPrograma de vendas\n\n");
		do
		{
			
			printf("Login: ");
		    scanf("%i", &usuario);
			    
			printf("Senha: ");
			scanf("%i", &senha1);
			
			FILE* senhaf;
			senhaf = fopen("DADOS/Senha.txt", "r");
			
			fscanf(senhaf,"%i %i", &usuario_, &senha_);
			fclose(senhaf);
				
				
			if(usuario != usuario_ || senha1 != senha_)
				printf("Login ou senha incorretos, tente novamente!\n\n");
				
			else
				printf("Acesso permitido!");
				
		}while(usuario != usuario_ || senha1 != senha_);
				
		printf("\n\n");
		
		//escolher data---------------------------------------------------------------------------------------------
		
		printf("Digite a data de acesso.\n");
		
		printf("Dia: ");
		scanf("%s", &dia);
		
		printf("Mes: ");
		scanf("%s", &mes);
		
		printf("Ano: ");
		scanf("%s", &ano);
		
		strcat(dia, "_");	
		strcat(dia, mes);
		
		strcat(dia, "_");	
		strcat(dia, ano);
		
		sprintf(dt,"DADOS/%s", dia);
		sprintf(dc,"DADOS/%s", dia);
		
		strcat(dia,".txt");
		
		sprintf(caminho, "DADOS/%s", dia);
		
		FILE* dados;
		dados = fopen(caminho, "r");
		
		if(dados == NULL)
		{
			FILE* dados;
			dados = fopen(("DADOS/Readme.txt"), "w");
			fprintf(dados,"Programa executou com sucesso!\n"
						  "Nao alterer os dados das pastas .txt\n"
						  "Em caso de erro apague a pasta DADOS que o programa reinica automaticamente.\n\n"
						  "Versao 1.0\nCopyright: William A. G. Junior\n"
						  "Aluno FACENS\n"
						  "https://www.linkedin.com/in/william-alfred-gazal-j%C3%BAnior-369a76185/");
			fclose(dados);
		}
		else if(dados != NULL)
		{
			FILE* dados;
			dados = fopen(caminho, "r");
			fclose(dados);
			
			printf("\nAcesso com debitos anteriores.\nPressione ENTER para continuar.");
			sleep(1);
			getch();
		}

		strcat(dt,"_t.txt");
		strcat(dc,"_c.txt");
	
		system("cls");
		
		printf("\n\n\n\t\tSeja Bem Vindo!");
		sleep(2);
		
		LerTotalTxt();
		LerCodigoTxt();
		
		system("cls");
		menu();
	}
/*----------------------------------------------------------------------------------------------------*/
	//menu inicial
	void menu()
	{	
		int op;			
		printf("	Menu\n\n"
				"1. Vendas\n"
				"2. Pedidos\n"
				"3. Total do dia\n"
				"4. Alterar Senha\n"
				"5. Finalizar programa\n"
				"Opcao: ");
		scanf("%i", &op);
		system("cls");
		
		switch(op)
		{
			case 1: vendas();
				break;
			case 2:repetir();
				break;	
			case 3: totalvendas();
				break;
			case 4: SalvarSenha();
				break;	
		}	
	}		

/*----------------------------------------------------------------------------------------------------*/
	struct cliente
	{
		char pedido[100];
		char produto[100];
		float preco;
	}clie;
	
/*----------------------------------------------------------------------------------------------------*/
	void salvarPedidoTxt()
	{
		FILE* salvar;
		salvar = fopen(caminho,"a");
		fprintf(salvar,"----------------------------------\n%i.      %s", n, clie.pedido);
		fclose(salvar);
		
		n++;
	}
/*----------------------------------------------------------------------------------------------------*/	
	void salvarprodutoTxt()
	{
		FILE* salvar;
		salvar = fopen(caminho,"a");
		fprintf(salvar,"\t%s\n",clie.produto);
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/	
	void salvarprecoTxt()
	{
		FILE* salvar;
		salvar = fopen(caminho,"a");
		fprintf(salvar,"\tTotal: %.2f\n\n",total);
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/
	void salvarTotalTxt()
	{
		FILE* salvar;
		salvar = fopen(dt,"w");
		fprintf(salvar,"%f",totalVendas);
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/
	void salvarCodigoTxt()
	{
		FILE* salvar;
		salvar = fopen(dc,"w");
		fprintf(salvar,"%i",n);
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/
	void LerTotalTxt()
	{
		FILE* salvar;
		salvar = fopen(dt,"r");
		fscanf(salvar,"%f",&totalVendas);
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/
	void LerCodigoTxt()
	{
		FILE* salvar;
		salvar = fopen(dc,"r");
		fscanf(salvar,"%i",&n);
	}
/*----------------------------------------------------------------------------------------------------*/
	void lerTxt()
	{
		FILE* salvar;
		salvar = fopen(caminho,"r");
		
		char texto[1000];
		
		while (fgets(texto,1000,salvar) != NULL)
		{
			printf("%s",texto);
		}
		fclose(salvar);
	}
/*----------------------------------------------------------------------------------------------------*/	
	//opção 1. vendas
	void vendas()
	{
		printf("	Vendas\n");
		printf("Nome do Pedido: ");
		
		fflush(stdin);
		fgets(clie.pedido,100, stdin);
		
		printf("%s",clie.pedido);
		
		system("cls");
		salvarPedidoTxt();
		
		printf("	Vendas\n");
		printf("Pedido: %s\n", clie.pedido);

		do
		{
			printf("\nNome do Produto: ");
						
			fflush(stdin);
			fgets(clie.produto,100, stdin);	
			
			salvarprodutoTxt();			
			
			printf("Preco: R$");
			scanf("%f", &clie.preco);
						
			printf("\nEnter para continuar.\nEsc para finalizar o pedido.\n");
						
			total += clie.preco;
						
		}while(getch() !=27);
					
		system("cls");
		
		printf("	Vendas\n");
		printf("\nPreco total: %.2f",total);
		
		totalVendas += total;
		i++;
		
		salvarprecoTxt();
		salvarTotalTxt();
		salvarCodigoTxt();
		
		//do
		//{
			printf("\n\n(1) Dinheiro\n"/*(2) Cartao\n\nForma de pagamento:*/ );		
		//	scanf("%i", &Fpagamento);
		//}while(Fpagamento < 1 || Fpagamento > 2);
			
		//if(Fpagamento == 1)
		//{
			printf("\nTotal em dinheiro: ");
			scanf("%f",&troco);	
							
			if(total <= troco)
			{
				troco-=total;
				printf("Troco: %.2f",troco);					
			}
			
			else if(total > troco)
			{
				total -= troco;
				printf("\n\nEsta faltando %.2f reais\n\n",total);
			}
		//}
		/*else if(Fpagamento == 2)
		{	
			do
			{
				printf("\n(1) Debito\n(2) Credito\n\nDigite: ");
				scanf("%i", &cartao);	
			
				if(cartao < 1 || cartao > 2)
					system("cls");
				
			}while(cartao < 1 || cartao > 2);
			
			if(cartao == 1 || cartao == 2)
			{
				do
				{
					printf("\nInsira a senha do cartao: ");
					scanf("%i", &senha);					
				}while(cartao < 1 || cartao > 2);
						
				printf("\nTransferencia Concluida.\n");
			}
		}*/
		printf("\n\nPressione ENTER para voltar ao menu.");
		getch();
		
		system("cls");
		
		total=0;
		return menu();
	}
/*----------------------------------------------------------------------------------------------------*/
	//opção 2. pedidos
	void repetir()	
	{	
		printf("\tPedidos\n\n");
		lerTxt();
		
		printf("\nPressione ENTER para voltar ao menu.");   
		getch(); 
		system("cls");	
		
		return menu();
	}	
/*----------------------------------------------------------------------------------------------------*/	
	//opcao 3. total vendas	
	void totalvendas()
	{			
		printf("\tTotal de vendas do dia\n\nTotal: %.2f\n\n",totalVendas);
		
		getch();
		system("cls");
		return menu();
	}	 
/*----------------------------------------------------------------------------------------------------*/	
	//4. alterar senha
	void SalvarSenha()
	{
		int a, b;
		FILE* salvar;
		salvar= fopen("DADOS//Senha.txt","w+");
		
		printf("Novo Login: ");
		scanf("%i", &a);
	
		printf("Nova senha: ");
		scanf("%i", &b);
		
		fprintf(salvar,"%i %i",a,b);
		fclose(salvar);
		
		system("cls");
		return menu();
	}	
/*----------------------------------------------------------------------------------------------------*/
	//programa
	int main() 
	{		
		DIR *dir;
		
		dir = opendir("DADOS");
		
		if(dir == NULL)
			system("mkdir DADOS");
		
		login();

		return 0;
	}
