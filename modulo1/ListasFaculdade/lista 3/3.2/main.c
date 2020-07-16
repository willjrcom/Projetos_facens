#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i1,i2,n;
	printf("intervalo x1 a x2 e numero:\n");
	scanf("%i %i %i",&i1,&i2,&n);
	
	if(i1<=n && i2>=n){
		if(i1==n || i2==n)printf("extremidade");
		
		if(i1<n && i2>n)printf("esta dentro");
	}else printf("esta fora");
	
	getch();
	return 0;
}
