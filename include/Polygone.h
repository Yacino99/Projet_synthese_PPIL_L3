//
// Created by user on 11/02/2022.
//

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

class Polygone : public Formes {

private:
    Socket* s;
    vector<Vecteur2D*> tab_vect;

public:

    Polygone(Socket* ss, const string& couleur=" ") :Formes(couleur) { s = ss; }
    Polygone(vector<Vecteur2D*> vect,Socket* ss, const string& couleur=" "):Formes(couleur) { s = ss;tab_vect=vect; }

    virtual void dessiner(Socket* ss)const;

    Polygone* clone() const;
    void translation(const Vecteur2D& u);
    void homothetie(const Vecteur2D& u, double k);
    void rotation(const Vecteur2D &u, const double angle );

    Vecteur2D getCentreSymetrie() const;
    double calculerAire() const;
    virtual ~Polygone();
    operator string() const;
    Polygone& addPoint(const Vecteur2D* v);
    friend ostream& operator << (ostream& os, const Polygone& m);

    // DP Visitor pour la sauvegarde
    const void *accepte(const VisiteurSauvegarde * visiteur) const;
};

inline ostream& operator<<(ostream& os, const Polygone& m)
{
    return os << (string)m;
}





#endif //PROJETT_POLYGONE_H
