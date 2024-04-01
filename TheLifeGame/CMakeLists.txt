cmake_minimum_required(VERSION 3.23)
project(TheLifeGame)

set(CMAKE_CXX_STANDARD 20)

add_executable(TheLifeGame src/main.cpp src/GameField/GameField.cpp src/GameField/GameField.h src/Controller/Controller.cpp src/Controller/Controller.h src/Viewer/Viewer.cpp src/Viewer/Viewer.h src/TheLifeGameCreator/TheLifeGameCreator.cpp src/TheLifeGameCreator/TheLifeGameCreator.h)
