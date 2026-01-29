cmake_minimum_required(VERSION 3.20)
project(TestProjekt)

set(CMAKE_CXX_STANDARD 17)

# Wir erstellen ein Test-Target
# 'MeinTest' ist der Name, der oben rechts erscheinen soll
# 'Aufgabe1/main.cpp' ist der Pfad zur Datei
add_executable(Aufgabe_1 Aufgabe1/main.cpp
        Aufgabe6/main.cpp)
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
