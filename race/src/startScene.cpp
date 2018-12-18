//
// Created by Lukas on 17/12/2018.
//
//
// Created by Wouter Groeneveld on 02/08/18.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "startScene.h"
#include "raceScene.h"
#include "sprite_data.h"



std::vector<Background *> startScene::backgrounds() {
    return {};
}

std::vector<Sprite *> startScene::sprites() {
    return {arrow.get()};
}

void startScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    arrow = builder
            .withData(arrowTiles, sizeof(arrowTiles))
            .withSize(SIZE_16_16)
            .withLocation(64, 36)
            //.withinBounds()
            .buildPtr();

    TextStream::instance().setText("START GAME", 5, 10);
    TextStream::instance().setText("CHOOSE CAR", 10, 10);

}

void startScene::tick(u16 keys) {
    switch (arrow->getY()){
        case Y_TOP:
            if(keys & (KEY_UP | KEY_DOWN)){
                arrow->moveTo(64, Y_BOTTOM);
            }
            else if(keys & KEY_START) {
                if (!engine->isTransitioning()) {
                    TextStream::instance() << "Prepare for the race!!!";
                    engine->transitionIntoScene(new raceScene(engine), new FadeOutScene(2));
                }
            }
            break;
        case Y_BOTTOM:
            if(keys & (KEY_UP | KEY_DOWN)){
                arrow->moveTo(64, Y_TOP);
            }

            break;
    }

}

