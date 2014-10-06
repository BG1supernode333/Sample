#include <windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	HWND hWnd;
	MSG msg;
	WNDCLASS wc;

	wc.lpszClassName = "Rectangle";
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

		MessageBox(NULL, "RegisterClass failed!", "Rectangle", MB_OK | MB_ICONHAND);
		return -1;

	}

	hWnd = CreateWindow("Rectangle", "Rectangle", WS_OVERLAPPEDWINDOW, 100, 100, 640, 480, NULL, NULL, hInstance, NULL);
	if (hWnd == NULL){

		MessageBox(NULL, "CreateWindow failed!", "Rectangle", MB_OK | MB_ICONHAND);
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

	static POINT start;
	static POINT end;

	switch (uMsg){

		case WM_CREATE:

			return 0;

		case WM_DESTROY:

			PostQuitMessage(0);
			break;
		
		case WM_PAINT:

			{

				HDC hDC;
				PAINTSTRUCT ps;

				hDC = BeginPaint(hwnd, &ps);

				Rectangle(hDC, start.x, start.y, end.x, end.y);

				EndPaint(hwnd, &ps);

			}

			break;

		case WM_LBUTTONDOWN:

			{

				start.x = LOWORD(lParam);
				start.y = HIWORD(lParam);

			}

			break;

		case WM_RBUTTONDOWN:

			{

				end.x = LOWORD(lParam);
				end.y = HIWORD(lParam);

				InvalidateRect(hwnd, NULL, FALSE);

			}

			break;

		default:

			break;

	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}