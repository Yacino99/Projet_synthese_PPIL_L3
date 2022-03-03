//
// Created by Yacino99 on 24/01/2022.
//

#include <iostream>

using namespace std;
#include "Vecteur2D.h"
#include "Matrice22.h"
#include "Erreur.h"
#include "InitReseaux.h"
#include "Socket.h"
#include "Formes.h"
#include "Rond.h"
#include "Croix.h"
#include "Triangle.h"
#include "Polygone.h"
#include "test.h"
#include "VisiteurSauvegarde.h"
#include "VisiteurSauvegardeTxt.h"

#include "Expert.h"
#include "ExpertChargementCOR.h"
#include "ExpertChargementGroupeCOR.h"
#include "ExpertChargementCroixCOR.h"
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

void testMatrice(){
    Matrice22 m1(1,2,3,4);
    Vecteur2D v1(1,2);
    Vecteur2D v2(3,4);
    Matrice22 m2(v1,v2);
    cout << v1 << endl << v2 << endl;
    cout << m1 << endl << m2 << endl;

    double m11 = cos(M_PIl);
    double m12 = -sin(M_PIl);
    double m21 = sin(M_PIl);
    double m22 = cos(M_PIl);

    Matrice22 M(m11,m12,m21,m22);


    cout << m1*v1 << endl;
    cout << "OK !!!!!!!!!!!!!!!!!!!!!! \n";
    cout << M << endl;

}

void testDistVect(){

    cout << "--------test des distances ------------" << endl;

    Vecteur2D u1(2,1), u2(7,2), v(5), w, v1(35,-63), u3(6,5), u4(3,-4);

    cout << " u1 = " <<  u1 << " u2 = " << u2 << " dist(u1,u2) = " << u1.distance(u2) << endl;
    // cout << " u1 = " <<  u1 << " u2 = " << u2 << " dist(u2,u1) = " << u2.distance(u1) << endl;
    cout << " u1 = " <<  u1 << " u3 = " << u3 << " dist(u1,u3) = " << u1.distance(u3) << endl;
    cout << " u2 = " <<  u2 << " u3 = " << u3 << " dist(u2,u3) = " << u2.distance(u3) << endl;
    cout << "u1 = " << u1 << " dist(u1,u1) = " << u1.distance(u1) << endl;

    double ab =  u1.distance(u2) , ac = u1.distance(u3) , bc = u2.distance(u3);
    double demiPeri = (ab + ac + bc)/2 ;
    double d = demiPeri;

    double aires = sqrt(d*(d-ab)*(d-ac)*(d-bc));
    cout << "demi perimetrre = " << demiPeri << endl;
    cout << "aire = " << aires << endl;


}

