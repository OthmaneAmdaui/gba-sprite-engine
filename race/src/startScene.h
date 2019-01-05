//
// Created by Lukas on 17/12/2018.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define Y_TOP 36
#define Y_BOTTOM 76

class startScene : public Scene {
private:
    std::unique_ptr<Sprite> sp_arrow;

    bool up_pressed = false;
    bool up_mem = false;
    bool down_pressed = false;
    bool down_mem = false;
    bool start_pressed = false;
    bool start_mem = false;

public:

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    startScene(std::shared_ptr<GBAEngine> engine) : Scene(engine) {}

    void load() override;
    void tick(u16 keys) override;

};
#endif //GBA_SPRITE_ENGINE_PROJECT_STARTSCENE_H
