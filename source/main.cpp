#include <3ds.h>
#include <stdio.h>

// init some logicGates menu vars
int menubar = 0;
int menucount = 0;
char* menuStuff[] = {"NOT gate", "AND gate", "NAND gate"};

int main(int argc, char **argv) {
    // Preparation stuff
    for (auto i: menuStuff) {
        menucount++;            // get items quantity from the menu array
    }

    gfxInitDefault();
    PrintConsole topScreen, bottomScreen;

    consoleInit(GFX_TOP, &topScreen);
    // Stuff to render on top screen
    printf("\x1b[10;5HLogisim3D Alpha codename 'Citrus' build 23\n");
    printf("\nUse the L and R triggers to change the gates below");

    consoleInit(GFX_BOTTOM, &bottomScreen);
    // Stuff to render on bottom screen

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;

        // scroll through the logicGates menu
        if (kDown & KEY_L) menubar--;
        if (kDown & KEY_R) menubar++;

        consoleClear();             // Clears the bottom screen to avoid overlapping text

        /*  Example

            NAND GATE

            After scrolling:

            AND GATEE <--- This E was from before scrolling
            consoleClear() should do the job for now
            (we may need to change it ASAP, it could be an issue for future stuff)
        */


        // this is to get the "infinite" scroll
        if (menubar < 0) { menubar = menucount; }
        if (menubar >= menucount) { menubar = 0; }

        printf("\n\x1b[2;0H%s\n", menuStuff[menubar]);      // actually displays the gate

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
