cmake_minimum_required(VERSION 3.5...3.30) # Akzeptiert moderne Policies
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)
project(TestProjekt)

set(CMAKE_CXX_STANDARD 17)

# Verhindert die Warnung zum Zeitstempel beim Download
cmake_policy(SET CMP0135 NEW)

# --- Raylib automatisch laden ---
include(FetchContent)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)

# Das hier zwingt Raylib, sich an moderne Standards zu halten
set(RAYLIB_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)
# --------------------------------


add_executable(Aufgabe_2 Aufgabe2/main.cpp
        Aufgabe2/Sprite.h
        Aufgabe7-8/main.cpp)
add_executable(Aufgabe_3 Aufgabe3/main.cpp
        Aufgabe3/Wuerfelspiel.cpp Aufgabe3/Wuerfelspiel.h)
add_executable(Aufgabe_4 Aufgabe4/main.cpp
        Aufgabe4/main.cpp
        Aufgabe4/Pflanze.cpp Aufgabe4/Pflanze.h
        Aufgabe4/Baum.cpp Aufgabe4/Baum.h
        Aufgabe4/Blume.cpp Aufgabe4/Blume.h
        Aufgabe4/Strauch.cpp Aufgabe4/Strauch.h
        Aufgabe4/Gras.cpp Aufgabe4/Gras.h)
add_executable(Aufgabe_5 Aufgabe5/main.cpp
        Aufgabe5/MyCppArray.h
        Aufgabe5/MyCppArray.cpp
        Aufgabe5/MyCppArrayB.cpp
        Aufgabe5/MyCppArrayB.h)
add_executable(Aufgabe_6 Aufgabe6/main.cpp
        Aufgabe6/component.h
        Aufgabe6/BaseCar.cpp
        Aufgabe6/BaseCar.h
        Aufgabe6/Brakes.cpp
        Aufgabe6/Brakes.h
        Aufgabe6/Gears.cpp
        Aufgabe6/Gears.h
        Aufgabe6/Wheels.cpp
        Aufgabe6/Wheels.h
        Aufgabe6/Frame.cpp
        Aufgabe6/Frame.h
        Aufgabe6/Suspension.cpp
        Aufgabe6/Suspension.h
        Aufgabe6/Engine.cpp
        Aufgabe6/Engine.h)
add_executable(Aufgabe_7-8 Aufgabe7-8/main.cpp
        Aufgabe7-8/Sprite.cpp
        Aufgabe7-8/Sprite.hpp
        Aufgabe7-8/Level.hpp
        Aufgabe7-8/main.cpp
Aufgabe7-8/resources)

target_link_libraries(Aufgabe_7-8 raylib)

# Sorgt dafür, dass die Header-Dateien gefunden werden
target_include_directories(Aufgabe_7-8 PUBLIC ${raylib_SOURCE_DIR}/src)