//
// Created by Othmane Amdaui on 01-Dec-18.
//

#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "raceScene.h"
#include "red_car.h"
#include "track1.h"

std::vector<Sprite *> raceScene::sprites() {
    return {
            raceSprite.get()
    };
}

std::vector<Background *> raceScene::backgrounds() {

    return {
            bg_test.get()
    };
}

void raceScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(red_carPal,sizeof(red_carPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(track_pal, sizeof(track_pal)));

    SpriteBuilder<Sprite> builder;

    raceSprite = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_HEIGHT/2, GBA_SCREEN_WIDTH/2)
            .buildPtr();

    bg_test = std::unique_ptr<Background>(new Background(1, track_data, sizeof(track_data), track1, sizeof(track1)));
    bg_test.get()->useMapScreenBlock(16);
}

void raceScene::tick(u16 keys) {
    if(keys & KEY_LEFT) {
        raceSprite->setVelocity(-2 ,0);
        if(raceSprite->getX() <= 35)
            raceSprite->moveTo(35,raceSprite->getY());
    } else if(keys & KEY_RIGHT) {
        raceSprite->setVelocity(+2, 0);
        if(raceSprite->getX() >= (GBA_SCREEN_WIDTH - 35 - raceSprite->getWidth()))
            raceSprite->moveTo(GBA_SCREEN_WIDTH - 35 - raceSprite->getWidth(),raceSprite->getY());
    } else if (keys & KEY_UP) {
        raceSprite->setVelocity(0, -2);
    } else if(keys & KEY_DOWN) {
        raceSprite->setVelocity(0, +2);
    } else if((keys & KEY_UP) && (keys & KEY_LEFT)) {
        raceSprite->setVelocity(-2, -2);
    } else if((keys & (KEY_UP|KEY_RIGHT))){// && (keys & KEY_RIGHT)) {
        raceSprite->setVelocity(+2, -2);
    } else {
        raceSprite->setVelocity(0, 0);
    }

    scrollY -= 1;
    bg_test.get()->scroll(scrollX, scrollY);

}
