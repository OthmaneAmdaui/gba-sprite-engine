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
#include "chooseCarScene.h"
#include "raceScene.h"
#include "track1.h"
#include "timer.h"
#include "sprite_data.h"
#include "soundFx_hit.h"

std::vector<Sprite *> RaceScene::sprites() {
    return {
            sp_red_car.get(),
            sp_scrollingCar1.get(),
            sp_scrollingCar2.get(),
            sp_scrollingCar3.get(),
            sp_scrollingCar4.get(),
            sp_scrollingCar5.get(),
            //sp_scrollingCar6.get(),
            sp_heart1.get(),
            sp_heart2.get(),
            sp_heart3.get(),
            sp_heart4.get(),
            sp_heart5.get()
    };
}

std::vector<Background *> RaceScene::backgrounds() {

    return {
            bg_track1.get()
    };
}

void RaceScene::load() {
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal,sizeof(sharedPal)));
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(track_pal, sizeof(track_pal)));

    bg_track1 = std::unique_ptr<Background>(new Background(1, track_data, sizeof(track_data), track1, sizeof(track1)));
    bg_track1.get()->useMapScreenBlock(16);

    SpriteBuilder<Sprite> builder;
    sp_red_car = builder
            .withData(red_carTiles, sizeof(red_carTiles))
            .withSize(SIZE_16_16)
            .withLocation(GBA_SCREEN_WIDTH/4, GBA_SCREEN_HEIGHT/2)
                    //.withinBounds()
            .buildPtr();

    srand(time(NULL));
    createObstacle(1);
    createObstacle(2);
    createObstacle(3);
    createObstacle(4);
    createObstacle(5);
    //createObstacle(6);
    createHearts();

    initTimer0();
    initTimer1();
    startTimer0();
    startTimer1();
}

void RaceScene::tick(u16 keys) {
    std::string score_str = std::to_string(score);

    checkLevel();

    if(checkStartMovingCounter())
        stopStartMovingCntr = true;         // after the last one

    enableScrollObstacles();

    //Dead?
    if(!isDead){
        //Car movement
        checkCarMovements(keys);
        //Scroller for background
        scrollBackGround();
        //Scroller for objects
        checkScrollObjects();
        moveScrollObjects();
        // update score
        updateScore(score_str);
        checkMovingCounter();
    }
    else{
            dead(score_str);
            if(keys & KEY_START){
                engine->transitionIntoScene(new StartScene(engine), new FadeOutScene(10));
            }
    }
    //Collision
    checkCollision();
}

void RaceScene::createObstacle(uint8_t select) {

    //srand(time(NULL));
    //int select = rand()%6;
    int xPos=0;
    SpriteBuilder<Sprite> builder;

    switch (select) {
        case 1:
            xPos = XMIN + rand() % ((XMAX + 1)-XMIN);
            sp_scrollingCar1 = builder
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
            sp_scrollingCar6 = builder
                    .withData(mustard_carTiles, sizeof(mustard_carTiles))
                    .withSize(SIZE_16_16)
                    .withLocation(xPos, 240)
                            //.withinBounds()
                    .buildPtr();
            break;
    }
}

void RaceScene::createHearts(){
    SpriteBuilder<Sprite> builder;
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
}

bool RaceScene::checkStartMovingCounter() {
    switch (startMovingCounter) {        // time between each obstacle
        case 1:
            startMove[0] = true;
            break;
        case 50:
            startMove[1] = true;
            break;
        case 100:
            startMove[2] = true;
            break;
        case 150:
            startMove[3] = true;
            break;
        case 200:
            startMove[4] = true;
            // after last resset startMovingCounter and stop the counting
            startMovingCounter = 0;
            return true; // after last obstacle, doesn't need to count
    }
    return false;
}

void RaceScene::checkLevel() {

    switch (level) {
        case 10:
            setTimer1Value(0xCCD);
            break;
        case 20:
            setTimer1Value(0x924);
            break;
        case 30:
            setTimer1Value(0x666);
            break;
        case 40:
            setTimer1Value(0x333);
            break;
        case 50:
            setTimer1Value(0x19A);
            break;
        case 60:
            setTimer1Value(0xCCD);
            velocity = 3;
            break;
    }
    /*if( (score%5) == 0 )
    {
        setTimer1Value(0x52);
    }*/
}

