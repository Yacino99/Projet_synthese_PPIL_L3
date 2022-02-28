//
// Created by Anwender on 12/02/2022.
//
#include <iostream>

using namespace std;

#include "VisiteurSauvegardeTxt.h"
#include "Erreur.h"

const void *VisiteurSauvegardeTxt::visite(const Formes *forme) const
{
    ofstream file;

    file.open("../sauvegardeTxt/sauvegardeForme.txt", fstream::app);

    file << forme << "\n";

    file.close();

    return 0;
}

