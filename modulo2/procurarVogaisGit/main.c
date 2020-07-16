#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

int l=0;

int Vogal(char s[50], int i, int tvogais);

int main()
{
	char Palavra[50];
	int tvogais=0;
	
	printf("Digite a palavra: ");
	gets(Palavra);
	
	Vogal(Palavra, 0, tvogais);
	
	
	
	return 0;
}


int Vogal(char p[50], int i, int tvogais)
{
	int j;
	
	if(p[i] == 0)
	{
		return;
	}
		
	if((toupper(p[i]) == 'A') || (toupper(p[i]) == 'E') || (toupper(p[i]) == 'I') || (toupper(p[i]) == 'O') || (toupper(p[i]) == 'U'))
	{
		printf("%c", p[i]);
		tvogais+=1;
	}
	if((toupper(p[i]) == ',') || (toupper(p[i]) == ';') || (toupper(p[i]) == '.') || (toupper(p[i]) == '!') || (toupper(p[i]) == '?')|| (toupper(p[i]) == '-'))
	{
		p[i]='+';
	}
	Vogal(p, i+1,tvogais);
	
	if(l==0)
	{
	printf("\nTotal de Vogais: %i", tvogais);
	printf("\n%s",p);
	l++;	
	}
	

}
