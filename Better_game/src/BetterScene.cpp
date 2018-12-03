//
// Created by Othmane Amdaui on 29-Nov-18.
//

#include "BetterScene.h"
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include "mooi.h"

std::vector<Sprite *> BetterScene::sprites() {
    return {
        mooiSprite.get()
    };
}

std::vector<Background *> BetterScene::backgrounds() {

    return {};
}

void BetterScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(paddoPal,sizeof(paddoPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager());

    SpriteBuilder<Sprite> builder;

    mooiSprite = builder
            .withData(paddoTiles, sizeof(paddoTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_HEIGHT/2, GBA_SCREEN_WIDTH/2)
            .buildPtr();
}

void BetterScene::tick(u16 keys) {
    //mooiSprite.get() ->moveTo(mooiSprite.get()->getX(),mooiSprite.get()->getY() + 1);
    if(keys & KEY_LEFT) {
        mooiSprite->setVelocity(-2 ,0);
        if(mooiSprite->getX() <= 35)
            mooiSprite->moveTo(35,mooiSprite->getY());
    } else if(keys & KEY_RIGHT) {
        mooiSprite->setVelocity(+2, 0);
        if(mooiSprite->getX() >= (GBA_SCREEN_WIDTH - 35 - mooiSprite->getWidth()))
            mooiSprite->moveTo(GBA_SCREEN_WIDTH - 35 - mooiSprite->getWidth(),mooiSprite->getY());
    } else if (keys & KEY_UP) {
        mooiSprite->setVelocity(0, -2);
    } else if(keys & KEY_DOWN) {
        mooiSprite->setVelocity(0, +2);
    } else {
        mooiSprite->setVelocity(0, 0);
    }
}