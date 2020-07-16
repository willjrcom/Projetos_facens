//William Alfred Gazal Junior
//RA 180037

#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int dia,mes,ano;
	
	printf("Dia: ");
	scanf("%i",&dia);
	
	printf("\nMes: ");
	scanf("%i",&mes);
	
	printf("\nAno: ");
	scanf("%i",&ano);
	
	if(ano!=1994 || mes!=12 || dia<1 || dia>31) printf("Erro! Valores inicias incorretos.");
	
	else if((dia==30 || dia==11 || dia==12 || dia==14) && mes==12 && ano==1994 ) printf("Estudar.");
	
	else if(dia==30 && mes==11 && ano==1994) printf(" Estudar.");
	
	else if((dia==18 || dia==17) && mes==12 && ano==1994) {
		printf("estudar na sexta."); 
		
		else printf("livre");
	}
	
	return 0;
}
