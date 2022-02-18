//
// Created by Anwender on 14/02/2022.
//

#include "Triangle.h"
#include "Matrice22.h"
#include "VisiteurSauvegarde.h"

void Triangle::dessiner(Socket *ss) const
{
    ostringstream oss;
    oss << (string)*this;
    string requete = oss.str();
    ss->sendMessage(requete.c_str());

}

void Triangle::translation(const Vecteur2D& u)
{
    a = a + u;
    b = b + u;
    c = c + u;
}

void Triangle::homothetie(const Vecteur2D &u, double k) {
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



//TODO : trouver la bonne formule pour calculer l'air d'un triangle

/**
 * La formule de Héron stipule que l'aire A d'un triangle de côtés de longueurs
 * a , b et c est A = √ d ( d − a ) ( d − b ) ( d − c )
 * où d est le demi-périmètre du triangle ou la moitié de son périmètre.
 * perimetre = somme des 3 cotes du triangle
 */
double Triangle::calculerAire() const {

   // double ab =  u1.distance(u2) , ac = u1.distance(u3) , bc = u2.distance(u3);
    // double aire = (ab + ac + bc)/2;

    double ab = a.distance(b) , ac = a.distance(c) , bc = b.distance(c);
    double d = (ab+ac+bc)/2; // d est le demi perimetre

    return sqrt(d*(d-ab)*(d-ac)*(d-bc));

    // probleme -> NAN
}

void Triangle::rotation(const Vecteur2D &u, const double angle) {

    double m11 = cos(angle);
    double m12 = -sin(angle);
    double m21 = sin(angle);
    double m22 = cos(angle);

    Matrice22 M(m11,m12,m21,m22);

    a =  M * (a - u) + u ;
    b =  M * (b - u) + u ;
    c =  M * (c - u) + u ;
}

Vecteur2D Triangle::getCentreSymetrie() const {
    double x = (a.x+b.x+c.x)/3;
    double y = (a.y+b.y+c.y)/3;
    return Vecteur2D(x,y);
}


const void *Triangle::accepte(const VisiteurSauvegarde *visiteur) const {
    return visiteur->sauvegarde(this);
}

