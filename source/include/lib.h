#pragma once

struct logicGate
{
    int inputs, outputs;

    int outType;
    //  0 = 1 bit (0/1)
    //  1 = custom (2 bits, 1 byte etc..)

   int gateOperation;
};

logicGate NOTgate;
NOTgate.inputs = 1;
NOTgate.outputs = 1;
NOTgate.outType = 0;
int notGate = NOTgate.loadGate();

logicGate ANDgate;
ANDgate.inputs = 2;
ANDgate.outputs = 1;
ANDgate.outType = 0;

logicGate NANDgate;
NANDgate.inputs = 2;
NANDgate.outputs = 1;
NANDgate.outType = 0;