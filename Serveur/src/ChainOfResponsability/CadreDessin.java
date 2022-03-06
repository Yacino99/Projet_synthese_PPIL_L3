/**
 * \file      CadreDessin.java
 * \date      06 mars 2022
 * \brief     Classe CadreDessin
 * \details   destinee recevoir des dessins realises en Active-Rendering
 *            paint() est desactivee
 *            pourrait etre amelioree par l'utilisation d'un Canvas : Panel specialise pour le dessin
 *            pourrait etre amelioree par l'utilisation de coordonnees relatives plutet que des coordonnees en pixels
 */

package ChainOfResponsability;

import java.awt.*;
import java.awt.event.*;

public class CadreDessin extends Frame
{
    public Graphics graphics;      // pour dessiner sur this
    public final int bordGauche, bordSuperieur;

    /**
     * @param titre : titre de la fenetre
     * @param ox : abscisse souhaite pour le bord gauche de la fenetre
     * @param oy : ordonnee souhaitee pour le bord superieur de la fenetre
     * @param largeur : largeur souhaitee pour la fenetre
     * @param hauteur : hauteur souhaitee pour la fenetre
     * \details l'unite pour ces 4 parametres est le pixel
     */
    public CadreDessin(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
    {
        super(titre);
// ------------------ parametrage de la position et des dimensions de la fenetre --------------------------
        Toolkit tk = Toolkit.getDefaultToolkit();
        //setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int le, he; // largeur ecran, hauteur ecran

        Dimension dim = tk.getScreenSize(); // dimensions de l'ecran

        le = (int) dim.getWidth();
        he = (int) dim.getHeight();

        int  l, h ;

        bordGauche = Math.max(0, ox);
        bordSuperieur = Math.max(0, oy);
        l = Math.min(largeur, le - bordGauche);
        h = Math.min(hauteur, he - bordSuperieur);
        this.setBounds(bordGauche, bordSuperieur, l, h);


        this.setVisible(true);

//------------------------- initialisation de l'active rendering -----------------------

        this.setIgnoreRepaint(true);
        int nombreBuffers = 2;
        this.createBufferStrategy(nombreBuffers);
        Thread.sleep(100);   // il faut attendre un minimum de 50 ms pour que le buffer soit operationnel
        this.graphics = this.getBufferStrategy().getDrawGraphics();

        //----------permet la fermeture de la fenetre quand on appuie sur la croix---------

        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });


    }


}

