#include <stdio.h>
#include <stdlib.h>


struct composto
{
	char sigla; // [O]cupado
	int num; // número do quarto ou do registro do hóspede
};


union estado
{
	char sigla; // [L]ivre
	struct compostocampo;
};


struct hospede
{
	int numreg; // número do registro do hóspede
	char nome[80];
	int acompanhante; //quantidade de acompanhantes
	int dias; // tempo de permanência –em dias
	union estadotabela;
};


struct quarto
{
	int num; // número do quarto
	char categoria // [S]olteiro / [F]amiliar
	char status // [L]ivre / [O]cupado
	union estadostatus;
};


int main()
{
	
	return 0;
}
