#pragma once

struct logicGate
{
    int inputs;
    int outputs;

    int outType;
    /*
        0 = 1 bit (0/1)
        1 = custom (2 bits, 1 byte etc..)
    */

   char returnMessage;

   int loadGate() {
    int input_list[inputs];
    int inputs_num = 0;
    // Initialise inputs
    for (int i = 0; i < inputs; i++)
        input_list[i] = i;
        inputs_num++;

    return inputs_num;
    
   }
};
