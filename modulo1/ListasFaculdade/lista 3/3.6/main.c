#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a,b,c;
	char s;
	printf("calculadora.\n");
	scanf("%i %i %c",&a,&b,&s);
	
	switch(s)
	{
	case '+': 
	c=a+b;
	printf("%i",c);
	break;
	
	case'-': 
	c=a-b;
	printf("%i",c);
	break;
	
	
	}
	return 0;
}
