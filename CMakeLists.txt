cmake_minimum_required(VERSION 3.20)
project(SFML_Ex VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Fetch SFML from git and build for any system
include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL)
FetchContent_MakeAvailable(SFML)

# Create the executable
# List source files here (cpp, c)
add_executable(SFML_Ex 
    main.cpp
    src/Utilities.cpp 
    "src/Projectile.h" 
    "src/Tower.h"  
    "src/Tower.cpp" 
    "src/towers/Bank.h" 
    "src/towers/Bank.cpp" 
    "src/towers/People.h" 
    "src/towers/People.cpp"
    "src/Towers/Landmine.h" 
    "src/Towers/Landmine.cpp" 
    "src/Towers/Mortar.h" 
    "src/Towers/Mortar.cpp"
    "src/Towers/Rifleman.h" 
    "src/Towers/Rifleman.cpp" 
    "src/Towers/Tank.h" 
    "src/Towers/Tank.cpp"
    "src/Towers/Barricade.h" 
    "src/Towers/Barricade.cpp" 
    "src/Towers/Stickman.h" 
    "src/Towers/Stickman.cpp"
    "src/Grid/GridTile.cpp" 
    "src/Grid/Grid.cpp" 
    "src/MobQueue/MobQueue.h"
    "src/MobQueue/MobQueue.cpp" 
    "src/Character.cpp" 
    "src/TowerSelect/TowerSelect.h" 
    "src/TowerSelect/TowerSelect.cpp"
    "src/Machine.h" 
    "src/Machine.cpp" 
    "src/machines/Toaster.hpp" 
    "src/machines/Tesla.hpp" 
    "src/machines/Dog.hpp" 
    "src/machines/ChickenJockey.hpp" 
    "src/machines/Flamethrower.hpp" 
    "src/machines/Alarm.hpp" 
    "src/machines/Tank.hpp" 
    "src/Player.h" "src/Player.h")

target_link_libraries(SFML_Ex
        SFML::System # Required
        SFML::Window # Required
        SFML::Graphics # Required
        # Drop these two if you use external libraries for Audio or Networking.
        # Only include them if they are part of your project.
        SFML::Audio # Used for audio transactions (playing sound, bg noise, etc.)
        SFML::Network # Used for basic networking
)

# Set assets path for use in project
set(ASSETS_PATH "${CMAKE_SOURCE_DIR}/assets")
target_compile_definitions(SFML_Ex PRIVATE ASSETS_PATH="${ASSETS_PATH}")