int main()
{
    //testMatrice();
    testDistVect();
    test t;
    t.sayHi();

    cout << "essai des vecteurs 2D \n";

    Vecteur2D u1(2,3), u2(2,3), v(5), w, v1(35,-63), u3(3,4), u4(3,-4), v3;

    cout << " u1 = " <<  u1 << endl;
    cout << " u2 = " <<  u2 << endl;
    cout << " u1 - u2 = " <<  u1-u2 << endl;
    cout << " 5*u1 = " <<  u1*5 << endl;

    cout << "Determinant de u1 et u3 = " << u1.determinant(u3) << endl;
    cout << u1 << " . " << u2 << " = " << u1*u2<<endl; // produit scalaire de deux vecteurs

    cout << "test operator = et == " << endl;
    u1 = u3;

    cout << "u1 = " << u1 << " u3 = " << u3 << "u1 == u3 ->" << (u1==u3) << endl;

    cout << "Test sur les matrices 2x2" << endl;

    Matrice22 m1(u1,u2);
    Matrice22 m2(u3,u4);

    cout << "m1 = \n" << m1 << endl;
    cout << "m2 = \n" << m2 << endl;


    cout << "m1 - m2 = \n" << m1 -m2 << endl;
    cout << "m1 + m2 = \n" << m1 +m2 << endl;
    cout << "m1 * u4 = \n" << m1 * u4 << endl;
    cout << "m1 * 5 = \n" << m1 *5 << endl;


    m1 = m2;
    // test d'affectation matrice
    cout << "m1 = m2 -> "<< (m1==m2) << endl << m1 << endl << m2 << endl;

    cout << "m1 *m1-1 = " << m1*m1.inverse() << endl;


    try{
        const char* addr = "127.0.0.1";
        InitReseaux* reseau = InitReseaux::getInitReseaux();
        Socket * s = new Socket(addr, 9111);

        cout << " on est la" << endl;

        Formes * f1 ,*f2 , *f3;
        f1 = new Rond (300, 300, 30.0, "blue");
        f2 = new Croix(30, 100, 100, 30, "red");

        // test du rond
        f1->dessine(new VisiteurLibrairieAwt, s);
        f1->translation(u1*15);
        f1->dessine(new VisiteurLibrairieAwt, s);
        f1->homothetie(Vecteur2D(0,0),1.3);
        f1->dessine(new VisiteurLibrairieAwt, s);
        //test croix
        f2->dessine(new VisiteurLibrairieAwt, s);
        f2->translation(u1*12);
        f2->dessine(new VisiteurLibrairieAwt, s);
        f2->homothetie(Vecteur2D(0,0),1.5);
        f2->dessine(new VisiteurLibrairieAwt, s);
        // test Triangle
        f3 =  new Triangle(Vecteur2D(30,200), Vecteur2D(90,200), Vecteur2D(45,50), "green");
        f3->dessine(new VisiteurLibrairieAwt, s);
        cout << "aire du triangle est = " << f3->calculerAire() << endl;
        f3->translation(u2*31);
        f3->dessine(new VisiteurLibrairieAwt, s);
        cout << "aire du triangle est = " << f3->calculerAire() << endl;
        f3->homothetie(Vecteur2D(0,0),2);
        f3->setColor("red");
        //  f3->rotation(Vecteur2D(0,0), M_PIl);
        f3->dessine(new VisiteurLibrairieAwt, s);
        cout << f3 << " Aire = " << f3->calculerAire() << endl;

        Formes* gros = new Rond(Vecteur2D(400,400) ,100 , "red");
        gros->dessine(new VisiteurLibrairieAwt, s);
        gros->rotation(Vecteur2D(400,400),M_PIl);
        gros->dessine(new VisiteurLibrairieAwt, s);

        //Formes * f3;
        f3 =  new Triangle(Vecteur2D(30,200), Vecteur2D(90,200), Vecteur2D(45,50), "green");
        Vecteur2D centreTri( (30+90+45)/3,(200+200+50)/3);

        // f3->dessine(new VisiteurLibrairieAwt, s);
        //f3->translation(u2*31);
        //f3->dessine(new VisiteurLibrairieAwt, s);
        //f3->homothetie(Vecteur2D(0,0),2);
        //f3->setColor("red");
        // f3->rotation(f3->getCentreSymetrie(), M_PIl/2);
        //f3->dessine(new VisiteurLibrairieAwt, s);

        //test croix rotation
        /* Formes * f2 = new Croix(30, 100, 100, 30, "red");
         f2->dessine(new VisiteurLibrairieAwt, s);
         f2->rotation(f2->getCentreSymetrie(),M_PIl/6);
         f2->dessine(new VisiteurLibrairieAwt, s);
 */

        // ================================== Sauvegarde des formes dans un fichier text  ==================================
        /* f1->sauvegarde(new VisiteurSauvegardeTxt);
         f2->sauvegarde(new VisiteurSauvegardeTxt);
         f3->sauvegarde(new VisiteurSauvegardeTxt);*/
        // =================================================================================================================

        Vecteur2D a(120, 40), b(140, 70), c(150, 80);
        Vecteur2D d(190, 60), e(60, 125), f(90, 125);

        /*
          polygon2.addPoint( 165, 135 );
         polygon2.addPoint( 175, 150 );
         polygon2.addPoint( 270, 200 );
         polygon2.addPoint( 200, 220 );
         polygon2.addPoint( 130, 180 ); */
        Polygone * p = new Polygone();
        p->addPoint(new Vecteur2D(175,135)).addPoint(new Vecteur2D(270,200))
                .addPoint(new Vecteur2D(200,220)).addPoint(new Vecteur2D(130,180));//.addPoint(&e);
        p->rotation(p->getCentreSymetrie(),M_PIl/2);
        cout << "aire = " << p->calculerAire() << endl;
        //p->dessine(new VisiteurLibrairieAwt, s);


        Vecteur2D aa(175,135);
        Vecteur2D bb(270,200);
        Vecteur2D cc(200,220);
        Vecteur2D dd(130,180);

        //--- test des distances du polygone
        double ab = aa.distance(bb);
        double bc = bb.distance(cc);
        double cd = cc.distance(dd);
        double ad = aa.distance(dd);

        cout << "ab = " << ab << " bc = " << bc << " cd= " << cd << " ad= " << ad << endl;

        //-------test du groupe formes---------------------------



        GroupeFormes groupe("red");
        groupe.addForme(f1).addForme(f2).addForme(f3);

        groupe.dessine(s);
        groupe.appliquerHomothetie(Vecteur2D(0,0), 0.5, false);
        groupe.dessine(s);
        groupe.dessine(new VisiteurLibrairieAwt, s);

        // verifier que la couleur de la forme inseré est un clone de l'original donc l'original n'est pas modifié
        f1->dessine(new VisiteurLibrairieAwt, s);

        cout << groupe << endl;


        /* Rond * rond = new Rond(1200,200,50,"purple");
         //rond->dessine(new VisiteurLibrairieAwt, s);
         Rond * rond2 = new Rond(900,200,50,"blue");
         //rond2->dessine(new VisiteurLibrairieAwt, s);
         Triangle *tt = new Triangle(Vecteur2D(200,200),Vecteur2D(300,100),Vecteur2D(800,100),"red");
         //tt->dessine(new VisiteurLibrairieAwt, s);
         Triangle *tt1 = new Triangle(Vecteur2D(-0.3,1.7),Vecteur2D(2.8,-2.5),Vecteur2D(4.3,5.2),"purple");
         Rond * rond3 = new Rond(5.8,-3.5,1.2,"blue");
         // pBG = (-0.3 , -2.5) <- absisse/ordonnee mini  pHD = (7,5.2) <- absisse/ordonnee maxi
         GroupeFormes *g2 = new GroupeFormes("purple");
         g2->addForme(tt1);
         g2->addForme(rond3);*/

        /*  cout << "==================================================================" << endl;

          //g2->dessine(s);
          g2->sauvegarde(new VisiteurSauvegardeTxt);

          cout << "==================================================================" << endl;
          */
        // Test chargement de formes
/*
        cout << "================================================== TEST CHARGEMENT ==================================================" << endl;

        ifstream ifs("../sauvegardeTxt/sauvegardeForme.txt", std::ifstream::in);
        cout << "Lecture des valeurs : " << endl;
        vector<Formes *> listFormes = ChargeurListeFormes::charge(ifs);

       /* vector<Formes*>::iterator it = listFormes.begin();
        for (std::size_t i = 0; i < listFormes.size(); i++)
            listFormes[i]->dessine(new VisiteurLibrairieAwt, s);*/

        //   cout << "================================================ FIN TEST CHARGEMENT ================================================" << endl;


        //g2->dessinerFormes(s,600,300); // defini rect '    pBasGauche'=(0,300) , pHautDroit' = (600,0)

        // Formes * grb = new GroupeFormes();
        // ici yacino
        int nnn;
        cout << "type any character -:" ;
        cin >>nnn;

    }catch(Erreur e)
    {
        cout << e.message;
    }

    cout << "Fin du programme :) !!!"<<endl;


    return 0;
}