//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include "startScene.h"
#include "raceScene.h"
#include "track1.h"
#include "timer.h"
#include "sprite_data.h"
#include "mustardCar.h"


std::vector<Sprite *> raceScene::sprites() {
    return {
            sp_red_car.get(),
            sp_scrollingCar.get(),
            sp_scrollingCar2.get(),
            sp_heart1.get(),
            sp_heart2.get(),
            sp_heart3.get(),
            sp_heart4.get(),
            sp_heart5.get()
    };
}

std::vector<Background *> raceScene::backgrounds() {

    return {
            bg_track1.get()
    };
}

void raceScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(track_pal, sizeof(track_pal)));

    SpriteBuilder<Sprite> builder;

    sp_red_car = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH/4, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();
    createObstacle();
    sp_scrollingCar2 = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(160, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();

    sp_heart1 = builder
            .withData(heartTiles, sizeof(heartTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-21, 0)
            .buildPtr();
    sp_heart2 = builder
            .withData(heartTiles, sizeof(heartTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-21, 16)
            .buildPtr();
    sp_heart3 = builder
            .withData(heartTiles, sizeof(heartTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-21, 32)
            .buildPtr();
    sp_heart4 = builder
            .withData(heartTiles, sizeof(heartTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-21, 48)
            .buildPtr();
    sp_heart5 = builder
            .withData(heartTiles, sizeof(heartTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH-21, 64)
            .buildPtr();

    bg_track1 = std::unique_ptr<Background>(new Background(1, track_data, sizeof(track_data), track1, sizeof(track1)));
    bg_track1.get()->useMapScreenBlock(16);

    initTimer0();
    toggleTimer0();
    initTimer1();
    toggleTimer1();

}

void raceScene::tick(u16 keys) {
    std::string score_str = std::to_string(score);

    //Dead?
    if(!isDead){
        //Car movement
        if(keys & KEY_LEFT) {
            sp_red_car->setVelocity(-2 ,0);
            if(sp_red_car->getX() <= LIMIT_LEFT)
                sp_red_car->moveTo(LIMIT_LEFT,sp_red_car->getY());
        } else if(keys & KEY_RIGHT) {
            sp_red_car->setVelocity(+2, 0);
            if(sp_red_car->getX() >= (GBA_SCREEN_WIDTH - LIMIT_RIGHT - sp_red_car->getWidth()))
                sp_red_car->moveTo(GBA_SCREEN_WIDTH - LIMIT_RIGHT - sp_red_car->getWidth(),sp_red_car->getY());
        } else if (keys & KEY_UP) {
            if(keys & KEY_RIGHT) {
                sp_red_car->setVelocity(+2, -2);
            } else if(keys & KEY_LEFT) {
                sp_red_car->setVelocity(+2, -2);
            }else{
                sp_red_car->setVelocity(0, -2);
            }
        } else if(keys & KEY_DOWN) {
            sp_red_car->setVelocity(0, +2);
        } else {
            sp_red_car->setVelocity(0, 0);
        }
        //Scroller for background
        scrollY -= 1;
        bg_track1.get()->scroll(scrollX, scrollY);
        //Scroller for objects
        if (scroller >= GBA_SCREEN_HEIGHT + 16) {
            scroller = 0;
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            // clear obstacle (car sprite)
            // create Obstacle
        }
        sp_scrollingCar->moveTo(xPos, scroller);
        scroller ++;
        sp_scrollingCar2->moveTo(160, scroller2);
        scroller2 ++;
    }
    else{
        TextStream::instance().clear();
        toggleTimer0();
        scrollY = 0;
        scroller = 0;
        TextStream::instance().setText("YOU DIED",8,12);
        TextStream::instance().setText("SCORE: ",9,13);
        TextStream::instance().setText(score_str,9,19);

        if(keys & KEY_START){
            engine->transitionIntoScene(new startScene(engine), new FadeOutScene(10));
        }
    }

    //Collision
    isHit_mem = isHit;
    if(sp_red_car->collidesWith(*sp_scrollingCar)){isHit = true;}
    else{isHit = false;}

    if(isHit == true & isHit_mem != true){
        if(score > 0){score = score - 6;}
        if (score <= 0){score = 0;}
        TextStream::instance().setText("-5", 1, 2);
        if(life > 0){
            life --;
            switch (life){
                case 4:
                    sp_heart5->moveTo(GBA_SCREEN_HEIGHT,GBA_SCREEN_HEIGHT);
                    break;
                case 3:
                    sp_heart4->moveTo(GBA_SCREEN_HEIGHT,GBA_SCREEN_HEIGHT);
                    break;
                case 2:
                    sp_heart3->moveTo(GBA_SCREEN_HEIGHT,GBA_SCREEN_HEIGHT);
                    break;
                case 1:
                    sp_heart2->moveTo(GBA_SCREEN_HEIGHT,GBA_SCREEN_HEIGHT);
                    break;
                case 0:
                    sp_heart1->moveTo(GBA_SCREEN_HEIGHT,GBA_SCREEN_HEIGHT);
                    break;
            }
        }
        else{isDead = true;}
    }

    //Timer0; T = 1s
    if(REG_TM1D != timer0){
        timer0 = REG_TM1D;
        TextStream::instance().clear();
        score++;
        TextStream::instance().setText(score_str, 0, 1);
    }


    //Timer1 T < 1s
    if(REG_TM3D != timer1 ) {
        timer1 = REG_TM3D;
        //nog niks
    }

    // generate obstacle

}

int raceScene::createObstacle() {

    srand(time(NULL));
    int select = rand()%6;
    xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
    static unsigned long int ID =0;
    SpriteBuilder<Sprite> builder;
    ID++;

    if(ID>3)
        ID = 1;

    switch (select) {
        case 1:
            sp_scrollingCar = builder
                    .withData(red_carTiles, sizeof(red_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
        case 2:
            sp_scrollingCar = builder
                    .withData(purple_carTiles, sizeof(purple_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
        case 3:
            sp_scrollingCar = builder
                    .withData(turquoise_carTiles, sizeof(turquoise_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
        case 4:
            sp_scrollingCar = builder
                    .withData(blue_carTiles, sizeof(blue_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
        case 5:
            sp_scrollingCar = builder
                    .withData(green_carTiles, sizeof(green_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
        case 6:
            sp_scrollingCar = builder
                    .withData(mustard_carTiles, sizeof(mustard_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            return ID;
            //break;
    }
}
