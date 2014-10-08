#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "TranslateMessage";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;

	if (!RegisterClass(&wc)){

		MessageBox(NULL, "RegisterClass failed!", "TranslateMessage", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("TranslateMessage", "TranslateMessage", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "TranslateMessage", MB_OK | MB_ICONHAND);
		return -2;

	}
	
	ShowWindow(hWnd, SW_SHOW);

	while (GetMessage(&msg, NULL, 0, 0) > 0){

		DispatchMessage(&msg);
		TranslateMessage(&msg);

	}

	DestroyWindow(hWnd);

	return 0;

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	switch (uMsg){

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);

			break;

		case WM_KEYUP:

			{
				
				HDC hDC;

				hDC = GetDC(hwnd);

				Rectangle(hDC, -1, -1, 641, 481);

				ReleaseDC(hwnd, hDC);

			}

			break;

		case WM_CHAR:

			{
				
				HDC hDC;

				hDC = GetDC(hwnd);

				TextOut(hDC, 0, 0, "WM_CHAR", 7);

				ReleaseDC(hwnd, hDC);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}