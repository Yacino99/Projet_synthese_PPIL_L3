/**
 * \file      GroupeFormes.h
 * \date      04 mars 2022
 * \brief     Classe GroupeFormes
 * \details   Un groupe de formes est représenté par un vecteur de formes
 */

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
    /**  \brief  Constructeur  */
    explicit GroupeFormes(const string& couleur = " ") : Formes(couleur)
    {
        this->couleur = couleur;
    }
    /**  \brief  Constructeur  */
    GroupeFormes(vector<Formes*> shapes, const string& couleur = " ") : Formes(couleur)
    {
        this->couleur = couleur;
        formes = shapes;
    }

    virtual ~GroupeFormes();

    Formes *getForme(int i) const;
    void setCouleur(const string &color);
    const string getCouleur() const { return couleur; }

    GroupeFormes &addForme(const Formes *f);

    /**  \brief  Opération de translation */
    void translation(const Vecteur2D& u) ;
    /**  \brief  Opération d'homothétie */
    void homothetie(const Vecteur2D& u,double k) ;
    /**  \brief  Opération de rotation */
    void rotation(const Vecteur2D &u, const double angle ) ;

    /**  \brief  Opération de translation */
    void appliquerTranslation(const Vecteur2D &u, bool centreSymetrie);
    /**  \brief  Opération d'homothétie */
    void appliquerHomothetie(const Vecteur2D &u, const double k, bool centreSymetrie);
    /**  \brief  Opération de rotation */
    void appliquerRotation(const Vecteur2D &u, const double angle, bool centreSymetrie) ;

    double calculerAire() const ;
    Vecteur2D getCentreSymetrie() const;
    operator string() const  ;
    virtual GroupeFormes* clone() const {return new GroupeFormes(*this);}

    const double sommeAires() const;

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
