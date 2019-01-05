//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include "startScene.h"
#include "chooseCarScene.h"
#include "raceScene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    auto *startScene1 = new startScene(engine);

    engine->setScene(startScene1);

    while (true) {
        engine->update();
        engine->delay(1000);
    }
}

