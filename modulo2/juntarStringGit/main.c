#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void receberString(char *string)
{
	printf("\nDigite o texto:");
	fflush(stdin);
	gets(string);
}

void concatenarStrings(char *stringA, char *stringB, char *stringC, int ta, int tb)
{
	int i,t=ta+tb;
	
	
	for(i=0; i<t; i++,stringA++,stringB++,stringC++)
	{
		if(stringA==NULL)
			*stringC='11';
		else
		*stringC=*stringA;
		
		stringC++;
		
		if(stringB==NULL)
			*stringC='1';
		else
		*stringC=*stringB;
	}
	*stringC='\0';
	
}

int main()
{

	char a[50],b[50],c[100];
	int ta,tb;
	
	receberString(a);
	receberString(b);
	
	ta=strlen(a);
	tb=strlen(b);
	
	concatenarStrings(a,b,c,ta,tb);
	
	printf("%s",c);
	return 0;
}
