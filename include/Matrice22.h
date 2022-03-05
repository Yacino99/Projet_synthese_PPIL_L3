/**
 * \file      Matrice22.h
 * \date      04 mars 2022
 * \brief     Classe Matrice22
 */

#ifndef PROJETT_MATRICE22_H
#define PROJETT_MATRICE22_H

#include "Vecteur2D.h"

#include <sstream>

/**
 * represenation de la matrice 2x2 :
 * [ u.x  u.y  ]
 * [ v.x  v.y ]
 */

class Matrice22
{

public:

    Vecteur2D u,v;

    /** construteur a partir de 4 reels */
    explicit Matrice22(const double & m11 = 0, const double & m12 = 0, const double & m21 = 0, const double & m22 = 0);
    /** constructeur a partir de deux vecteur2D */
    explicit Matrice22(const Vecteur2D& u,const Vecteur2D& v);

    /** operteurs  */

    const Matrice22 operator + (const Matrice22 & m) const;
    const Matrice22 operator - (const Matrice22 & m) const;
    const Matrice22 operator * (const double & a) const;
    const Matrice22 operator * (const Matrice22 & m) const;
    Matrice22& operator = (const Matrice22& m) ;
    const bool operator == (const Matrice22 & m) const;
    const Vecteur2D operator * (const Vecteur2D & vec) const;

    const double determinant() const;
    const Matrice22 inverse() const ;
    const Matrice22 comatrice() const;
    /** operateur unaire */
    const Matrice22 operator - () const;

    operator string() const;

    friend ostream & operator << (ostream & os, const Matrice22 & m);
};
#endif //PROJETT_MATRICE22_H
