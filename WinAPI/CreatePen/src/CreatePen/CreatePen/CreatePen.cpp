#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "CreatePen";
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

		MessageBox(NULL, "RegisterClass failed!", "CreatePen", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("CreatePen", "CreatePen", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "CreatePen", MB_OK | MB_ICONHAND);
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

	static HPEN hPen;

	switch (uMsg){

		case WM_CREATE:

			{

				hPen = CreatePen(PS_SOLID, 1, RGB(0xFF, 0x00, 0x00));

			}

			return 0;

		case WM_DESTROY:

			{

				DeleteObject(hPen);

				PostQuitMessage(0);

			}

			break;
		
		case WM_PAINT:

			{

				HDC hDC;
				PAINTSTRUCT ps;
				HPEN hOldPen;
				POINT pt;

				hDC = BeginPaint(hwnd, &ps);

				hOldPen = (HPEN)SelectObject(hDC, hPen);

				MoveToEx(hDC, 0, 0, &pt);
				LineTo(hDC, 678, 480);

				SelectObject(hDC, hOldPen);

				EndPaint(hwnd, &ps);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}