#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------
int contar (char *texto)
{
	int cont=0;
	for(;*texto; texto++) cont++;
	return cont;
}
//----------------------------------------------------------------
void maiusculas(char *texto)
{
	for(;*texto; texto++)
		if(*texto>=65 && *texto<=90)
			*texto+=32;
}
//----------------------------------------------------------------
void passarstring(char *texto, char*aux)
{
	for(;*texto;texto++,aux++) *aux= *texto;
}
//----------------------------------------------------------------
void trocar(char *aux, char *troca, int t)
{
	int i,j,k;
	for(i=0; i<t; i++)
	{
		if(*(aux+i) == 'z')
			*(troca+i) = 'a';
		else
			*(troca+i) = *(aux+i)+1;
		
		for(j=0; j<=t+i; j++)
		{
		//printf("\n%s",troca);
			if(*(troca+i) == *(aux+j))
			{		
				*(troca+i)+=1;
				j=0;	
				
				for(k=0;k<t; k++)
					if(*(troca+i) == *(aux+k))
					{		
						*(troca+i)+=1;
						k=0;
						
					}
			}
		*(aux+t+i+1) = *(troca+i);	
		}
	}
	*(troca+t+1)='\0';
	*(aux+t+i+1)='\0';
			
}
//----------------------------------------------------------------
int main()
{
	char nome[20], aux[40], troca[20];
	int t;
	
	printf("digite o texto: ");
	scanf("%s", &nome);
	
	t=contar(nome);
	maiusculas(nome);
	passarstring(nome,aux);
	trocar(aux,troca,t);
	
	printf("\n nome %s\n aux: %s\n troca: %s\n total: %i",nome,aux,troca,t);
	return 0;
}
//----------------------------------------------------------------
