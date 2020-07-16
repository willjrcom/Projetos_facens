#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int idade, sexo, p;
	float alt;
	printf("qual sua idade: ");
	scanf("%i",&idade);
	printf("altura: ");
	scanf("%f",&alt);
	
	
		if(idade>12 && idade <65){
			printf("(1) para masculino.\n(2) para feminino.\n:");
			scanf("%i",&sexo);
			
				if(sexo==1) {
					p =  (alt*72.7) - 62 ;
				}
				else if(sexo==0) {
					p = (62.1 * alt) - 48.7;
				}
			
				printf("seu peso ideal eh: %i",p);
				if(idade> 12 && idade <17) printf("\nAdolescente");
				if(idade> 18 && idade <25) printf("\nJovem");
				if(idade> 26 && idade <65) printf("\nAdulto");
		}
		else printf("proibido para menores de 12 anos");
		
	getch();
	return 0;
}
