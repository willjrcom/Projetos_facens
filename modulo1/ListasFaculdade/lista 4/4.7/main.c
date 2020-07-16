#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	float teo,lab;
	int i,nf;
	
	for(i=1; i<=30; i++){
		printf("teorica: ");
		scanf("%f",&teo);
		
		printf("laboratorio: ");
		scanf("%f",&lab);
		
		nf = (lab*0.4)+(teo*0.6);
		if(nf>=7)printf("parabens\n\n");
		else if(5<=nf && 7>nf)printf("regular\n\n");
		else printf("voce foi mal\n\n");
	}
	getch();
	return 0;
}
