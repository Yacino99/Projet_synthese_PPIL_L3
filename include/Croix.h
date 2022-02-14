//
// Created by Yacino99 on 07/02/2022.
//

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

class Croix : public Formes{

private :


    Vecteur2D a, b;
    Socket* s;
public:

    Croix(double g, double h, double d, double b,  Socket* s, const string& couleur = " ") :
            Formes(couleur) , s(s) , a(g,h),b(d,b){
    }
    Croix(Vecteur2D a, Vecteur2D b,  Socket* s, const string& couleur = " ") :
            Formes(couleur) , s(s) , a(a),b(b){
    }

    // dans le projet on met un parametre pour dessiner
    virtual void dessiner(Socket *ss)const
    {

        ostringstream oss;
        oss << (string)*this;
        string requete = oss.str();
        ss->sendMessage(requete.c_str());

    }

    double calculerAire() const;
    Vecteur2D getCentreSymetrie() const;
    Croix* clone() const { return new Croix(*this); }
    virtual ~Croix() { delete s; }
    friend ostream& operator << (ostream& os, const Croix& m);
    operator string() const;


    void translation(const Vecteur2D &u);
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle );


};


inline ostream& operator << (ostream& os, const Croix& m) {
    return os << (string)m;
}

Croix::operator string() const
{
    ostringstream os;

    os << "croix ( " << a.x << " , " <<
       a.y << " , " << b.x << " , " << b.y << " )" << this->couleur;


    return os.str();
}

inline void Croix::translation(const Vecteur2D &u)
{
    a = a + u;
    b = b + u;
}

inline void Croix::homothetie(const Vecteur2D &u, double k) {
    a =  (a - u)*k  + u;
    b =  (b - u)*k  + u;
}

//Vecteur OB’ = R * (vecteur OB – vecteur OC) + vecteur OC
inline void Croix::rotation(const Vecteur2D &u, const double angle) {
    Matrice22 M(Vecteur2D(cos(angle),-sin(angle)) , Vecteur2D(sin(angle), cos(angle)));
    b =  M * (b - u) + u ;
    a =  M * (a - u) + u ;
}

double Croix::calculerAire() const {
    return 0;
}

Vecteur2D Croix::getCentreSymetrie() const {
    double x = (a.x+b.x)/2;
    double y = (a.y+b.y)/2;
    return Vecteur2D(x,y);
}


#endif //PROJETT_CROIX_H
