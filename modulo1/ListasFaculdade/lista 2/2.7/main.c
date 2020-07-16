#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int s,sn;
	printf("salario.\n");
	scanf("%i",&s);
	
	if(s<=1000)printf("salario com aumento: %i",sn=(s*0.05)+s);
	else printf("salario com aumento: %i",sn=(s*0.07)+s);
	
	getch();
	return 0;
}
