cmake_minimum_required(VERSION 3.21)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Projet
        src/main.cpp src/Erreur.cpp include/Erreur.h src/InitReseaux.cpp include/InitReseaux.h include/Socket.h include/Transformable.h include/Formes.h include/Rond.h include/Croix.h include/Triangle.h include/Polygone.cpp include/Polygone.h)
