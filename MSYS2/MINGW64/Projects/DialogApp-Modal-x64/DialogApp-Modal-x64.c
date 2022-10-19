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
   | @date     : 26/08/2022                                               |
   | @license  : n/a                                                      |
   |______________________________________________________________________|
   |                                                                      |
   |                Blue DeviL's Win64 MINGW64 C Templates                |
   |                      Modal Dialog App Template                       |
   \______________________________________________________________________/
*/
#include <windows.h>

#define IDD_DIALOG  1000

const char ClassName[]  =   "SimpleWin64Class";
const char AppName[]    =   "Our First Window";


LRESULT CALLBACK
DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            
            return TRUE;
        case WM_COMMAND:
            
            break;
        case WM_CLOSE:
            EndDialog(hWnd,0);
            break;
        default:
            break;
    }
    
    return FALSE;
}

int WINAPI

WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    DialogBoxParam(hInstance,MAKEINTRESOURCE(IDD_DIALOG),0,(DLGPROC)DlgProc,0);
    ExitProcess(0);
    
    return 0;
}
