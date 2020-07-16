//T2
//Professor1 dos Trezentos:  Emanuela lopez 190176
//Aluno1: Mathias Waibel 190026
//Aluno2: William Junior 180037

#include <stdio.h>
#include <stdlib.h>

int contar(char *texto)
{
	int cont=0;
	for(; *texto; texto++) cont++;
	return cont;
}
//--------------------------------------------------------------------------------------
void maiuscula(char *texto)
{
	for(;*texto;texto++)
		if(*texto<=90 && *texto>=65)
			*texto+=32;	
}
//--------------------------------------------------------------------------------------
void concatenar(char *nome1, char *nome2, char *nome3,int t1, int t2)
{
	int i;
	for(i=0; i<t1; i++)
		*(nome3+i)= *(nome1+i);
	for(i=0; i<t2; i++)
		*(nome3+i+t1)= *(nome2+i);
}
//--------------------------------------------------------------------------------------
void ordenar(char *nome1, int t)
{
	int i,j;
	char aux;
	
	for(i=0; i<t; i++)
		for(j=0; j<t-1; j++)
		
			if( (*(nome1+j+1) < *(nome1+j)) && (*(nome1+j+1)<=122 && *(nome1+j+1)>=97) )
			{
				aux = *(nome1+j+1);
				*(nome1+j+1) = *(nome1+j);
				*(nome1+j) = aux;
				//printf("\n%s", nome1);
			}
	printf("\n----------------------\n");
	
	for(i=0; i<t; i++)
	{
		if( *(nome1+i) == *(nome1+i+1) )
			for(j=0; j<t; j++)
			{
				*(nome1+j+i) = *(nome1+j+i+1);
				//printf("\n%s", nome1);
			}
	}
	*(nome1+i)='\0';
}
//--------------------------------------------------------------------------------------
int main()
{
	char nome1[20], nome2[20],nome3[40];
	int enum1[20], enum2[20],t1, t2, t3;
	
	printf("texto: ");
	scanf("%s", &nome1);
	
	printf("texto 2: ");
	scanf("%s", &nome2);
	
	t1 = contar(nome1);
	t2 = contar(nome2);
	
	maiuscula(nome1);
	maiuscula(nome2);
	
	concatenar(nome1,nome2,nome3,t1,t2);
	
	t3 = contar(nome3);
	
	ordenar(nome3,t3);
	
	printf("\nNome: %s", nome3);
	
	return 0;
}
