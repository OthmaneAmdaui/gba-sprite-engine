//
// Created by Lukas on 19/12/2018.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <vector>
#include "chooseCarScene.h"
#include "startScene.h"
#include "sprite_data.h"
#include "soundFx_menuNav.h"



std::vector<Background *> ChooseCarScene::backgrounds() {
    return {};
}

std::vector<Sprite *> ChooseCarScene::sprites() {
    return {sp_arrow.get(),
            sp_red_car.get(),
            sp_blue_car.get(),
            sp_green_car.get(),
            sp_purple_car.get(),
            sp_turquoise_car.get(),
            sp_mustard_car.get()};
}

void ChooseCarScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    createSpriteObjects();
    TextStream::instance().setText("CHOOSE YOUR CAR", 3, 2);

}

void ChooseCarScene::tick(u16 keys) {

    //Positive flank detection
    right_mem = right_pressed;
    left_mem = left_pressed;
    up_mem  = up_pressed;
    down_mem = down_pressed;
    start_mem = start_pressed;
    if(keys & KEY_RIGHT){right_pressed = true;}
    else{right_pressed = false;}
    if(keys & KEY_LEFT){left_pressed = true;}
    else{left_pressed = false;}
    if(keys & KEY_UP){up_pressed = true;}
    else{up_pressed = false;}
    if(keys & KEY_DOWN){down_pressed = true;}
    else{down_pressed = false;}
    if(keys & KEY_START){start_pressed = true;}
    else{start_pressed  = false;}

    if(sp_arrow->getX() == RED_CAR_X & sp_arrow->getY() == RED_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(BLUE_CAR_X, BLUE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(MUSTARD_CAR_X, MUSTARD_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(PURPLE_CAR_X, PURPLE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(PURPLE_CAR_X, PURPLE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 1;
            engine->transitionIntoScene(new StartScene(engine, 1), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == BLUE_CAR_X & sp_arrow->getY() == BLUE_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(GREEN_CAR_X, GREEN_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(RED_CAR_X, RED_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(TURQUOISE_CAR_X, TURQUOISE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(TURQUOISE_CAR_X, TURQUOISE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 2;
            engine->transitionIntoScene(new StartScene(engine, 2), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == GREEN_CAR_X & sp_arrow->getY() == GREEN_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(PURPLE_CAR_X, PURPLE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(BLUE_CAR_X, BLUE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(MUSTARD_CAR_X, MUSTARD_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(MUSTARD_CAR_X, MUSTARD_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 3;
            engine->transitionIntoScene(new StartScene(engine, 3), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == PURPLE_CAR_X & sp_arrow->getY() == PURPLE_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(TURQUOISE_CAR_X, TURQUOISE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(GREEN_CAR_X, GREEN_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(RED_CAR_X, RED_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(RED_CAR_X, RED_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 4;
            engine->transitionIntoScene(new StartScene(engine, 4), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == TURQUOISE_CAR_X & sp_arrow->getY() == TURQUOISE_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(MUSTARD_CAR_X, MUSTARD_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(PURPLE_CAR_X, PURPLE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(BLUE_CAR_X, BLUE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(BLUE_CAR_X, BLUE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 5;
            engine->transitionIntoScene(new StartScene(engine, 5), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == MUSTARD_CAR_X & sp_arrow->getY() == MUSTARD_CAR_Y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(RED_CAR_X, RED_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(TURQUOISE_CAR_X, TURQUOISE_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(GREEN_CAR_X, GREEN_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(GREEN_CAR_X, GREEN_CAR_Y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 6;
            engine->transitionIntoScene(new StartScene(engine, 6), new FadeOutScene(10));
        }
    }
}

void ChooseCarScene::createSpriteObjects(){
    SpriteBuilder<Sprite> builder;

    sp_arrow = builder
            .withData(arrowTiles, sizeof(arrowTiles))
            .withSize(SIZE_16_16)
            .withLocation(ARROW_X, ARROW_Y)
            .buildPtr();
    sp_red_car = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(RED_CAR_X + 16, RED_CAR_Y)
            .buildPtr();
    sp_blue_car = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(BLUE_CAR_X + 16, BLUE_CAR_Y)
            .buildPtr();
    sp_green_car = builder
            .withData(green_carTiles, sizeof(green_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GREEN_CAR_X + 16, GREEN_CAR_Y)
            .buildPtr();
    sp_purple_car = builder
            .withData(purple_carTiles, sizeof(purple_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(PURPLE_CAR_X + 16, PURPLE_CAR_Y)
            .buildPtr();
    sp_turquoise_car = builder
            .withData(turquoise_carTiles, sizeof(turquoise_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(TURQUOISE_CAR_X + 16, TURQUOISE_CAR_Y)
            .buildPtr();
    sp_mustard_car = builder
            .withData(mustard_carTiles, sizeof(mustard_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(MUSTARD_CAR_X + 16, MUSTARD_CAR_Y)
            .buildPtr();
}



