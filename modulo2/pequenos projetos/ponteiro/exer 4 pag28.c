#include <stdio.h>
#include <stdlib.h>

void receber1();
void receber2();
void media();
int main()
{
	float n1[100],n2[100],m[100];
	int qtd;
	
	printf("\nDigite uma quantidade de alunos :");
	scanf("%i",&qtd);
	
	receber1(n1,qtd);
	
	printf("\n");
	
	receber2(n2,qtd);
	
	media(n1,n2,qtd,m);
	
	getch();
	return 0;
}
void receber1(float *p, int q)
{
	int i;
	for(i=0;i<q; p++,i++)
	{
		printf("\nAluno %i-Nota 1 :",i+1);
		scanf("%f",p);
	}
	

}
void receber2(float *p, int q)
{
	int i;
	for(i=0;i<q; p++,i++)
	{
		printf("\nAluno %i-Nota 2 :",i+1);
		scanf("%f",p);
	}
	

}
void media(float *n1, float *n2, int q, float *m)
{
	int i=0;
	for(i=0; i<q; i++)
		{
		*m = (*n1 + *n2)/2;
		printf("aluno %i media: %.2f\n\n",i+1,*m);	
		}
}
