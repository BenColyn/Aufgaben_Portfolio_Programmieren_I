cmake_minimum_required(VERSION 3.5...3.30) # Akzeptiert moderne Policies
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

# Wir erstellen ein Test-Target
# 'MeinTest' ist der Name, der oben rechts erscheinen soll
# 'Aufgabe1/main.cpp' ist der Pfad zur Datei
add_executable(Aufgabe_2 Aufgabe2/main.cpp
        Aufgabe2/Sprite.h)
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
add_executable(Aufgabe_6 Aufgabe6/main.cpp)
add_executable(Aufgabe_7 Aufgabe7/main.cpp
        Aufgabe7/Sprite.cpp
        Aufgabe7/Sprite.hpp)

target_link_libraries(Aufgabe_7 raylib)

# Sorgt dafür, dass die Header-Dateien gefunden werden
target_include_directories(Aufgabe_7 PUBLIC ${raylib_SOURCE_DIR}/src)