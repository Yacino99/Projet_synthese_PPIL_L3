cmake_minimum_required(VERSION 3.21)
project(Projet)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Projet
        src/main.cpp src/Erreur.cpp include/Erreur.h src/InitReseaux.cpp include/InitReseaux.h include/Socket.h include/Transformable.h include/Formes.h include/Rond.h include/Segment.h include/Triangle.h src/Polygone.cpp include/Polygone.h src/Vecteur2D.cpp src/Matrice22.cpp src/Segment.cpp src/Rond.cpp src/Triangle.cpp src/VisiteurSauvegardeTxt.cpp include/Expert.h include/ExpertChargementCOR.h include/ExpertChargementSegmentCOR.h include/ChargeurListeFormes.h include/ExpertChargementPolygoneCOR.h include/ExpertChargementRondCOR.h include/ExpertChargementTriangleCOR.h include/VisiteurLibrairie.h include/VisiteurLibrairieAwt.h src/VisiteurLibrairieAwt.cpp src/GroupeFormes.cpp include/GroupeFormes.h include/ExpertChargementGroupeCOR.h)
