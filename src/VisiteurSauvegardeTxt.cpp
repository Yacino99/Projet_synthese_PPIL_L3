//
// Created by Anwender on 12/02/2022.
//
#include <iostream>

using namespace std;

#include "VisiteurSauvegardeTxt.h"
#include "Erreur.h"

void *VisiteurSauvegardeTxt::sauvegarde(const Triangle *triangle) const
{
    // Lecture d'un fichier
    /*ifstream ifs("../sauvegardeTxt/triangleSave.txt");
    string tmp;
    while (getline(ifs, tmp))
    {
        cout << "ligne lue : " << tmp << endl;
    }*/

    // Nouvelle version de l'écriture dans un fichier
    ofstream file;
    file.open("../sauvegardeTxt/triangleSave.txt", fstream::app);

    file << triangle << "\n";

    file.close();

    // Ancienne version de l'écriture dans un fichier
    //ofstream fw("../sauvegardeTxt/triangleSave.txt", std::ofstream::out);
    /*if (fw.is_open())
    {
        fw << "\n" << triangle << "\n";
        fw.close();
        cout << "Vous avez bien sauvegardez la forme : \"" << triangle << "\", sous le format .txt" << endl;
    }
    //else throw Erreur("Erreur de sauvegarde de la forme sous format .txt");
    else cout << "Erreur de sauvegarde de la forme : \"" << triangle << "\", sous format .txt" << endl;
    fw.close();*/

    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Rond *rond) const
{
    ofstream file;
    file.open("../sauvegardeTxt/rondSave.txt", fstream::app);

    file << rond << "\n";

    file.close();

    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Croix *croix) const
{
    ofstream file;
    file.open("../sauvegardeTxt/croixSave.txt", fstream::app);

    file << croix << "\n";

    file.close();

    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Polygone *polygone) const
{
    ofstream file;
    file.open("../sauvegardeTxt/polygoneSave.txt", fstream::app);

    file << polygone << "\n";

    file.close();

    return 0;
}

