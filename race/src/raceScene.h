//
// Created by Othmane Amdaui on 01-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H


#include <libgba-sprite-engine/scene.h>

class raceScene : public Scene{
private:
    std::unique_ptr<Sprite> raceSprite;
    std::unique_ptr<Sprite> sp_scrollingCar;
    std::unique_ptr<Sprite> sp_heart;
    std::unique_ptr<Background> bg_track1;

    int scrollX, scrollY;

    int scroller = 0;
    int timer0 = -1;
    int timer1 = -1;
    int timerSec = 0;
    int timerMin = 0;
    int timerHour = 0;
    int score = 0;
    int levens = 6;
    bool isHit = false;

public:
    raceScene(std::shared_ptr<GBAEngine> engine) : Scene(engine), scrollX(0), scrollY(0) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
