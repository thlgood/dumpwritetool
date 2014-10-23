#include "stdafx.h"
#include <Windows.h>
#include <atlstr.h>
#include <DbgHelp.h>

#pragma comment(lib, "Dbghelp")

CString GetDumpFileName()
{
    TCHAR szExePath[MAX_PATH * 2 + 1] = {0};
    if (!::GetModuleFileName(NULL, szExePath, MAX_PATH * 2))
    {
        return L"";
    }

    CString strFileName = ::PathFindFileName(szExePath);
    if (strFileName.IsEmpty())
    {
        return L"";
    }

    DWORD dwPid = GetCurrentProcessId();
    strFileName.AppendFormat(L".%d.dmp", dwPid);
    return strFileName;
}

void WriteMiniDumpFile(struct _EXCEPTION_POINTERS* ExceptionInfo)
{
    if (ExceptionInfo == NULL)
    {
        return;
    }
    CString strDumpFilePath = GetDumpFileName();
    if (strDumpFilePath.IsEmpty())
    {
        return;
    }


    HANDLE hfile = CreateFile(strDumpFilePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (INVALID_HANDLE_VALUE == hfile)
    {
        return;
    }

    MINIDUMP_EXCEPTION_INFORMATION dumpInfo = {0};
    dumpInfo.ExceptionPointers = ExceptionInfo;
    dumpInfo.ClientPointers = TRUE;
    dumpInfo.ThreadId = GetCurrentThreadId();

    MiniDumpWriteDump(GetCurrentProcess(),
        GetCurrentProcessId(),
        hfile,
        MiniDumpWithFullMemory,
        &dumpInfo,
        NULL,
        NULL);

    if (hfile != INVALID_HANDLE_VALUE)
    {
        CloseHandle(hfile);
    }
}

LONG WINAPI ExceptionHandle(struct _EXCEPTION_POINTERS* ExceptionInfo)
{
    if (NULL == ExceptionInfo)
    {
        return EXCEPTION_CONTINUE_SEARCH;
    }
    WriteMiniDumpFile(ExceptionInfo);
    return EXCEPTION_EXECUTE_HANDLER;
}

extern "C" __declspec(dllexport) void SetDumpHandler()
{
    SetErrorMode(SEM_NOOPENFILEERRORBOX);
    SetUnhandledExceptionFilter(ExceptionHandle);
}