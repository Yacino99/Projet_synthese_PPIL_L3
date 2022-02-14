//
// Created by user on 14/02/2022.
//

#pragma once

#include "Matrice22.h"
#include "Vecteur2D.h"

Matrice22::Matrice22(const Vecteur2D &u1, const Vecteur2D &u2) {u=u1,v=u2;}
Matrice22::Matrice22(const double &m11, const double &m12, const double &m21, const double &m22) : u(m11,m12), v(m21,m22) {}

const Matrice22 Matrice22::operator+(const Matrice22 &m) const {
    return Matrice22(u+m.u,v+m.v);
}

const Matrice22 Matrice22::operator-(const Matrice22 &m) const {
    return Matrice22(u-m.u,v-m.v);
}

const Matrice22 Matrice22::operator-() const {
    return Matrice22(-u,-v);
}

const Matrice22 Matrice22::operator*(const double &a) const {
    return Matrice22(u*a,v*a);
}

const Vecteur2D Matrice22::operator*(const Vecteur2D &vec) const {
    double l1 = u.x*vec.x + u.y*vec.y;
    double l2 =  v.x*vec.x + v.y*vec.y;
    return Vecteur2D(l1,l2);
}

const Matrice22 Matrice22::operator*(const Matrice22 &m) const {
    return Matrice22(); // TODO : faire le prduit matriciel
}

Matrice22& Matrice22::operator=(const Matrice22 &m) {
    if (this== &m)
        return *this;

    u=m.u;
    v=m.v;

    return *this;
}

const bool Matrice22::operator==(const Matrice22 &m) const {
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
