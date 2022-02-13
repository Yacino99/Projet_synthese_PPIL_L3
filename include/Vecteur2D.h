//
// Created by Yacino99 on 24/01/2022.
//

#ifndef PROJETT_VECTEUR_H
#define PROJETT_VECTEUR_H


#include <string>
#include <ostream>
#include <sstream>
#include <math.h>

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


    inline explicit Vecteur2D(const double & x = 0, const double & y = 0);

/**
 * DONNEES : s respectant le format "(  nombre réel, nombre réel)"
 *
 * */
    inline Vecteur2D(const char * s);
    inline Vecteur2D* clone()const { return new Vecteur2D(*this); }
    inline const Vecteur2D operator + (const Vecteur2D & u) const;
    inline const Vecteur2D operator - (const Vecteur2D & u) const;
    inline const Vecteur2D operator * (const double & a) const;
    inline const bool operator == (const Vecteur2D & u) const;
    inline const double operator * (const Vecteur2D & u) const;
    inline const double determinant(const Vecteur2D& u) const;
    inline const double distance(const Vecteur2D& b) const;
    inline Vecteur2D& operator = (const Vecteur2D& u) ;
/**
 * - unaire (c'est-à- dire opposé d'un vecteur)
 * */
    inline const Vecteur2D operator - () const;



    operator string() const;

}; // classe Vecteur2D

inline const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a;}

//------------ implémentation des fonctions inline

inline  Vecteur2D::Vecteur2D(const double & x, const double & y): x(x),y(y){}

inline const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}

inline const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
    return Vecteur2D( x-u.x, y-u.y);
}

inline const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}

inline const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}

inline const bool Vecteur2D::operator==(const Vecteur2D &u) const {
    return ( x==u.x && y==u.y );
}

Vecteur2D::operator string() const
{
    ostringstream os;
    os << "( " << x <<", " << y << ")";
    return os.str();
}

ostream & operator << (ostream & os, const Vecteur2D & u)
{
    os << (string) u;
    return os;
}

inline const double Vecteur2D::determinant(const Vecteur2D &u) const
{
    return (x*u.y-y*u.x);
}

inline const double Vecteur2D::operator*(const Vecteur2D &u) const {
    return (x*u.x + y*u.y);
}

inline Vecteur2D& Vecteur2D::operator=(const Vecteur2D &u)  {
    if (this== &u)
        return *this;

    x = u.x;
    y = u.y;

    return *this;
}


const double Vecteur2D::distance(const Vecteur2D &b) const {
    return sqrt(pow(b.x-x,2) + pow(y-b.y,2));
}

#endif //PROJETT_VECTEUR_H
