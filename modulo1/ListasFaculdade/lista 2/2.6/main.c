#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b;
	printf("ordem crescente\n");
	scanf("%i %i",&a,&b);
	
	if(a>b)printf("%i %i",b,a);
	if(b>a)printf("%i %i",a,b);	
	getch();
	return 0;
}
