#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minha_strlen(char *str)
{
     int cont =0;
     for(;*str;str++) cont++;
     return cont;
}

int main ()
{
	char texto[10] = "will";
	minha_strlen(texto);
	printf("Total de caracteres: %i",minha_strlen(texto));
	return 0;
}
