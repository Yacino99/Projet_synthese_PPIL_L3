//
// Created by Anwender on 12/02/2022.
//
#include <iostream>

using namespace std;

#include "VisiteurSauvegardeTxt.h"
#include "Erreur.h"

//TODO: - Message de confirmation  de sauvegarde à potentiellement retirer
//      - Si échec de sauvegarde : soit faire un cout, soit throw Erreur("") à l'aide de la classe Erreur (mais dans ce cas comment concaténer la forme qui a posé problème ?)

void *VisiteurSauvegardeTxt::sauvegarde(const Triangle *triangle) const
{
    ofstream fw("../sauvegardeTxt/triangleSave.txt", std::ofstream::out);
    if (fw.is_open())
    {
        fw << triangle << "\n";
        fw.close();
        cout << "Vous avez bien sauvegardez la forme : \"" << triangle << "\", sous le format .txt" << endl;
    }
    //else throw Erreur("Erreur de sauvegarde de la forme sous format .txt");
    else cout << "Erreur de sauvegarde de la forme : \"" << triangle << "\", sous format .txt" << endl;
    fw.close();


    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Rond *rond) const
{
    ofstream fw("../sauvegardeTxt/rondSave.txt", std::ofstream::out);
    if (fw.is_open())
    {
        fw << rond << "\n";
        fw.close();
        cout << "Vous avez bien sauvegardez la forme : \"" << rond << "\", sous le format .txt" << endl;
    }
    else cout << "Erreur de sauvegarde de la forme : \"" << rond << "\", sous format .txt" << endl;
    fw.close();

    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Croix *croix) const
{
    ofstream fw("../sauvegardeTxt/croixSave.txt", std::ofstream::out);
    if (fw.is_open())
    {
        fw << croix << "\n";
        fw.close();
        cout << "Vous avez bien sauvegardez la forme : \"" << croix << "\", sous le format .txt" << endl;
    }
    else cout << "Erreur de sauvegarde de la forme : \"" << croix << "\", sous format .txt" << endl;
    fw.close();

    return 0;
}

void *VisiteurSauvegardeTxt::sauvegarde(const Polygone *polygone) const
{
    ofstream fw("../sauvegardeTxt/polygoneSave.txt", std::ofstream::out);
    if (fw.is_open())
    {
        fw << polygone << "\n";
        fw.close();
        cout << "Vous avez bien sauvegardez la forme : \"" << polygone << "\", sous le format .txt" << endl;
    }
    else cout << "Erreur de sauvegarde de la forme : \"" << polygone << "\", sous format .txt" << endl;
    fw.close();

    return 0;
}

