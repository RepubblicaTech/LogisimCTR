#include <3ds.h>
#include <stdio.h>

int menubar = 0;
int menucount = 0;
char* menuStuff[] = {"NOT gate", "AND gate", "NAND gate"};

int main(int argc, char **argv) {
    // Preparation stuff
    for (auto i: menuStuff) {
        menucount++;
    }

    gfxInitDefault();
    PrintConsole topScreen, bottomScreen;

    consoleInit(GFX_TOP, &topScreen);
    // Stuff to render on top screen
    printf("\x1b[10;5HLogisim3D Alpha codename 'Citrus' build 23\n");
    printf("\n  Use the L and R triggers to change the gates below");

    consoleInit(GFX_BOTTOM, &bottomScreen);
    // Stuff to render on bottom screen

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;
        if (kDown & KEY_L) menubar--;
        if (kDown & KEY_R) menubar++;

        consoleClear();

        if (menubar < 0) { menubar = menucount; }
        if (menubar >= menucount) { menubar = 0; }

        printf("\n\x1b[2;0H%s\n", menuStuff[menubar]);

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
