#include "CConsole.h"


CConsole::CConsole(){
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
}
CConsole::~CConsole(){
	CloseHandle(hConsoleOutput);
}
void CConsole::setCursorPosition(int shXPos, int shYPos){

	COORD coord;
	coord.X = shXPos;
	coord.Y = shYPos;
	SetConsoleCursorPosition(hConsoleOutput, coord);
}


void CConsole::setColor(WORD wFore, WORD wBack){

	SetConsoleTextAttribute(hConsoleOutput, wFore | wBack);
}