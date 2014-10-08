#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "BitBlt";
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

		MessageBox(NULL, "RegisterClass failed!", "BitBlt", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("BitBlt", "BitBlt", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "BitBlt", MB_OK | MB_ICONHAND);
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

					MessageBox(NULL, "LoadImage failed!", "BitBlt", MB_OK | MB_ICONHAND);
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
				HBITMAP hOldBitmap;

				hDC = BeginPaint(hwnd, &ps);

				hMemDC = CreateCompatibleDC(hDC);

				hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);

				BitBlt(hDC, 0, 0, 640, 480, hMemDC, 0, 0, SRCCOPY);

				SelectObject(hMemDC, hOldBitmap);

				DeleteDC(hMemDC);

				EndPaint(hwnd, &ps);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}