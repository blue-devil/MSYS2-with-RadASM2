//_________________________________________________________________________
//constant variables

#define IDD_MAIN    1000
#define IDC_COLOR   1001
#define BTN_SELECT  1002
#define EDT_HUE     1004
#define EDT_SAT     1006
#define EDT_LUM     1008
#define EDT_RED     1013
#define EDT_GRE     1011
#define EDT_BLU     1009

// ChooseColor Dialog equates
// From ColorDlg.h
#define COLOR_HUE       703
#define COLOR_SAT       704
#define COLOR_LUM       705
#define COLOR_RED       706
#define COLOR_GRE       707
#define COLOR_BLU       708

//_________________________________________________________________________
//function prototypes

INT_PTR DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
UINT_PTR CCHookProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL doesFileExists(LPCTSTR szPath);
BOOL GetAppPath(LPSTR lpPathBuffer);

//_________________________________________________________________________
//initialized variables

const char WindowName[] =   "[SCT] Window Title";
const char szFile[] = "settings.ini";
const char szCustomColors[] = "Custom Colors";
const char szColors[] ="Colors";
const char szStartColor[] = "Start";
CHOOSECOLOR cc = {sizeof(cc),0,0,0,0,CC_FULLOPEN | CC_RGBINIT | CC_ENABLEHOOK, 0, &CCHookProc, NULL};
unsigned int DefColors[] = {0x00ff0000, 0x0000ff00, 0x000000ff, 0xffff0000, 0x0000ffff, 0x00cc0000, 0x0000cc00, 0x000000cc,0x00cccc00,0x0000cccc, 0x00800000, 0x00008000, 0x00000080, 0x00808000, 0x00008080, 0x00400000};
unsigned int ClrSize = (sizeof(ClrSize)/sizeof(unsigned int));

//_________________________________________________________________________
//uninitialized variables

HINSTANCE hInst;
HICON hIcon;
HANDLE hMain;
HANDLE hColorCtl;
HBRUSH hBrush;
unsigned long int MyColors[64];
char lpszFile[MAX_PATH + 1];
int arrayLength;