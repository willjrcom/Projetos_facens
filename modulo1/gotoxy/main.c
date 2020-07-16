#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x, int y)
{
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

int main() 
{
	system("color f1");
	gotoxy(50,10);
 	printf("Bem Vindo");
 	getch();
 	return 0;
}
