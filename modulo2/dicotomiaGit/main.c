#include <stdio.h>
#include <stdlib.h>
#include <math.h>

	/*Função:f(x)=x³–x–1
	•Intervalo:[1,2]
	•Precisão:=0,03*/
	
void isolarRaiz(int i, float min, float max, float erro)
{
	float media, fmin, fmedia, fmax;
	
	media= (min+max)/2;
	
	fmin=(pow(min,3))-min-1;
	fmedia=(pow(media,3))-media-1;
	fmax=(pow(max,3))-max-1;
	printf("\n%i	%f	%f	%f	%f	%f	%f",i,min,media,max,fmin,fmedia,fmax);
	
	if((fmedia>0)&&(fmedia<erro))
	{
		printf("\n\nTotal de iteracoes: %i",i);
		return;
	}
	else if(fmedia*(-1) <0)
	{
		max=media;
		i++;
		isolarRaiz(i,min,max,erro);
	}
	else
	{
		min=media;
		i++;
		isolarRaiz(i,min,max,erro);
	}
}
int main()
{
	float min,max,erro;
	int i=0;
	
	printf("\nmin: ");
	scanf("%f", &min);
	
	printf("\nmax: ");
	scanf("%f", &max);
	
	printf("\nerro: ");
	scanf("%f", &erro);
	
	isolarRaiz(i,min,max,erro);
	
	return 0;
}
