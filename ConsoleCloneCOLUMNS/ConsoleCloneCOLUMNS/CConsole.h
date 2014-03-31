#include <Windows.h>

class CConsole{
private:
	HANDLE	hConsoleOutput;
public:
	void setCursorPosition(int, int);
	void setColor(WORD, WORD);
	CConsole();
	~CConsole();
};