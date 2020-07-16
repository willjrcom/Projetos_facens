#include <stdio.h>
#include <stdlib.h>

int main()
{
	char senha[7], confsenha[7];
	int i,v=0;
	
	do
	{
	printf("\nDigite a senha: ");
	scanf("%s",&senha);
	
	printf("\nConfirme a senha: ");
	scanf("%s",&confsenha);
	
	if(senha[0]==confsenha[0]==senha[1]==confsenha[1]==senha[2]==confsenha[2])
	{
		printf("\nSenha invalida.");
		v=1;
	}
		
	for(i=0; i<6; i++)
	{
		if((senha[i]!=confsenha[i])&&(v==0))
		{
			printf("\nsenha invalida.");
			i=6;
			v=1;
		}
		else
		v=0;
	}
	}while(v==1);
	
	printf("\nSenha valida.");
	return 0;
}
