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

    /** \brief Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    Vecteur2D getMinXMinY() const ;
    /** \brief  Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    Vecteur2D getMaxXMaxY() const ;

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
