#include <stdio.h>
#include <stdlib.h>

void teste(int **p)
{
	printf("%i", **p);
	printf("%i", *p);
	printf("%i", p);
	printf("%i", &p);
}


int main() 
{
	int **p = NULL;
	 
	**p = (int**)calloc(1, sizeof(int*));
	teste(p);
	
	return 0;
}
