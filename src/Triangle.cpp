/**
 * \file      Triangle.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Triangle
 */

#include "Triangle.h"
#include "Matrice22.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurLibrairie.h"

void Triangle::translation(const Vecteur2D& u)
{
    a = a + u;
    b = b + u;
    c = c + u;
}

void Triangle::homothetie(const Vecteur2D &u, double k)
{
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
    c =  (c - u)*k  + u;
}

Triangle::operator string() const
{
    ostringstream os;
    os << "triangle ( " << a.x << " , " << a.y << " , " << b.x << " , " <<
       b.y << " , "  << c.x << " , " << c.y  << " ) " << this->couleur;
    return os.str();
}

/**
* \brief      Méthode qui retourne l'aire du triangle
* \details    La formule de Héron stipule que l'aire A d'un triangle de côtés de longueurs
*             a , b et c est A = √ d ( d − a ) ( d − b ) ( d − c )
*             où d est le demi-périmètre du triangle ou la moitié de son périmètre. \n
*             Perimètre = somme des 3 cotes du triangle.
* \return     Un double
*/
double Triangle::calculerAire() const
{
    double ab = a.distance(b) , ac = a.distance(c) , bc = b.distance(c);
    double d = (ab+ac+bc)/2; // d est le demi perimetre

    return sqrt(d*(d-ab)*(d-ac)*(d-bc));
}

void Triangle::rotation(const Vecteur2D &u, const double angle)
{
    double m11 = cos(angle);
    double m12 = -sin(angle);
    double m21 = sin(angle);
    double m22 = cos(angle);

    Matrice22 M(m11,m12,m21,m22);

    a =  M * (a - u) + u ;
    b =  M * (b - u) + u ;
    c =  M * (c - u) + u ;
}

Vecteur2D Triangle::getCentreSymetrie() const
{
    Vecteur2D g = (a+b+c)*(1/3.0);
    return g;
}

/**
 * \brief      Méthode du Design Pattern Visitor
 * \details    Cette méthode sauvegarde() permet de visiter cette forme et d'appliquer
 *             l'opération de sauvegarde associée à celle-ci grâce au Design Pattern Visitor.
 * \param      *visiteur instance de VisiteurSauvegarde
 */
const void *Triangle::sauvegarde(const VisiteurSauvegarde *visiteur) const
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
const void *Triangle::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}