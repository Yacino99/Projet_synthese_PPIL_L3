/**
 * \file      Formes.h
 * \date      04 mars 2022
 * \brief     Classe Formes
 */

#ifndef PROJETT_FORMES_H
#define PROJETT_FORMES_H

#include <string>
#include "Socket.h"
#include "Vecteur2D.h"
#include "Transformable.h"

using namespace std;

class VisiteurSauvegarde;
class VisiteurLibrairie;

class Formes : public Transformable
{
protected:
    string couleur;

public:

    /**  \brief  Constructeur vide */
    Formes();
    /**  \brief  Constructeur */
    Formes(const string& couleur) : couleur(couleur) {}


    /**  \brief  Opération de translation */
    virtual void translation(const Vecteur2D& u) = 0;
    /**  \brief  Opération d'homothétie */
    virtual void homothetie(const Vecteur2D& u,double k) = 0;
    /**  \brief  Opération de rotation */
    virtual void rotation(const Vecteur2D &u, const double angle ) = 0;


    /** \brief
     * Avoir le point X minimal et point Y minimal  du plan selon la figure
     * @return un vecteur2D qui contient le le point min x et le point min Y
     */
    virtual Vecteur2D getMinXMinY() const =0;

    /** \brief
     * Avoir le point X maximal et point Y maximal  du plan selon la figure
     * @return un vecteur2D qui contient le le point max x et le point max Y
     */
    virtual Vecteur2D getMaxXMaxY() const =0;


    void setColor(const string& c) { couleur=c;}
    virtual double calculerAire() const = 0;
    virtual Vecteur2D getCentreSymetrie() const = 0;
    virtual operator string() const  = 0;
    virtual Formes* clone() const = 0;

    inline friend ostream& operator << (ostream& os, const Formes* m);
    virtual ~Formes() {}

    /**  \brief      Méthode de sauvegarde du Design Pattern Visitor */
    virtual const void * sauvegarde(const VisiteurSauvegarde * visiteur) const = 0;
    /**  \brief      Méthode de dessin du Design Pattern Visitor */
    virtual const void * dessine(const VisiteurLibrairie * visiteur, Socket * s) const = 0;
};

inline ostream& operator << (ostream& os, const Formes* m)
{
    os << (string)(*m);
    return os;
}

#endif //PROJETT_FORMES_H