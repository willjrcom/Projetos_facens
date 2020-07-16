#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int contar(char *texto)
{
	int cont=0;
	for(;*texto;texto++) cont++;
	return cont++;
}
//------------------------------------------------------------------------------------------------------------------
int inverte(char *texto, int t, int cont)
{	
	int i;
	if(cont==0)
	{
		for(i=0;i<t;i++,texto++);
		cont++;	
	}

	printf("%c",*texto);
	texto--;
	
	if(*texto==0)
		return 1;
	else 
		return inverte(texto,t,cont);
}
//------------------------------------------------------------------------------------------------------------------
int main()
{
	char texto[50];
	int t,cont=0;
	
	printf("Digite seu texto: ");
	gets(texto);
	
	t=contar(texto);
	printf("%i\n",t);
	
	inverte(texto,t,cont);
	
	return 0;
}
