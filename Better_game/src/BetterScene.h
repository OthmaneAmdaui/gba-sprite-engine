//
// Created by Othmane Amdaui on 29-Nov-18.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_BETTERSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_BETTERSCENE_H


#include <libgba-sprite-engine/scene.h>

class BetterScene : public Scene {
private:
    std::unique_ptr<Sprite> mooiSprite;

public:
    BetterScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    void load() override;
    void tick(u16 i) override;

};


#endif //GBA_SPRITE_ENGINE_PROJECT_BETTERSCENE_H
