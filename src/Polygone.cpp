/**
 * \file      Polygone.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Polygone
 */

#include "Polygone.h"
#include "Vecteur2D.h"
#include "Matrice22.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"
#include "Triangle.h"

/**
 * \brief      Méthode qui retourne l'aire du polygone
 * \details    Cette méthode retourne l'aire d'un polygone en le divisant en plusieurs triangles
 * \return     Un double
 */
double Polygone::calculerAire() const
{
    if (tab_vect.size() < 3)
    {
        return 0;
    }
    else
    {
        double aire = 0;
        for (int i = 0; i < tab_vect.size()-2; ++i)
        {
            Vecteur2D a = *tab_vect[0];
            Vecteur2D b = *tab_vect[i+1];
            Vecteur2D c = *tab_vect[i+2];
            Triangle triangle(a,b,c); // ligne qui crash
            aire += triangle.calculerAire();
        }
        return aire;
    }
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

/**
 * \brief      Méthode qui ajoute un point au polygone
 * \return     Un Polygone
 */
Polygone& Polygone::addPoint(const Vecteur2D* v)
{
    tab_vect.push_back(v->clone());
    return *this;
}

Polygone* Polygone::clone()const
{
    Polygone* p = new Polygone();

    for (int i = 0; i < tab_vect.size(); i++)
    {
        p->tab_vect.push_back(tab_vect[i]);
    }

    return p;
}

void Polygone::translation(const Vecteur2D& u)
{
    for (int i = 0; i < tab_vect.size(); i++)
    {
        *tab_vect[i] = *tab_vect[i] + u;
    }
}

void Polygone::homothetie(const Vecteur2D& u, double k)
{
    for (int i = 0; i < tab_vect.size(); i++)
    {
        *tab_vect[i] =  ( *tab_vect[i] - u )*k  + u ;
    }
}

void Polygone::rotation(const Vecteur2D &u, const double angle)
{
    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;

    Matrice22 M(m11,m12,m21,m22);

    for (int i = 0; i < tab_vect.size(); i++)
    {
        *tab_vect[i] = M * ( *tab_vect[i] - u ) + u ;
    }
}

Vecteur2D Polygone::getCentreSymetrie() const
{
    double x =  0 , y = 0;

    for (int i = 0; i < tab_vect.size(); ++i)
    {
        x += tab_vect[i]->x;
        y += tab_vect[i]->y;
    }

    return Vecteur2D(x/tab_vect.size(),y/tab_vect.size());
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *Polygone::sauvegarde(const VisiteurSauvegarde *visiteur) const
{
    return visiteur->visite(this);
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode dessine() permet de visiter cette forme et d'appliquer
 *             l'opération de dessin associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurLibrairie
 * \param      *s        socket permettant de dessiner en C++ avec un Client TCP/IP
 */
const void *Polygone::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}

Vecteur2D Polygone::getMinXMinY() const {

    double minX = tab_vect[0]->x , minY = tab_vect[0]->y;

    for(int i = 0 ; i < tab_vect.size() ; i++){
        if ( tab_vect[i]->x < minX ) minX =tab_vect[i]->x;
        if ( tab_vect[i]->y < minY ) minY =tab_vect[i]->y;
    }

    return Vecteur2D(minX,minY);
}

Vecteur2D Polygone::getMaxXMaxY() const {
    double maxX = tab_vect[0]->x , maxY = tab_vect[0]->y;

    for(int i = 0 ; i < tab_vect.size() ; i++){
        if ( tab_vect[i]->x > maxX ) maxX =tab_vect[i]->x;
        if ( tab_vect[i]->y > maxY ) maxY =tab_vect[i]->y;
    }

    return Vecteur2D(maxX,maxY);
}
