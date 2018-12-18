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
#include "startScene.h"
#include "raceScene.h"
#include "track1.h"
#include "timer.h"
#include "sprite_data.h"



std::vector<Sprite *> raceScene::sprites() {
    return {
            raceSprite.get(),
            sp_scrollingCar.get(),
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

    raceSprite = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH/4, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();

    sp_scrollingCar = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(60, GBA_SCREEN_HEIGHT/2)
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

    //Car movement
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

    //Collision
    if(raceSprite->collidesWith(*sp_scrollingCar)){
        isHit = true;
        TextStream::instance().setText("-5", 1, 2);
    }

    //Timer0; T = 1s
    if(REG_TM1D != timer0){
        timer0 = REG_TM1D;

        if(isHit == true){
            if(life > 0){
                if(score > 0){score = score - 6;}
                if (score <= 0){score = 0;}

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
            else{
                score = score - 5;
                isDead = true;
            }
            isHit = false;
        }
        TextStream::instance().clear();
        TextStream::instance().setText(score_str, 0, 1);
        score++;
    }

    //Dead
    if(!isDead){
        //Scroller for background
        scrollY -= 1;
        bg_track1.get()->scroll(scrollX, scrollY);
        //Scroller for objects
        if (scroller >= GBA_SCREEN_HEIGHT + 16) {
            scroller = 0;
        }
        sp_scrollingCar->moveTo(50, scroller);
        scroller ++;
    }
    else{
        TextStream::instance().clear();
        toggleTimer0();
        scrollY = 0;
        scroller = 0;
        TextStream::instance().setText("YOU DIED",8,12);
        TextStream::instance().setText("SCORE: ",9,13);
        TextStream::instance().setText(score_str,9,19);
    }


    //Timer1 T < 1s
    if(REG_TM3D != timer1 ) {
        timer1 = REG_TM3D;
        //nog niks
    }

}
