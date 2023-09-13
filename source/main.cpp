#include <3ds.h>
#include <iostream>
#include "lib.h"
#include "buildnumber.h"
#include <stdio.h>
using namespace std;

int main(int argc, char **argv) {

    logicGate notGate, andGate, nandGate;

    notGate.name = "NOT";
    andGate.name = "AND";

    andGate.ins = 2;
    andGate.outs = 1;

    notGate.outs = 1;
    notGate.ins = notGate.outs;

    int debug = notGate.init();

    // init some logicGates menu vars
    logicGate logicGates[] = {notGate,
                              andGate};
    char* menuStuff[] = {notGate.name,
                         andGate.name};             // The list of gates
    int menucount = 0;                              // Counts how many items are in menuStuff
    int menubar = 0;                                // Counter to know which is the displaying item in the list

    
    // Preparation stuff
    for (auto i: menuStuff) {
        menucount++;            // get items quantity from the menu array
    }

    // Initialise the screen
    gfxInitDefault();
    PrintConsole topScreen, bottomScreen;
    consoleInit(GFX_TOP, &topScreen);
    consoleInit(GFX_BOTTOM, &bottomScreen);


    printf("\x1b[10;5HLogisimCTR alpha v0.1 build %s\n", BUILDNUMBER_STR);
    printf("\x1b[16;0HUse L and R to scroll\n");

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

        printf("\n\x1b[2;0H%s gate\n", menuStuff[menubar]);      // actually displays the gate
        printf("Inputs: %d\n", logicGates[menubar].ins);
        printf("Outputs: %d\n", logicGates[menubar].outs);

        consoleSelect(&bottomScreen);

        gfxFlushBuffers();

        // gfxSwapBuffers();
        // gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
