#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	float pe,al,imc;
	
	printf("peso: ");
	scanf("%f",&pe);
	
	printf("altura: ");
	scanf("%f",&al);
	
	imc = pe/(al*al);
	
	if(imc<18.5){
		printf("abaixo do peso, %f", imc);
	}
	else{
		if(imc>18.5 && imc<25)     printf("Saudável, %f",imc);
		else if (imc>=25 && imc<30)printf("Sobrepeso, %f", imc);
		else if (imc>=30 && imc<35)printf("Obesidade Grau I, %f ", imc);
		else if (imc>=35 && imc<40)printf("Obesidade Grau II (severa), %f", imc);
		else printf("Obesidade Grau III (mórbida), %f",imc);
	}
	getch();
	return 0;
}
