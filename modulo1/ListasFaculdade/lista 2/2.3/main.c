#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,d,r;
	printf("numerador: ");
	scanf("%i",&n);
	
	printf("denominador: ");
	scanf("%i",&d);
	
	if(d==0) {
	printf("nao existe divisao por zero");
	}
	
	if(d!=0){
	r=n/d;
	printf("%i",r);
	}
	
	getch();
	
	return 0;
}
