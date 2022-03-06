package mainLocal;

import ChainOfResponsability.CadreDessin;
import ChainOfResponsability.DrawCircleHandler;
import ChainOfResponsability.DrawLineHandler;
import ChainOfResponsability.Handler;
import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.Pair;
import Serveur.Convertisseur.TransfoMondeEcran;
import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;
import java.util.ArrayList;

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


            //CAS ISGROUPE = FALSE , IL LE MET AU CENTRE DE L'ECRAN

            Vecteur2D centre = new Vecteur2D(5,5);
            int rayoon = 3;

            Pair<Vecteur2D> p = TransfoMondeEcran.basGaucheHautDroitCercle(centre,rayoon);


            TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(p.getPremier(),p.getDeuxieme(),
                    new Vecteur2D(0,Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

            int r = t.convertirRayonDuCercle(centre,rayoon,new Vecteur2D(centre.getX()-rayoon,centre.getY()-rayoon),
                    new Vecteur2D(centre.getX()+rayoon,centre.getY()+rayoon));

            Vecteur2D c = t.transforme(centre);
            cadreDessin.graphics.fillOval((int)c.getX(),(int)c.getY(),r,r);
            System.out.println("x = "+c.getX()+" y ="+c.getY()+" r= "+r);


            /*

            // CAS ISGROUPE = TRUE , IL LE MET PAS AU CENTRE DE L'ECRAN

            TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(new Vecteur2D(-2,-8),
                    new Vecteur2D(10,0),
                    new Vecteur2D(0,-Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

            Vecteur2D c = new Vecteur2D(6,-5); // coordoonnes du cercle
           // rayon = 5
            Vecteur2D ct = t.transforme(c);   // cercle converti en monde ecran

            int rayon = t.convertirRayonDuCercle(c,5,new Vecteur2D(-2,-10),
                    new Vecteur2D(10,0) );  // rayon converti en monde ecran

            System.out.println("x t = " + ct.getX()+"  y t = "+ct.getY()+ " rayon = "+rayon);

            cadreDessin.graphics.setColor(Color.BLUE);
            cadreDessin.graphics.fillOval((int)ct.getX(),(int)ct.getY(),rayon,rayon);
            //cadreDessin.graphics.fillOval((int)ct.getX(),(int)ct.getY(),20,20);
            //cadreDessin.graphics.drawOval(200,200,80,80);
*/

            /*
            Vecteur2D deb = new Vecteur2D(-1,1) ; Vecteur2D fin = new Vecteur2D(5,5);
            Pair<Vecteur2D> p2 = TransfoMondeEcran.basGaucheHautDroitSegment(deb,fin);

            TransfoMondeEcran t2 = TransfoMondeEcran.creerTransfoMondeEcran(p2.getPremier(),p2.getDeuxieme(),
                    new Vecteur2D(0,Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

            deb = t2.transforme(deb);
            fin = t2.transforme(fin);

            cadreDessin.graphics.drawLine((int)deb.getX(),(int)deb.getY(),(int)fin.getX(),(int)fin.getY());
            */

        /*
            int[] x = new int[]{-1,2,3};
            int[] y = new int[]{-1,4,1};

            //int[] x = new int[]{60,420,540};
            //int[] y = new int[]{600,0,360};


            Pair<Vecteur2D> p3 = TransfoMondeEcran.basGaucheHautDroitTriangleEtPolygone(x,y);

            TransfoMondeEcran t3 = TransfoMondeEcran.creerTransfoMondeEcran(p3.getPremier(),p3.getDeuxieme(),
                    new Vecteur2D(0,Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

            ArrayList<Vecteur2D> pointss = Vecteur2D.pointsToVect(x,y);

            for(int i = 0 ; i < pointss.size() ; i++ ) {
                Vecteur2D v = pointss.get(i);
                v = t3.transforme(v);
                pointss.set(i,v);
            }

            for(int i = 0 ; i < x.length ; i++){
                x[i] = (int)pointss.get(i).getX();
                y[i] = (int)pointss.get(i).getY();

                System.out.println("x["+i+"] =" +x[i]+" y["+i+"] =" +y[i]);
            }

            Polygon p = new Polygon(x,y,3);
            cadreDessin.graphics.fillPolygon(p);
            */
            cadreDessin.getBufferStrategy().show();

        }catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println("after-");
    }
}
