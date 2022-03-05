/**
 * \file      Erreur.h
 * \date      04 mars 2022
 * \brief     Classe Erreur
 */

#ifndef PROJETT_ERREUR_H
#define PROJETT_ERREUR_H

using namespace std;
#include <string>
#include <iostream>

class Erreur {

public:
    const static int LONGUEURMESSAGE = 100;
    char message[1 + LONGUEURMESSAGE];

    Erreur();
    Erreur(const char* messageErreur);

    operator string() const;

    friend ostream& operator << (ostream& os, const Erreur& erreur);
};

inline ostream& operator << (ostream& os, const Erreur& erreur)
{
    os << (string)erreur;
    return os;
}

#endif //PROJETT_ERREUR_H
