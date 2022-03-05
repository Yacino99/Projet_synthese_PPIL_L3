/**
 * \file      Vecteur2D.h
 * \date      04 mars 2022
 * \brief     Classe Vecteur2D
 */

#pragma once

#ifndef PROJETT_VECTEUR_H
#define PROJETT_VECTEUR_H

#include <string>
#include <ostream>
#include <sstream>

using namespace std;

template <class T>

inline const T operator - (const T & u, const T & v)
{
    return u + -v;
}

class Vecteur2D
{
public:
    double x,y;

    explicit Vecteur2D(const double & x = 0, const double & y = 0);

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
    Vecteur2D(const char * s);
    Vecteur2D* clone()const { return new Vecteur2D(*this); }
    const Vecteur2D operator + (const Vecteur2D & u) const;
    const Vecteur2D operator - (const Vecteur2D & u) const;
    const Vecteur2D operator * (const double & a) const;
    const bool operator == (const Vecteur2D & u) const;
    const double operator * (const Vecteur2D & u) const;
    const double determinant(const Vecteur2D& u) const;
    const double distance(const Vecteur2D& b) const;
    Vecteur2D& operator = (const Vecteur2D& u) ;
/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
    const Vecteur2D operator - () const;

    friend ostream & operator << (ostream & os, const Vecteur2D & u);

    operator string() const;

}; // classe Vecteur2D

#endif //PROJETT_VECTEUR_H
