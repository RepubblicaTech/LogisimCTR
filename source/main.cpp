#include <3ds.h>
#include <iostream>
#include <stdio.h>
#include "lib.h"
#include "VariadicTable.h"
#include "buildnumber.h"
using namespace std;

int main(int argc, char **argv) {

    logicGate notGate, andGate, nandGate;

    notGate.name = "NOT";
    andGate.name = "AND";

    andGate.ins = 2;
    andGate.outs = 1;
    int and_inputs[andGate.ins];
    int and_outputs[andGate.outs];

    notGate.ins = 1;
    notGate.outs = notGate.ins;
    int not_inputs[notGate.ins];
    int not_outputs[notGate.outs];

    // init some logicGates menu vars
<<<<<<< Updated upstream
    // The list of gates
    logicGate logicGates[] = {notGate,
=======

    logicGate logicGates[] = {notGate,              // The list of gates
>>>>>>> Stashed changes
                              andGate};
    int menucount = 0;                              // Counts how many items are in menuStuff
    int menubar = 0;                                // Counter to know which is the displaying item in the list

    
    // Preparation stuff
    for (auto i: logicGates) {
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

        printf("\n\x1b[2;0H%s gate\n\n", logicGates[menubar].name);      // actually displays the gate
        printf("Inputs: %d\n", logicGates[menubar].ins);
        printf("Outputs: %d\n\n", logicGates[menubar].outs);
        
        if (logicGates[menubar].name == "NOT") {
            
            not_inputs[0] = 1;
            not_outputs[0] = not not_inputs[0];
            VariadicTable<int, int> vt({"IN", "OUT"},
                                        10);
            vt.addRow(not_inputs[0], not_outputs[0]);
            not_inputs[0] = 0;
            not_outputs[0] = NOT(not_inputs[0]);
            vt.addRow(not_inputs[0], not_outputs[0]);
            vt.print(std::cout);
        }
        if (logicGates[menubar].name == "AND") {
            
            and_inputs[0] = 0;
            and_inputs[1] = 0;
            and_outputs[0] = AND(and_inputs[0], and_inputs[1]);
            VariadicTable<int, int, int> vt({"IN1", "IN2", "OUT"},
                                              10);
            vt.addRow(and_inputs[0], and_inputs[1], and_outputs[0]);
            and_inputs[0] = 1;
            and_inputs[1] = 0;
            and_outputs[0] = AND(and_inputs[0], and_inputs[1]);
            vt.addRow(and_inputs[0], and_inputs[1], and_outputs[0]);
            and_inputs[0] = 0;
            and_inputs[1] = 1;
            and_outputs[0] = AND(and_inputs[0], and_inputs[1]);
            vt.addRow(and_inputs[0], and_inputs[1], and_outputs[0]);
            and_inputs[0] = 1;
            and_inputs[1] = 1;
            and_outputs[0] = AND(and_inputs[0], and_inputs[1]);
            vt.addRow(and_inputs[0], and_inputs[1], and_outputs[0]);

            vt.print(std::cout);
        }

        consoleSelect(&bottomScreen);

        gfxFlushBuffers();

        // gfxSwapBuffers();
        // gspWaitForVBlank();
    }

    gfxExit();
    return 0;
    
}
