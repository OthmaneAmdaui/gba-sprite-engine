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
            sp_scrollingCar3.get(),
            sp_scrollingCar4.get(),
            sp_scrollingCar5.get(),
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
    srand(time(NULL));
    createObstacle(2);
    createObstacle(3);
    createObstacle(4);
    createObstacle(5);
    createObstacle(6);
    /*sp_scrollingCar = builder
            .withData(blue_carTiles, sizeof(blue_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(160, GBA_SCREEN_HEIGHT/2)
            //.withinBounds()
            .buildPtr();*/

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
    // first time
    if(secCounter == 1) //
    {
        //startMovingObstacle1 = true;
        move[0] = true;
    }
    if(secCounter == 2)
    {
        move[1] = true;
    }
    /*if(firstLoad){
        // 3sec later start move the first obstacle
        switch (secCounter){
            case 1:
                startMovingObstacle1 = true;
                move1 = true;
                secCounter = 0;
                break;
            // case 5:
            // firstLoad =false;
        }
    }*/
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
       // if(startMovingObstacle1)
        //{
            if (scroller >= GBA_SCREEN_HEIGHT + 16) {
                scroller = 0;
                xPos[0] = XMIN + rand() % ((XMAX + 1)-XMIN);
                //move1 = false;
                //obstaclePassed = true;
                //createObstacle();
                // clear obstacle (car sprite)
                // create Obstacle
            }
            if (scroller2 >= GBA_SCREEN_HEIGHT + 16) {
                scroller2 = 0;
                xPos[1] = XMIN + rand() % ((XMAX + 1) - XMIN);
            }
            if (scroller3 >= GBA_SCREEN_HEIGHT + 16) {
                scroller3 = 0;
                xPos[2] = XMIN + rand() % ((XMAX + 1) - XMIN);
            }
            if(move[0])
            {
                sp_scrollingCar->moveTo(xPos[0], scroller);
                scroller +=velocity;
                //move[0] = false;
            }
            if(move[1])
            {
                sp_scrollingCar2->moveTo(xPos[1], scroller2);
                scroller2 +=velocity;
                secCounter = 0;             // wait until next time
                move[1] = false;
                move[0] = false;
            }

            if(move[2])
            {
                sp_scrollingCar3->moveTo(xPos[2], scroller3);
                scroller3 +=velocity;
                move[2] = false;
            }
//            sp_scrollingCar->moveTo(xPos[0], scroller);
//            scroller +=velocity;
        //}
/*        if (scroller >= GBA_SCREEN_HEIGHT + 16) {
            scroller = 0;
            xPos[0] = XMIN + rand() % ((XMAX + 1)-XMIN);
            //createObstacle();
            // clear obstacle (car sprite)
            // create Obstacle
        }
        if (scroller2 >= GBA_SCREEN_HEIGHT + 16) {
            scroller2 = 0;
            xPos[1] = XMIN + rand() % ((XMAX + 1) - XMIN);
        }
        if (scroller3 >= GBA_SCREEN_HEIGHT + 16) {
            scroller3 = 0;
            xPos[2] = XMIN + rand() % ((XMAX + 1) - XMIN);
        }
        if (scroller4 >= GBA_SCREEN_HEIGHT + 16) {
            scroller4 = 0;
            xPos[3] = XMIN + rand() % ((XMAX + 1) - XMIN);
        }
        if (scroller5 >= GBA_SCREEN_HEIGHT + 16) {
            scroller5 = 0;
            xPos[4] = XMIN + rand() % ((XMAX + 1) - XMIN);
        }
        sp_scrollingCar->moveTo(xPos[0], scroller);
        scroller +=velocity;
        sp_scrollingCar2->moveTo(xPos[1], scroller2);
        scroller2 +=velocity;
        sp_scrollingCar3->moveTo(xPos[2], scroller3);
        scroller3 +=velocity;
        sp_scrollingCar4->moveTo(xPos[3], scroller4);
        scroller4 +=velocity;
        sp_scrollingCar5->moveTo(xPos[4], scroller5);
        scroller5 +=velocity;
        */
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
        secCounter++;
        //nog niks
    }

    // generate obstacle

}

void raceScene::createObstacle(uint8_t select) {

    //srand(time(NULL));
    //int select = rand()%6;
    int xPos=0;
    SpriteBuilder<Sprite> builder;

    switch (select) {
        case 1:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar = builder
                    .withData(red_carTiles, sizeof(red_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
        case 2:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar2 = builder
                    .withData(purple_carTiles, sizeof(purple_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
        case 3:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar3 = builder
                    .withData(turquoise_carTiles, sizeof(turquoise_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
        case 4:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar4 = builder
                    .withData(blue_carTiles, sizeof(blue_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
        case 5:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar5 = builder
                    .withData(green_carTiles, sizeof(green_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
        case 6:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar = builder
                    .withData(mustard_carTiles, sizeof(mustard_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
    }
}
