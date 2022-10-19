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
   | @license  : GPLv3                                                    |
   |______________________________________________________________________|
   |                                                                      |
   |          MINGW64 C Programming - BlueDeviL's Code Sniplets           |
   |                    Base ColorChoose Code Sniplet                     |
   \______________________________________________________________________/
*/
#include <windows.h>
#include <commctrl.h>
#include <shlwapi.h>
#include "ColorChoose.h"

INT_PTR DlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_INITDIALOG:
            hMain = hDlg;
            
            hIcon = LoadIcon(hInst, MAKEINTRESOURCE(5001));
            SendMessage(hDlg, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
            SetWindowText(hDlg, WindowName);
            
            hColorCtl = GetDlgItem(hDlg, IDC_COLOR);
            if (doesFileExists(lpszFile))
            {
                arrayLength = sizeof(MyColors) / sizeof(MyColors[0]);
                GetPrivateProfileStruct(szCustomColors, szColors, MyColors, arrayLength, lpszFile);
                GetPrivateProfileStruct(szCustomColors, szStartColor, &cc.rgbResult, sizeof(cc.rgbResult), lpszFile);
            }
            
            return TRUE;
            
        case WM_COMMAND:
            if (HIWORD(wParam)==BN_CLICKED)
            {
                if (LOWORD(wParam)==BTN_SELECT)
                {
                    cc.hInstance = (HWND)hInst;
                    cc.hwndOwner = hDlg;
                    cc.lpCustColors = MyColors;
                    if(ChooseColor(&cc))
                    {
                        DeleteObject(hBrush);
                        hBrush = CreateSolidBrush(cc.rgbResult);
                        InvalidateRect(hColorCtl, NULL, TRUE);
                    }
                    
                }
            }
            break;
            
        case WM_CTLCOLORSTATIC:
            if(lParam==(LPARAM)hColorCtl)
            {
                return (INT_PTR)hBrush;
            }
            return FALSE;
            
        case WM_CLOSE:
            arrayLength = sizeof(MyColors) / sizeof(MyColors[0]);
            WritePrivateProfileStruct(szCustomColors, szColors, MyColors, arrayLength, lpszFile);
            WritePrivateProfileStruct(szCustomColors, szStartColor, &cc.rgbResult, sizeof(cc.rgbResult), lpszFile);
            DeleteObject(hBrush);
            
            EndDialog(hDlg, 0);
            break;
        default:
            return FALSE;
    }
    
    return TRUE;
}

UINT_PTR
CCHookProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    UINT rv = 0;
    switch(uMsg)
    {
        case WM_COMMAND:
            if (HIWORD(wParam)==BN_CLICKED)
            {
                if (LOWORD(wParam)==IDOK)
                {
                    rv = GetDlgItemInt(hDlg, COLOR_HUE, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_HUE, rv, FALSE);
                    
                    rv = GetDlgItemInt(hDlg, COLOR_SAT, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_SAT, rv, FALSE);
                    
                    rv = GetDlgItemInt(hDlg, COLOR_LUM, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_LUM, rv, FALSE);
                    
                    rv = GetDlgItemInt(hDlg, COLOR_RED, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_RED, rv, FALSE);
                    
                    rv = GetDlgItemInt(hDlg, COLOR_GRE, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_GRE, rv, FALSE);
                    
                    rv = GetDlgItemInt(hDlg, COLOR_BLU, NULL, FALSE);
                    SetDlgItemInt(hMain, EDT_BLU, rv, FALSE);
                }
            }
            break;
    }
    
    return FALSE;
}

BOOL
GetAppPath(LPSTR lpPathBuffer)
{
    GetModuleFileName(NULL, lpPathBuffer, MAX_PATH);
    if(PathRemoveFileSpec(lpPathBuffer)==0)
    {
        MessageBox(NULL, "[-] ERROR: PathRemoveFileSpec", WindowName, MB_OK);
        return FALSE;
    }
    
    return TRUE;
}

BOOL
doesFileExists(LPCTSTR szPath)
{
  DWORD dwAttrib = GetFileAttributes(szPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
         !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    hInst = hInstance;
    
    GetAppPath(lpszFile);
    strcat(lpszFile, "\\");
    strcat(lpszFile, szFile);
    
    InitCommonControls();
    DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_MAIN), NULL, DlgProc, 0);
    
    return 0;
}