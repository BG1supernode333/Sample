#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "CreateCompatibleBitmap";
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

		MessageBox(NULL, "RegisterClass failed!", "CreateCompatibleBitmap", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("CreateCompatibleBitmap", "CreateCompatibleBitmap", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "CreateCompatibleBitmap", MB_OK | MB_ICONHAND);
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

	static HDC hDC;
	static HBITMAP hLoadBitmap;
	static HBITMAP hOldLoadBitmap;
	static HDC hLoadMemDC;
	static HBITMAP hBackBitmap;
	static HBITMAP hOldBackBitmap;
	static HDC hBackMemDC;
				
	switch (uMsg){

		case WM_CREATE:

			{
				
				LPCREATESTRUCT lpCS;

				lpCS = (LPCREATESTRUCT)lParam;

				hDC = GetDC(hwnd);

				hBackMemDC = CreateCompatibleDC(hDC);

				hLoadMemDC = CreateCompatibleDC(hDC);

				hBackBitmap = (HBITMAP)CreateCompatibleBitmap(hDC, 640, 480);

				hLoadBitmap = (HBITMAP)LoadImage(lpCS->hInstance, "test.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				if (hLoadBitmap == NULL){

					MessageBox(NULL, "LoadImage failed!", "CreateCompatibleBitmap", MB_OK | MB_ICONHAND);
					DeleteObject(hBackBitmap);
					hBackBitmap = NULL;
					DeleteDC(hLoadMemDC);
					hLoadMemDC = NULL;
					DeleteDC(hBackMemDC);
					hBackMemDC = NULL;
					ReleaseDC(hwnd, hDC);
					hDC = NULL;

					return -1;

				}

				hOldBackBitmap = (HBITMAP)SelectObject(hBackMemDC, hBackBitmap);

				hOldLoadBitmap = (HBITMAP)SelectObject(hLoadMemDC, hLoadBitmap);

			}

			return 0;

		case WM_DESTROY:

			{

				SelectObject(hLoadMemDC, hOldLoadBitmap);
				SelectObject(hBackMemDC, hOldBackBitmap);

				DeleteObject(hLoadBitmap);
				hLoadBitmap = NULL;
				DeleteObject(hBackBitmap);
				hBackBitmap = NULL;
				DeleteDC(hLoadMemDC);
				hLoadMemDC = NULL;
				DeleteDC(hBackMemDC);
				hBackMemDC = NULL;
				ReleaseDC(hwnd, hDC);
				hDC = NULL;

				PostQuitMessage(0);

			}

			break;
		
		case WM_PAINT:

			{

				BitBlt(hBackMemDC, 0, 0, 640, 480, hLoadMemDC, 0, 0, SRCCOPY);
				Rectangle(hBackMemDC, 200, 200, 100, 100);
				BitBlt(hDC, 0, 0, 640, 480, hBackMemDC, 0, 0, SRCCOPY);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}