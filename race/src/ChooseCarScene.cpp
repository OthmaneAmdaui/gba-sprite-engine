//
// Created by Lukas on 19/12/2018.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <vector>
#include "ChooseCarScene.h"
#include "StartScene.h"
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

    SpriteBuilder<Sprite> builder;

    sp_arrow = builder
            .withData(arrowTiles, sizeof(arrowTiles))
            .withSize(SIZE_16_16)
            .withLocation(36, 60)
            .buildPtr();
    sp_red_car = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(red_car_x + 16, red_car_y)
            .buildPtr();
    sp_blue_car = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(blue_car_x + 16, blue_car_y)
            .buildPtr();
    sp_green_car = builder
            .withData(green_carTiles, sizeof(green_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(green_car_x + 16, green_car_y)
            .buildPtr();
    sp_purple_car = builder
            .withData(purple_carTiles, sizeof(purple_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(purple_car_x + 16, purple_car_y)
            .buildPtr();
    sp_turquoise_car = builder
            .withData(turquoise_carTiles, sizeof(turquoise_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(turquoise_car_x + 16, turquoise_car_y)
            .buildPtr();
    sp_mustard_car = builder
            .withData(mustard_carTiles, sizeof(mustard_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(mustard_car_x + 16, mustard_car_y)
            .buildPtr();
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

    if(sp_arrow->getX() == red_car_x & sp_arrow->getY() == red_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(blue_car_x, blue_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(mustard_car_x, mustard_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(purple_car_x, purple_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(purple_car_x, purple_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 1;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == blue_car_x & sp_arrow->getY() == blue_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(green_car_x, green_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(red_car_x, red_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 2;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == green_car_x & sp_arrow->getY() == green_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(purple_car_x, purple_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(blue_car_x, blue_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(mustard_car_x, mustard_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(mustard_car_x, mustard_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 3;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == purple_car_x & sp_arrow->getY() == purple_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(green_car_x, green_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(red_car_x, red_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(red_car_x, red_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 4;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == turquoise_car_x & sp_arrow->getY() == turquoise_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(mustard_car_x, mustard_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(purple_car_x, purple_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(blue_car_x, blue_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(blue_car_x, blue_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 5;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == mustard_car_x & sp_arrow->getY() == mustard_car_y){
        if(right_pressed == true & right_mem != true){
            sp_arrow->moveTo(red_car_x, red_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(left_pressed == true & left_mem != true){
            sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (up_pressed == true & up_mem != true){
            sp_arrow->moveTo(green_car_x, green_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if (down_pressed == true & down_mem != true){
            sp_arrow->moveTo(green_car_x, green_car_y);
            engine.get()->enqueueSound(fx_menuNav, sizeof(fx_menuNav), 44100);
        }
        else if(start_pressed == true & start_mem != true){
            chosen_car = 6;
            engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
        }
    }
}



