//190301
//190032
//190142
//163130
//180037



#include <stdio.h>
#include <stdlib.h>

int contar(char *texto)
{
	int cont=0;
	for(;*texto;texto++) cont++;
	return cont;
}
void maiuscula(char *texto)
{
	for(;*texto;texto++)
		if((*texto>=65 && *texto<=90)&& !isspace(*texto))
			*texto+=32;
}

void comparar(char *texto1, char *texto2, char *lc, int t1, int t2, int *pos)
{
	int i,j,cont=0, cont2 = 0;
	
	for(i=0;i<t1;i++)
	{
		//cont=0;
		//*pos=0;
		
		for(j=0;j<t2;j++)
		{
			cont2 = 0;
			if(*(texto1 + i) == *(texto2 + j))
			{
//				do{
//					pos+=1;
//					texto2++;
//				}while(*texto2!=NULL);
				while(*lc != '\0' || (cont == 0 || cont2 == 0))
				{
					if(*lc  != *texto1){
						cont2++;
						break;
					}
				}
				
				if (cont2 != 0)
				{
					*lc = *(texto1 + i);
					lc++;
					cont++;
				}
				
				
				pos++;
				
				//printf("\n%c %i",*lc,*pos);
			}
		}
	}
	
		
		
			
	
				
}
int main()
{
	char nome1[20], nome2[20], lc[40];
	int i,t1,t2,pos[40];
	
	printf("nome 1: ");
	scanf("%s",&nome1);
	
	printf("nome 2: ");
	scanf("%s",&nome2);
		
	printf("\n%s %s\n",nome1,nome2);
	
	t1= contar(nome1);
	t2= contar(nome2);
	maiuscula(nome1);
	maiuscula(nome2);
	
	printf("\n\nLetras em comum: ");

	comparar(nome1,nome2,lc,t1,t2,pos);
	
	puts(lc);
	
//	for(i=0;i<40;i++)
//		printf("\n%i",pos[i]);
		
	return 0;
}
