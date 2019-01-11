//
// Created by Lukas on 17/12/2018.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include "startScene.h"
#include "chooseCarScene.h"
#include "raceScene.h"
#include "sprite_data.h"
#include "soundFx_menuNavigation_data.h"

std::vector<Background *> startScene::backgrounds() {
    return {};
}

std::vector<Sprite *> startScene::sprites() {
    return {sp_arrow.get()};
}

void startScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    sp_arrow = builder
            .withData(arrowTiles, sizeof(arrowTiles))
            .withSize(SIZE_16_16)
            .withLocation(64, 36)
            //.withinBounds()
            .buildPtr();

    TextStream::instance().setText("START GAME", 5, 10);
    TextStream::instance().setText("CHOOSE CAR", 10, 10);

    //engine->enqueueMusic(bgm_menu, bgm_menu_bytes);
}
void startScene::tick(u16 keys) {
    //Positive flank detection
    up_mem = up_pressed;
    down_mem = down_pressed;
    start_mem = start_pressed;
    if(keys & KEY_UP){up_pressed = true;}
    else{up_pressed = false;}
    if(keys & KEY_DOWN){down_pressed = true;}
    else{down_pressed = false;}
    if(keys & KEY_START){start_pressed = true;}
    else{start_pressed  = false;}

    switch (sp_arrow->getY()){
        case Y_TOP:
            if((up_pressed == true & up_mem != true) | (down_pressed == true & down_mem != true)){
                engine.get()->enqueueSound(menu_nav, menu_nav_bytes, 32000);
                sp_arrow->moveTo(64, Y_BOTTOM);
            }
            else if(start_pressed == true & start_mem != true) {
                //if (!engine->isTransitioning()) {
                    TextStream::instance().setText("Prepare for the race!!!",0,0);
                    engine->transitionIntoScene(new raceScene(engine), new FadeOutScene(2));
                //}
            }
            break;
        case Y_BOTTOM:
            if((up_pressed == true & up_mem != true) | (down_pressed == true & down_mem != true)){
                engine.get()->enqueueSound(menu_nav, menu_nav_bytes, 32000);
                sp_arrow->moveTo(64, Y_TOP);
            }
            else if(start_pressed == true & start_mem != true) {
                engine.get()->enqueueSound(menu_nav, menu_nav_bytes, 32000);
                engine->transitionIntoScene(new chooseCarScene(engine), new FadeOutScene(10));
            }
            break;
    }
}

