//
// Created by user on 11/02/2022.
//

#include "Polygone.h"
#include "Vecteur2D.h"
#include "Matrice22.h"

void Polygone::dessiner(Socket *ss) const
{
    ostringstream oss;
    oss << (string)*this;
    string requete = oss.str();
    ss->sendMessage(requete.c_str());

}

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

void Polygone::homothetie(const Vecteur2D& u, double k)
{
    //b = k * (b - u) + u;
    for (int i = 0; i < tab_vect.size(); i++)
        *tab_vect[i] =  ( *tab_vect[i] - u )*k  + u ;

}

void Polygone::rotation(const Vecteur2D &u, const double angle) {

    double m11 = cos(angle);
    double m12 = -sin(angle);
    double m21 = sin(angle);
    double m22 = cos(angle);

    Matrice22 M(m11,m12,m21,m22);

    /*a =  M * (a - u) + u ;*/

    for (int i = 0; i < tab_vect.size(); i++)
        *tab_vect[i] = M * ( *tab_vect[i] - u ) + u ;

}

Vecteur2D Polygone::getCentreSymetrie() const {
    double x =  0 , y = 0;


    for (int i = 0; i < tab_vect.size(); ++i) {
        x += tab_vect[i]->x;
        y += tab_vect[i]->y;
    }

    return Vecteur2D(x/tab_vect.size(),y/tab_vect.size());
}


