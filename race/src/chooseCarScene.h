//
// Created by Lukas on 19/12/2018.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define ARROW_X 36
#define ARROW_Y 60
#define RED_CAR_X 36
#define RED_CAR_Y 60
#define BLUE_CAR_X 96
#define BLUE_CAR_Y 60
#define GREEN_CAR_X 156
#define GREEN_CAR_Y 60
#define PURPLE_CAR_X 36
#define PURPLE_CAR_Y 100
#define TURQUOISE_CAR_X 96
#define TURQUOISE_CAR_Y 100
#define MUSTARD_CAR_X 156
#define MUSTARD_CAR_Y 100

class ChooseCarScene : public Scene {
private:
    std::unique_ptr<Sprite> sp_arrow;
    std::unique_ptr<Sprite> sp_red_car;
    std::unique_ptr<Sprite> sp_blue_car;
    std::unique_ptr<Sprite> sp_green_car;
    std::unique_ptr<Sprite> sp_purple_car;
    std::unique_ptr<Sprite> sp_turquoise_car;
    std::unique_ptr<Sprite> sp_mustard_car;

    bool right_pressed = false;
    bool right_mem = false;
    bool left_pressed = false;
    bool left_mem = false;
    bool up_pressed = false;
    bool up_mem = false;
    bool down_pressed = false;
    bool down_mem = false;
    bool start_pressed = false;
    bool start_mem = false;
    //1:red (default), 2:blue, 3:green, 4:purple, 5:turquoise, 6:mustard
    int chosen_car = 1;

public:
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

    ChooseCarScene(std::shared_ptr<GBAEngine> engine) : Scene(engine){}

    void load() override;
    void tick(u16 keys) override;
    void createSpriteObjects();

};
#endif //GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H
