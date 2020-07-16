#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int a= 2019;
	int b;
	int c;
	int d;
	printf("Qual o seu ano de nascimento? ");
	scanf("%i",&b);
	c = a-b;
	d= c*365;
	printf("que legal! voce tem %i anos e %i dias de vida.",c,d);
	getch();
	return 0;
	System("PAUSE");
}
