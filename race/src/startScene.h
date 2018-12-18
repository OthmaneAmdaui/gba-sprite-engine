//
// Created by Lukas on 17/12/2018.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/scene.h>

#define Y_TOP 36
#define Y_BOTTOM 76

class startScene : public Scene {
private:
    std::unique_ptr<Sprite> arrow;


public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    startScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};
#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
