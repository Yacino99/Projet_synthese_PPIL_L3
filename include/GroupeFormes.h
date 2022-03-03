//
// Created by Yacino99 on 19/02/2022.
//

#ifndef PROJET_GROUPEFORMES_H
#define PROJET_GROUPEFORMES_H

#include <string>
#include <vector>
#include "Formes.h"
#include "Socket.h"

using namespace std;

class GroupeFormes {

private:
    vector<Formes*> formes;
    string couleur;


    // trandformations
    void translation(const Vecteur2D& u) ;
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle ) ;


public:
    explicit GroupeFormes(const string& couleur = " ") : couleur(couleur){}
    GroupeFormes(const vector<Formes*> shapes, const string& couleur = " ") ;
    virtual ~GroupeFormes();

    //getters / setters
    Formes *getForme(int i) const;
    void setCouleur(const string &color);
    const string getCouleur() const;

    GroupeFormes &addForme(const Formes *f);



    void appliquerTranslation(const Vecteur2D &u, bool centreSymetrie);
    void appliquerHomothetie(const Vecteur2D &u, const double k, bool centreSymetrie);
    void appliquerRotation(const Vecteur2D &u, const double angle, bool centreSymetrie) ;


    // pour faire le passage monde ecran
    //virtual void bornes(double &xmin , double &ymin , double &xmax,double &ymax) = 0;

    double calculerAire() const ;
    Vecteur2D getCentreSymetrie() const;
    operator string() const  ;
    virtual GroupeFormes* clone() const {return new GroupeFormes(*this);}


    // DP Visitor
    const void * sauvegarde(const VisiteurSauvegarde * visiteur) const;
    //const void * dessine(const VisiteurLibrairie * visiteur, Socket * s) const;

    void dessine(Socket *s) const;

    friend ostream& operator << (ostream& os,const GroupeFormes &g);

};

/*
inline ostream& operator << (ostream& os, const GroupeFormes& g)
{
    os << (string)(g);
    return os;
}
*/
#endif //PROJET_GROUPEFORMES_H