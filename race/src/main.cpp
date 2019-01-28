//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/scene.h>

#include "startScene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    //auto game = new game();

    auto *startScene = new StartScene(engine);

    //auto *chooseCarScene = new ChooseCarScene(engine);
    //auto *raceScene = new RaceScene(engine);

    //game->setStartScene(startScene);
    //game->setChooseCarScene(chooseCarScene);
    //game->setRaceScene(raceScene);

    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }
}

