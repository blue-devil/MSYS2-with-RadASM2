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
   | @date     : 14/10/2022                                               |
   | @license  : n/a                                                      |
   |______________________________________________________________________|
   |                                                                      |
   |          MINGW64 C Programming - BlueDeviL's Code Sniplets           |
   |                      Base DlgProc Code Sniplet                       |
   \______________________________________________________________________/
*/
#include <windows.h>
#include <commctrl.h>
#include "DialogWithManifestC.h"

INT_PTR DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            hIcon = LoadIcon(hInst, MAKEINTRESOURCE(5001));
            SendMessage(hDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            SetWindowText(hDlg, WindowName);
            return TRUE;
            
        case WM_COMMAND:
            
            break;
            
        case WM_CLOSE:
            EndDialog(hDlg, 0);
            break;
        default:
            return FALSE;
    }
    
    return TRUE;
}

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    hInst = hInstance;
    InitCommonControls();
    DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG), NULL, DlgProc, 0);
    
    return 0;
}
