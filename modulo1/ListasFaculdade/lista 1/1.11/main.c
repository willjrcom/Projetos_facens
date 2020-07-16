#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int vm,ds,dt;
	printf("velocidade media.\n\ndistancia: ");
	scanf("%i",&ds);
	
	printf("tempo: ");
	scanf("%i",&dt);
	
	vm = ds / dt;
	
	printf("\na velocidade media e: %i",vm);
	getch();

	return 0;
}
