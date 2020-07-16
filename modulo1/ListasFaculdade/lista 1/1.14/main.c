#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	float m1 ,m2 ,m3 ,inst ,final , finalsub ;
	
	printf("calcular media da prova\n\nnota m1: ");
	scanf("%f", &m1);
	
	while ( m1<0 || m1>10){
		
		printf("Digite um valor entre 0 e 10.\n");
		scanf("%f", &m1);
	}
	
	
	printf("nota m2: ");
	scanf("%f", &m2);
	
	while ( m2<0 || m2>10){
		
		printf("Digite um valor entre 0 e 10.\n");
		scanf("%f", &m2);
	}
	
	printf("institucional: ");
	scanf("%f",&inst);
	
	while ( inst<0 || inst>1){
		
		printf("Digite um valor entre 0 e 1.\n");
		scanf("%f", &inst);
	}
	
	final = (m1*0.45)+(m2*0.45f)+inst ;
	
	printf("\nSua nota final e: %.2f\n\n", final);
	
	
	
	
	
	
	
	
	
		if(final<=5){
	
		printf("parabens! Voce foi reprovado\n\n");
		
					if( 2.5 <= final && 4.9 >= final ){
					
					printf("Prova sub: ");
					scanf("%f", &m3);
							
							
							if(m1<m2){
								
								finalsub = ( m3 * 0.45 ) + ( m2 * 0.45 )+inst ;
								
									printf("\nSua nota e: %.2f", finalsub );
					
					
					
									if(finalsub<5){
										printf("\nReprovado");
									}
									
										
									else{
										printf("\nagora sim voce passou de ano");
									}
							}
									
									
									
							else{
								finalsub = ( m3 * 0.45 ) + ( m1 * 0.45 )+inst ;
								
									printf("\nSua nota e: %.2f", finalsub );
					
					
					
									if(finalsub<5){
										printf("\nReprovado");
									}	
									
									
									else{
										printf("\nagora sim voce passou de ano");
									}
					
				
						}
					}
		
		
		
		
		}else{
			printf("parabens! voce passou de ano");
		}
	
	getch();
	return 0;
}
