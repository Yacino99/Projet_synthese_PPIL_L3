/**
 * \file      Segment.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Segment
 */

#include "Segment.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"

/**
 * \brief    Fonction qui retourne le centre de symétrie
 * \return    Un Vecteur2D
 */
Vecteur2D Segment::getCentreSymetrie() const
{
    Vecteur2D g = (a+b)*(1/2.0);
    return g;
}

Segment::operator string() const
{
    ostringstream os;

    os << "segment ( " << a.x << " , " <<
       a.y << " , " << b.x << " , " << b.y << " ) " << this->couleur;

    return os.str();
}

/**
 * \brief    Opération de translation
 */
void Segment::translation(const Vecteur2D &u)
{
    a = a + u;
    b = b + u;
}

/**
 * \brief    Opération d'homothétie
 */
void Segment::homothetie(const Vecteur2D &u, double k)
{
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
}

/**
 * \brief    Opération de rotation
 */
void Segment::rotation(const Vecteur2D &u, const double angle)
{
    double m11 = cos(angle);
    double m21 = sin(angle);
    double m12 = -m21;
    double m22 = m11;

    Matrice22 M(m11,m12,m21,m22);
    b =  M * (b - u) + u ;
    a =  M * (a - u) + u ;
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *Segment::sauvegarde(const VisiteurSauvegarde *visiteur) const
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
const void *Segment::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}

Vecteur2D Segment::getMinXMinY() const {

    double minX = a.x < b.x ? a.x : b.x;
    double minY = a.y < b.y ? a.y : b.y;
    return Vecteur2D(minX,minY);
}

Vecteur2D Segment::getMaxXMaxY() const {

    double maxX = a.x > b.x ? a.x : b.x;
    double maxY = a.y > b.y ? a.y : b.y;
    return Vecteur2D(maxX,maxY);
}
