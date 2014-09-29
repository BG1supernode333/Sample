#include <windows.h>
#include <stdio.h>
#include <string.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "WM_CREATE";
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;

	if (!RegisterClass(&wc)){

		MessageBox(NULL, "RegisterClass failed!", "WM_CREATE", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("WM_CREATE", "WM_CREATE", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "WM_CREATE", MB_OK | MB_ICONHAND);
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

	char szMsg[1024] = {0};
	char szTmp[1024] = {0};
	LPCREATESTRUCT lpcs;

	switch (uMsg){

		case WM_CREATE:

			lpcs = (LPCREATESTRUCT)lParam;

			sprintf(szTmp, "WM_CREATE");
			strcat(szMsg, szTmp);

			sprintf(szTmp, "\nhwnd=0x%08x", (unsigned int)hwnd);
			strcat(szMsg, szTmp);
			
			sprintf(szTmp, "\nlpcs->lpszName = %s", lpcs->lpszName);
			strcat(szMsg, szTmp);

			sprintf(szTmp, "\nlpcs->x = %d", lpcs->x);
			strcat(szMsg, szTmp);

			lpcs = (LPCREATESTRUCT)lParam;
			sprintf(szTmp, "\nlpcs->y = %d", lpcs->y);
			strcat(szMsg, szTmp);

			lpcs = (LPCREATESTRUCT)lParam;
			sprintf(szTmp, "\nlpcs->cx = %d", lpcs->cx);
			strcat(szMsg, szTmp);

			lpcs = (LPCREATESTRUCT)lParam;
			sprintf(szTmp, "\nlpcs->cy = %d", lpcs->cy);
			strcat(szMsg, szTmp);

			MessageBox(hwnd, szMsg, "WM_CREATE", MB_OK | MB_ICONASTERISK);

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}