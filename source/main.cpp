#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include "lib.h"
using namespace std;

// init some logicGates menu vars
char* menuStuff[] = {"NOT", "AND", "NAND"};     // The list of gates
int menucount = 0;                              // Counts how many items are in menuStuff
int menubar = 0;                                // Counter to know which is the displaying item in the list

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
    printf("\x1b[16;0HUse L and R to scroll\n");

    while (aptMainLoop())
    {
        hidScanInput();
        u32 kDown = hidKeysDown();

        if (kDown & KEY_START) break;

        consoleSelect(&topScreen);

        if (menuStuff[menubar] == "NOT") {
            printf("\x1b[4;0HInputs: %d\n", NOTgate.inputs);
        } else if (menuStuff[menubar] == "AND") {
            printf("\x1b[4;0HInputs: %d\n", ANDgate.inputs);
        } else if (menuStuff[menubar] == "NAND") {
            printf("\x1b[4;0HInputs: %d\n", NANDgate.inputs);
        } else {
            printf("\x1b[4;0HNo gates to display\n");
        }

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

        printf("\n\x1b[2;0H%s gate\n", menuStuff[menubar]);      // actually displays the gate
        
        consoleSelect(&bottomScreen);

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
