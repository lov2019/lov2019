#include <windows.h>
#ifndef IDC_STATIC
#define IDC_STATIC (-1)
#endif

#define IDD_MAIN_DIALOG                         101

HINSTANCE hInst;

LRESULT MainDlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	HWND hMainDlg = NULL;

	hInst = hInstance;
	hMainDlg = CreateDialog(hInstance, (LPCTSTR)IDD_MAIN_DIALOG, 0,(DLGPROC)MainDlgProc);
	ShowWindow(hMainDlg, nCmdShow);
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT MainDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
		case WM_INITDIALOG :
			return TRUE ;
		case WM_COMMAND :
			switch (LOWORD (wParam)) {
				case IDOK :
				case IDCANCEL :
					DestroyWindow(hDlg);
					return TRUE ;
			}
			break ;
		case WM_CLOSE:
			DestroyWindow(hDlg);
			return TRUE;
		case WM_DESTROY:
			PostQuitMessage(0);
			return TRUE;
	};
	return FALSE;//返回FALSE给缺省对话框函数DefDlgProc(),表示没有处理本消息
}
