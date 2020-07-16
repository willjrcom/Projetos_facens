#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void receber(int *funcao, float *min, float *max, int *n, int grau)
{
	int i;
	
	for(i=0; i<=grau; i++)
	{
		printf("Digite o valor de x na potencia %i: ", i);
		scanf("%i", (funcao+i));
	}
	fflush(stdin);
	printf("\nIntervalo minimo: ");
	scanf("%f", min);
	
	printf("\nIntervalo maximo: ");
	scanf("%f", max);
	
	printf("\nNumero de Intervalos: ");
	scanf("%i", n);
	
}
//-------------------------------------------------------------------------
int main()
{
	int op=0;
	while(op==0)
	{
		
	int grau, *funcao, i, j=0, n;
	float min, max, h, area=0, soma=0, v, temp,total=0,som=0;
	
	system("CLS");
	
	printf("\tRegra dos trapezios\n\nDigite o grau da funcao: ");
	scanf("%i", &grau );
	
	if((funcao = (int *) calloc(grau+1, sizeof(int))) == NULL)
		exit(1);
	
	printf("\n");
	
	receber(funcao, &min,&max, &n, grau);
	
	h = ( max - min) / n;
	system("CLS");
	
	printf("\tFuncao: ");
	
	for(i=grau; i>=0; i--)
	{
		if(i != 0  && *(funcao+i) != 0 && *(funcao+i) != 1)
			printf("%i x^%i + ",*(funcao+i), grau+j);
		
		if(i != 0  && *(funcao+i) != 0 && *(funcao+i) == 1)
			printf("x^%i + ", grau+j);
			
		else if (i == 0)
		printf("%i", *(funcao+i));
		
		j--;
	}
	
	printf("\nMinimo: %.1f \nMaximo: %.1f \nN: %i \nH: %.4f\n", min, max, n, h);
	v= min; 
	
	for(i=0; i<=n; i++)
	{
		temp=0;
		printf("\nF[%i]= ", i);
			
		for(j=grau; j>=0; j--)
		{
			temp+= pow( v,j ) **(funcao+j);
		}
		
		if(v == min || 4 == v)
				som += temp;
		
		printf(" %.2f\n", temp);
		total += temp;
		v += h;			
	}
	total -= (som+temp);
	total *= 2;
	total += (som+temp);
	total *= (h/2);
	
	
	printf("\nArea %.3f", total);
	
	free(funcao);

	printf("\n\nDeseja continuar?\n0 - sim\n1 - Nao\n: ");
	scanf("%i",&op);
	}
	return 0;
}
