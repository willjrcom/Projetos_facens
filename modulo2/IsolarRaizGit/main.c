#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Funcao
min | max
erro
indice | min | media | max | Fmin | Fmedia | Fmax
*/

int raiz(int i, float min, float max, float erro, float n[], float e[], int t)
{
	float fmin, media, fmedia, fmax;
	int a,b,c;

	media = (min+max) / 2;
	
	for(a=0; a<t; a++)
	fmin += n[a]* pow( min, e[a] );
	
	for(b=0; b<t; b++)
	fmedia += n[b]* pow( media, e[b] );
	
	for(c=0; c<t; c++)
	fmax += n[c]* pow( max, e[c] );			
		
	printf("\n%i\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\t%.3f\n",i, min, media, max, fmin, fmedia, fmax);
	
	if( (fmedia <= erro) && (0 < fmedia) )
	{
		printf("\n\nTotal de iteracoes: %i",i);
		return 0;
	}
	else if( (fmedia*-1) < 0)
	{
		max = media;
		i++;
		return raiz(i,min,max,erro,n,e,t);
	}
	else
	{
		min  = media;
		i++;
		return raiz(i,min,max,erro,n,e,t);
	}
}
// função principal------------------------------------------------------------------------------------------------------
int main() {
	
	float min, max, erro;
	int i=0, j, t;
	
	printf("Isolamento de Raiz\n\nTotal de termos:\n");
	scanf("%i",&t);
	
	float n[t],e[t];
	
	
	if( (t<=10) && (t>0) )
		for(j=0; j<t; j++)
		{
			printf("\nDigite o valor do %i coeficiente e do %i expoente de x: ",j+1, j+1);
			scanf("%f %f", &n[j], &e[j]);
		}
	
	printf("Min: ");
	scanf("%f", &min);
	
	printf("Max: ");
	scanf("%f", &max);
	
	printf("Erro: ");
	scanf("%f", &erro);
	
	printf("\ni\tA\tM\tB\tFa\tFm\tFb\n");
	
	raiz(i,min,max,erro,n,e,t);
	
	getch();
	return 0;
}
