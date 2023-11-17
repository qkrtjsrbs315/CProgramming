#include <windows.h>
#include <stdio.h>

#define HOTKEY_ID 1

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_HOTKEY:
        // ����Ű�� ������ �� ó���� �ڵ带 ���⿡ �߰�
        if (wParam == HOTKEY_ID) {
            MessageBox(NULL, TEXT("����Ű�� ���Ƚ��ϴ�!"), TEXT("�˸�"), MB_OK);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int main() {
    // ������ Ŭ���� ���
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("MyWindowClass");
    RegisterClass(&wc);

    // ������ ����
    HWND hwnd = CreateWindowEx(0, TEXT("MyWindowClass"), NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
    ShowWindow(hwnd, SW_HIDE);  // �����츦 ����

    // ����Ű ���
    if (RegisterHotKey(hwnd, HOTKEY_ID, MOD_CONTROL | MOD_SHIFT, 'A')) {
        printf("����Ű Ctrl + Shift + A �� ��ϵǾ����ϴ�. ���α׷��� ������ ���¿��� �׽�Ʈ�غ�����.\n");
    }
    else {
        printf("����Ű ��Ͽ� �����߽��ϴ�.\n");
    }

    // �޽��� ���� ����
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // ����Ű ����
    UnregisterHotKey(hwnd, HOTKEY_ID);
     
    return 0;
}
