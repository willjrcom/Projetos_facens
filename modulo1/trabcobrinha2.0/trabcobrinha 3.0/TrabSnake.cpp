//////////////////////////////////////////////////////////////////declaração das bibliotecas
#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<string.h>
//////////////////////////////////////////////////////////////////fim da declaração das bibliotecas

//////////////////////////////////////////////////////////////////função principal do jogo
int main(){

	int menu=2;

	do{//loop para tornar opcional o jogar novamente

//declaração das variaveis utilizadas
	int x, y, d=2, t=2, mx, my, velo=200, velo2=0, menu=2, pontos=0;
    char tecla='a';
//fim da ddeclaração das variaveis utilizadas
    
//criação dos vetores utilizados
    int cx[300]={10,20}, cy[300]={7,7}, integer;//declarando do tamanho maximo de 't' e da posição inicial da cobra
    char nome[50], string;
//fim da criação dos vetores utilizados
	
//declaração das funções do programa
	int fim_de_jogo();
	void menu_do_jogo(void);
	void caixa_do_menu(void);
	void imprime_parede(void);
	void mgotoxy(int x,int y);
	void imprime_cabecalho(void);
//fim da declaração das funções do programa

//declaração de ponteiros
//	FILE *nm, *pt;
//fim da decalração de ponteiros
	
	system("color f1"); //declaração da cor do jogo(background e fonte)
	
	menu_do_jogo();
	
	mgotoxy(32,16);
	scanf("%i",&menu);
	
	if(menu==1){
		system("cls");
		mgotoxy(10,6);
		printf("Obrigado por jogar");
		fim_de_jogo();
		getch();
		return 0;
		}
/*	if(menu==3){
		char string[100];
		while(fgets(string, 100, nm)!=NULL){
			printf("%s", string);
			system("PAUSE");
		}
	}*/
	
	system("cls");

//menu de nickname
	caixa_do_menu();
	
    mgotoxy(26, 13);
    printf("Digite suas iniciais:\n");
    
	mgotoxy(26, 15);
    fflush(stdin);//limpa o buffer do teclado para ler o nome
    gets(nome);//lê o nome
	/*
    nm= fopen("nomes.txt", "a");
    fprintf(nm,"%s\n", nome);//guarda o nome no arquivo
	fclose(nm);
	*/
    system("cls");
    
//fim do menu de nickname
	system("cls");
	mgotoxy(20,16);
	printf("DIGITE QUALQUER TECLA PARA COMECAR O JOGO");
	getch();
	system("cls");

	imprime_cabecalho();//chamada da função com o nome do jogo
    
	imprime_parede();//imprime as paredes do jogo
    
	
/*função que define a semente
do algoritmo do gerador de
números aleatórios para a
maçã aparecer aleatóriamente
e dentro do mapa.*/
	mx=(rand()%39)+5;
    my=(rand()%29)+3;
    
    while(tecla!='s'){//condição para o final de jogo
		
		while(tecla!='s'&&!(tecla=kbhit())){/*após a condição do S ele aguarda um clique e
		o 'kbhit()' tambem faz com que o programa esteja sempre aguardando um clique para
		movimentar a cobra sem precisar pedir uma entrada.*/
		for(x=t;x>0;x--){
			cx[x]=cx[x-1];
            cy[x]=cy[x-1];
        }
		//definição dos movimentos nos eixos
        if(d==0)cx[0]--;
        if(d==1)cy[0]--;
        if(d==2)cx[0]++;
        if(d==3)cy[0]++;
        mgotoxy(cx[t],cy[t]);
        printf(" ");//espaço é dado para apagar o rastro
        
		
		if(mx==cx[0]&&my==cy[0]){//se a cobra 'come' a maçã
		    t++;//a variavel 't' armazena o tamanho da cobrinha
            mx=(rand()%39)+5;//aparecimento aleatório da maçã
            my=(rand()%29)+3;//aparecimento aleatório da maçã
            velo-=4;
            pontos=pontos+1;
            velo2=velo2+5;
            
        }
        	mgotoxy(cx[0],cy[0]);//posição aonde irá aparecer a cobrinha
            printf("%c",254);//254
            mgotoxy(mx,my);
            printf("%c",35);//sinal do item comivel
            
            //informações de pontos e velocidade
			mgotoxy(50,8);
			printf("pontos: %i ", pontos);
			mgotoxy(50,10);
			printf("velocidade: %i bytes/s", velo2);
			
            Sleep(velo);//velocidade da cobra
            for(x=1;x<t;x++){
            	//acionamento da condição de morte por colisão com a própria cobra
               if(cx[0]==cx[x]&&cy[0]==cy[x]){
			   tecla='s';
				}
            }
            //acionamento da condição de morte por colisão com a parede 
            if(cy[0]==2||cy[0]==32||cx[0]==4||cx[0]==44){
			tecla='s';
			}
        
		}
        //ligação do movimento com as setas do teclado
        if(tecla != 's'){
		tecla=getch();}
		if(tecla == 'K'){
		d=0;}
		if(tecla == 'H'){
		d=1;}
		if(tecla == 'M'){
		d=2;}
		if(tecla == 'P'){
		d=3;}
		//acionamento da condição de morte 
		if(cy[0] == 2 || cy[0] == 32 || cx[0] == 4 || cx[0] == 44){
		tecla='s';
    	}
	
	}
		/*
    	pt= fopen("pontos.txt", "a");
    	fprintf(pt,"%d\n", pontos);//guarda os pontos no arquivo
		fclose(pt);
		*/
		mgotoxy(10,6);
		printf("Obrigado por jogar");
		fim_de_jogo();
		mgotoxy(10,8);
		printf("press key to save...");
		getch();
		system("cls");
		
		
	}while(menu=2);
	return 0;
}
//////////////////////////////////////////////////////////////////fim da função principal do jogo

