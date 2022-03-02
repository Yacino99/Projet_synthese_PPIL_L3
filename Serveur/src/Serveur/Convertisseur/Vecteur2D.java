package Serveur.Convertisseur;

/**
 * Classe Vecteur2D
 */
public class Vecteur2D {
    double x,y;
    /**
     * Constructeur
     * @param x
     * @param y
     */
    public Vecteur2D(double x,double y) {
        this.x = x;
        this.y = y;
    }
    /**
     * Constructeur par recopie
     * @param v
     */
    public Vecteur2D(Vecteur2D v) {
        this.x = v.x;
        this.y = v.y;
    }

    // Getters
    public double getX() {
        return x;
    }
    public double getY() {
        return y;
    }

    //Setters
    public void setX(double x) {
        this.x = x;
    }
    public void setY(double y) {
        this.y = y;
    }
    /**
     * additionne deux vecteurs ensemble
     * @param v
     * @return Vecteur2D
     */
    public Vecteur2D plus(Vecteur2D v) {
        return new Vecteur2D(v.getX() + x,v.getY() + y);
    }
    /**
     * soustrait deux vecteurs ensemble
     * @param v
     * @return Vecteur2D
     */
    public Vecteur2D moins(Vecteur2D v) {
        return new Vecteur2D(x -v.getX(),y - v.getY());
    }
    /**
     * soustrait double au Vecteur2D
     * @param n
     * @return Vecteur2D
     */
    public Vecteur2D moins(double n) {
        return new Vecteur2D(x - n,y - n);
    }
    /**
     * multiplie un double au Vecteur2D
     * @param f
     * @return Vecteur2D
     */
    public Vecteur2D fois(double f) {
        return new Vecteur2D(f*x,f*y);
    }

    /**
     * retourne un Vecteur2D contenant les valeur absolue de x y et z du Vecteur2D
     * @return Vecteur2D
     */
    public Vecteur2D valeurAbs() {
        return new Vecteur2D(Math.abs(x),Math.abs(y));
    }



    private double lambda;
    private double E1,E2;
    private double a,b;

    /**
     * initialiser lambda E1,E2,a et b selon min et max
     * @param min
     * @param max
     */
    private void initConversion(Vecteur2D min, Vecteur2D max){

        Vecteur2D P1,P2;
        Vecteur2D C1,C2;
        // Determiner P1
        P1 = new Vecteur2D(min);
        P1.setX(P1.getX() - 15);
        P1.setY(P1.getY() - 15);
        // Determiner P2
        P2 = new Vecteur2D(max);
        P2.setX(P2.getX() + 20);
        P2.setY(P2.getY() + 20);

        // Determiner lambda
        lambda = Math.min(Math.abs(Config.LARGEUR)/Math.abs(P2.getX() - P1.getX()),Math.abs(- Config.HAUTEUR )/Math.abs(P2.getY() - P1.getY()));

        // Determiner E1
        if(((Config.LARGEUR) > 0 && (P2.getX() - P1.getX()) > 0) ||((Config.LARGEUR) < 0 && (P2.getX() - P1.getX()) < 0))
            E1 = 1;
        else
            E1 = -1;
        // Determiner E2
        if(((0-Config.HAUTEUR) >0 && (P2.getY() - P1.getY()) >0) || ((0-Config.HAUTEUR) <0 && (P2.getY() - P1.getY()) <0))
            E2 = 1;
        else
            E2 = -1;
        // Determiner C'
        C1 = new Vecteur2D((Config.LARGEUR)/2,(Config.HAUTEUR)/2);
        // Determiner C
        C2 = new Vecteur2D((P2.getX() + P1.getX())/2,(P2.getY() + P1.getY())/2);
        // Determiner a
        a = C1.getX()- lambda * E1* C2.getX();
        // Determiner b
        b = C1.getY() - lambda * E2* C2.getY();


    }



    /**
     * convertie les repere monde en repere ecran en fonction de min et max
     * @param min
     * @param max
     * @return Vecteur2D
     */
    public Vecteur2D convertirRepereMondeToRepereEcran(Vecteur2D min,Vecteur2D max) {
        initConversion(min, max);
        return new Vecteur2D((lambda*E1*x + a),(lambda * E2 * y + b));
    }

    /**
     * Converti les reperes ecran en repere monde selon min et max
     * @param min
     * @param max
     * @return
     */
    public Vecteur2D convertirRepereEcranToRepereMonde(Vecteur2D min,Vecteur2D max) {
        initConversion(min, max);
        return new Vecteur2D((x-a)/(lambda*E1),(y-b)/(lambda*E2));
    }


    public double distance( Vecteur2D b) {

        double opg = (b.x-x)*(b.x-x);
        double opd = (b.y-y)*(b.y-y);

        return Math.sqrt(opg + opd);
    }

    public String toString() {
        return "("+x+","+y+")";
    }

}
