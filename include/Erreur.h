//
// Created by user on 06/02/2022.
//

#ifndef PROJETT_ERREUR_H
#define PROJETT_ERREUR_H

/*
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
*/
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
