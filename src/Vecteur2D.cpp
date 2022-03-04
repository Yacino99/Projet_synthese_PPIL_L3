//
// Created by user on 14/02/2022.
//

#pragma once


#include <string>
#include <ostream>
#include <sstream>

#include "../include/Vecteur2D.h"

const Vecteur2D operator *(const double & a, const Vecteur2D & u) { return u*a;}

//------------ implémentation des fonctions inline

Vecteur2D::Vecteur2D(const double & x, const double & y): x(x),y(y){}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
    return Vecteur2D( x+u.x, y+u.y);
}

const Vecteur2D Vecteur2D::operator - (const Vecteur2D & u) const
{
    return Vecteur2D( x-u.x, y-u.y);
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{
    return Vecteur2D( x*a, y*a);
}

const Vecteur2D Vecteur2D::operator - () const
{
    return Vecteur2D(-x,-y);
}

const bool Vecteur2D::operator==(const Vecteur2D &u) const
{
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

const double Vecteur2D::determinant(const Vecteur2D &u) const
{
    return (x*u.y-y*u.x);
}

const double Vecteur2D::operator*(const Vecteur2D &u) const
{
    return (x*u.x + y*u.y);
}

Vecteur2D& Vecteur2D::operator=(const Vecteur2D &u)
{
    if (this== &u)
    {
        return *this;
    }

    x = u.x;
    y = u.y;

    return *this;
}

const double Vecteur2D::distance(const Vecteur2D &b) const
{
    double opg = (b.x-x)*(b.x-x);
    double opd = (b.y-y)*(b.y-y);
    //double opg = pow(b.x-x,2);
    //double opd =  pow(b.y-y,2);
    return sqrt(opg + opd);
}
