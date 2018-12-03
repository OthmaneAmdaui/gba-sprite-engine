//
// Created by Othmane Amdaui on 01-Dec-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H


#include <libgba-sprite-engine/scene.h>

class raceScene : public Scene{
private:
    std::unique_ptr<Sprite> raceSprite;

public:
    raceScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_RACESCENE_H
