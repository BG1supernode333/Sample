#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;

	hWnd = CreateWindow("STATIC", "ShowWindow", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "ShowWindow", MB_OK | MB_ICONHAND);
		return -1;

	}
	
	ShowWindow(hWnd, SW_SHOW);

	MessageBox(NULL, "CreateWindow succeed! and ShowWindow!", "ShowWindow", MB_OK | MB_ICONASTERISK);

	DestroyWindow(hWnd);

	return 0;

}