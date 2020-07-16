#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contar(char *texto)
{
	int cont=0;
	for(;*texto;texto++) 
	{
	cont++;
	}
	
	return cont;
}
int main()
{
	char texto[30];
	int i,t;
	gets(texto);
	
	printf("%s\n",texto);
	
	t= contar(texto);
	printf("\n%i\n",t);
	
	texto[0]-=32;
	
	for(i=0;i<t;i++)
		if(isspace(texto[i]))
			texto[i+1]-=32;
		
	puts(texto);
	
	return 0;
}
