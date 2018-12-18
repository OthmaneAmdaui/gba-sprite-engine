//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include "startScene.h"
#include "raceScene.h"
#include "timer.h"

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    startScene* scene = new startScene(engine);
    engine->setScene(scene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }
}

