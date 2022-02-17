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
    Socket* s;
    const double valAbs(double d) const {return d < 0 ? -d : d;}
public:

    Triangle(int a1, int a2 ,int b1,int b2 , int c1 , int c2 , double rayon, Socket* s, const string& color = " ") :
            Formes(color), a(a1,a2), b(b1,b2), c(c1,c2), s(s) {

    }

    Triangle(Vecteur2D a, Vecteur2D b,Vecteur2D c, Socket* s, const string& color = " ") :
            Formes(color), a(a), b(b) , c(c) , s(s) {

    }

    virtual void dessiner(Socket* ss)const;

    double calculerAire() const;
    Vecteur2D getCentreSymetrie() const;
    virtual ~Triangle() { delete s; }

    Triangle* clone() const { return new Triangle(*this); }
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );
    void translation(const Vecteur2D& u);
    explicit operator string() const override;
    friend ostream& operator << (ostream& os, const Triangle& m);

    // DP Visitor pour la sauvegarde
    const void *accepte(const VisiteurSauvegarde * visiteur) const;
};


inline ostream& operator << (ostream& os, const Triangle& m) {
    return os << (string)m;
}




#endif //PROJETT_TRIANGLE_H
