//bibliotecas--------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <stdlib.h>
//função 1--------------------------------------------------------------------------------------------//
void calcularx(float *x, int t)
{
	int i;
	printf("\n\nDigite o valor de cada ponto de x:");
	
	for(i=0; i<t; i++, x++)
	{
		printf("\nx[%i]: ",i);
		scanf("%f",x);
	}
}
//função 2--------------------------------------------------------------------------------------------//
void calcularfx(float *fx, int t)
{
	int i;
	printf("\n\nDigite o valor de cada ponto de f(x):");
	
	for(i=0; i<t; i++, fx++)
	{
		printf("\nf(x[%i]): ",i);
		scanf("%f",fx);
	}
}
//função interpolar--------------------------------------------------------------------------------------------//
void interpolar(int t, float *fx, float *x, int x1)
{
	int i,j;
	float px=0,li;
	
	for(i=0; i<t; i++)
		{
			li=1;
			
			for(j=0; j<t; j++)
			{
				if(i!=j)
				{
					li= li *( x1 -*(x+j) ) / ( *(x+i) - *(x+j) ) ;
				}
			}
		px = px+(li* *(fx+i));
		printf("\nL[%i] = %.2f\n", i,li);
		}	
		
		printf("\nvalor de x no f(x): %.2f",px);
}
//função principal--------------------------------------------------------------------------------------------//
int main()
{
	float x[10], fx[10],x1;
	int t;
	
	printf("--------------Metodos Numericos - Lagrange--------------");
	printf("\n\nDigite o total de pontos de x e f(x) na tabela: ");
	scanf("%i",&t);
	
	
	printf("\nDigite o ponto a ser interpolado: ");
	scanf("%f",&x1);
	
	calcularx(x,t);
	calcularfx(fx,t);
	interpolar(t,fx,x,x1);
	
	getch();
	return 0;
}
