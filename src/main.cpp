/**
 * \file      main.cpp
 * \date      04 mars 2022
 * \brief     Main
 */

#include <iostream>

using namespace std;
#include "Vecteur2D.h"
#include "Matrice22.h"
#include "Erreur.h"
#include "InitReseaux.h"
#include "Socket.h"
#include "Formes.h"
#include "Rond.h"
#include "Segment.h"
#include "Triangle.h"
#include "Polygone.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurSauvegardeTxt.h"

#include "Expert.h"
#include "ExpertChargementCOR.h"
#include "ExpertChargementSegmentCOR.h"
#include "ExpertChargementPolygoneCOR.h"
#include "ExpertChargementRondCOR.h"
#include "ExpertChargementTriangleCOR.h"
#include "ChargeurListeFormes.h"

#include "VisiteurLibrairie.h"
#include "VisiteurLibrairieAwt.h"

#include "GroupeFormes.h"

#pragma comment(lib,"ws2_32.lib") // specifique  a visual studio et Clion

# define M_PIl          3.141592653589793238462643383279502884L
//-----------------------------------------debut test------------------------------------------------------

/**
 *  \fn int main ()
 */
int main()
{
    Vecteur2D u1(2,3), u2(2,3), v(5), w, v1(35,-63), u3(3,4), u4(3,-4), v3;

    try
    {
        // =======================  Initialisation d'une socket pour le client TCP/IP =======================
        const char* addr = "127.0.0.1";
        InitReseaux* reseau = InitReseaux::getInitReseaux();
        Socket * socket = new Socket(addr, 9111);

        // ======================= CREATIONS DE FORMES =======================
        Formes *rond, *segment, *triangle;
        Polygone * polygone = new Polygone();
        polygone->addPoint(new Vecteur2D(175,135)).addPoint(new Vecteur2D(270,200)).addPoint(new Vecteur2D(200,220)).addPoint(new Vecteur2D(130,180));
        polygone->setColor("blue");
        rond = new Rond(300, 300, 30.0, "blue");
        segment = new Segment(30, 100, 100, 30, "blue");
        triangle = new Triangle(Vecteur2D(30,200), Vecteur2D(90,200), Vecteur2D(45,50), "blue");

        // ======================= DESSIN DES FORMES =======================
        /*polygone->dessine(new VisiteurLibrairieAwt, socket);
        rond->dessine(new VisiteurLibrairieAwt, socket);
        segment->dessine(new VisiteurLibrairieAwt, socket);
        triangle->dessine(new VisiteurLibrairieAwt, socket);*/

        // ======================= CREATION ET DESSIN D'UN GROUPE DE FORME =======================
        GroupeFormes *groupeForm = new GroupeFormes("magenta");
        groupeForm->addForme(rond);
        groupeForm->addForme(segment);
        groupeForm->addForme(polygone);
        groupeForm->addForme(triangle);
        //groupeForm->dessine(new VisiteurLibrairieAwt, socket);

        // ======================= TRANSFORMATIONS GEOMETRIQUE =======================
        cout << "Triangle avant translation : " << triangle << endl;
        triangle->translation(u1*30);
        cout << "Triangle apres translation : " << triangle << endl;

        // ======================= SAUVEGARDE ET CHARGEMENT D'UNE FORME =======================
        //triangle->sauvegarde(new VisiteurSauvegardeTxt);
       //groupeForm->sauvegarde(new VisiteurSauvegardeTxt);
        ifstream ifs("../sauvegardeTxt/sauvegardeForme.txt", std::ifstream::in);
        vector<Formes *> listFormes = ChargeurListeFormes::charge(ifs);

        // ======================= ENVOIE AU SERVEUR DES FORMES CHARGEES POUR DESSIN =======================
        vector<Formes*>::iterator it = listFormes.begin();
        for (std::size_t i = 0; i < listFormes.size(); i++)
        {
            listFormes[i]->dessine(new VisiteurLibrairieAwt, socket);
        }

        // ======================= FONCTIONNALITE DIVERSES =======================
        // ======================= CALCUL D'AIRE =======================
        double airePolygone = polygone->calculerAire();
        cout << "L'aire du polygone est de : " << airePolygone << endl;

        // ======================= CONVERSION EN STRING =======================
        cout << polygone << endl;
        cout << groupeForm << endl;

        // ======================= Monde/Ecran =======================
        Formes * MondeEcran;
        MondeEcran = new Rond(10, 10, 2, "red");
        MondeEcran->dessine(new VisiteurLibrairieAwt, socket);

        int nnn;
        cout << "type any character -:" ;
        cin >>nnn;

    }
    catch(Erreur e)
    {
        cout << e.message;
    }

    cout << "Fin du programme :) !!!" << endl;

    return 0;
}