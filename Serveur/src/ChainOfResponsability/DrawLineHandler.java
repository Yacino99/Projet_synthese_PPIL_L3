package ChainOfResponsability;

import Serveur.Convertisseur.Config;
import Serveur.Convertisseur.Pair;
import Serveur.Convertisseur.TransfoMondeEcran;
import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;
import java.util.HashMap;

public class DrawLineHandler extends Handler {


    /** \brief parseur et dessinateur d'un seguement
     *  \message : message a parser.
     *  \cadreDessin : la fenetre dont on veut dessiner dessus
     *  \Isgroupe : permet de savoir si on dessine dans la meme fenetre ou sur une autre
     *  \Vmin : connaitre le point bas Gauche de l'ecran pour un groupe
     *  \Vmax : connaitre le point haut droit de l'ecran pour un groupe
     *  \returns booleen qui permet de dire si il ya un prochain expert ou pas
     */
    @Override
    public boolean handle(String message , CadreDessin cadreDessin,boolean Isgroupe,
                          Vecteur2D Vmin,Vecteur2D Vmax) throws InterruptedException {

        //savoir si on va parser un segment
        if(message.toLowerCase().contains("segment"))
        {
            int parOuvrante = message.indexOf("(");

            String type = message.substring(0,parOuvrante);

            type = type.toLowerCase().trim();
            //savoir si c'est un cercle seul et pas un cercle dans un segment
            if(type.contains("segment") && !type.contains("groupe") )
            {
                // on cherche les index de les parenthese ouvrantes et fermantes
                //on extrait ce qu'il ya dedans

                int parFermante = message.indexOf(")");
                String part1 = message.substring(parOuvrante+1,parFermante);
                String couleur = message.substring(parFermante+1).trim().toLowerCase();


                String[] splited =  part1.split(",");

                // on convertis les points de string en double
                int gauche = (int) Double.parseDouble(splited[0].trim());
                int haut = (int) Double.parseDouble(splited[1].trim());
                int droit = (int) Double.parseDouble(splited[2].trim());
                int bas = (int) Double.parseDouble(splited[3].trim());

                // on affecte a la forme la couleur specifique
                if(map.containsKey(couleur))
                    cadreDessin.graphics.setColor(map.get(couleur));

                //origine de la droite
                Vecteur2D deb = new Vecteur2D(gauche,haut) ;
                // fin de la droite
                Vecteur2D fin = new Vecteur2D(droit,bas);

                Pair<Vecteur2D> pairVect;

                // debut de la tranformation monde ecran

                // savoir si le message vient du geoupe ou pas
                // si oui on converti selon les points bgM et hdM du groupe sinon celui du segment seul
                if(Isgroupe)
                    pairVect = TransfoMondeEcran.basGaucheHautDroitSegment(Vmin,Vmax);
                else
                    pairVect = TransfoMondeEcran.basGaucheHautDroitSegment(deb,fin);




                TransfoMondeEcran t2 = TransfoMondeEcran.creerTransfoMondeEcran(pairVect.getPremier(),
                        pairVect.getDeuxieme(),
                        new Vecteur2D(0, Config.HAUTEUR),new Vecteur2D(Config.LARGEUR,0));

                deb = t2.transforme(deb);
                fin = t2.transforme(fin);

                // fin de la transformation monde ecran

                cadreDessin.graphics.drawLine((int)deb.getX(),(int)deb.getY(),(int)fin.getX(),(int)fin.getY());

                System.out.println("i drawed a cross");

            }
        }



        return handleNext(message,cadreDessin,Isgroupe, Vmin, Vmax);

    }
}
