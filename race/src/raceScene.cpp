//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include "raceScene.h"
#include "red_car.h"
#include "track1.h"
#include "timer.h"

#define LIMITE_RIGHT 29
#define LIMITE_LEFT 46

std::vector<Sprite *> raceScene::sprites() {
    return {
            raceSprite.get(), sp_scrollingCar.get()
    };
}

std::vector<Background *> raceScene::backgrounds() {

    return {
            bg_track1.get()
    };
}

void raceScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(red_carPal,sizeof(red_carPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(track_pal, sizeof(track_pal)));

    SpriteBuilder<Sprite> builder;

    raceSprite = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH/4, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();

    sp_scrollingCar = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(60, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();

    bg_track1 = std::unique_ptr<Background>(new Background(1, track_data, sizeof(track_data), track1, sizeof(track1)));
    bg_track1.get()->useMapScreenBlock(16);

    initTimer0();
    startTimer0();
    initTimer1();
    startTimer1();
}

void raceScene::tick(u16 keys) {
    if(keys & KEY_LEFT) {
        raceSprite->setVelocity(-2 ,0);
        if(raceSprite->getX() <= LIMITE_LEFT)
            raceSprite->moveTo(LIMITE_LEFT,raceSprite->getY());
    } else if(keys & KEY_RIGHT) {
        raceSprite->setVelocity(+2, 0);
        if(raceSprite->getX() >= (GBA_SCREEN_WIDTH - LIMITE_RIGHT - raceSprite->getWidth()))
            raceSprite->moveTo(GBA_SCREEN_WIDTH - LIMITE_RIGHT - raceSprite->getWidth(),raceSprite->getY());
    } else if (keys & KEY_UP) {
        if(keys & KEY_RIGHT) {
            raceSprite->setVelocity(+2, -2);
        } else if(keys & KEY_LEFT) {
            raceSprite->setVelocity(+2, -2);
        }else{
            raceSprite->setVelocity(0, -2);
        }
    } else if(keys & KEY_DOWN) {
        raceSprite->setVelocity(0, +2);
    } else {
        raceSprite->setVelocity(0, 0);
    }

    scrollY -= 1;
    bg_track1.get()->scroll(scrollX, scrollY);




    //Collision
    if(raceSprite->collidesWith(*sp_scrollingCar)){
        isHit = true;
        if(score > 0){score = score - 5;}
        else{score = 0;}
        TextStream::instance().setText("-5", 1, 1);
    }
    //Timer0; T = 1s
    if(REG_TM1D != timer0){
        timer0 = REG_TM1D;

        timerSec = timer0%60;
        timerMin = (timer0%3600)/60;
        timerHour = timer0/3600;

        //TextStream::instance()<< "H:" << timerHour << "M:" << timerMin << "S:" <<timerSec;
        TextStream::instance().clear();
        std::string score_str = std::to_string(score);
        TextStream::instance().setText(score_str, 0, 1);
        score++;

    }
    if (scroller >= GBA_SCREEN_HEIGHT + 16) {
        scroller = 0;
    }
    sp_scrollingCar->moveTo(50, scroller);
    scroller ++;

    //Timer1 T < 1s
    if(REG_TM3D != timer1 ) {
        timer1 = REG_TM3D;
        //nog niks
    }

}
