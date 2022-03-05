/**
 * \file      Erreur.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe Erreur
 */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Erreur.h"

using namespace std;

Erreur::Erreur()
{
    strcpy(this->message, "ERREUR ! ");
}

Erreur::Erreur(const char* messageErreur)
{
    strcpy(this->message, "ERREUR : ");
    int l = strlen(messageErreur);

    static int n = LONGUEURMESSAGE - 9;
    if (l <= n) strcat(this->message, messageErreur);
    else
    {
        strncat(this->message, messageErreur, n);
        this->message[LONGUEURMESSAGE] = '\0';
    }
}

Erreur::operator string() const
{
    return string(this->message);
}
