#include <Windows.h>
#pragma once

typedef void (*pInitialDumpTool)();

BOOL inline InitialDump(LPCTSTR lpDumpDllPath = L"dumpwritetool.dll")
{
    HMODULE hmodule = ::LoadLibrary(lpDumpDllPath);
    if (NULL == hmodule)
    {
        return FALSE;
    }

    pInitialDumpTool func = (pInitialDumpTool)::GetProcAddress(hmodule, "InitialDumpTool");
    if (func != NULL)
    {
        func();
        return TRUE;
    }

    return FALSE;
}