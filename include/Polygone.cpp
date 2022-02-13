//
// Created by user on 11/02/2022.
//
/*
#include "Polygone.h"
#include "Vecteur2D.h"

double Polygone::calculerAire() const
{
    return 0.0;
}


Polygone::~Polygone()
{
    for (int i = 0; i < tab_vect.size(); i++)
        delete tab_vect[i];
    delete s;
}


Polygone::operator string() const
{
    ostringstream os;
    os << "polygone ( ";
    int i;
    for ( i = 0; i < tab_vect.size()-1; i++)
    {
        os << tab_vect[i]->x << " , " << tab_vect[i]->y << " , ";
    }
    os << tab_vect[i]->x << " , " << tab_vect[i]->y;
    os << " ) " << this->couleur;
    return os.str();
}

Polygone& Polygone::addPoint(const Vecteur2D* v){

    tab_vect.push_back(v->clone());
    return *this;
}

Polygone* Polygone::clone()const{

    Polygone* p = new Polygone(this->s);

    for (int i = 0; i < tab_vect.size(); i++)
        p->tab_vect.push_back(tab_vect[i]);

    //return new Polygone(*this);
    return p;
}

void Polygone::translation(const Vecteur2D& u)
{
    for (int i = 0; i < tab_vect.size(); i++)
        *tab_vect[i] = *tab_vect[i] + u;
}

inline void Polygone::homothetie(const Vecteur2D& u, double k)
{
    //b = k * (b - u) + u;
    for (int i = 0; i < tab_vect.size(); i++)
        *tab_vect[i] = k * ( *tab_vect[i] - u ) + u ;

}

void Polygone::rotation(const Vecteur2D &u, const double angle) {

}

Vecteur2D Polygone::getCentreSymetrie() const {
    return Vecteur2D();
}
*/