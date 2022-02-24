//
// Created by user on 07/02/2022.
//

#ifndef PROJETT_TRANSFORMABLE_H
#define PROJETT_TRANSFORMABLE_H


#include "Vecteur2D.h"

// interface transformable

/*
 * translation homotetie et rotation , sont des cas particuliers d'une notion que je dois definir
 * */

class Transformable {
public:
    virtual void translation(const Vecteur2D& u) = 0;
    virtual void homothetie(const Vecteur2D& u,double k) = 0;
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;
};

#endif //PROJETT_TRANSFORMABLE_H
