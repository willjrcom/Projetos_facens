#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, t = 10, n;
	
	scanf("%i", &n);
	for(i = 0; i < t; i++)
	{
		for(j = 0; j < t; j++)
		{
			printf("%k", n);
		}
	}
	
	return 0;
}
