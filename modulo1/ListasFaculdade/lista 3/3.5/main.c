#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int a,b,c;
	
	printf("numero maior.\n");
	scanf("%i %i %i",&a,&b,&c);
	
	if(a>b && a>c)printf("%i eh o maior",a);
	else if (b>a && b>c)printf("%i eh o maior",b);
	else printf("%i eh o maior",c);
	
	getch();
	return 0;
}
