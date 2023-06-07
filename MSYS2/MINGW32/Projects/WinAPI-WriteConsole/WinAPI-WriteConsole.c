#include <stdio.h>
#include <windows.h>

int main(void)
{
    const char * msg = "[*] Pentagram - Lions in cage";
    HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdOut != NULL && stdOut != INVALID_HANDLE_VALUE)
    {
        DWORD written = 0;
        WriteConsoleA(stdOut, msg, strlen(msg), &written, NULL);
    }
    
    return 0;
}