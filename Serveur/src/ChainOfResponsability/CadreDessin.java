package ChainOfResponsability;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/**
 * destine e recevoir des dessins realises en Active-Rendering
 *
 * paint() est desactivee
 *
 * pourrait etre amelioree par l'utilisation d'un Canvas : Panel specialise pour le dessin
 * pourrait etre amelioree par l'utilisation de coordonnees relatives plutet que des coordonnees en pixels
 * */
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
     *
     * l'unite pour ces 4 parametres est le pixel
     *
     * */
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

//this.setBounds(ox, oy, largeur, hauteur);


        this.setVisible(true);

//------------------------- initialisation de l'active rendering -----------------------

        this.setIgnoreRepaint(true);

        int nombreBuffers = 2;
        this.createBufferStrategy(nombreBuffers);
        Thread.sleep(100);   // il faut attendre un minimum de 50 ms pour que le buffer soit operationnel
        this.graphics = this.getBufferStrategy().getDrawGraphics();

        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });

        addComponentListener(new ComponentAdapter(){
            public void componentResized(ComponentEvent componentEvent) {
                // do stuff
                //System.out.println("x = " + this.getWidth() + ", y = " + this.getHeight());
                System.out.println("redimentionnement");
                //drawElements(taframe);
            }
        });

    }





    //----adapter la largeur
    public void setLargeur(int largeur)  {
        this.setSize(largeur,this.getHeight());

        try {
            Thread.sleep(150);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        //this.setBounds(bordGauche, bordSuperieur, largeur, this.getHeight());
       // this.getBufferStrategy().show();

    }

    //----adapter la longueur
   public  void setLongueur(int longeur){
        this.setSize(this.getWidth(),longeur);
       try {
           Thread.sleep(150);
       } catch (InterruptedException e) {
           e.printStackTrace();
       }
       //this.setBounds(bordGauche, bordSuperieur, this.getWidth(), longeur);
        //this.getBufferStrategy().show();

    }
}

