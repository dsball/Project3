#include "uimanip.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_SCREEN_BUFFER_INFO initconfig;

HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
WORD   index   = 0;

void cInit()
{
	GetConsoleScreenBufferInfo( hstdout, &initconfig );
}

//Set console color()
void cSet(int myColor)
{
	SetConsoleTextAttribute( hstdout, myColor );
}

//Backup console attributes
void cBackup(int)
{
	GetConsoleScreenBufferInfo( hstdout, &csbi );
}

//restore console attributes to result of cBackup()
void cRestore()
{
	SetConsoleTextAttribute( hstdout, csbi.wAttributes );
}

//restores initial console settings
void cRestoreInit()
{
	SetConsoleTextAttribute( hstdout, initconfig.wAttributes );
}

void cGotoxy( int x, int y )
{
    COORD p = { x, y };
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), p );
}

