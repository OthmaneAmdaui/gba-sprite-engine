//
// Created by Lukas on 19/12/2018.
//

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_memdef.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <vector>
#include "startScene.h"
#include "raceScene.h"
#include "chooseCarScene.h"
#include "sprite_data.h"



std::vector<Background *> chooseCarScene::backgrounds() {
    return {};
}

std::vector<Sprite *> chooseCarScene::sprites() {
    return {sp_arrow.get(),
            sp_red_car.get(),
            sp_blue_car.get(),
            sp_green_car.get(),
            sp_purple_car.get(),
            sp_turquoise_car.get()};
}

void chooseCarScene::load() {
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
            .withLocation(52, 60)
            .buildPtr();
    sp_blue_car = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(112, 60)
            .buildPtr();
    sp_green_car = builder
            .withData(green_carTiles, sizeof(green_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(172, 60)
            .buildPtr();
    sp_purple_car = builder
            .withData(purple_carTiles, sizeof(purple_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(82, 100)
            .buildPtr();
    sp_turquoise_car = builder
            .withData(turquoise_carTiles, sizeof(turquoise_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(142, 100)
            .buildPtr();

    TextStream::instance().setText("CHOOSE YOUR CAR", 3, 2);

}

void chooseCarScene::tick(u16 keys) {

    //Positive flank detection
    right_mem = right_pressed;
    left_mem = left_pressed;
    if(keys & KEY_RIGHT){right_pressed = true;}
    else{right_pressed = false;}
    if(keys & KEY_LEFT){left_pressed = true;}
    else{left_pressed = false;}

    if(sp_arrow->getX() == red_car_x & sp_arrow->getY() == red_car_y){
        if(right_pressed == true & right_mem != true){sp_arrow->moveTo(blue_car_x, blue_car_y);}
        else if(left_pressed == true & left_mem != true){sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);}
        else if(keys & KEY_START){
            chosen_car = 1;
            engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == blue_car_x & sp_arrow->getY() == blue_car_y){
        if(right_pressed == true & right_mem != true){sp_arrow->moveTo(green_car_x, green_car_y);}
        else if(left_pressed == true & left_mem != true){sp_arrow->moveTo(red_car_x, red_car_y);}
        else if(keys & KEY_START){
            chosen_car = 2;
             engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }
    }
    else if(sp_arrow->getX() == green_car_x & sp_arrow->getY() == green_car_y){
        if(right_pressed == true & right_mem != true){sp_arrow->moveTo(purple_car_x, purple_car_y);}
        else if(left_pressed == true & left_mem != true){sp_arrow->moveTo(blue_car_x, blue_car_y);}
        else if(keys & KEY_START){
            chosen_car = 3;
            engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == purple_car_x & sp_arrow->getY() == purple_car_y){
        if(right_pressed == true & right_mem != true){sp_arrow->moveTo(turquoise_car_x, turquoise_car_y);}
        else if(left_pressed == true & left_mem != true){sp_arrow->moveTo(green_car_x, green_car_y);}
        else if(keys & KEY_START){
            chosen_car = 4;
            engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }

    }
    else if(sp_arrow->getX() == turquoise_car_x & sp_arrow->getY() == turquoise_car_y){
        if(right_pressed == true & right_mem != true){sp_arrow->moveTo(red_car_x, red_car_y);}
        else if(left_pressed == true & left_mem != true){sp_arrow->moveTo(purple_car_x, purple_car_y);}
        else if(keys & KEY_START){
            chosen_car = 5;
            engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }

    }

}


