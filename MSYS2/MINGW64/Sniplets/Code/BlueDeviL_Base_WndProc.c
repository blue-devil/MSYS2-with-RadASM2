/*  ______________________________________________________________________
   |  ______ __          ,.'   __.'.__  .   ______               ___      |
   | |      |  |         /b`  '-.   .-'  d\|      ;             |   |     |
   | |   __ |  |        .5h     /.'.\    =5|   _   \            |   |     |
   | |.  1 \|  |        (0=h    '   '    =C)   1\   \        .--:.  |     |
   | |   1_/|  |        ?3==,          .==7|   | \   \       |__|   |     |
   | |.     | .-- -.-----{=`==oo____oo==`=}|   |  |.----.-- -.--:.  |     |
   | |.  __ | |  V |  ^__|'"o58888888888,; |.  |  ||  ^_|  V |  |.  |     |
   | |:  1 \|_|____|_____| `?88P^\,?88^\P  |.  | / |____|\___|__|:  |___  |
   | |:  1_/   /            C8?\__d88\_/'  |:  1/   / .         |:  1   | |
   | |::.. .  /             `8o8888/\88P   |::.. . /            |::.. . | |
   | `-------'               '7oo88oo8P    `------'             `-------' |
   |                     Cooo##~\/\/\/~====>        github.com/blue-devil |
   |                                                 gitlab.com/bluedevil |
   | Freedom doesn't come from second-hand thoughts.      www.sctzine.com |
   |______________________________________________________________________|
   | @author   : Blue DeviL <bluedevil@sctzine.com>                       |
   | @tester   : ErrorInside <errorinside@sctzine.com>                    |
   | @IDE      : RadASM v2.2.2.4                                          |
   | @template : Blue DeviL                                               |
   | @date     : 09/09/2022                                               |
   | @license  : n/a                                                      |
   |______________________________________________________________________|
   |                                                                      |
   |          MINGW64 C Programming - BlueDeviL's Code Sniplets           |
   |                      Base WndProc Code Sniplet                       |
   \______________________________________________________________________/
*/
#include <windows.h>

const char ClassName[]  =   "BaseWin64Class";
const char WindowName[] =   "[SCT] Window Title";


LRESULT CALLBACK
WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd,uMsg,wParam,lParam);
    }
    
    return 0;
}

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wcex;
    HWND hWnd;
    MSG msg;
    
    wcex.cbSize         = sizeof(WNDCLASSEX);
    wcex.style          = 0;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = ClassName;
    wcex.hIconSm        = LoadIcon(NULL, IDI_APPLICATION);
    
    if(!RegisterClassEx(&wcex))
    {
        const char lpMessage[] = "Window Registration Failed!";
        const char lpCaption[] = "[SCT] Error!";
        MessageBox(NULL, lpMessage, lpCaption,MB_OK | MB_ICONEXCLAMATION);
        return 0;
    }
    
    hWnd = CreateWindowEx(
            WS_EX_CLIENTEDGE, \
            ClassName, \
            WindowName, \
            WS_OVERLAPPEDWINDOW, \
            CW_USEDEFAULT, \
            CW_USEDEFAULT, \
            CW_USEDEFAULT, \
            CW_USEDEFAULT, \
            NULL, \
            NULL, \
            hInstance, \
            NULL);
    if(hWnd == NULL)
    {
        const char lpMessage[] = "Window Creation Failed!";
        const char lpCaption[] = "[SCT] Error!";
        MessageBox(NULL, lpMessage, lpCaption,MB_OK | MB_ICONEXCLAMATION);
        return 0;
    }
    
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    
    while(GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}
