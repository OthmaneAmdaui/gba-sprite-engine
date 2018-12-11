//
// Created by Lukas on 10/12/2018.
//
#include "timer.h"

void initTimer(){
    REG_TM2D = -0x4000;          // 0x4000 ticks till overflow
    REG_TM2CNT = TM_FREQ_1024;   // we're using the 1024 cycle timer
    REG_TM3CNT = TM_ENABLE | TM_CASCADE;     // cascade into tm3

}