void RaceScene::checkLife() {

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

void RaceScene::checkCollision(){
    isHit_mem = isHit;
    if((sp_red_car->collidesWith(*sp_scrollingCar1)) || (sp_red_car->collidesWith(*sp_scrollingCar2))
       || (sp_red_car->collidesWith(*sp_scrollingCar3)) || (sp_red_car->collidesWith(*sp_scrollingCar4))
       || (sp_red_car->collidesWith(*sp_scrollingCar5)) || (sp_red_car->collidesWith(*sp_scrollingCar6)))
    {
        isHit = true;

        //engine.get()->enqueueSound(hit, sizeof(hit), 44100);
    }
    else{isHit = false;}

    if(isHit == true & isHit_mem != true){
        if(score > 0){score = score - 6;}
        if (score <= 0){score = 0;}
        TextStream::instance().setText("-5", 1, 2);
        if(life > 0){
            life --;
            checkLife();
        }
        else{isDead = true;}
    }
}

void RaceScene::checkCarMovements(u16& keys){
    if(keys & KEY_LEFT) {
        sp_red_car->setVelocity(-2 ,0);
        if(sp_red_car->getX() <= LIMIT_LEFT)
            sp_red_car->moveTo(LIMIT_LEFT,sp_red_car->getY());
    } else if(keys & KEY_RIGHT) {
        sp_red_car->setVelocity(+2, 0);
        if(sp_red_car->getX() >= (GBA_SCREEN_WIDTH - LIMIT_RIGHT - sp_red_car->getWidth()))
            sp_red_car->moveTo(GBA_SCREEN_WIDTH - LIMIT_RIGHT - sp_red_car->getWidth(),sp_red_car->getY());
    } else if (keys & KEY_UP) {
        sp_red_car->setVelocity(0, -2);
        if(sp_red_car->getY() <= LIMIT_UP)
            sp_red_car->moveTo(sp_red_car->getX(), LIMIT_UP);
    } else if(keys & KEY_DOWN) {
        sp_red_car->setVelocity(0, +2);
        if(sp_red_car->getY() >= (GBA_SCREEN_HEIGHT - 18))
            sp_red_car->moveTo(sp_red_car->getX(), (GBA_SCREEN_HEIGHT - 18));
    } else {
        sp_red_car->setVelocity(0, 0);
    }
}

void RaceScene::checkScrollObjects(){
    if (scrollYObj[0] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[0] = 0;
        xPos[0] = XMIN + rand() % ((XMAX + 1)-XMIN);
    }
    if (scrollYObj[1] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[1] = 0;
        xPos[1] = XMIN + rand() % ((XMAX + 1) - XMIN);
    }
    if (scrollYObj[2] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[2] = 0;
        xPos[2] = XMIN + rand() % ((XMAX + 1) - XMIN);
    }
    if (scrollYObj[3] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[3] = 0;
        xPos[3] = XMIN + rand() % ((XMAX + 1) - XMIN);
    }
    if (scrollYObj[4] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[4] = 0;
        xPos[4] = XMIN + rand() % ((XMAX + 1) - XMIN);
    }
    /*if (scrollYObj[5] >= GBA_SCREEN_HEIGHT + 16) {
        scrollYObj[5] = 0;
        xPos[5] = XMIN + rand() % ((XMAX + 1) - XMIN);
    }*/
}

void RaceScene::moveScrollObjects(){
    if(Move[0])
    {
        sp_scrollingCar1->moveTo(xPos[0], scrollYObj[0]);
        scrollYObj[0] +=velocity;
        Move[0] = false;
    }
    if(Move[1])
    {
        sp_scrollingCar2->moveTo(xPos[1], scrollYObj[1]);
        scrollYObj[1] +=velocity;
        Move[1] = false;
    }
    if(Move[2])
    {
        sp_scrollingCar3->moveTo(xPos[2], scrollYObj[2]);
        scrollYObj[2] +=velocity;
        Move[2] = false;
    }
    if(Move[3])
    {
        sp_scrollingCar4->moveTo(xPos[3], scrollYObj[3]);
        scrollYObj[3] +=velocity;
        Move[3] = false;
    }
    if(Move[4])
    {
        sp_scrollingCar5->moveTo(xPos[4], scrollYObj[4]);
        scrollYObj[4] +=velocity;
        Move[4] = false;
    }
    /*if(Move[5])
    {
        sp_scrollingCar6->moveTo(xPos[5], scrollYObj[5]);
        scrollYObj[5] +=velocity;
        Move[5] = false;
    }*/
}

void RaceScene::stopScrollingAll(){
    scrollY = 0;
    scrollX = 0;
    for (int i = 0; i < 6; i++){
        scrollYObj[i] = 0;
    }
}

void RaceScene::scrollBackGround(){
    scrollY -= 1;
    bg_track1.get()->scroll(scrollX, scrollY);
}

void RaceScene::updateScore(std::string& score_str){
    //Timer0; T = 1s
    if(REG_TM1D != timer0){
        timer0 = REG_TM1D;
        TextStream::instance().clear();
        score++;
        level++;
        TextStream::instance().setText(score_str, 0, 1);
    }
}

void RaceScene::dead(std::string& score_str){

    TextStream::instance().clear();
    stopTimer0();
    stopTimer1();
    stopScrollingAll();
    TextStream::instance().setText("YOU DIED",8,12);
    TextStream::instance().setText("SCORE: ",9,13);
    TextStream::instance().setText(score_str,9,19);
}

void RaceScene::checkMovingCounter(){
    //Timer1 T < 25ms
    if(REG_TM2D != timer1 ) {
        timer1 = REG_TM2D;
        if(!stopStartMovingCntr){       // count until all the obstacles are moved
            startMovingCounter++;
        }
        obstacleVelocityCntr++;
    }
}

void RaceScene::enableScrollObstacles(){
    // unlock (move = true)
    if(obstacleVelocityCntr == WAITING_TIME) {
        if (startMove[0]) { Move[0] = true; }
        if (startMove[1]) { Move[1] = true; }
        if (startMove[2]) { Move[2] = true; }
        if (startMove[3]) { Move[3] = true; }
        if (startMove[4]) { Move[4] = true; }
        //if (startMove[5]) { Move[5] = true; }
        obstacleVelocityCntr = 0;
    }
}
