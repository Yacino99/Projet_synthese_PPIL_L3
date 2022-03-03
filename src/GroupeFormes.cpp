//
// Created by Anwender on 03/03/2022.
//

#include "GroupeFormes.h"
#include "Formes.h"
#include "Erreur.h"
#include "VisiteurLibrairieAwt.h"
#include "VisiteurSauvegarde.h"

using namespace std;

GroupeFormes::~GroupeFormes() {
    for (int i = 0; i < formes.size(); ++i) {
        delete formes[i];
    }
}

Formes *GroupeFormes::getForme(int i) const {

    if (i < 0 || i >= formes.size())
        throw Erreur("indice invalide");
    else
        return formes[i];
}

void GroupeFormes::setCouleur(const string &color) {
    couleur=color;
    for (int i = 0; i < formes.size(); ++i) {
        formes[i]->setColor(color);
    }
}

const string GroupeFormes::getCouleur() const {
    return couleur;
}

GroupeFormes::operator string() const {

    ostringstream os;

    os << "groupe : [ ";
    for (int i = 0; i < formes.size(); ++i) {
        os << formes[i] << endl;
    }
    os << " ] " << this->couleur;
    return os.str();

}

GroupeFormes &GroupeFormes::addForme(const Formes *f)
{
    Formes * newF = f->clone();
    newF->setColor(couleur);
    formes.push_back(newF);
    return (*this);
}

void GroupeFormes::appliquerTranslation(const Vecteur2D &u, bool centreSymetrie) {

    for (int i = 0; i < formes.size(); ++i) {
        if (centreSymetrie)
            formes[i]->translation(formes[i]->getCentreSymetrie());
        else
            formes[i]->translation(u);
    }
}

void GroupeFormes::appliquerHomothetie(const Vecteur2D &u, const double k, bool centreSymetrie) {

    for (int i = 0; i < formes.size(); ++i) {
        if (centreSymetrie)
            formes[i]->homothetie(formes[i]->getCentreSymetrie(),k);
        else
            formes[i]->homothetie(u,k);
    }
}

void GroupeFormes::appliquerRotation(const Vecteur2D &u, const double angle, bool centreSymetrie) {

    for (int i = 0; i < formes.size(); ++i) {
        if (centreSymetrie)
            formes[i]->rotation(formes[i]->getCentreSymetrie(),angle);
        else
            formes[i]->rotation(u,angle);
    }
}

const double GroupeFormes::sommeAires() const
{

    double somme = 0;
    for (int i = 0; i < formes.size(); ++i) {
        somme += formes[i]->calculerAire();
    }
    return somme;
}

void GroupeFormes::dessine(Socket *s) const
{
    for (int i = 0; i < formes.size(); ++i) {
        formes[i]->dessine(new VisiteurLibrairieAwt, s);
    }
}

void GroupeFormes::translation(const Vecteur2D &u) {


}

void GroupeFormes::homothetie(const Vecteur2D &u, double k) {


}

Vecteur2D GroupeFormes::getCentreSymetrie() const {
    return Vecteur2D();
}

double GroupeFormes::calculerAire() const
{
    double somme = 0;
    for (int i = 0; i < formes.size(); ++i) {
        somme += formes[i]->calculerAire();
    }
    return somme;
}

void GroupeFormes::rotation(const Vecteur2D &u, const double angle) {

}

const void *GroupeFormes::sauvegarde(const VisiteurSauvegarde *visiteur) const
{
    return visiteur->visite(this);
}

const void *GroupeFormes::dessine(const VisiteurLibrairie *visiteur, Socket *s) const
{
    return visiteur->visite(this, s);
}
