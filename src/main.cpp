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

int main()
{
    //testMatrice();


    cout << "essai des vecteurs 2D \n";

    Vecteur2D u1(2,3), u2(2,3), v(5), w, v1(35,-63), u3(3,4), u4(3,-4), v3;

    cout << " u1 = " <<  u1 << endl;
    cout << " u2 = " <<  u2 << endl;
    cout << " u1 - u2 = " <<  u1-u2 << endl;
    cout << " 5*u1 = " <<  5*u1 << endl;

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
        std::cout << "initialisation reseau reussi!\n";
        Socket *socket = new Socket(addr, 9111);

        cout << " on est la" << endl;


        /*
        Formes * f1 ,*f2 , *f3;
        f1= new Rond (300, 300, 30.0, socket, "blue");
        f2 = new Croix(30, 100, 100, 30, socket, "red");
        // test du rond
        f1->dessiner(socket);
        f1->translation(u1*15);
        f1->dessiner(socket);
        f1->homothetie(Vecteur2D(0,0),1.3);
        f1->dessiner(socket);
        //test croix
        f2->dessiner(socket);
        f2->translation(u1*12);
        f2->dessiner(socket);
        f2->homothetie(Vecteur2D(0,0),1.5);
        f2->dessiner(socket);
        // test Triangle
        f3 =  new Triangle(Vecteur2D(30,200), Vecteur2D(90,200), Vecteur2D(45,50), socket, "green");
        f3->dessiner(socket);
        f3->translation(u2*31);
        f3->dessiner(socket);
        f3->homothetie(Vecteur2D(0,0),2);
        f3->setColor("red");
      //  f3->rotation(Vecteur2D(0,0), M_PIl);
        f3->dessiner(socket);
        cout << f3 << " Aire = " << f3->calculerAire() << endl;
     */
        Formes* gros = new Rond(Vecteur2D(400,400) ,100 , socket , "red");
        gros->dessiner(socket);
        gros->rotation(Vecteur2D(400,400),M_PIl);
        gros->dessiner(socket);

        Formes * f3;
        f3 =  new Triangle(Vecteur2D(30,200), Vecteur2D(90,200), Vecteur2D(45,50), socket, "green");
        Vecteur2D centreTri( (30+90+45)/3,(200+200+50)/3);
        // f3->dessiner(socket);
        //f3->translation(u2*31);
        //f3->dessiner(socket);
        //f3->homothetie(Vecteur2D(0,0),2);
        //f3->setColor("red");
        // f3->rotation(f3->getCentreSymetrie(), M_PIl/2);
        //f3->dessiner(socket);


        //test croix rotation
       /* Formes * f2 = new Croix(30, 100, 100, 30, socket, "red");
        f2->dessiner(socket);
        f2->rotation(f2->getCentreSymetrie(),M_PIl/6);
        f2->dessiner(socket);
*/


        Vecteur2D a(120, 40), b(140, 70), c(150, 80);
        Vecteur2D d(190, 60), e(60, 125), f(90, 125);

        /*
         * 32 polygon2.addPoint( 165, 135 );
         polygon2.addPoint( 175, 150 );
         polygon2.addPoint( 270, 200 );
         polygon2.addPoint( 200, 220 );
         polygon2.addPoint( 130, 180 ); */

        Polygone * p = new Polygone(socket);
        p->addPoint(new Vecteur2D(175,135)).addPoint(new Vecteur2D(270,200))
        .addPoint(new Vecteur2D(200,220)).addPoint(new Vecteur2D(130,180));//.addPoint(&e);
        p->rotation(p->getCentreSymetrie(),M_PIl/2);
        p->dessiner(socket);
        int nnn;
        cout << "type any character -:" ;
        cin >>nnn;

    }catch(Erreur e)
    {
        cout << e.message;
    }

    cout << "Fin du programme !!!"<<endl;


    return 0;
}