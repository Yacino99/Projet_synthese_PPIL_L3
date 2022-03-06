/**
 * \file      Triangle.h
 * \date      04 mars 2022
 * \brief     Classe Triangle
 */

#ifndef PROJETT_TRIANGLE_H
#define PROJETT_TRIANGLE_H


#include <sstream>
#include <iostream>
#include "Formes.h"
#include "Vecteur2D.h"
#include "Socket.h"

using namespace std;

class Triangle : public Formes
{
private:
    Vecteur2D a, b, c;

public:

    /**  \brief  Constructeur  */
    Triangle(int a1, int a2 ,int b1,int b2 , int c1 , int c2 , const string& color = " ") : Formes(color), a(a1,a2), b(b1,b2), c(c1,c2) {}
    /**  \brief  Constructeur  */
    Triangle(Vecteur2D a, Vecteur2D b,Vecteur2D c, const string& color = " ") : Formes(color), a(a), b(b) , c(c) {}

    double calculerAire() const;
    Vecteur2D getCentreSymetrie() const;
    virtual ~Triangle() {}

    Triangle* clone() const { return new Triangle(*this); }
    /**  \brief  Opération d'homothétie */
    void homothetie(const Vecteur2D& u,double k) ;
    /**  \brief  Opération de rotation */
    void rotation(const Vecteur2D &u, const double angle );
    /**  \brief  Opération de translation */
    void translation(const Vecteur2D& u);

    /** \brief Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    Vecteur2D getMinXMinY() const ;
    /** \brief  Avoir le point X maximal et point Y maximal  du plan selon la figure
 * @return un vecteur2D qui contient le le point max x et le point max Y
 */
    Vecteur2D getMaxXMaxY() const ;


    explicit operator string() const override;
    friend ostream& operator << (ostream& os, const Triangle& m);

    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};

inline ostream& operator << (ostream& os, const Triangle& m)
{
    return os << (string)m;
}

#endif //PROJETT_TRIANGLE_H
