//Amanda Yumi Uwai 190509
//William Junior 180037
//------------------------------------------------------------------/
#include <stdio.h>
#include <stdlib.h>
//------------------------------------------------------------------/
int cont=0;
//------------------------------------------------------------------/
int receberTemp(float *temp1, float *temp2)
{
	char continuar;
	int i=0;
	
	do
	{
		printf("\nTemperatura dia %i: ",i+1);
		scanf("%f",temp1);
		
		printf("Previsao dia %i: ",i+1);
		scanf("%f",temp2);
		
		printf("\n\nDeseja continuar?\nS- Sim\nN- Nao\n: ");
		fflush(stdin);
		scanf("%c",&continuar);
		cont++;
		temp1++;
		temp2++;
		i++;
		
	}while((continuar == 'S')||(continuar == 's'));
}
//------------------------------------------------------------------/
int calcularTaxa(float *taxa1, float *taxa2)
{
	float taxa=0;
	int i;
	
	for(i=0; i<cont; i++,taxa1++, taxa2++)
	{
		if(*taxa1==*taxa2)
		{
			taxa++;
		}
	}
	
	taxa=(taxa*100)/cont;
	printf("\n\nTaxa de acerto: %.2f%%",taxa);	
}
//------------------------------------------------------------------/
int maiorDiferenca(float *maior1, float *maior2)
{
	int i;
	float c[30],maior=0;
	
	for(i=0; i<cont; i++,maior1++, maior2++)
	{
		c[i]= *maior1-*maior2;
		
		if(c[i]<0)
			c[i]*=-1;
			
		if(c[i] > maior)
			maior=c[i];
		
	}
	printf("\n\nA maior diferenca entre temperatura prevista e registrada foi de %.2f graus",maior);
}
//------------------------------------------------------------------/
int main()
{
	int i;
	float v1[30],v2[30];
	
	
	receberTemp(v1,v2);
	
	calcularTaxa(v1,v2);
	
	maiorDiferenca(v1,v2);
	
	return 0;
}
