//
// Created by Lukas on 10/12/2018.
// Source: http://www.coranac.com/tonc/text/timers.htm
//
#include <libgba-sprite-engine/gba_engine.h>
#include "timer.h"

void initTimer0(){
    setTimer0Value(0x4000); // 0x4000 (1s) ticks till overflow
    REG_TM0CNT = TM_FREQ_1024;  // we're using the 1024 cycle timer
    REG_TM1CNT = TM_ENABLE | TM_CASCADE; // cascade into tm1
}
void startTimer0(){
    REG_TM0CNT |= TM_ENABLE;
}
void stopTimer0(){
    REG_TM0CNT = REG_TM0CNT & !TM_ENABLE;
}
void toggleTimer0(){
    REG_TM0CNT ^= TM_ENABLE;
}
void setTimer0Value(int value){
    REG_TM0D = -value;
}


void initTimer1(){
    setTimer1Value(0x52);   // 25ms
    REG_TM2CNT = TM_FREQ_1024;
    REG_TM3CNT = TM_ENABLE | TM_CASCADE;
}
void startTimer1(){
    REG_TM2CNT |= TM_ENABLE;
}
void stopTimer1(){
    REG_TM2CNT = REG_TM2CNT & !TM_ENABLE;
}
void toggleTimer1(){
    REG_TM2CNT ^= TM_ENABLE;
}
void setTimer1Value(int value){
    REG_TM2D = -value;
}
