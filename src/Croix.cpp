//
// Created by Anwender on 14/02/2022.
//

#include "Croix.h"
#include "VisiteurSauvegarde.h"

void Croix::dessiner(Socket *ss) const
{

    ostringstream oss;
    oss << (string)*this;
    string requete = oss.str();
    ss->sendMessage(requete.c_str());

}

double Croix::calculerAire() const {
    return 0;
}

Vecteur2D Croix::getCentreSymetrie() const {
    double x = (a.x+b.x)/2;
    double y = (a.y+b.y)/2;
    return Vecteur2D(x,y);
}

Croix::operator string() const
{
    ostringstream os;

    os << "croix ( " << a.x << " , " <<
       a.y << " , " << b.x << " , " << b.y << " )" << this->couleur;


    return os.str();
}

void Croix::translation(const Vecteur2D &u)
{
    a = a + u;
    b = b + u;
}

void Croix::homothetie(const Vecteur2D &u, double k) {
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
}

//Vecteur OB’ = R * (vecteur OB – vecteur OC) + vecteur OC
void Croix::rotation(const Vecteur2D &u, const double angle) {
    Matrice22 M(Vecteur2D(cos(angle),-sin(angle)) , Vecteur2D(sin(angle), cos(angle)));
    b =  M * (b - u) + u ;
    a =  M * (a - u) + u ;
}

void *Croix::accepte(const VisiteurSauvegarde *visiteur) const {
    return visiteur->sauvegarde(this);
}

