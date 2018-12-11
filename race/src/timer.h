//
// Created by Lukas on 10/12/2018.
//
#ifndef GBA_SPRITE_ENGINE_PROJECT_TIMER_H
#define GBA_SPRITE_ENGINE_PROJECT_TIMER_H

#include <libgba-sprite-engine/gba_engine.h>

#define MEM_IO 0x04000000

#define REG_BASE MEM_IO

#define REG_TM2D *(vu16*)(REG_BASE+0x0108)
#define REG_TM2CNT *(vu16*)(REG_BASE+0x010A)


#define TM_FREQ_SYS   0 //System clock timer (16.7 Mhz).
#define 	TM_FREQ_1   0   //1 cycle/tick (16.7 Mhz)
#define 	TM_FREQ_64   0x0001 //64 cycles/tick (262 kHz)
#define 	TM_FREQ_256   0x0002    //256 cycles/tick (66 kHz)
#define 	TM_FREQ_1024   0x0003   //1024 cycles/tick (16 kHz)
#define 	TM_CASCADE   0x0004 //Increment when preceding timer overflows.
#define 	TM_IRQ   0x0040 //Enable timer irq.
#define 	TM_ENABLE   0x0080  //Enable timer.

void initTimer();

#endif //GBA_SPRITE_ENGINE_PROJECT_TIMER_H
