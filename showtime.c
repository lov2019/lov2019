// 时间实时显示程序-by 港南二中2322班懂哥
#include <windows.h>
#include <time.h>
#include <stdio.h>

#define IDT_TIMER1 1001

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI UpdateTimeThread(LPVOID lpParam);

HWND hwnd;
HFONT hFont;
char buffer[30];

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	FreeConsole();
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "MyWindowClass";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    strcpy(buffer, "Loading...");
    if (!RegisterClass(&wc)) {
        MessageBox(NULL, "注册窗口类失败", "错误", MB_OK | MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(
        "MyWindowClass",
        "当前时间",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        400,
        200,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hwnd) {
        MessageBox(NULL, "创建窗口失败", "错误", MB_OK | MB_ICONERROR);
        return 0;
    }

    // 创建字体
    hFont = CreateFont(
        36,
        0,
        0,
        0,
        FW_NORMAL,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_DEFAULT_PRECIS,
        CLIP_DEFAULT_PRECIS,
        DEFAULT_QUALITY,
        DEFAULT_PITCH | FF_SWISS,
        "Arial"
    );

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // 创建线程用于更新时间
    CreateThread(
        NULL,
        0,
        UpdateTimeThread,
        NULL,
        0,
        NULL
    );

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    DeleteObject(hFont);
    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	//printf("hwnd=%d message=%s wParam=%s lParam=%s\n", hWnd, message, wParam, lParam);
    switch (message) {
        case WM_PAINT: {
        	//printf(".\n");
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // 设置字体
            SelectObject(hdc, hFont);
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0, 0, 0));

            // 获取窗口客户区尺寸
            RECT rect;
            GetClientRect(hWnd, &rect);

            // 显示时间文本（居中）
            DrawText(hdc, buffer, -1, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

            EndPaint(hWnd, &ps);
            break;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 线程函数：定时更新时间
DWORD WINAPI UpdateTimeThread(LPVOID lpParam) {
	//printf("Thread started\n");
    while (1) {
        time_t rawtime;
        struct tm *timeinfo;
        //char buffer[80];

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
        //printf("buffer=%s\n", buffer);
        // 发送自定义消息或直接调用 InvalidateRect 强制重绘
        InvalidateRect(hwnd, NULL, TRUE);
        //UpdateWindow(hwnd);

        Sleep(100); // 每0.1秒刷新一次
    }
    return 0;
}
