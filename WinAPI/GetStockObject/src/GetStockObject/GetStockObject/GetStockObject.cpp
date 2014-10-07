#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "GetStockObject";
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

		MessageBox(NULL, "RegisterClass failed!", "GetStockObject", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("GetStockObject", "GetStockObject", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "GetStockObject", MB_OK | MB_ICONHAND);
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

	switch (uMsg){

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			break;
		
		case WM_PAINT:

			{

				HDC hDC;
				PAINTSTRUCT ps;
				unsigned int uiLen;
				HPEN hPen;
				HBRUSH hBrush;
				char szHPenHBrush[128];

				hDC = BeginPaint(hwnd, &ps);

				hPen = (HPEN)GetStockObject(BLACK_PEN);
				hBrush = (HBRUSH)GetStockObject(GRAY_BRUSH);
				
				sprintf(szHPenHBrush, "hPen = 0x%08x, hBrush = 0x%08x", (unsigned int)hPen, (unsigned int)hBrush);
				uiLen = strlen(szHPenHBrush);
				
				TextOut(hDC, 0, 0, szHPenHBrush, uiLen);

				EndPaint(hwnd, &ps);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}