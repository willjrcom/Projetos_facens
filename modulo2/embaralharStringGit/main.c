#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	
	char jogador1[20], jogador2[20], aux, jogador[20];
	int i,t,cont=0;
	//srand(time(NULL));
	
	printf("--------------Jogador n1----------\nDigite sua palavra: ");
	scanf("%s", &jogador1);
	
	system("CLS");
	
	printf("\nSorteando....");
	sleep(1);
	
	system("CLS");
	t = strlen(jogador1);
	
	for(i=0; i<t; i++)
	{
		jogador[i]=jogador1[i];
	}
	for(i=0; i<t-1; i++)
	{	
		if(i%2==0 && jogador1[i]!=NULL)
		{
			aux=jogador1[i];
			jogador1[i]=jogador1[i+1];
			jogador1[i+1]=aux;
		}
	}
		printf("\n--------Jogador 2---------\n-Voce tem 2 chances!");
	do{
		
		printf("\n-Chance: %i",cont+1);
		printf("\nPalavra embaralhada: %s\n\nA palavra certa eh: ",jogador1);
		scanf("%s",jogador2);
		
		system("CLS");
		
		printf("Processando...");
		sleep(1);
		system("CLS");
		
		for(i=0;i<t; i++)
		{
			if(jogador2[i]!=jogador[i])
			{
				printf("\nVoce errou!");
				i=t+1;	
			}
		}
		if(i==t)
			printf("\nParabens, voce acertou!");
		cont++;
		
	}while((cont!=2) && (i!=t));
	
	return 0;
}

/*
	int v[t];
	
	for(i=0; i<t;i++)
	{
		sort=(rand()%t);
		v[i]=sort;
		
		for(j=0;j<i;j++)
		{	
			if(sort!=v[i-j])
			{
			jogador1[i-j]=jogador1[sort];
			j=i;
			}
		}
	}
	*/
