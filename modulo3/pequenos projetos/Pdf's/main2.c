#include <stdio.h>

#include <stdlib.h>

#include <string.h>

 

typedef struct aluno{

        char RA[7];

        char nome[80];

        int *numreg;

        int dias;

        }aluno;

 

typedef struct livro{

        int  reg;

        char titulo[80];

        char status;

        }livro;

 

void cadastro_livro(livro **pliv,int qliv);

int procura_RA(aluno *palu,int qalu,char *aux);

void aloca_aluno(aluno **palu,int qalu);

void emprestimo(aluno *palu,livro *pliv,int qliv);

int busca_livro(livro *pliv,int qliv,char *aux);

void devolucao(aluno *palu,livro *pliv,int qliv);

void maiuscula(char *aux);

void mostra(aluno *palu,int qalu);

 

main( )

{

livro *liv=NULL;

aluno *alu=NULL;

char aux[80];

int qliv=5, qalu=0, op, achou;

 

cadastro_livro(&liv,qliv);

do{

   system("cls");                  

   printf("1. Emprestimo\n2. Devolucao\n3. Mostra\n4. Fim\n\nOpcao: ");

   scanf("%i",&op);

   fflush(stdin);

   switch(op)

      {

      case 1: aloca_aluno(&alu,qalu);                                 // aloca aluno

              emprestimo(alu+qalu,liv,qliv);

              qalu++;

              break;

             

      case 2: printf("\nRA do aluno: ");

              gets(aux);

              fflush(stdin);

              achou=procura_RA(alu,qalu,aux);

              if(achou==-1)

                printf("\nAluno nao encontrado");

              else

                devolucao(alu+achou,liv,qliv);

              break;

             

      case 3: mostra(alu,qalu);

              break;

      }//switch

   }while(op!=4);

}//main  

 

void cadastro_livro(livro **pliv,int qliv)

{ int i;

if((*pliv=(livro*)realloc(*pliv,qliv*sizeof(livro)))==NULL)

  exit(1);

for(i=0;i<qliv;i++)

  {

  (*pliv+i)->reg=i+1;

  strcpy((*pliv+i)->titulo,"LIVRO");

  (*pliv+i)->status='L';

  }

}//cadastro_livro

 

int procura_RA(aluno *palu,int qalu,char *aux)

{

int i;

for(i=0;i<qalu;i++)

  if(strcmp((palu+i)->RA,aux)==0)                                                         // compara RA

    return i;

return -1;

}//procura_RA

 

void aloca_aluno(aluno **palu,int qalu)

{

if((*palu=(aluno*)realloc(*palu,(qalu+1)*sizeof(aluno)))==NULL)

  exit(1);

}//aloca_aluno   

 

void emprestimo(aluno *palu,livro *pliv,int qliv)

{

char tit[80];

int ind;

printf("\nRA: ");

gets(palu->RA);

fflush(stdin);

printf("\nNome: ");

gets(palu->nome);

fflush(stdin);

maiuscula(palu->nome);

printf("\nTitulo: ");

gets(tit);

fflush(stdin);

maiuscula(tit);

ind=busca_livro(pliv,qliv,tit);

if(ind==-1)

  {

  printf("\nNao ha livro disponivel");

  printf("\n\n\n");

  system("pause");

  }

else

  {

  (*palu->numreg=&((pliv+ind)->reg));                                                        //aponta p/o reg do livro

  printf("\nDias: ");

  scanf("%i", &(palu->dias));                                            // recebe tempo de permanência

  fflush(stdin);

  printf("\nLivro emprestado - registro %i",*(palu->numreg));

  printf("\n\n\n");

  system("pause");

  }

}//emprestimo

 

int busca_livro(livro *pliv,int qliv,char *aux)

{

int i;

for(i=0;i<qliv;i++)

  if(strcmp((pliv+i)->titulo,aux)==0 && (pliv+i)->status=='L')                                  // compara título e status

    {

    ((pliv+i)->status ='E');                                                        // troca o status do livro para Emprestado

    return i;

    }

return -1;

}//busca_livro

 

void devolucao(aluno *palu,livro *pliv,int qliv)

{

int i,ind,achou=0;

printf("\nRA: %s",palu->RA);

printf("\nNome: %s",palu->nome);

printf("\nRegistro do livro: %i", palu->numreg);                     //mostra registro do livro

( (pliv+*(palu->numreg)-1)->status='L' );  //39 ou 2                                                                   // troca status para Livre

printf("\nTitulo do livro: %s",      (pliv+*(palu->numreg)-1)->titulo);                     //mostra título

printf("\nDias: %i",palu->dias);

printf("\nValor a pagar: %i", palu->dias*5 );                     // calcula o valor a pagar

printf("\n\n\n");

system("pause");

}//devolucao

 

void maiuscula(char *aux)

{

int i,tam;

tam=strlen(aux);

for(i=0;i<tam;i++)

  if(*(aux+i)>='a'&&*(aux+i)<='z')

    *(aux+i)-=32;

}//maiuscula

 

void mostra(aluno *palu,int qalu)

{

int i;

for(i=0;i<qalu;i++)

  printf("\nRA: %s\nNome: %s",(palu+i)->RA,(palu+i)->nome);

printf("\n\n\n");

system("pause");

}//mostra
