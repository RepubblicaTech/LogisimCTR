#pragma once
#include <3ds.h>
#include <iostream>
#include "lib.h"
#include <stdio.h>
using namespace std;

struct logicGate {
    char* name = "Sample gate";
    int ins = 0;
    int outs = 0;
};

int NOT(int in) {
    return not in;
}

int AND(int in1, int in2) {
    return in1 and in2;
}
