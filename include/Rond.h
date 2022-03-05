/**
 * \file      Rond.h
 * \date      04 mars 2022
 * \brief     Classe Rond
 */

#ifndef PROJETT_ROND_H
#define PROJETT_ROND_H

#include "Formes.h"
#include <string>
#include "Socket.h"
#include <sstream>
#include <string>
#include "Vecteur2D.h"
using namespace std;

class Rond : public Formes
{
private :

	double rayon;
	const double PI = 3.141592653589793;
	Vecteur2D v;

public:

    /**  \brief  Constructeur  */
	Rond(int x, int y, double rayon, const string& color = " ") : Formes(color), rayon(rayon),v(x,y) {}
    /**  \brief  Constructeur  */
    Rond(Vecteur2D v, double rayon, const string& color = " ") : Formes(color), rayon(rayon),v(v) {}

	double calculerAire() const;
    Vecteur2D getCentreSymetrie() const { return v; }
	virtual ~Rond() {}

	Rond* clone() const{ return new Rond(*this); }
    /**  \brief  Opération de rotation */
    void rotation(const Vecteur2D &u, const double angle );
    /**  \brief  Opération de translation */
    void translation(const Vecteur2D& u);
    /**  \brief  Opération d'homothétie */
    void homothetie(const Vecteur2D& u,double k) ;

    operator string() const;
	friend ostream& operator << (ostream& os, const Rond& m);

    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};


inline ostream& operator << (ostream& os, const Rond& m)
{
	return os << (string)m;
}




#endif //PROJETT_ROND_H
