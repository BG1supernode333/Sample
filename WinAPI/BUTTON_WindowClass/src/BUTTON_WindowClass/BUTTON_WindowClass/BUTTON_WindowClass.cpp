#include <windows.h>

#define IDB_BUTTON1 100

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "BUTTON_WindowClass";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;

	if (!RegisterClass(&wc)){

		MessageBox(NULL, "RegisterClass failed!", "BUTTON_WindowClass", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("BUTTON_WindowClass", "BUTTON_WindowClass", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "BUTTON_WindowClass", MB_OK | MB_ICONHAND);
		return -2;

	}
	
	ShowWindow(hWnd, SW_SHOW);

	while (GetMessage(&msg, NULL, 0, 0) > 0){

		DispatchMessage(&msg);
		TranslateMessage(&msg);

	}

	return 0;

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	switch (uMsg){

		case WM_CREATE:

			{

				LPCREATESTRUCT lpCS;
				HWND hButton;

				lpCS = (LPCREATESTRUCT)lParam;

				hButton = CreateWindow("BUTTON", "BUTTON_WindowClass", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 240, 160, 160, 120, hwnd, (HMENU)IDB_BUTTON1, lpCS->hInstance, NULL);

			}

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}