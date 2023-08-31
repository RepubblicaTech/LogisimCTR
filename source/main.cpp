#include <3ds.h>
#include <stdio.h>
#include <string>
#include "lib.h"

int menubar = 0;
int menucount = 0;
char* menuStuff[] = {"NOT gate", "AND gate", "NAND gate"};
Gate AND_gate, NOT_gate;

int main(int argc, char **argv) {
    // Preparation stuff
    for (auto i: menuStuff) {
        menucount++;
    }

    gfxInitDefault();
    PrintConsole topScreen, bottomScreen;

    consoleInit(GFX_TOP, &topScreen);
    // Stuff to render on top screen
    printf("\x1b[10;9HLogisim3D Alpha codename 'Citrus'");

    consoleInit(GFX_BOTTOM, &bottomScreen);
    // Stuff to render on bottom screen
    printf("\x1b[1;0HMenu bar:");
    printf("\x1b[3;0HItems in menubar: %d", menucount);

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;
        if (kDown & KEY_DLEFT) menubar--;
        if (kDown & KEY_DRIGHT) menubar++;

        if (menubar < 0) { menubar = menucount; }
        if (menubar >= menucount) { menubar = 0; }

        consoleClear();

        printf("\x1b[2;0H%s", menuStuff[menubar]);
        printf("\x1b[4;0HmenuItem = %d", menubar);

        /*

        touchPosition touch;
        hidTouchRead(&touch);

        consoleSelect(&bottomScreen);
        printf("\x1b[2;0H%03d; %03d", touch.px, touch.py);

        */
        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
