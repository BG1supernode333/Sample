#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

	int iRet1;
	int iRet2;

	iRet1 = MessageBox(NULL, "MessageBox Test Start?", "MessageBox", MB_YESNO | MB_ICONQUESTION);
	if (iRet1 == IDYES){

		iRet2 = MessageBox(NULL, "MessageBox Test Processing.", "MessageBox", MB_OKCANCEL | MB_ICONEXCLAMATION);
		if (iRet2 == IDCANCEL){

			MessageBox(NULL, "MessageBox Test Abort!", "MessageBox", MB_OK | MB_ICONHAND);

			return -1;

		}
		else{

			MessageBox(NULL, "MessageBox Test Succeed!", "MessageBox", MB_OK | MB_ICONASTERISK);
		
		}
	}
	else{

		MessageBox(NULL, "MessageBox Test Abort!", "MessageBox", MB_OK | MB_ICONHAND);

		return -2;

	}

	MessageBox(NULL, "MessageBox Test End.", "MessageBox", MB_OK);

	return 0;

}