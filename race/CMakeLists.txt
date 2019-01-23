project(race)

add_executable(${PROJECT_NAME}.elf
        src/main.cpp
        src/RaceScene.cpp
        src/RaceScene.h
        src/track1.h
        src/timer.cpp
        src/timer.h
        src/StartScene.h
        src/StartScene.cpp
        src/sprite_data.h
        src/ChooseCarScene.h
        src/ChooseCarScene.cpp
        src/Game.h src/soundFx_hit.h src/soundFx_menuNav.h)



target_link_libraries(${PROJECT_NAME}.elf gba-sprite-engine)

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -v -O binary ${PROJECT_NAME}.elf ${PROJECT_NAME}.gba
        )
