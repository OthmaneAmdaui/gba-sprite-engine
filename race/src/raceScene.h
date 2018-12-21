//
// Created by Othmane Amdaui on 01-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H


#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define LIMIT_RIGHT 29
#define LIMIT_LEFT 46
#define XMIN 46
#define XMAX 195

class raceScene : public Scene{
private:
    std::unique_ptr<Sprite> sp_red_car;
    std::unique_ptr<Sprite> sp_scrollingCar1;
    std::unique_ptr<Sprite> sp_scrollingCar2;
    std::unique_ptr<Sprite> sp_scrollingCar3;
    std::unique_ptr<Sprite> sp_scrollingCar4;
    std::unique_ptr<Sprite> sp_scrollingCar5;
    std::unique_ptr<Sprite> sp_scrollingCar6;
    std::unique_ptr<Sprite> sp_heart1;
    std::unique_ptr<Sprite> sp_heart2;
    std::unique_ptr<Sprite> sp_heart3;
    std::unique_ptr<Sprite> sp_heart4;
    std::unique_ptr<Sprite> sp_heart5;
    std::unique_ptr<Background> bg_track1;

    int scrollX, scrollY;

    int scroller[5] = {0,0,0,0,0};
    int timer0 = -1;
    int timer1 = -1;
    int score = 0;
    int life = 6;
    int velocity = 2;
    int waitingTime = 1;
    int levelCntr = 1;
    int xPos[6] = {XMIN + rand() % ((XMAX + 1) - XMIN),XMIN + rand() % ((XMAX + 1) - XMIN),
                   XMIN + rand() % ((XMAX + 1) - XMIN),XMIN + rand() % ((XMAX + 1) - XMIN),
                   XMIN + rand() % ((XMAX + 1) - XMIN), XMIN + rand() % ((XMAX + 1) - XMIN)};
    int startMovingCounter = 0;
    int obstacleVelocityCntr = 0;
    bool stopStartMovingCntr = false;
    bool startMove[5] = {false, false, false, false, false};
    bool Move[5] = {false, false, false, false, false};
    bool isHit = false;
    bool isHit_mem = false;
    bool isDead = false;

public:
    raceScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;
    void createObstacle(uint8_t select);

};


#endif //GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
