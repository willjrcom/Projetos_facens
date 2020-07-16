#include <stdio.h>
#include <stdlib.h>

int main() {
	
	char dia[10], mes[10], ano[10];
	
	
	scanf("%s",&dia);
	scanf("%s",&mes);
	scanf("%s",&ano);
	
	strcat(dia,"_");
	
	strcat(dia,mes);
	strcat(dia,"_");
	
	strcat(dia,ano);
	strcat(dia,".txt");
	
	FILE* file;
	file=fopen(dia,"w");
	fprintf(file,"oi");
	fclose(file);
	return 0;
}
