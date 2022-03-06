package ChainOfResponsability;

import Serveur.Convertisseur.Vecteur2D;

public class DrawGroupeHandler extends Handler{


    /** \brief :parseur et dessinateur d'un groupe
     * \details : appelles les autres chaines de responsabilite pour parser les formes
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


        if (message.toLowerCase().contains("groupe"))
        {
            int parOuvrante = message.indexOf(": [");
            String type = message.substring(0, parOuvrante).trim().toLowerCase();

            if (type.contains("groupe"))
            {
                int crochetOuvrant = message.indexOf("[");
                int crochetFermant = message.indexOf("]");
                String part1= message.substring(parOuvrante+1).trim().toLowerCase();
                String entreCrochet = message.substring(crochetOuvrant+1,crochetFermant);

                //System.out.println("type = "+type);
                //System.out.println("part1 ="+part1);
               // System.out.println("entre crochet ="+entreCrochet);

                String apresCrochetFermant = message.substring(crochetFermant+1);
                String vects[] = apresCrochetFermant.split(" I ");

                Vecteur2D vmin = new Vecteur2D(vects[1]);
                Vecteur2D vmax = new Vecteur2D(vects[2]);


                String formes[] = entreCrochet.split(";");

                Handler h1 = new DrawCircleHandler();
                Handler h2 = new DrawLineHandler();
                Handler h3 = new DrawPolygonHandler();
                Handler h4 = new DrawGroupeHandler();
                h1.setNextChain(h2);
                h2.setNextChain(h3);
                h3.setNextChain(h4);

                CadreDessin cadreDessin2 = new CadreDessin(cadreDessin.getTitle(),cadreDessin.bordGauche,
                        cadreDessin.bordSuperieur, cadreDessin.getWidth(),cadreDessin.getHeight());

                cadreDessin2.setResizable(false);

                for (int i = 0 ; i < formes.length -1 ; i++) {
                    System.out.println(formes[i]);
                    h1.handle(formes[i],cadreDessin2,true,vmin,vmax);

                }

                cadreDessin2.getBufferStrategy().show();
                System.out.println("i drawed a group");
            }


        }

        return handleNext(message,cadreDessin,Isgroupe, Vmin, Vmax);

        //return false;
    }

}
