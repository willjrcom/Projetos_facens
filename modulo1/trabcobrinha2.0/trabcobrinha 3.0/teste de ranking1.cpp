#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<iostream>
#include<string.h>

int main (void){
	
	FILE *nm, *pt;
	char nomes[100];
	int pts[100], aux, x, y, i=0;
	
	nm = fopen("nomes.txt", "r");
	
	fclose(nm);
	
	pt = fopen("pontos.txt", "r");
	
	while(i<3)
	{
		fscanf(pt, "%d", pts[i]);
		i++;
	}
	fclose(pt);
	
	for(i=0; i<3; i++)
		printf("%d", pts[i]);
	
	return 0;
}
