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
    virtual void dessiner(Socket *ss)const;

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










#endif //PROJETT_CROIX_H
