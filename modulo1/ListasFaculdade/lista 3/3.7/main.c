#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	
	printf("medidas do triangulo\n");
	scanf("%i %i %i",&a,&b,&c);
	
	if (a==b && b==c)printf("triangulo equilatero.");
	else if ((a==b&&b!=c)||(b==c&&c!=a)||(c==a&&a!=b))printf("triangulo isosceles.");
	else if(a!=b && b!=c && c!=a) printf("triangulo escaleno");
	
	getch();
	return 0;
}
