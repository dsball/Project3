#ifndef _UIMANIP_INTERFACE_
#define _UIMANIP_INTERFACE_

#include "utility.h"

CONSOLE_SCREEN_BUFFER_INFO csbi;
CONSOLE_SCREEN_BUFFER_INFO initconfig;

const WORD colors[] = 
{
	0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
};

enum color {A,B,C,D,E,F,G,H,I,J,K,L};

//code I only sort of understand ... a handle is a pointer to an object?
HANDLE hstdin  = GetStdHandle( STD_INPUT_HANDLE  );
HANDLE hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
WORD   index   = 0;

//sets initial console config
void cInit()
{
	GetConsoleScreenBufferInfo( hstdout, &initconfig );
}

//Set console color()
void cSet(WORD myColor)
{
	SetConsoleTextAttribute( hstdout, colors[ myColor ] );
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

#endif