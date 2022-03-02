package mainLocal;

import ChainOfResponsability.CadreDessin;
import ChainOfResponsability.DrawCircleHandler;
import ChainOfResponsability.DrawLineHandler;
import ChainOfResponsability.Handler;
import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.TransfoMondeEcran;
import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;

public class Main {

    public static void main(String[] args) {
	// write your code here

        Handler h1 = new DrawCircleHandler();
        Handler h2 = new DrawLineHandler();

        h1.setNextChain(h2);
        System.out.println("le push");
        System.out.println("before");

        try{
            CadreDessin cadreDessin = new CadreDessin("cadre dessin",60,60,Config.LARGEUR, Config.HAUTEUR);
            cadreDessin.setResizable(false);
            //h1.handle("rond(200,200,50,50)",cadreDessin);
           // h2.handle("croix(140,100,30,70)",cadreDessin);

            Vecteur2D centre = new Vecteur2D(5,5);
            int rayoon = 3;
            TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(new Vecteur2D(centre.getX()-rayoon,centre.getY()-rayoon),
                    new Vecteur2D(centre.getX()+rayoon,centre.getY()+rayoon),
                    new Vecteur2D(0,Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));


            int r = t.convertirRayonDuCercle(centre,rayoon,new Vecteur2D(centre.getX()-rayoon,centre.getY()-rayoon),
                    new Vecteur2D(centre.getX()+rayoon,centre.getY()+rayoon));

            Vecteur2D c = t.transforme(centre);
            cadreDessin.graphics.fillOval((int)c.getX(),(int)c.getY(),r,r);
            System.out.println("x = "+c.getX()+" y ="+c.getY()+" r= "+r);
            /*
            TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(new Vecteur2D(-2,-8),
                    new Vecteur2D(10,0),
                    new Vecteur2D(0,-Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

            Vecteur2D c = new Vecteur2D(6,-5); // coordoonnes du cercle
            Vecteur2D r = new Vecteur2D(3,3);  // rayon
            Vecteur2D ct = t.transforme(c);   // cercle converti en monde ecran

            int rayon = t.convertirRayonDuCercle(c,5,new Vecteur2D(-2,-10),
                    new Vecteur2D(10,0) );  // rayon converti en monde ecran

            System.out.println("x t = " + ct.getX()+"  y t = "+ct.getY()+ " rayon = "+rayon);

            cadreDessin.graphics.setColor(Color.BLUE);
            cadreDessin.graphics.fillOval((int)ct.getX(),(int)ct.getY(),rayon,rayon);
            //cadreDessin.graphics.fillOval((int)ct.getX(),(int)ct.getY(),20,20);
            //cadreDessin.graphics.drawOval(200,200,80,80);
            */

            cadreDessin.getBufferStrategy().show();

        }catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("after");
    }
}
