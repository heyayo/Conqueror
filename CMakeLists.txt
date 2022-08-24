cmake_minimum_required(VERSION 3.0.0)
project(Prototype)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set(CMAKE_GENERATOR_PLATFORM x64)

add_executable(Prototype
        main.cpp
        Entity.cpp
        Maths.cpp
        Physical.cpp
        Player.cpp
        Scene.cpp
        UiElement.cpp
        TextBox.cpp
        Scenes/TestScene.cpp
        V2.cpp
        StaticBody.cpp
        Wall.cpp
        Arrow.cpp
        Game.cpp
        Slime.cpp
        Scenes/MainMenu.cpp
        Config.cpp
        Skeleton.cpp
        Undead.cpp
        Demon.cpp
        Door.cpp
        Enemy.cpp
        DeadSoul.cpp
        Actor.cpp
        SaveState.cpp
        Group.cpp
        Scenes/LevelOne.cpp
        Goblin.cpp
        Scenes/LevelTwo.cpp
        timer.cpp
        Melee.cpp
        Scenes/LevelFive.cpp
        Scenes/classChoose.cpp
        Dragon.cpp
         "Scenes/LevelFour.cpp" "Scenes/LevelFour.h")

target_include_directories(Prototype PUBLIC headers)
target_include_directories(Prototype PUBLIC Scenes)
if (UNIX)
    target_link_libraries(Prototype ${CMAKE_SOURCE_DIR}/lib/libraylib.a)
endif(UNIX)
if(WIN32)
    target_link_libraries(Prototype PRIVATE ${CMAKE_SOURCE_DIR}/lib/raylibdll.lib)
endif(WIN32)
