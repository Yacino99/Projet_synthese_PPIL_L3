/**
 * \file      Transformable.h
 * \date      04 mars 2022
 * \brief     Classe Transformable
 * \details   Classe contenant les opérations de transformations des formes
 */

#ifndef PROJETT_TRANSFORMABLE_H
#define PROJETT_TRANSFORMABLE_H

#include "Vecteur2D.h"

class Transformable
{
public:
    /**  \brief  Opération translation */
    virtual void translation(const Vecteur2D& u) = 0;
    /**  \brief  Opération d'homothétie */
    virtual void homothetie(const Vecteur2D& u,double k) = 0;
    /**  \brief  Opération rotation */
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;
};

#endif //PROJETT_TRANSFORMABLE_H
