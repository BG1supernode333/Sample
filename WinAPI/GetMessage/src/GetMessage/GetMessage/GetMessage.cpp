#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	char szMsg[128];

	hWnd = CreateWindow("STATIC", "GetMessage", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "GetMessage", MB_OK | MB_ICONHAND);
		return -1;

	}
	
	ShowWindow(hWnd, SW_SHOW);

	GetMessage(&msg, NULL, 0, 0);
	sprintf(szMsg, "msg.message = 0x%08x", msg.message);
	MessageBox(hWnd, szMsg, "GetMessage", MB_OK | MB_ICONASTERISK);

	DestroyWindow(hWnd);

	return 0;

}