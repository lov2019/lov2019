/*港南二中2322班懂哥编写*/
#include <windows.h>
LRESULT CALLBACK WndProc(HWND hwnd,UINT Message,WPARAM wParam,LPARAM lParam){
	switch(Message){
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;
	memset(&wc,0,sizeof(wc));
	wc.cbSize=sizeof(WNDCLASSEX);
	wc.lpfnWndProc=WndProc;
	wc.hInstance=hInstance;
	wc.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName="WindowClass";
	wc.hIcon=LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm=LoadIcon(NULL, IDI_APPLICATION);
	if(!RegisterClassEx(&wc)){
		MessageBox(NULL,"Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	hwnd=CreateWindowEx(
        WS_EX_CLIENTEDGE,
        "WindowClass",
        "Caption",
        WS_VISIBLE|WS_OVERLAPPEDWINDOW,
	    CW_USEDEFAULT,
	    CW_USEDEFAULT,
	    640,
	    480,
	    NULL,
        NULL,
        hInstance,
        NULL
	);
	if(!hwnd){
		MessageBox(NULL,"Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
    while(GetMessage(&Msg,NULL,0,0)>0){
	    TranslateMessage(&Msg);
        DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
