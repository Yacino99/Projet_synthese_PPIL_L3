/**
 * \file      ExpertChargementPolygoneCOR.h
 * \date      04 mars 2022
 * \brief     Classe ExpertChargementPolygoneCOR
 * \details   Cette expert essaie de trouver un polygone parmi les formes qui lui sont données
 */

package ChainOfResponsability;

import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.Pair;
import Serveur.Convertisseur.TransfoMondeEcran;
import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;
import java.util.HashMap;

public class DrawCircleHandler extends Handler{


    /** \brief parseur et dessinateur d'un cercle
     *  \message : message a parser.
     *  \cadreDessin : la fenetre dont on veut dessiner dessus
     *  \Isgroupe : permet de savoir si on dessine dans la meme fenetre ou sur une autre
     *  \Vmin : connaitre le point bas Gauche de l'ecran pour un groupe
     *  \Vmax : connaitre le point haut droit de l'ecran pour un groupe
     *  \returns booleen qui permet de dire si il ya un prochain expert ou pas
     */
    @Override
    public boolean handle(String message, CadreDessin cadreDessin, boolean Isgroupe,
                          Vecteur2D Vmin, Vecteur2D Vmax) throws InterruptedException {

        //savoir si on va parser un cercle
        if(message.toLowerCase().contains("rond"))
        {
            int parOuvrante = message.indexOf("(");

            String type = message.substring(0,parOuvrante);

            //savoir si c'est un cercle seul et pas un cercle dans un groupe
            if(type.trim().contains("rond") && !type.contains("groupe") )
            {

                // on cherche les index de les parenthese ouvrantes et fermantes
                //on extrait ce qu'il ya dedans

                int parFermante = message.indexOf(")");
                String part1 = message.substring(parOuvrante+1,parFermante);
                String couleur = message.substring(parFermante+1).trim().toLowerCase();

                String[] splited =  part1.split(",");

                // on convertis les points de string en double
                double Xcentre = Double.parseDouble(splited[0].trim());
                double Ycentre = Double.parseDouble(splited[1].trim());
                double rayon = Double.parseDouble(splited[2].trim());

                int x = (int)Xcentre;
                int y = (int)Ycentre;
                int r = (int)rayon;

                // on affecte a la forme la couleur specifique
                if(map.containsKey(couleur))
                    cadreDessin.graphics.setColor(map.get(couleur));

                // debut de la tranformation monde ecran
                TransfoMondeEcran t;
                Vecteur2D centre = new Vecteur2D(Xcentre,Ycentre);

                // savoir si le message vient du groupe ou pas
                if(Isgroupe){

                    t = TransfoMondeEcran.creerTransfoMondeEcran(
                            Vmin, Vmax,
                            new Vecteur2D(0,-Config.HAUTEUR),
                            new Vecteur2D(Config.LARGEUR,0));

                    centre = t.transforme(centre);

                    r = t.convertirRayonDuCercle(centre,r,Vmin, Vmax );  // rayon converti en monde ecran


                }
                else {

                    Pair<Vecteur2D> p = TransfoMondeEcran.basGaucheHautDroitCercle(centre,r);

                     t = TransfoMondeEcran.creerTransfoMondeEcran(
                             p.getPremier(),p.getDeuxieme(),
                            new Vecteur2D(0, Config.HAUTEUR),
                             new Vecteur2D(Config.LARGEUR,0));

                     // on convertis le rayon du cercle en monde ecran
                    r = t.convertirRayonDuCercle(centre,r,new Vecteur2D(centre.getX()-r,centre.getY()-r),
                            new Vecteur2D(centre.getX()+r,centre.getY()+r));

                    centre = t.transforme(centre);

                }
                // fin de la tranformation monde ecran
                cadreDessin.graphics.fillOval((int)centre.getX(),(int)centre.getY(),r,r);

                System.out.println("i drawed a circle");
            }
        }


        return handleNext(message,cadreDessin,Isgroupe, Vmin, Vmax);

    }


}
