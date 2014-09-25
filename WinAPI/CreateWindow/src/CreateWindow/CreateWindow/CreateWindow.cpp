#include <windows.h>
#include <stdio.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	char szHWnd[128];

	hWnd = CreateWindow("STATIC", "CreateWindow", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "CreateWindow", MB_OK | MB_ICONHAND);
		return -1;

	}
	
	sprintf(szHWnd, "CreateWindow succeed!(hWnd = 0x%08x)", (unsigned int)hWnd);
	MessageBox(NULL, szHWnd, "CreateWindow", MB_OK | MB_ICONASTERISK);

	DestroyWindow(hWnd);

	return 0;

}