#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


void alocarChar( char **texto, int t)
{
	if((*texto = (char*) realloc(*texto, t * sizeof(char))) == NULL)
		exit(1);
}


void diretorios(char meuDir, char *diretorio)
{
	 DIR *dp;
    struct dirent *d;
    
    dp = opendir( diretorio );
    
    while ( ( d = readdir( dp ) ) != NULL )
       printf( "%s\n", d->d_name );

    closedir( dp );
}


int main()
{
	char *diretorio = NULL;
	char auxDir[30] = "C:\\", meuDir[30];
	int t = 4;
	
	alocarChar(&diretorio, t);
	strcpy(diretorio, auxDir);
	
	diretorios(meuDir, diretorio);
	
    printf("\n\nMeu diretorio: %s\nBuscar diretorio: ", diretorio);
	gets(meuDir);
	fflush(stdin);
    
    diretorios(meuDir, auxDir);
    
    getch();
    return 0;
}
