#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hospede
{
	int     quarto;
	char    *nome;
	int     acompanhante;
	char    categoria;
	int     dias;
}hospede;

typedef struct quarto
{
	int    num;
	char   categoria;
	char   status;
}quarto;

/*
void aloca_quarto(quarto **pq,int qq);
void aloca_hospede(hospede **ph,int qh);
void aloca_char(char **p,int q);
void cadastro_quarto(quarto *pq,int qq);
void cadastro_hospede(hospede *ph,quarto *pq,int qq);
int  busca_hospede(hospede *ph,int qh,int nq);
int  busca_quarto(quarto *pq,int qq,char cat);
void check_out(hospede *ph,quarto *pq);
void mostra(hospede *ph,int qh);
*/
int main()
{
	quarto *pq = NULL;
	hospede *ph = NULL;
	int op, qh = 0, ind, num_q; 
	//qh - qtde hospede, ind - indice de hospede, num_q - numero 

	quartoaloca_quarto(&pq, 15);
	cadastro_quarto(pq, 15);

	do
	{      
		system("cls");
		
	    printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra\n[4]Fim\nopcao: ");
	    scanf("%i",&op);
		fflush(stdin);
		
		switch(op)
		{     
			case 1:             
				break;     
			case 2: printf("\nQuarto a ser encerrado: ");             
				break;     
			case 3: mostra(ph,qh);             
				break;     
		}//switch   
	}while(op != 4);
}//main


void aloca_quarto(quarto **pq,int qq)
{
	if((*pq=(quarto*)realloc(*pq,qq*sizeof(quarto))) == NULL)  
	exit(1);
}//aloca_quarto


void aloca_hospede(hospede **ph,int qh)
{
	if((*ph=(hospede*)realloc(*ph,qh*sizeof(hospede))) == NULL)  
	exit(1);
}//aloca_hospede


void aloca_char(char **p,int q)
{
	if((*p=(char*)realloc(*p,q*sizeof(char))) == NULL)  
	exit(1);
}//aloca_char


void cadastro_quarto(quarto *pq, int qq)
{
	int i;
	
	for(i=0; i<qq; i++)
	{
		(pq+i)->num = i+1;
		(pq+i)->status = 'L';
		
		if(i<5)
			(pq+i)->categoria = 'S';
		else
			(pq+i)->categoria = 'F';
	}//for
}//cadastro_quarto


int  busca_hospede(hospede *ph, int qh, int nq)
{
	return -1;
}//busca_hospede


void cadastro_hospede(hospede *ph, quarto *pq, int qq)
{
	system("pause");
}//cadastro_hospede


int  busca_quarto(quarto *pq, int qq, char cat)
{
	return -1;
}//busca_quarto


void check_out(hospede *ph, quarto *pq)
{
	system("pause");
}//check_out


void mostra(hospede *ph, int qh)
{
	printf("\n\n\n");
	system("pause");
}//mostra




