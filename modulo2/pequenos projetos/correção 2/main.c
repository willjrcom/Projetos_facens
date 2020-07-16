/*190301 elias della torre
163130 suele cristine
190142 pablo henrique moral
190032 henrique akao
180037 william junior 
*/
#include <stdio.h>
#include <stdlib.h>

//--------------------------------------------------------------------------------------
int contar(char *texto)
{
	int cont =0;
		
	for(;*texto;texto++) cont++;
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
void trocar(char *nome, char *aux, char *troca, int t)
{
	int i,j,k;
	
	for(i=0; i<t; i++, troca++, nome++, aux++)
	{
		
		*troca= *nome;
		for(k=0; k<t;k++)
			if(*troca== *(aux+k))
			{
				*troca+=1;
				k=0;
				
			}
			else if(j<t)
				for(j=0;j<t;j++)
					if()
		}
		*(aux+t+i+1)= *troca;

	*(troca+1)='\0';
	*(aux+1)='\0';
}
//--------------------------------------------------------------------------------------
void passarstring(char *nome, char *aux)
{
	for(; *nome;nome++,aux++) *aux=*nome;
}
int main()
{
	char nome[20], aux[40], troca[20];
	int t;
	printf("Digite o nome: ");
	scanf("%s", &nome);
	
	t=contar(nome);
	maiuscula(nome);
	passarstring(nome,aux);
	
	
	
	trocar(nome,aux,troca,t);
	
	printf("nome: %s \nAux: %s\nTotal :%i\nTroca: %s",nome,aux, t,troca);
	
	return 0;
}
