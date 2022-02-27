//
// Created by Yacino99 on 07/02/2022.
//

#ifndef PROJETT_TRIANGLE_H
#define PROJETT_TRIANGLE_H


#include <sstream>
#include <iostream>
#include "Formes.h"
#include "Vecteur2D.h"
#include "Socket.h"

using namespace std;

class Triangle : public Formes {

private:
    Vecteur2D a, b, c;

public:

    Triangle(int a1, int a2 ,int b1,int b2 , int c1 , int c2 , const string& color = " ") :
            Formes(color), a(a1,a2), b(b1,b2), c(c1,c2) {

    }

    Triangle(Vecteur2D a, Vecteur2D b,Vecteur2D c, const string& color = " ") :
            Formes(color), a(a), b(b) , c(c) {

    }

    double calculerAire() const;
    Vecteur2D getCentreSymetrie() const;
    virtual ~Triangle() {}

    Triangle* clone() const { return new Triangle(*this); }
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );
    void translation(const Vecteur2D& u);
    explicit operator string() const override;
    friend ostream& operator << (ostream& os, const Triangle& m);

    // DP Visitor
    const void *sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void *dessine(const VisiteurLibrairie * visiteur, Socket * s) const;
};


inline ostream& operator << (ostream& os, const Triangle& m) {
    return os << (string)m;
}




#endif //PROJETT_TRIANGLE_H
