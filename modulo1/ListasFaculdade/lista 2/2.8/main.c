#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float m,r;
	printf("minutos no celular: ");
	scanf("%f",&m);
	
	if (m<=50)printf("voce vai pagar R$50,00");
	else printf("voce vai pagar R$%.2f",r=50+((m-50)*1.5f));
	getch();
	return 0;
}
