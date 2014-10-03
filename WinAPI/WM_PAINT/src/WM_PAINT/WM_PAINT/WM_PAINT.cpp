#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "WM_PAINT";
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

		MessageBox(NULL, "RegisterClass failed!", "WM_PAINT", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("WM_PAINT", "WM_PAINT", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "WM_PAINT", MB_OK | MB_ICONHAND);
		return -2;

	}
	
	ShowWindow(hWnd, SW_SHOW);

	while (GetMessage(&msg, NULL, 0, 0) > 0){

		DispatchMessage(&msg);

	}

	DestroyWindow(hWnd);

	return 0;

}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){

	static int iCount = 1;

	switch (uMsg){

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			break;

		case WM_PAINT:

			{

				HDC hDC;

				hDC = GetDC(hwnd);

				char szTxt[128];
				unsigned int uiLen;

				sprintf(szTxt, "%d times repainted!", iCount);
				uiLen = strlen(szTxt);
				TextOut(hDC, 50, 50, szTxt, uiLen);

				iCount++;

				ReleaseDC(hwnd, hDC);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}