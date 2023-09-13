#pragma once
#include <3ds.h>
#include <iostream>
#include "lib.h"
#include <stdio.h>
using namespace std;

struct io {
    int state = 0;
    // 0 = off, 1 = on
};


struct logicGate {
    char* name = "Sample gate";
    int ins = 0;
    int outs = 0;
};
