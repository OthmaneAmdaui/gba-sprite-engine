//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/sprites/affine_sprite.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba/tonc_memmap.h>
#include <libgba-sprite-engine/background/text_stream.h>
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

    //Autoscroller
    if(REG_TM3D != timerSec ) {
        timerSec = REG_TM3D;

        if (teller >= GBA_SCREEN_HEIGHT + 16) {
            teller = 0;
            TextStream::instance().clear();
        }
        sp_scrollingCar->moveTo(60, teller);
        teller++;
    }
    if(keys & KEY_START)  // pause by disabling timer
        REG_TM2CNT ^= TM_ENABLE;

    if(keys & KEY_SELECT) // pause by enabling cascade
        REG_TM2CNT ^= TM_CASCADE;

    //Collision
    if(raceSprite->collidesWith(*sp_scrollingCar)){
        TextStream::instance().setText("Raak en kapot", 3, 8);
    }
}
