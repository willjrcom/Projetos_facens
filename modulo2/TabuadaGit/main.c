#include <stdio.h>
#include <stdlib.h>

int tabuada(int n1, int n2,int i)
{
	printf("\n%i x %i = %i",i,n1,i*n1);
	
	if(i==n2)
		return 0;
	else
		return tabuada(n1,n2,i+1);
}
int main()
{
	int n1,n2, i=0;
	printf("Tabuada do: ");
	scanf("%i",&n1);
	
	printf("\nAte: ");
	scanf("%i",&n2);
	
	tabuada(n1,n2,i);
	
	return 0;
}
