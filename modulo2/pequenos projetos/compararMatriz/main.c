#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int a[3][3],i,j;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("\ndigite os valores de : %i %i\n",i,j);
			scanf("%i", &a[i][j]);	
		}	
	}
	if(a[0][0]==a[1][1]==a[2][2])
	{
		printf("elementos iguais");
	}
	return 0;
}
