/**
 * \file      VisiteurSauvegardeTxt.cpp
 * \date      04 mars 2022
 * \brief     Implémentation de la classe VisiteurSauvegardeTxt
 */

#include <iostream>

using namespace std;

#include "VisiteurSauvegardeTxt.h"

const void *VisiteurSauvegardeTxt::visite(const Formes *forme) const
{
    ofstream file;

    file.open("../sauvegardeTxt/sauvegardeForme.txt", fstream::app);

    file << forme << "\n";

    file.close();

    return 0;
}