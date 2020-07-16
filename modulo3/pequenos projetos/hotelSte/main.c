// Stefany Lima - RA 190144
// william junior RA 180037
// Danielle Zeferino RA 190275


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct hospede
{
    int quarto;
    char *nome;
    int acompanhante;
    char categoria;
    int dias;
    union estado tabela;
}hospede;
       
       
typedef struct quarto
{
    int num;
    char categoria;
    char status;
    union estado status;
}quarto;


void aloca_quarto(quarto **pq, int qq);
void aloca_hospede(hospede **ph, int qh);
void aloca_char(char **p, int q);
void cadastro_quarto(quarto *pq, int qq);
void cadastro_hospede(hospede *ph, quarto *pq, int qq);
int  busca_hospede(hospede *ph, int qh, int nq);
int  busca_quarto(quarto *pq, int qq, char cat);
void check_out(hospede *ph, quarto *pq);
void mostra(hospede *ph, int qh);


int main()
{
	quarto *pq = NULL;
	hospede *ph = NULL;
	int op, qh = 0, ind, num_q; //qh - qtde hospede, ind - indice de hospede, num_q - numero quarto
	
	aloca_quarto(&pq, 15);
	cadastro_quarto(pq, 15);
	
	do
	{
		system("cls");
		printf("\n[1]Check-in\n[2]Check-out\n[3]Mostra\n[4]Fim\nopcao: ");
		scanf("%i", &op);
		fflush(stdin);
		
		switch(op)
		{
	    	case 1: ind = busca_hospede(ph, qh, -1);
	    	
					if (ind == -1)// nao ha espaco vago
					{
						aloca_hospede(&ph, qh+1);
						ind = qh;
						qh++;
					}
					cadastro_hospede(ph+ind, pq, 15);
	            break;
	            	
	    	case 2: printf("\nQuarto a ser encerrado: ");
					scanf ("%i", &num_q);
					ind = busca_hospede(ph, qh, num_q);
					
					if (ind == -1)// nao encontrou o quarto
					{
						printf ("\nQuarto sem registro\n");
						system ("PAUSE");	
					}
					else
						check_out(ph+ind, pq+num_q -1);
				break;
	             	
	    	case 3: mostra(ph, qh);
				break;
	             	
	     }//switch
	   }while(op != 4);
}//main               


void aloca_quarto(quarto **pq, int qq)
{
	if((*pq = (quarto*)realloc(*pq,qq*sizeof(quarto)))==NULL)
	  exit(1);
}//aloca_quarto


void aloca_hospede(hospede **ph, int qh)
{
	if((*ph = (hospede*)realloc(*ph,qh*sizeof(hospede)))==NULL)
	  exit(1);
}//aloca_hospede


void aloca_char(char **p, int q)
{
	if((*p = (char*)realloc(*p, q*sizeof(char)))==NULL)
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
	int i;
	for (i=0; i<qh; i++)
		if ((ph+i)->quarto == nq)
			return i;		
	return -1;
}//busca_hospede


void cadastro_hospede(hospede *ph, quarto *pq, int qq)
{
	int tam;
	char aux[20];
	ph->nome = NULL; // 1

	printf ("\nNome: ");
	gets (aux);
	fflush(stdin);
	
	tam = strlen(aux); //2
	aloca_char (&(ph->nome), tam+1); //3
	strcpy (ph->nome, aux); //4

	printf ("\nAcompanhantes: ");
	scanf ("%i", &(ph->acompanhante));
	
	if(ph->acompanhante == 0)
		ph->categoria = 'S';
	else
		ph->categoria = 'F';
		
	printf ("\nDias ");
	scanf ("%i", &(ph->dias));
	
	ph->quarto = busca_quarto(pq, qq, ph->categoria);
	
	if (ph->quarto == -1)
		printf ("\nCategoria indisponivel\n");
	else
		printf ("\nSucesso - Quarto: %i\n\n", ph->quarto);
	

	system("pause");
}//cadastro_hospede


int  busca_quarto(quarto *pq, int qq, char cat)
{
	int i;
	
	for (i=0; i<qq; i++)
		if ((pq+i)->categoria == cat && (pq+i)->status == 'L')
		{
			(pq+i)->status = 'O';
			return ((pq+i)-> num);
		}	
	return -1;
}//busca_quarto 


void check_out(hospede *ph, quarto *pq)
{
	float total;

	printf ("\nQuarto: %i\nNome: %s\nAcompanhantes: %i", ph->quarto, ph->nome, ph->acompanhante);
	printf ("\nCategoria: %c\nDias: %i\n", ph->categoria, ph->dias);
	
	if (ph->categoria == 'S')
		total = ph->dias*85;
	else
		total = ph->dias*((ph->acompanhante)+1)*45;
		
	printf ("\nTotal a pagar: R$ %.2f\n\n\n", total);
	
	ph->quarto = -1;
	pq->status = 'L';
	
	system("pause");
}//check_out


void mostra(hospede *ph, int qh)
{
	int i;
	for (i=0; i<qh; i++, ph++)
		if(ph->quarto != -1)
		{
			printf ("\nQuarto: %i\nNome: %s\nAcompanhantes: %i", ph->quarto, ph->nome, ph->acompanhante);
			printf ("\nCategoria: %c\nDias: %i\n", ph->categoria, ph->dias);
		}

	printf("\n\n\n");
	system("pause");
}//mostra


