#include <stdio.h>
#include <stdlib.h>

int main()
{
	char textArq[80];
	
	FILE *imprimir, *ler;
	if((imprimir = fopen("LPT1","w"))==NULL) //impressora
	{
		puts("Impressora Indisponivel");
		//exit(1);
	}
	if((ler = fopen("imprimir.txt","r"))==NULL) //ler arquivo
	{
		puts("Arquivo Indisponivel");
		//exit(1);
	}
	while(!feof(ler))
	{
		fgets(textArq,80,ler);
		fputs(textArq,imprimir);
	}	
	
	fclose(imprimir);
	fclose(ler);
	
	system("PAUSE");
	
	return 0;
}
