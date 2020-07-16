//William Alfred Gazal Junior
//RA: 180037

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int chakra,i;
	float orbe,t=0.01,raiofinal;
	

	printf("Calculo Chakra.\n\nRaio inicial do orbe: ");
	scanf("%f", &orbe);
	
	printf("\nPorcentagem do chakra: ");
	scanf("%i",&chakra);
	
		if((chakra<0 || chakra>100) ||orbe<0)printf("Erro! Valores inicias incorretos.");
		
		else{
			for(i=0;i<chakra;i++){
				
		
			orbe=(orbe+(orbe/100));
			}
			
			t=chakra*t;
			printf("%i\n",chakra);
			printf("\nRaio final do orbe: %f\n",orbe);
			printf("\nSegundos: %f",t);
		}
			
	
		
	
	return 0;
}
