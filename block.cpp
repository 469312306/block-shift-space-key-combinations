#include <Windows.h>

#define HOTKEY_ID 0x5955

int main(int argc, char const *argv[]){
    // hide console
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    // register shift+space
    RegisterHotKey(NULL, HOTKEY_ID, MOD_SHIFT, VK_SPACE);
    MSG msg = {0};
    while (GetMessage(&msg, NULL, 0, 0)){
        // wait till shift+space pressed
        if (msg.message == WM_HOTKEY){
            // release space and shift, enter space
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
            keybd_event(VK_SPACE, 0, 0, 0);
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);
        }
    }
    // release the register
    UnregisterHotKey(NULL, HOTKEY_ID);
    return 0;
}