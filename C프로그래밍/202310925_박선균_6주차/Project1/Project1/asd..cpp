#include <windows.h>
#include <stdio.h>

#define HOTKEY_ID 1

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_HOTKEY:
        // 단축키가 눌렸을 때 처리할 코드를 여기에 추가
        if (wParam == HOTKEY_ID) {
            MessageBox(NULL, TEXT("단축키가 눌렸습니다!"), TEXT("알림"), MB_OK);
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
    // 윈도우 클래스 등록
    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = TEXT("MyWindowClass");
    RegisterClass(&wc);

    // 윈도우 생성
    HWND hwnd = CreateWindowEx(0, TEXT("MyWindowClass"), NULL, 0, 0, 0, 0, 0, HWND_MESSAGE, NULL, NULL, NULL);
    ShowWindow(hwnd, SW_HIDE);  // 윈도우를 숨김

    // 단축키 등록
    if (RegisterHotKey(hwnd, HOTKEY_ID, MOD_CONTROL | MOD_SHIFT, 'A')) {
        printf("단축키 Ctrl + Shift + A 가 등록되었습니다. 프로그램을 실행한 상태에서 테스트해보세요.\n");
    }
    else {
        printf("단축키 등록에 실패했습니다.\n");
    }

    // 메시지 루프 시작
    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // 단축키 해제
    UnregisterHotKey(hwnd, HOTKEY_ID);
     
    return 0;
}
