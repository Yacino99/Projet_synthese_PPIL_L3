/**
 * \file      Polygone.h
 * \date      04 mars 2022
 * \brief     Classe Polygone
 */

#pragma once

#ifndef PROJETT_POLYGONE_H
#define PROJETT_POLYGONE_H

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "Socket.h"
#include "Formes.h"
#include "Vecteur2D.h"
#include "Matrice22.h"
using namespace std;

class Polygone : public Formes
{
private:
    vector<Vecteur2D*> tab_vect;

public:
    /**  \brief  Constructeur  */
    Polygone(const string& couleur=" ") : Formes(couleur) {}
    /**  \brief  Constructeur  */
    Polygone(vector<Vecteur2D*> vect, const string& couleur=" ") : Formes(couleur) { tab_vect=vect; }

    Polygone* clone() const;
    /**  \brief  Opération de translation */
    void translation(const Vecteur2D& u);
    /**  \brief  Opération d'homothétie */
    void homothetie(const Vecteur2D& u, double k);
    /**  \brief  Opération de rotation */
    void rotation(const Vecteur2D &u, const double angle );

    Vecteur2D getCentreSymetrie() const;
    double calculerAire() const;
    virtual ~Polygone() {};
    operator string() const;
    Polygone& addPoint(const Vecteur2D* v);
    friend ostream& operator << (ostream& os, const Polygone& m);

    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};

inline ostream& operator<<(ostream& os, const Polygone& m)
{
    return os << (string)m;
}

#endif //PROJETT_POLYGONE_H
