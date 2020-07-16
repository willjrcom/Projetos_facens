#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	float a,b,c;
	printf("calcule a media\n\nmedia 1: ");
	scanf("%f.",&a);
	
	printf("media 2: ");
	scanf("%f.",&b);
	
	c=(a+b)/2;
	
	printf("\na media e: %.1f",c);
	
	getch();
	return 0;

}
