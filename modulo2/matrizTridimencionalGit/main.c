//DANIELLE ZEFERINO 190275
//William Junior 180037

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
//-----------------------------------------------------------------------------------
#define alunos 50 //quantidade de alunos
#define x 10 //quantidade de questoes
#define y 5 //quantidade de alternativas
//-----------------------------------------------------------------------------------

int RecebeGabarito(int gab[10][5])//(gabarito)(questoes)
{
	int i,j,a=0,q;
	
	printf("Digite o total de questoes da prova entre 0 a 10: ");
	
	do
	{
		if(a!=0)
			printf("\nDigite novamente um valor valido!: ");
	
		scanf("%i", &q);
		a++;
	
	}while(q<=0 || q>10);
	
	printf("\n\tDigite o Gabarito:\n");
	
	for(i=0; i<q; i++)
	{
		printf("\n\nQuestao %i", i+1);
		
		for(j=0; j<5; j++)
		{
			printf("\nItem %i: ", j+1);
			scanf("%i", *(gab+i)+j );
			// printf("%i", *(*(gab+i)+j) );
		}//for
	}//for
	return q;
}//RecebeGaba
//-----------------------------------------------------------------------------------
int RecebeRespAluno(int Ra[50][10][5], int q)//(provas)
{
	int i,j,al,a=0,t;
	
	printf("\n\tReceber Notas\nDigite o total de alunos de 0 a 50: ",q);
	
	do
	{
		if(a!=0)
			printf("\nDigite novamente um valor valido!: ");
		
		scanf("%i", &t);
		a++;
	
	}while(q<=0 || q>50);
	
	for(al=0; al<t; al++)
	{
		printf("\n\tAlunos %i",al+1);
		
		for(i=0;i<q;i++)
		{
			printf("\n\nQuestao: %i\n",i+1);
			
			for(j=0;j<5;j++)
			{
				printf("\nItem %i: ",j+1);
				scanf("%i", *(*(Ra+al)+i)+j );
				// printf("%i", *(*(*(Ra+al)+i)+j) );
			}//for
		}//for
	}//for
	return t;
}

//-------------------------------------------------------------------------------------------------------------------------
void Corrige(int gab[10][5], int pro[50][10][5], int q, int t, float *notas)//(gabarito)(provas)(questoes)(alunos)(notas)
{
	int i=0,j,al,soma=0;
	float notaf;
	printf("\n\tNotas: \n");
	
	for(al=0; al<t; al++)//(alunos)
	{
		*(notas+i) = 0;
		notaf=0;
		
		for(i=0; i<q; i++)//(questoes)
		{
			for(j=0; j<5;j++)//(item)
			{
				if( *(*(*(pro+al)+i)+j) == *(*(gab+i)+j) )
					soma++;
			
				if(soma==3)
				{
					notaf += 0.6;
					soma=0;
					j=4;
				}
			}
			soma=0;
		}
		*(notas+i) = notaf*0.2;
		printf("\nAluno: %i  --- Nota: %.2f",al+1, *(notas+i) );
	}
}
//-----------------------------------------------------------------------------------
int main()
{
	int gabarito[10][5], provas[50][10][5],q,t;
	float notas[50];
	
	printf("---------Correcao de Provas----------\n");
	
	q = RecebeGabarito(gabarito);
	t = RecebeRespAluno(provas,q);
	Corrige(gabarito,provas,q,t,notas);
	
	getch();
	return 0;
}//main
