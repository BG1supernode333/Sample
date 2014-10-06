#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "LineTo";
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

		MessageBox(NULL, "RegisterClass failed!", "LineTo", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("LineTo", "LineTo", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "LineTo", MB_OK | MB_ICONHAND);
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

	switch (uMsg){

		case WM_CREATE:

			hDC = GetDC(hwnd);

			return 0;

		case WM_DESTROY:

			ReleaseDC(hwnd, hDC);

			PostQuitMessage(0);
			break;
		
		case WM_LBUTTONDOWN:

			{

				int x;
				int y;
				POINT pt;
				char szPoints[128];
				unsigned int uiLen;

				x = LOWORD(lParam);
				y = HIWORD(lParam);

				MoveToEx(hDC, x, y, &pt); 

				sprintf(szPoints, "before(%d, %d) -> after(%d, %d)", pt.x, pt.y, x, y);
				uiLen = strlen(szPoints);	

				TextOut(hDC, 0, 0, szPoints, uiLen);

			}

			break;

		case WM_RBUTTONDOWN:

			{

				int x;
				int y;

				x = LOWORD(lParam);
				y = HIWORD(lParam);

				LineTo(hDC, x, y);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}