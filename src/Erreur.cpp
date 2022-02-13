//
// Created by user on 06/02/2022.
//

/*
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include "Erreur.h" //aaaaazz
//zazza
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
