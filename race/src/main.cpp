//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include "raceScene.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    raceScene* startScene = new raceScene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }
}

