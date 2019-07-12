#include <winuser.h>
#include <stdio.h>

const int HOTKEY_ID = 1;

int main(int argc, char **argv)
{
	if (RegisterHotKey(
					NULL, // this thread will process the hotkey
					HOTKEY_ID,
					MOD_WIN,
					VK_OEM_3)) // ~
	{
		printf("hot key registered\n");
	}

	MSG msg = {0};
	while (GetMessage(&msg, NULL, 0, 0) != 0){
		if (msg.message == WM_HOTKEY)
		{
			// process hot key
			printf("hot key pressed\n");
		}
	}

	UnregisterHotKey(NULL, HOTKEY_ID);
}
