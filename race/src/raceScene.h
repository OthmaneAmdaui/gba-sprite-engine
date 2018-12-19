//
// Created by Othmane Amdaui on 01-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H


#include <libgba-sprite-engine/scene.h>

#define LIMITE_RIGHT 29
#define LIMITE_LEFT 46

class raceScene : public Scene{
private:
    std::unique_ptr<Sprite> sp_red_car;
    std::unique_ptr<Sprite> sp_scrollingCar;
    std::unique_ptr<Sprite> sp_heart1;
    std::unique_ptr<Sprite> sp_heart2;
    std::unique_ptr<Sprite> sp_heart3;
    std::unique_ptr<Sprite> sp_heart4;
    std::unique_ptr<Sprite> sp_heart5;
    std::unique_ptr<Background> bg_track1;

    int scrollX, scrollY;

    int scroller = 0;
    int timer0 = -1;
    int timer1 = -1;
    int score = 0;
    int life = 6;
    bool isHit = false;
    bool isDead = false;

public:
    raceScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
