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

public:
    explicit GroupeFormes(const string& couleur = " ") : couleur(couleur){}
    explicit GroupeFormes(const vector<Formes*> shapes, const string& couleur = " ") : couleur(couleur),
                                                                                            formes(shapes){}
    virtual ~GroupeFormes(){}
    // setters & getters

    Formes * getForme(int i) const;

    void setCouleur(const string &color);
    const string  getCouleur() const;

    // operators
    operator string() const;
    GroupeFormes & addForme(const Formes * f);

    // tranformations
    void appliquerTranslation(const Vecteur2D& u  , bool centreSymetrie = true);
    void appliquerHomothetie(const Vecteur2D& u, const double k , bool centreSymetrie = true);
    void appliquerRotation(const Vecteur2D& u, const double angle , bool centreSymetrie = true);

    const double sommeAires() const;
    void dessinerFormes(Socket *s) const;

     friend ostream& operator << (ostream& os, const Formes& g);

};

/*
inline ostream& operator << (ostream& os, const GroupeFormes& g)
{
    os << (string)(g);
    return os;
}
*/
#endif //PROJET_GROUPEFORMES_H
