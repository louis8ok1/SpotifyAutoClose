//=======================================
//File name: Spotify_auto_closed.exe
//
//Author: Louis Chen
//
//=======================================
#include <windows.h>
#include <stdio.h>
#include <tlhelp32.h>
//========================================
// 1. Using CreateToolhelp32SnapShot function to get all processes.
// 2. Setting related struct size.
// 3. Using Process32First to get first process(module,thread).
// 4. Using Process32Next to get next process(module,thread).
//========================================
int main()
{
    HANDLE hProcessSnap;
    // 1. Using CreateToolhelp32SnapShot function to get all processes.
    hProcessSnap = CreateToolhelp32Snapshot( TH32CS_SNAPPROCESS, 0 );
    if( hProcessSnap == INVALID_HANDLE_VALUE ) {
        printf("Create snapshot fail.....\n");
        return EXIT_FAILURE;
    }

    PROCESSENTRY32 pe32;
    // 2. Setting related struct size.
    pe32.dwSize = sizeof( PROCESSENTRY32 );
    // 3. Using Process32First confirm whether get process correctly.
    if( !Process32First( hProcessSnap, &pe32 ) )  {
        printf("Get process fail....\n");
        CloseHandle( hProcessSnap );
        return EXIT_FAILURE;
    }
    //4. Using while loop to find Soptify.exe , and Kill them.
    while(Process32Next( hProcessSnap, &pe32 )){

        if(!stricmp("Spotify.exe",pe32.szExeFile)){
            // find excel.exe, kill it.
            HANDLE hProcess;
            hProcess = OpenProcess( PROCESS_ALL_ACCESS,
                                    FALSE,
                                    pe32.th32ProcessID );
            if( hProcess == NULL ) printf("Open process fail.\n");
            TerminateProcess(hProcess,0);
            WaitForSingleObject(hProcess,INFINITE);
            CloseHandle( hProcess );

            break; // after close, then break
        }
    }
    CloseHandle( hProcessSnap );
    return EXIT_SUCCESS;
}
