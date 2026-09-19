cmake_minimum_required(VERSION 4.3)
project(VacuousValley)

set(CMAKE_CXX_STANDARD 20)

add_executable(VacuousValley "src/main.cpp"
        "src/Level 1/Tree/Tree.cpp"
        "src/Level 1/Tree/Tree.h"
        "src/Level 1/River/River.cpp"
        "src/Level 1/River/River.h"
        "src/Level 1/Menu/Menu.cpp"
        "src/Level 1/Menu/Menu.h"
        "src/Level 1/Core/Core.cpp"
        "src/Level 1/Core/Core.h"

        "src/Level 2/Monster/Monster.cpp"
        "src/Level 2/Monster/Monster.h"
        "src/Level 2/Core2/Core2.cpp"
        "src/Level 2/Core2/Core2.h"
        "src/Level 2/Exit/Exit.cpp"
        "src/Level 2/Exit/Exit.h"

        "src/Level 3/Level_3.cpp"
        "src/Level 3/Level_3.h"
        "src/Level 3/Core/GameState.h"
        "src/Level 3/Core/GameRules.cpp"
        "src/Level 3/Core/GameRules.h"
        "src/Level 3/Systems/RenderSystem.cpp"
        "src/Level 3/Systems/RenderSystem.h"
        "src/Level 3/Systems/InputSystem.cpp"
        "src/Level 3/Systems/InputSystem.h"
        "src/Level 3/Systems/PhysicsSystem.cpp"
        "src/Level 3/Systems/PhysicsSystem.h"
        "src/Level 3/Systems/AudioSystem.cpp"
        "src/Level 3/Systems/AudioSystem.h"
        "src/Level 3/Managers/SceneManager.cpp"
        "src/Level 3/Managers/SceneManager.h"
        "src/Level 3/Managers/ResourceManager.cpp"
        "src/Level 3/Managers/ResourceManager.h"
        utils/Random.h
)
target_include_directories(VacuousValley PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib-6.0/include
)

target_link_directories(VacuousValley PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib-6.0/lib
)

target_link_libraries(VacuousValley
        raylib
)

if(WIN32)
    target_link_libraries(VacuousValley
            winmm
            gdi32
            opengl32
    )
endif()