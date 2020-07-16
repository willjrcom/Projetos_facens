#include <stdio.h>
#include <stdlib.h>


struct composto
{
	char sigla; // [O]cupado
	int num; // n�mero do quarto ou do registro do h�spede
};


union estado
{
	char sigla; // [L]ivre
	struct compostocampo;
};


struct hospede
{
	int numreg; // n�mero do registro do h�spede
	char nome[80];
	int acompanhante; //quantidade de acompanhantes
	int dias; // tempo de perman�ncia �em dias
	union estadotabela;
};


struct quarto
{
	int num; // n�mero do quarto
	char categoria // [S]olteiro / [F]amiliar
	char status // [L]ivre / [O]cupado
	union estadostatus;
};


int main()
{
	
	return 0;
}
