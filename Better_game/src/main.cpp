//
// Created by Othmane Amdaui on 29-Nov-18.
//

#include "BetterScene.h"

#include <libgba-sprite-engine/gba_engine.h>

int main() {
    std::shared_ptr<GBAEngine> engine(new GBAEngine());

    BetterScene* startScene = new BetterScene(engine);
    engine->setScene(startScene);

    while (true) {
        engine->update();
        engine->delay(1000);
    }
}
