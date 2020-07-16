#include <stdio.h>
#include <stdlib.h>

torres(int disco, char t1, char t3, char temp);

int main()
{
	int tdiscos;
   	
	printf("Torre de Hanoi\n\nTotal de discos: ");
	scanf("%i", &tdiscos);
   
	torres( tdiscos, 'A', 'C', 'B');
   
	return 0;
}




int torres(int disco, char t1, char t3, char temp)
{	
	if (disco==1) 
	{
		printf("\nDisco %i da torre %c para a torre %c", disco, t1, t3);
		
		
		return;
	}
	
	torres(disco-1, t1, temp, t3);
	  
	printf("\nDisco %i da torre %c para a torre %c", disco, t1, t3);
	  
	torres(disco-1, temp, t3, t1);
	
}
