/**
 * \file      DrawPolygonHandler.java
 * \date      06 mars 2022
 * \brief     Classe DrawPolygonHandler
 */

package ChainOfResponsability;

import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.Pair;
import Serveur.Convertisseur.TransfoMondeEcran;
import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;
import java.util.ArrayList;
import java.util.HashMap;

public class DrawPolygonHandler extends Handler{


    /** \brief parseur et dessinateur d'un Triangle et un polygone
     *  \param message : message a parser.
     *  \param cadreDessin : la fenetre dont on veut dessiner dessus
     *  \param Isgroupe : permet de savoir si on dessine dans la meme fenetre ou sur une autre
     *  \param Vmin : connaitre le point bas Gauche de l'ecran pour un groupe
     *  \param Vmax : connaitre le point haut droit de l'ecran pour un groupe
     *  \returns booleen qui permet de dire si il ya un prochain expert ou pas
     */
    @Override
    public boolean handle(String message, CadreDessin cadreDessin,boolean Isgroupe,
    Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {


        //savoir si on va parser un polygone/triangle
        if( (message.toLowerCase().contains("triangle") || message.toLowerCase().contains("polygone") ) )
        {
            int parOuvrante = message.indexOf("(");

            String type = message.substring(0,parOuvrante);


            if( (type.toLowerCase().trim().contains("triangle") || type.toLowerCase().trim().contains("polygone") ) )
            {

                int parFermante = message.indexOf(")");
                String cordString = message.substring(parOuvrante+1,parFermante);
                String couleur = message.substring(parFermante+1).trim().toLowerCase();


                String cords[] = cordString.split(",");
                int[] x = new int[cords.length];
                int[] y = new int[cords.length];

                // on recupere les points X et Y de la figure

                for(int i = 0 ,j=0,k=1 ; i < cords.length ; i+=2,j++,k+=2){
                    x[j]= (int) Double.parseDouble(cords[i].trim());
                    y[j]= (int) Double.parseDouble(cords[k].trim());
                }

                // on lui affcete sa couleur
                if(map.containsKey(couleur))
                    cadreDessin.graphics.setColor(map.get(couleur));

                // debut de la tranformation monde ecran

                Pair<Vecteur2D> pairVect;

                // savoir si le message vient du geoupe ou pas
                // si oui on converti selon les points bgM et hdM du groupe sinon celui de la figule seule
                if(Isgroupe)
                    pairVect = new Pair<Vecteur2D>(Vmin,Vmax);
                else
                    pairVect = TransfoMondeEcran.basGaucheHautDroitTriangleEtPolygone(x,y);

                TransfoMondeEcran t = TransfoMondeEcran.creerTransfoMondeEcran(pairVect.getPremier(),
                        pairVect.getDeuxieme(),
                        new Vecteur2D(0, Config.HAUTEUR),
                        new Vecteur2D(Config.LARGEUR,0));

                // fin de la transormation monde ecran

                ArrayList<Vecteur2D> pointss = Vecteur2D.pointsToVect(x,y);

                // recuperation des points tranformees dans les tebleaux x[] et y[]

                for(int i = 0 ; i < pointss.size() ; i++ ) {
                    Vecteur2D v = pointss.get(i);
                    v = t.transforme(v);
                    pointss.set(i,v);
                }

                for(int i = 0 ; i < x.length ; i++){
                    x[i] = (int)pointss.get(i).getX();
                    y[i] = (int)pointss.get(i).getY();
                }


                // creation du polygone a dessiner
                Polygon p = new Polygon(y,x,x.length/2);

                // dessin du plugone
                cadreDessin.graphics.fillPolygon(p);;

            }
        }

        return handleNext(message,cadreDessin,Isgroupe, Vmin, Vmax);
    }
}
