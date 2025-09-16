#include <windows.h>
#include <string>

const wchar_t g_szClassName[] = L"myAppWindow";
HWND hLabel, hEdit, hButton;
HFONT hFont;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CREATE:
        // Ustawienie czcionki systemowej dla pełnego Unicode
        hFont = CreateFontW(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
                            DEFAULT_CHARSET, OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
                            CLEARTYPE_QUALITY, VARIABLE_PITCH, L"MS Shell Dlg 2");

        // Etykieta "Podaj swoje imię:"
        hLabel = CreateWindowExW(0, L"STATIC", L"Podaj swoje imię:", WS_CHILD | WS_VISIBLE,
                                 20, 10, 250, 20, hwnd, NULL, NULL, NULL);
        SendMessageW(hLabel, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Pole tekstowe do wpisania imienia
        hEdit = CreateWindowExW(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
                                20, 35, 250, 25, hwnd, (HMENU)1, NULL, NULL);
        SendMessageW(hEdit, WM_SETFONT, (WPARAM)hFont, TRUE);

        // Przycisk "OK"
        hButton = CreateWindowExW(0, L"BUTTON", L"OK", WS_CHILD | WS_VISIBLE,
                                  20, 70, 80, 30, hwnd, (HMENU)2, NULL, NULL);
        SendMessageW(hButton, WM_SETFONT, (WPARAM)hFont, TRUE);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 2) // Kliknięcie przycisku OK
        {
            wchar_t name[100];
            GetWindowTextW(hEdit, name, 100); // Pobieramy wpisane imię

            std::wstring message = L"Witaj " + std::wstring(name) + L" w aplikacji myApp_C++!";
            MessageBoxW(hwnd, message.c_str(), L"Powitanie", MB_OK);
        }
        break;

    case WM_CLOSE:
        DeleteObject(hFont); // Usunięcie czcionki przed zamknięciem
        DestroyWindow(hwnd);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProcW(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
    // Wymuszenie języka polskiego w GUI Windows
    SetThreadUILanguage(LANG_POLISH);
    SetProcessDPIAware(); // Poprawia renderowanie czcionek

    WNDCLASSW wc = {0}; // Unicode
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = g_szClassName;
    RegisterClassW(&wc);

    HWND hwnd = CreateWindowExW(0, g_szClassName, L"myApp_C++", WS_OVERLAPPEDWINDOW,
                                CW_USEDEFAULT, CW_USEDEFAULT, 350, 200,
                                NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
