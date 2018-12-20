project(race)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/raceScene.cpp
        src/raceScene.h
        src/redCar.h
        src/track1.h
        src/timer.cpp src/timer.h src/startScene.h src/startScene.cpp src/arrow.h src/sprite_data.h src/chooseCarScene.h src/chooseCarScene.cpp src/blueCar.h src/mustardCar.h src/purpleCar.h src/greenCar.h src/turquoiseCar.h)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
