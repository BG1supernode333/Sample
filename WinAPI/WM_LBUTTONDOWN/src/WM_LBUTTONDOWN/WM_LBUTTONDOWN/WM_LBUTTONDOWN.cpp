#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "WM_LBUTTONDOWN";
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

		MessageBox(NULL, "RegisterClass failed!", "WM_LBUTTONDOWN", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("WM_LBUTTONDOWN", "WM_LBUTTONDOWN", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "WM_LBUTTONDOWN", MB_OK | MB_ICONHAND);
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

	static int x;
	static int y;
	static HDC hDC;
	static PAINTSTRUCT ps;

	switch (uMsg){

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			break;

		case WM_PAINT:

			{

				hDC = BeginPaint(hwnd, &ps);

				char szXY[128];
				unsigned int uiLen;

				sprintf(szXY, "(%d, %d)", x, y);
				uiLen = strlen(szXY);
				TextOut(hDC, 0, 0, szXY, uiLen);

				EndPaint(hwnd, &ps);

			}

			break;
		
		case WM_LBUTTONDOWN:

			{
				
				x = LOWORD(lParam);
				y = HIWORD(lParam);

				InvalidateRect(hwnd, NULL, TRUE);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}