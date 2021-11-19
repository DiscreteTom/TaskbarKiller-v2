#include <Windows.h>

#ifdef _DEBUG
#include <stdio.h>
#endif

#ifndef _DEBUG
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

const int HOTKEY_ID = 1;

int main(int argc, char** argv)
{
	// get taskbar handle
	HWND taskbar = FindWindow("Shell_TrayWnd", NULL);
#ifdef _DEBUG
	printf("taskbar handle: %p\n", taskbar);
#endif

	// register hot key
	if (RegisterHotKey(
		NULL, // this thread will process the hotkey
		HOTKEY_ID,
		MOD_WIN,
		VK_OEM_3 // ~
	))
	{
#ifdef _DEBUG
		printf("hot key registered\n");
#endif
	}

	MSG msg = { 0 };
	int hidden = 0;
	while (GetMessage(&msg, NULL, 0, 0) != 0) // while msg is not WM_QUIT
	{
		if (msg.message == WM_HOTKEY) // process hot key
		{
			hidden = !hidden;
			if (hidden) {
				ShowWindow(taskbar, 0); //hide taskbar
#ifdef _DEBUG
				printf("hide\n");
#endif
			}
			else {
				ShowWindow(taskbar, 1); //show taskbar
#ifdef _DEBUG
				printf("show\n");
#endif
			}
		}
	}

	UnregisterHotKey(NULL, HOTKEY_ID);
	ShowWindow(taskbar, 1); // show taskbar at last
}
