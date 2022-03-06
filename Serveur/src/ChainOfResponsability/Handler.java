package ChainOfResponsability;

import Serveur.Convertisseur.Vecteur2D;

import java.awt.*;
import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.HashMap;


/**
 * destine a gerer la chaine de responsaibilite ceci est l'expert pere abstrait
 * chaque classe qui derive de celle ci est centre etre un expert qui sait dessiner un forme specifique
 *
 * contient une hashmap dans le contructeur qui permer d'associer la couleur en String a une classe COLOR
 * */

public abstract class  Handler {
    private Handler next;

    protected BufferedReader fluxEntrant ;
    protected PrintStream fluxSortant ;
    protected Frame f1AR;

    protected HashMap<String,Color> map=new HashMap<String,Color>();

/**
 * Constructeur contient l'initialisation de la hashmap et les ajout des couleurs
 * **/

    protected Handler(){
        map.put("red",Color.red);
        map.put("blue",Color.BLUE);
        map.put("yellow",Color.yellow);
        map.put("green",Color.green);
        map.put("orange",Color.ORANGE);
        map.put("magenta",Color.MAGENTA);
        map.put("cyan",Color.CYAN);
        map.put("pink",Color.PINK);
        map.put("gray",Color.GRAY);
        map.put("",Color.black);
    }
/**
 * @brief parseur et dessinateur d'une forme particuliere
 * @param message : message a parser.
 * @param cadreDessin : la fenetre dont on veut dessiner dessus
 * @param Isgroupe : permet de savoir si on dessine dans la meme fenetre ou sur une autre
 * @param Vmin : connaitre le point bas Gauche de l'ecran pour un groupe
 * @param Vmax : connaitre le point haut droit de l'ecran pour un groupe
 * */
    public abstract boolean handle(String message, CadreDessin cadreDessin,boolean Isgroupe,
    Vecteur2D Vmin,Vecteur2D Vmax) throws InterruptedException;

    /**
     * @brief de set le prochain expert de la chaine
     * @param nextChain prochain expert
     */
    public void setNextChain(Handler nextChain){
        next = nextChain;
    }

    /**
     * @brief parseur et dessinateur d'une forme particuliere
     * @param message : message a parser.
     * @param cadreDessin : la fenetre dont on veut dessiner dessus
     * @param Isgroupe : permet de savoir si on dessine dans la meme fenetre ou sur une autre
     * @param Vmin : connaitre le point bas Gauche de l'ecran pour un groupe
     * @param Vmax : connaitre le point haut droit de l'ecran pour un groupe
     * @return booleen qui permet de dire si il ya un prochain expert ou pas
     * */
    protected boolean handleNext(String message, CadreDessin cadreDessin,boolean Isgroupe,
                                 Vecteur2D Vmin,Vecteur2D Vmax){
        if(next == null)
            return true;

        try {
            return next.handle(message,cadreDessin,Isgroupe,Vmin,Vmax);
        }catch (InterruptedException e) {
            e.printStackTrace();
        }

        return true;

    }
}
