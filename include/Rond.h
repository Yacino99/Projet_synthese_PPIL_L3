//
// Created by Yacino99 on 07/02/2022.
//

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

	Rond(int x, int y, double rayon, const string& color = " ") : Formes(color), rayon(rayon),v(x,y) {}
    Rond(Vecteur2D v, double rayon, const string& color = " ") : Formes(color), rayon(rayon),v(v) {}

	double calculerAire() const;
    Vecteur2D getCentreSymetrie() const { return v; }
	virtual ~Rond() {}

	Rond* clone() const{ return new Rond(*this); }
    void rotation(const Vecteur2D &u, const double angle );

    void translation(const Vecteur2D& u);
    void homothetie(const Vecteur2D& u,double k) ;

    operator string() const;
	friend ostream& operator << (ostream& os, const Rond& m);

    // DP Visitor
    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};


inline ostream& operator << (ostream& os, const Rond& m)
{
	return os << (string)m;
}




#endif //PROJETT_ROND_H
