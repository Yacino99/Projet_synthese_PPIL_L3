//
// Created by Anwender on 03/03/2022.
//

#ifndef PROJET_GROUPEFORMES_H
#define PROJET_GROUPEFORMES_H

#include <string>
#include <vector>
#include "Formes.h"
#include "Socket.h"

class GroupeFormes : public Formes
{

private:
    vector<Formes*> formes;
    string couleur;

public:
    explicit GroupeFormes(const string& couleur = " ") : Formes(couleur)
    {
        this->couleur = couleur;
    }

    GroupeFormes(vector<Formes*> shapes, const string& couleur = " ") : Formes(couleur)
    {
        this->couleur = couleur;
        formes = shapes;
    }

    virtual ~GroupeFormes();

    //getters / setters
    Formes *getForme(int i) const;
    void setCouleur(const string &color);
    const string getCouleur() const { return couleur; }

    GroupeFormes &addForme(const Formes *f);

    // trandformations
    void translation(const Vecteur2D& u) ;
    void homothetie(const Vecteur2D& u,double k) ;
    void rotation(const Vecteur2D &u, const double angle ) ;

    void appliquerTranslation(const Vecteur2D &u, bool centreSymetrie);
    void appliquerHomothetie(const Vecteur2D &u, const double k, bool centreSymetrie);
    void appliquerRotation(const Vecteur2D &u, const double angle, bool centreSymetrie) ;

    double calculerAire() const ;
    Vecteur2D getCentreSymetrie() const;
    operator string() const  ;
    virtual GroupeFormes* clone() const {return new GroupeFormes(*this);}

    const double sommeAires() const;

    // DP Visitor
    const void * sauvegarde(const VisiteurSauvegarde * visiteur) const;
    const void * dessine(const VisiteurLibrairie * visiteur, Socket * s) const;

    friend ostream& operator << (ostream& os,const GroupeFormes &g);

};

inline ostream& operator << (ostream& os, const GroupeFormes& g)
{
    os << (string)(g);
    return os;
}

#endif //PROJET_GROUPEFORMES_H
