#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
float celsius,fahrenheit;
printf("converter fahrenheit em ceusius.\n\nfahrenheit: ");
scanf("%f", &fahrenheit);

celsius  =  (fahrenheit -32)  /  1.8;
printf("\ncelsius: %.1f", celsius);
getch();
	return 0;
}
