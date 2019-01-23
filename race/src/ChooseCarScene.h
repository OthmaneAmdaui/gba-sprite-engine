//
// Created by Lukas on 19/12/2018.
//

#ifndef GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H
#define GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/gba_engine.h>

#define red_car_x 36
#define red_car_y 60
#define blue_car_x 96
#define blue_car_y 60
#define green_car_x 156
#define green_car_y 60
#define purple_car_x 36
#define purple_car_y 100
#define turquoise_car_x 96
#define turquoise_car_y 100
#define mustard_car_x 156
#define mustard_car_y 100

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
    int getChosenCar(){return chosen_car;}

};
#endif //GBA_SPRITE_ENGINE_PROJECT_CHOOSECARSCENE_H
