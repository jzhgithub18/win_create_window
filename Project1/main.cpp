#include<Windows.h>
#include <WinUser.h>
#include <stdio.h>
//int main(void) {
//    HINSTANCE hInstance = GetModuleHandleW(NULL);
//
//    HWND handle = ::CreateWindowW(L"testpainter", L"testpainter", WS_CLIPCHILDREN,
//        0, 0,
//        320, 240,
//        nullptr, NULL, hInstance, NULL);
//
//    return 0;
//}
#if 1
//自定义的窗口过程
LRESULT CALLBACK MyWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
    switch (Msg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, Msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR ICmdLine, int nCmdShow) {

    // 创建窗口类
    WNDCLASS wnd = {
        CS_HREDRAW,
        MyWindowProc,          // 使用自定义的窗口过程函数
        0,0,hInstance,
        LoadIcon(NULL,IDI_APPLICATION),
        LoadCursor(NULL,IDC_ARROW),
        (HBRUSH)(GetStockObject(WHITE_BRUSH)),
        NULL, L"MyWindow"
    };
    // 注册窗口类
    RegisterClass(&wnd);
    // 创建窗口
    HWND hWnd = CreateWindow(L"MyWindow", L"newWindow", WS_SIZEBOX | WS_POPUP | WS_MAXIMIZE| WS_CHILD,
        0, 0, 1280, 720, NULL, NULL, hInstance, NULL);
    //FindWindowde
    
    fprintf(stderr, "-----------------%x", hWnd);
    fflush(stderr);

    HWND parent = (HWND)0x000a0e3a;
    ////auto ret = ::SetWindowLong(parent, GWL_STYLE, GetWindowLong(parent, GWL_STYLE) & ~WS_POPUP);
  /*   ret = ::SetWindowLong(parent, GWL_STYLE, GetWindowLong(parent, GWL_STYLE)
        | WS_CHILD);
    ::SetWindowPos(parent, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_FRAMECHANGED);*/

    auto newhandle = SetParent(hWnd, parent);
    ShowWindow(hWnd, nCmdShow);

   /* HWND hWnd2 = CreateWindow(L"MyWindow", L"newWindow",WS_MAXIMIZE ,
        0, 200, 1280, 720, NULL, NULL, hInstance, NULL);
    ShowWindow(hWnd2, nCmdShow);*/

    //ret = ::SetWindowLong(parent, GWL_HWNDPARENT, (long)hWnd);
   bool ret = ::SetWindowPos(hWnd, HWND_TOP, 0, 100, 500, 500, SWP_SHOWWINDOW);
  //ret = MoveWindow(hWnd, 0, 100, 500, 500, true);

    // 更新窗口
    UpdateWindow(hWnd);
    //消息循环
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {    // 循环获取消息
        TranslateMessage(&msg);               // 翻译消息
        DispatchMessage(&msg);                // 派发消息
    }
    return 0;
}

#endif