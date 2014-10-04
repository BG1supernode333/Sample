#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "InvalidateRect";
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

		MessageBox(NULL, "RegisterClass failed!", "InvalidateRect", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("InvalidateRect", "InvalidateRect", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "InvalidateRect", MB_OK | MB_ICONHAND);
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

	static int iCount = 0;
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

				char szTxt[128];
				unsigned int uiLen;

				sprintf(szTxt, "%d times clicked and repainted!", iCount);
				uiLen = strlen(szTxt);
				TextOut(hDC, 50, 50, szTxt, uiLen);

				EndPaint(hwnd, &ps);

			}

			break;
		
		case WM_LBUTTONDOWN:

			{
				
				RECT rc;

				rc.left = 0;
				rc.top = 0;
				rc.right = 640;
				rc.bottom = 480;

				iCount++;

				InvalidateRect(hwnd, &rc, TRUE);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}