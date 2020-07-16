#include <stdio.h>
#include <stdlib.h>

int verif(int b[3][3])
{
	int i,j,k=0;
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			if((i!=j)&&(0!=b[i][j]))
					k++;
					
	if(k>=1)
		printf("\nA matriz nao eh diagonal");	
	else
		printf("\nA matriz eh diagonal");
}

int mostrar(int b[3][3])
{
	int i,j;
	printf("\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
			printf("%i ",b[i][j]);
			
	printf("\n");
	}
	
}
		

int main()
{
	int a[3][3], i,j;
	
	printf("Matriz Diagonal\nDigite 10 numeros: ");
	for(i=0; i<3; i++)
		for(j=0; j<3; j++)
			scanf("%i",&a[i][j]);
			
	verif(a);
	mostrar(a);

	return 0;
}

	

