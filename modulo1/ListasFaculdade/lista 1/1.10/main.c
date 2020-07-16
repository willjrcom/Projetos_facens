#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int l,km,total;
	printf("consumo medio do carro.\n\nlitros: ");
	scanf("%i",&l);
	
	printf("kilometros: ");
	scanf("%i",&km);
	
	total = km / l;
	
	printf("\nconsumo medio: %i",total);
	getch();
	return 0;
}
