#include <Windows.h>
#include <wchar.h>

#define BUF_SIZE 255

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

__declspec(dllexport) VOID test_func(VOID)
{
    const WCHAR formatstring[] = L"Shellcode injected into process: %d\n";
    WCHAR buf[BUF_SIZE] = {0};

    DWORD dwProcessId = GetCurrentProcessId();

    _snwprintf(buf, BUF_SIZE, formatstring, dwProcessId);

    MessageBoxW(NULL, buf, L"Shellcode", MB_OK);
    return;
}