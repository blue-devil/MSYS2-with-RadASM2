#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static char *title = TEXT("Check Box");

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG  msg ;
    WNDCLASS wc = {0};
    wc.lpszClassName = TEXT( "Check Box" );
    wc.hInstance     = hInstance ;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc ;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClass(&wc);
    CreateWindow(
            wc.lpszClassName,
            title,
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            150, 150, 230, 150, 0, 0,
            hInstance,
            0);

    while(GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)  
    {
        case WM_CREATE:
        {
            CreateWindow(
                    TEXT("button"),
                    TEXT("Show Title"),
                    WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                    20, 20, 185, 35,
                    hwnd,
                    (HMENU) 1,
                    ((LPCREATESTRUCT)lParam)->hInstance,
                    NULL
            );
            CheckDlgButton(hwnd, 1, BST_CHECKED);
            break;
        }
    
        case WM_COMMAND:
        {
            BOOL checked = IsDlgButtonChecked(hwnd, 1);
            if (checked) {
                CheckDlgButton(hwnd, 1, BST_UNCHECKED);
                SetWindowText(hwnd, TEXT(""));
            } else {
                CheckDlgButton(hwnd, 1, BST_CHECKED);
                SetWindowText(hwnd, title);
            }
            break;
        }
    
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            break;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}