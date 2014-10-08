#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "LoadImage";
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

		MessageBox(NULL, "RegisterClass failed!", "LoadImage", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("LoadImage", "LoadImage", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "LoadImage", MB_OK | MB_ICONHAND);
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

	static HBITMAP hBitmap;

	switch (uMsg){

		case WM_CREATE:

			{
				
				LPCREATESTRUCT lpCS;

				lpCS = (LPCREATESTRUCT)lParam;

				hBitmap = (HBITMAP)LoadImage(lpCS->hInstance, "test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				if (hBitmap == NULL){

					MessageBox(NULL, "LoadImage failed!", "LoadImage", MB_OK | MB_ICONHAND);
					return -1;

				}

			}

			return 0;

		case WM_DESTROY:

			{

				if (hBitmap != NULL){

					DeleteObject(hBitmap);
					hBitmap = NULL;

				}

				PostQuitMessage(0);

			}

			break;
		
		case WM_PAINT:

			{

				HDC hDC;
				PAINTSTRUCT ps;
				HDC hMemDC;
				char szHBitmap[128];
				unsigned int uiLen;

				hDC = BeginPaint(hwnd, &ps);

				hMemDC = CreateCompatibleDC(hDC);

				sprintf(szHBitmap, "hBitmap = 0x%08x", (unsigned int)hBitmap);
				uiLen = strlen(szHBitmap);

				TextOut(hDC, 50, 50, szHBitmap, uiLen);

				DeleteDC(hMemDC);

				EndPaint(hwnd, &ps);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}