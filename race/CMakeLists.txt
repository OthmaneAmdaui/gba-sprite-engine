project(race)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/raceScene.cpp
        src/raceScene.h
        src/track1.h
        src/timer.cpp src/timer.h src/startScene.h src/startScene.cpp src/sprite_data.h src/chooseCarScene.h src/chooseCarScene.cpp)

target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
