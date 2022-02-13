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

    virtual void dessiner(Socket* ss)const
    {
        ostringstream oss;
        oss << (string)*this;
        string requete = oss.str();
        ss->sendMessage(requete.c_str());

    }

    double calculerAire() const;
    Vecteur2D getCentreSymetrie() const;
    virtual ~Triangle() { delete s; }

    Triangle* clone() const { return new Triangle(*this); }
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );
    void translation(const Vecteur2D& u);
    explicit operator string() const override;
    friend ostream& operator << (ostream& os, const Triangle& m);
};


inline ostream& operator << (ostream& os, const Triangle& m) {
    return os << (string)m;
}


inline void Triangle::translation(const Vecteur2D& u)
{
    a = a + u;
    b = b + u;
    c = c + u;
}

inline void Triangle::homothetie(const Vecteur2D &u, double k) {
    a = k * (a - u) + u;
    b = k * (b - u) + u;
    c = k * (c - u) + u;
}

Triangle::operator string() const
{
    ostringstream os;
    os << "triangle ( " << a.x << " , " << a.y << " , " << b.x << " , " <<
       b.y << " , "  << c.x << " , " << c.y  << " ) " << this->couleur;
    return os.str();
}



//TODO : trouver la bonne formule pour calculer l'air d'un triangle

/**
 * La formule de Héron stipule que l'aire A d'un triangle de côtés de longueurs
 * a , b et c est A = √ d ( d − a ) ( d − b ) ( d − c )
 * où d est le demi-périmètre du triangle ou la moitié de son périmètre.
 * perimetre = somme des 3 cotes du triangle
 */
double Triangle::calculerAire() const {

    double ab =valAbs(a.distance(b));
    double ac =valAbs(a.distance(b));
    double bc = valAbs(b.distance(c));
    double d = (ab+ac+bc)/2;

    return sqrt(d*(d-ab)*(d-ab)*(d-bc));

    // probleme -> NAN
}

void Triangle::rotation(const Vecteur2D &u, const double angle) {

    double m11 = cos(angle);
    double m12 = -sin(angle);
    double m21 = sin(angle);
    double m22 = cos(angle);

    Matrice22 M(m11,m12,m21,m22);

    a =  M * (a - u) + u ;
    b =  M * (b - u) + u ;
    c =  M * (c - u) + u ;
}

Vecteur2D Triangle::getCentreSymetrie() const {
    double x = (a.x+b.x+c.x)/3;
    double y = (a.y+b.y+c.y)/3;
    return Vecteur2D(x,y);
}

#endif //PROJETT_TRIANGLE_H
