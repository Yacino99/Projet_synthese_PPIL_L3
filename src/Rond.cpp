//
// Created by Anwender on 14/02/2022.
//

#include "Rond.h"
#include "Matrice22.h"
#include "VisiteurSauvegarde.h"

void Rond::dessiner(Socket *ss) const
{
    ostringstream oss;
    oss << (string)*this;
    string requete = oss.str();
    ss->sendMessage(requete.c_str());
}

void Rond::translation(const Vecteur2D& u)
{
    v = v + u;
}

void Rond::homothetie(const Vecteur2D &u, double k) {
    v = (v - u)*k  + u;
    rayon *= k;
}

Rond::operator string() const
{
    ostringstream os;
    os << "rond ( " << v.x << " , " << v.y << " , " << rayon <<" ) " << this->couleur;
    return os.str();
}

double Rond::calculerAire() const {
    return (rayon * rayon) * PI;
}

void Rond::rotation(const Vecteur2D &u, const double angle) {

    double m11 = cos(angle);
    double m12 = -sin(angle);
    double m21 = sin(angle);
    double m22 = cos(angle);

    Matrice22 M(m11,m12,m21,m22);

    v =  M * (v - u) + u ;

}

Vecteur2D Rond::getCentreSymetrie() const {
    return v;
}

void *Rond::accepte(const VisiteurSauvegarde *visiteur) const {
    return visiteur->sauvegarde(this);
}

