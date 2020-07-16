#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char t1[10],t2[10],t3[20];
	int i, tt1,tt2;
	
	printf("Nome: ");
	gets(t1);
	
	printf("sobrenome: ");
	gets(t2);
	
	tt1=strlen(t1);
	tt2=strlen(t2);
	
	for(i=0; i<tt1; i++)
		t3[i] = t1[i];
		
	strcat(t3," ");
	
	for(i=0; i<tt2; i++)
		t3[i+tt1+1] = t2[i];
		
	printf("%s",t3);
	
	return 0;
}
