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
//�Զ���Ĵ��ڹ���
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

    // ����������
    WNDCLASS wnd = {
        CS_HREDRAW,
        MyWindowProc,          // ʹ���Զ���Ĵ��ڹ��̺���
        0,0,hInstance,
        LoadIcon(NULL,IDI_APPLICATION),
        LoadCursor(NULL,IDC_ARROW),
        (HBRUSH)(GetStockObject(WHITE_BRUSH)),
        NULL, L"MyWindow"
    };
    // ע�ᴰ����
    RegisterClass(&wnd);
    // ��������
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

    // ���´���
    UpdateWindow(hWnd);
    //��Ϣѭ��
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {    // ѭ����ȡ��Ϣ
        TranslateMessage(&msg);               // ������Ϣ
        DispatchMessage(&msg);                // �ɷ���Ϣ
    }
    return 0;
}

#endif