#include <WinUser.h>
#include <Windows.h>

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )

const int HOTKEY_ID = 1;

int main(int argc, char **argv)
{
	HWND tbHdl = FindWindow("Shell_TrayWnd", NULL); // handle of taskbar
	int hiden = 0;																	 // taskbar is hidden?
	if (RegisterHotKey(
					NULL, // this thread will process the hotkey
					HOTKEY_ID,
					MOD_WIN,
					VK_OEM_3)) // ~
	{
		// printf("hot key registered\n");
	}

	MSG msg = {0};
	while (GetMessage(&msg, NULL, 0, 0) != 0) // while msg is not WM_QUIT
	{
		if (msg.message == WM_HOTKEY) // process hot key
		{
			hiden = !hiden;
			if (hiden)
				ShowWindow(tbHdl, 0); //hide taskbar
			else
				ShowWindow(tbHdl, 1); //show taskbar
		}
	}

	UnregisterHotKey(NULL, HOTKEY_ID);
}
