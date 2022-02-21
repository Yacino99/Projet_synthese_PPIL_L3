package ChainOfResponsability;

import javax.swing.*;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

/**
 * destin� � recevoir des dessins r�alis�s en Active-Rendering
 *
 * paint() est d�sactiv�e
 *
 * pourrait �tre am�lior�e par l'utilisation d'un Canvas : Panel sp�cialis� pour le dessin
 * pourrait �tre am�lior�e par l'utilisation de coordonn�es relatives plut�t que des coordonn�es en pixels
 * */
public class CadreDessin extends Frame
{
    public Graphics graphics;      // pour dessiner sur this
    private int bordGauche, bordSuperieur;

    /**
     * @param titre : titre de la fen�tre
     * @param ox : abscisse souhait� pour le bord gauche de la fen�tre
     * @param oy : ordonn�e souhait�e pour le bord sup�rieur de la fen�tre
     * @param largeur : largeur souhait�e pour la fen�tre
     * @param hauteur : hauteur souhait�e pour la fen�tre
     *
     * l'unit� pour ces 4 param�tres est le pixel
     *
     * */
    public CadreDessin(String titre, int ox, int oy, int largeur, int hauteur) throws InterruptedException
    {
        super(titre);
// ------------------ parametrage de la position et des dimensions de la fenetre --------------------------
        Toolkit tk = Toolkit.getDefaultToolkit();
        //setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        int le, he; // largeur �cran, hauteur �cran

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

        int nombreBuffers = 1;
        this.createBufferStrategy(nombreBuffers);
        Thread.sleep(50);   // il faut attendre un minimum de 50 ms pour que le buffer soit op�rationnel
        this.graphics = this.getBufferStrategy().getDrawGraphics();

        addWindowListener (new WindowAdapter() {
            public void windowClosing (WindowEvent e) {
                dispose();
            }
        });

        

    }

    //----adapter la largeur
    public void setLargeur(int largeur){
        //this.setSize(largeur,this.getHeight());
        this.setBounds(bordGauche, bordSuperieur, largeur, this.getHeight());
    }

    //----adapter la longueur
   public  void setLongueur(int longeur){
       // this.setSize(this.getWidth(),longeur);
       this.setBounds(bordGauche, bordSuperieur, this.getWidth(), longeur);
    }

}

