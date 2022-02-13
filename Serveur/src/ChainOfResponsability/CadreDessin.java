package ChainOfResponsability;

import java.awt.*;

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
// ------------------ param�trage de la position et des dimensions de la fen�tre --------------------------

        Toolkit tk = Toolkit.getDefaultToolkit();

        int le, he; // largeur �cran, hauteur �cran

        Dimension dim = tk.getScreenSize(); // dimensions de l'�cran

        le = (int) dim.getWidth();
        he = (int) dim.getHeight();

        int bordGauche, bordSuperieur, l, h ;

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
    }

}

