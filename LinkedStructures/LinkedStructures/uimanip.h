#ifndef _UIMANIP_INTERFACE_
#define _UIMANIP_INTERFACE_

#include "utility.h"

void cInit();
void cSet(int myColor);
void cBackup(int);
void cRestore();
void cRestoreInit();

void cGotoxy( int x, int y );
#endif