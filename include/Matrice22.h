//
// Created by Yacino99 on 24/01/2022.
//

#ifndef PROJETT_MATRICE22_H
#define PROJETT_MATRICE22_H

#include "Vecteur2D.h"

#include <sstream>

/**
 * represenation de la matrice 2x2 :
 * [ u.x  u.y  ]
 * [ v.x  v.y ]
 */


class Matrice22 {

public:

    Vecteur2D u,v;

    /** construteur a partir de 4 reels */
    inline explicit Matrice22(const double & m11 = 0, const double & m12 = 0, const double & m21 = 0, const double & m22 = 0);
    /** constructeur a partir de deux vecteur2D */
    inline explicit Matrice22(const Vecteur2D& u,const Vecteur2D& v);

    /** operteurs  */

    inline const Matrice22 operator + (const Matrice22 & m) const;
    inline const Matrice22 operator - (const Matrice22 & m) const;
    inline const Matrice22 operator * (const double & a) const;
    inline const Matrice22 operator * (const Matrice22 & m) const;
    inline Matrice22& operator = (const Matrice22& m) ;
    inline const bool operator == (const Matrice22 & m) const;
    inline const Vecteur2D operator * (const Vecteur2D & vec) const;

    inline const double determinant() const;
    inline const Matrice22 inverse() const ;
    inline const Matrice22 comatrice() const;
    /** operateur unaire */
    inline const Matrice22 operator - () const;

    operator string() const;

};

inline  Matrice22::Matrice22(const Vecteur2D &u1, const Vecteur2D &u2) {u=u1,v=u2;}
inline Matrice22::Matrice22(const double &m11, const double &m12, const double &m21, const double &m22) : u(m11,m12), v(m21,m22) {}

inline const Matrice22 Matrice22::operator+(const Matrice22 &m) const {
    return Matrice22(u+m.u,v+m.v);
}

inline const Matrice22 Matrice22::operator-(const Matrice22 &m) const {
    return Matrice22(u-m.u,v-m.v);
}

inline const Matrice22 Matrice22::operator-() const {
    return Matrice22(-u,-v);
}

inline const Matrice22 Matrice22::operator*(const double &a) const {
    return Matrice22(u*a,v*a);
}

inline const Vecteur2D Matrice22::operator*(const Vecteur2D &vec) const {
   double l1 = u.x*vec.x + u.y*vec.y;
   double l2 =  v.x*vec.x + v.y*vec.y;
    return Vecteur2D(l1,l2);
}

inline const Matrice22 Matrice22::operator*(const Matrice22 &m) const {
    return Matrice22(); // TODO : faire le prduit matriciel
}

inline Matrice22& Matrice22::operator=(const Matrice22 &m) {
    if (this== &m)
        return *this;

    u=m.u;
    v=m.v;

    return *this;
}

inline const bool Matrice22::operator==(const Matrice22 &m) const {
    return (u==m.u && v==m.v);
}

Matrice22::operator string() const
{
    ostringstream os;
    os << "[ " << u<< " ]" << endl
    << "[ " << v << " ]";
    return os.str();
}

const double Matrice22::determinant() const {
    return u.determinant(v);
}

const Matrice22 Matrice22::inverse() const {
    return this->comatrice()*(1/this->determinant() );
}

const Matrice22 Matrice22::comatrice() const {
    return Matrice22(v.y,-v.x,-u.y,u.x);
}


ostream & operator << (ostream & os, const Matrice22 & m)
{
    os << (string) m;
    return os;
}

#endif //PROJETT_MATRICE22_H
