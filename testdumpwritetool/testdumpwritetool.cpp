// testdumpwritetool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <locale.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include "../initialdump.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "chs");

    InitialDump();

    int a = 0x10000;
    while (a++)
    {
        char* ptr = (char*)a;
        strcpy_s(ptr, a, "crash please");
    }
	return 0;
}

