//
// Created by Lukas on 10/12/2018.
// Source: http://www.coranac.com/tonc/text/timers.htm
//
#include <libgba-sprite-engine/gba_engine.h>

void initTimer0(){
    REG_TM0D = -0x4000; // 0x4000 (1s) ticks till overflow
    REG_TM0CNT = TM_FREQ_1024;  // we're using the 1024 cycle timer
    REG_TM1CNT = TM_ENABLE | TM_CASCADE; // cascade into tm3
}
void toggleTimer0(){
    REG_TM0CNT ^= TM_ENABLE;
}

void initTimer1(){
    REG_TM2D = -0x8000;
    REG_TM2CNT = TM_FREQ_64;
    REG_TM3CNT = TM_ENABLE | TM_CASCADE;
}
void toggleTimer1(){
    REG_TM2CNT ^= TM_ENABLE;
}