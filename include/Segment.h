/**
 * \file      Segment.h
 * \date      04 mars 2022
 * \brief     Classe Segment
 */

#ifndef PROJETT_CROIX_H
#define PROJETT_CROIX_H

#include "Formes.h"
#include <string>
#include "Socket.h"
#include <sstream>
#include <string>
#include <math.h>
#include "Vecteur2D.h"
#include "Matrice22.h"

using namespace std;

class Segment : public Formes
{
private :
    Vecteur2D a, b;

public:
    /**  \brief  Constructeur  */
    Segment(double g, double h, double d, double b, const string& couleur = " ") : Formes(couleur) , a(g, h), b(d, b) {}
    /**  \brief  Constructeur  */
    Segment(Vecteur2D a, Vecteur2D b, Socket* s, const string& couleur = " ") : Formes(couleur), a(a), b(b) {}

    double calculerAire() const { return 0; }

    Vecteur2D getCentreSymetrie() const;


    Segment* clone() const { return new Segment(*this); }
    virtual ~Segment() {}
    friend ostream& operator << (ostream& os, const Segment& m);
    operator string() const;

    void translation(const Vecteur2D &u);
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );

    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};

inline ostream& operator << (ostream& os, const Segment& m)
{
    return os << (string)m;
}

#endif //PROJETT_CROIX_H
