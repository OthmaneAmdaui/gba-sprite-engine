//
// Created by Lukas on 14/01/2019.
//
#ifndef GBA_SPRITE_ENGINE_PROJECT_GAME_H
#define GBA_SPRITE_ENGINE_PROJECT_GAME_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include "StartScene.h"
#include "ChooseCarScene.h"
#include "RaceScene.h"

class Game{
private:
    StartScene *startScene1b;
    RaceScene *raceScene1;
    ChooseCarScene *chooseCarScene1;

public:

    StartScene *getStartScene(){return startScene1;}
    ChooseCarScene *getChooseCarScene(){return chooseCarScene1;}
    RaceScene *getRaceScene(){return raceScene1;}

    void setStartScene(StartScene scene){startScene1 = scene;}
    void setChooseCarScene(ChooseCarScene scene){chooseCarScene1 = scene;}
    void setRaceScene(RaceScene scene){raceScene1 = scene;}
};

#endif //GBA_SPRITE_ENGINE_PROJECT_GAME_H
