#include <stdio.h>
#include <conio.h>

int ordenador(int vetor[z]){//lembra de trocar Z pelo tamanho do seu vetor
	
	int i , aux, vetor[z]={0}, x, y;
	
	for(i=0;i<z;i++){
		
		printf("digite: ");
		scanf("%d \n", &vetor[i]);
		
	}
	
	for(x=0;x<z;x++){
		for(y=x;y<z;y++){
			if(vetor[x]<vetor[y]){
				aux=vetor[x];
				vetor[x]=vetor[y];
				vetor[y]=aux;
			}
		}
	}
	
	return 0;
}