//////////////////////////////////////////////////////////////////função mgotoxy()
void mgotoxy(int x,int y){
	COORD p={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),p);
}
//////////////////////////////////////////////////////////////////fim da função mgotoxy()

//////////////////////////////////////////////////////////////////Ranking
void ranking(void){
	

}
//////////////////////////////////////////////////////////////////fim do Ranking

//////////////////////////////////////////////////////////////////função imprime_cabecalho()
void imprime_cabecalho(void){
	int bar=219, x=0, y=0;
	
	for(x=7;x<=21;x++){//barra superior do nome do jogo
		mgotoxy(x,10);
  		printf("%c", bar);
	}
  	for(y=10;y>13;y++){//barra esquerda do nome do jogo
		mgotoxy(7,y);
  		printf("%c", bar);
	}
	for(x=7;x<=21;x++){//barra inferior do nome do jogo
		mgotoxy(x,12);
  		printf("%c", bar);
	}
	for(y=10;y>13;y++){//barra direita do nome do jogo
		mgotoxy(21,y);
		printf("%c", bar);
	}
	
	mgotoxy(8,11);
	printf("Snake Game ", bar, bar);//nome do jogo
	mgotoxy(8,14);
	printf("*Flavio Lucas*");//nome do programador do jogo
	
	return;
  
}
//////////////////////////////////////////////////////////////////fim da função imprime_cabecalho()

//////////////////////////////////////////////////////////////////função que imprime as lateráis dos menus
void caixa_do_menu(){
	
	int x, y;
	
	for(x=23;x<57;x++){//borda superior
	mgotoxy(x,10);
	printf("%c", 219);
	}
	for(y=10;y<19;y++){//borda da esquerda
	mgotoxy(23,y);
	printf("%c", 219);
	}
	
	for(x=23;x<58;x++){//borda inferior
	mgotoxy(x,19);
	printf("%c", 219);
	}
	for(y=10;y<19;y++){//borda da direita
	mgotoxy(57,y);
	printf("%c", 219);
	}
	
}
//////////////////////////////////////////////////////////////////fim da função que imprime as lateráis dos menus

//////////////////////////////////////////////////////////////////função que escreve no menu
void menu_do_jogo(void){
	
	int x=0, y=0;
	
	caixa_do_menu();
	mgotoxy(24,12);
	printf("Digite [2] para Jogar.");
	mgotoxy(24,14);
	printf("Digite [1] para fechar o Jogo.");
	mgotoxy(24,16);
	printf("Select:_______");

}
//////////////////////////////////////////////////////////////////fim da função que escreve no menu

//////////////////////////////////////////////////////////////////função que imprime na tela as paredes do mapa
void imprime_parede(void){//desenho das laterais do jogo
	
	int x, y;
	void caixa_do_menu(void);
	
	for(y=2;y<32;y++){//borda lateral esquerda 
		mgotoxy(4,y);
        printf("%c",219);
    }
    for(y=2;y<32;y++){//borda lateral direita
		mgotoxy(44,y);
        printf("%c",219);
    }
    for(x=4;x<45;x++){//borda lateral inferior
		mgotoxy(x,32);
        printf("%c",219);
    }
    for(x=4;x<44;x++){//borda lateral superior
		mgotoxy(x,2);
        printf("%c",219);
    }
}
//////////////////////////////////////////////////////////////////fim da função que imprime na tela as paredes do mapa

//////////////////////////////////////////////////////////////////função de fim de jogo
int fim_de_jogo(){
	int bar=219;
	mgotoxy(16,11);
	printf("%cFim de Jogo!%c",bar ,bar);
	return 1; 
}
//////////////////////////////////////////////////////////////////fim do jogo
