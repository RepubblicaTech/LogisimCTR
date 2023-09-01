#include <3ds.h>
#include <stdio.h>
#include "lib.h"

// init some logicGates menu vars
int menubar = 0;
int menucount = 0;
char* menuStuff[] = {"NOT gate", "AND gate", "NAND gate"};

int main(int argc, char **argv) {
    // Preparation stuff
    for (auto i: menuStuff) {
        menucount++;            // get items quantity from the menu array
    }

    // Initialise the screen
    gfxInitDefault();
    PrintConsole topScreen, bottomScreen;
    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);


    printf("\x1b[10;5HLogisim3D Alpha codename 'Citrus'\n");
    printf("\nUse the L and R triggers to scroll through the menu");

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;

        consoleSelect(&topScreen);

        // scroll through the logicGates menu
        if (kDown & KEY_L) {
            menubar--;
            consoleClear();
        }
        if (kDown & KEY_R) {
            menubar++;
            consoleClear();
        }

        // this is to get the "infinite" scroll
        if (menubar < 0) { menubar = menucount - 1; }
        if (menubar >= menucount) { menubar = 0; }

        printf("\n\x1b[2;0H%s\n", menuStuff[menubar]);      // actually displays the gate
        

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
