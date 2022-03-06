package Serveur.Convertisseur;

/**
 * \brief : classe qui s'occupe des calculs de transformations monde vers ecran et ecran vers monde
 */

public class TransfoMondeEcran {

    public double lambda,eps1,eps2,a,b;
    public double lambdaEps1 , lambdaEps2 ;

    public TransfoMondeEcran(){

    }


    public TransfoMondeEcran(double lambda, double eps1, double eps2, double a, double b) {
        this.lambda = lambda;
        this.eps1 = eps1;
        this.eps2 = eps2;
        this.a = a;
        this.b = b;
        this.lambdaEps1 = lambda*eps1;
        this.lambdaEps2 = lambda*eps2;
    }

    /**
     * convertie le repere monde en repere ecran
     * @param v : vecteur a conveertir
     * @return Vecteur2D
     */


    public Vecteur2D transforme(Vecteur2D v)
    {
        return new Vecteur2D((lambdaEps1*v.x + a),(lambdaEps2 * v.y + b));
    }

    /**
     * convertie le repere monde en repere ecran
     * @param v : vecteur a conveertir
     * @return Vecteur2D
     */

    public Vecteur2D transformeInverse(Vecteur2D v)
    {
        return new Vecteur2D((v.x-a)/lambdaEps1,(v.y-b)/lambdaEps2);
    }


    /**
     * methode statique pour creer un covertisseur monde ecran
     * @param bgM point bas gauche monde
     * @param hdM point haut droit monde
     * @param bgE point bas gauche ecran
     * @param hdE point haut droit ecran
     * @return TransfoMondeEcran : objet qui qui contient les points monde ecran converti selon les calculs faits
     */
    public static TransfoMondeEcran creerTransfoMondeEcran(Vecteur2D bgM,Vecteur2D hdM,Vecteur2D bgE,Vecteur2D hdE){
        //ici calculer lambda , eps1 , eps2  , a , b

        double lambda,eps1,eps2,a,b;

        // Determiner lambda   //hdM  =hdm   , bgM = bgM
        lambda = Math.min(Math.abs(Config.LARGEUR)/Math.abs(hdM.getX() - bgM.getX()),Math.abs(- Config.HAUTEUR )/Math.abs(hdM.getY() - bgM.getY()));

        // Determiner E1
        if(((Config.LARGEUR) > 0 && (hdM.getX() - bgM.getX()) > 0) ||((Config.LARGEUR) < 0 && (hdM.getX() - bgM.getX()) < 0))
            eps1 = 1;
        else
            eps1 = -1;
        // Determiner E2
        if(((0-Config.HAUTEUR) >0 && (hdM.getY() - bgM.getY()) >0) || ((0-Config.HAUTEUR) <0 && (hdM.getY() - bgM.getY()) <0))
            eps2 = 1;
        else
            eps2 = -1;


       Vecteur2D C1 = new Vecteur2D((Config.LARGEUR)/2,(Config.HAUTEUR)/2);
        // Determiner C
        Vecteur2D C2 = new Vecteur2D((hdM.getX() + bgM.getX())/2,(hdM.getY() + bgM.getY())/2);
        // Determiner a
        a = C1.getX()- lambda * eps1* C2.getX();
        // Determiner b
        b = C1.getY() - lambda * eps2* C2.getY();

        return new TransfoMondeEcran(lambda,eps1,eps2,a,b);
    }


    /**
     * @brief permet de convertir le rayon du cercle du monde vers l'ecran
     * @param centre : centre du cercle
     * @param r : rayon du cercle
     * @param min : point bas gauche de l'ecran
     * @param max point haut droit de l'ecran
     * @return double : le rayon du cerlce converti en monde ecran
     */
    public int convertirRayonDuCercle( Vecteur2D centre, double r,Vecteur2D min,Vecteur2D max) {
        Vecteur2D vr = centre.plus(new Vecteur2D(r,0));
        //vr = vr.convertirRepereMondeToRepereEcran(min, max).moins(centre.convertirRepereMondeToRepereEcran(min, max));
        vr = transforme(vr).moins(transforme(centre));
        return (int) vr.getX();
    }

    /**
     * @brief trouve le point bas gauche et le point haut droit du plan selon le cercle
     * @param centre : centre du cercle
     * @param rayon  : rayon du cercle
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le cercle
     */
    public static Pair<Vecteur2D> basGaucheHautDroitCercle(Vecteur2D centre, double rayon){
        Vecteur2D v1 = new Vecteur2D(centre.getX()-rayon,centre.getY()-rayon);
        Vecteur2D v2 = new Vecteur2D(centre.getX()+rayon,centre.getY()+rayon);

        return new Pair<Vecteur2D>(v1,v2);
    }

    /**
     * @brief trouve le point bas gauche et le point haut droit du plan selon le segment
     * @param point1 : point d'origine du segment
     * @param point2  : point de fin sdu segment
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le segment
     */

    public static Pair<Vecteur2D> basGaucheHautDroitSegment(Vecteur2D point1,Vecteur2D point2){

        double minX = Math.min(point1.x, point2.x);
        double minY = Math.min(point1.y, point2.y);

        double maxX = Math.max(point1.x, point2.x);
        double maxY = Math.max(point1.y, point2.y);

        Vecteur2D bgm = new Vecteur2D(minX,minY);
        Vecteur2D hdm = new Vecteur2D(maxX,maxY);


        return new Pair<Vecteur2D>(bgm,hdm);
    }


    /**
     * @brief trouve le point bas gauche et le point haut droit du plan selon le tableau de points de la figure
     * qu'elle soit un triangle ou un polygone
     * @param x : tableau de points x de la figure
     * @param y  : tableau de points y de la figure
     * @return Pair<Vecteur2D> : une paire de vecteur2D qui sont
     * le point bas gauche et le point haut droit du plan selon le triangle ou le polygone
     */
    public static Pair<Vecteur2D> basGaucheHautDroitTriangleEtPolygone(int x[] , int y[]){

        double minX = Integer.MAX_VALUE  , minY = Integer.MAX_VALUE;
        double maxX = Integer.MIN_VALUE , maxY = Integer.MIN_VALUE;

        // trouve le point minX et le point maxX a partir du tableau des X

        for(int i = 0 ; i < x.length ; i++)
        {
            if(x[i] < minX)
                minX = x[i];

            if(x[i] > maxX)
                maxX = x[i];
        }

        // trouve le point minY et le point maxY a partir du tableau des Y

        for(int i = 0 ; i < y.length ; i++)
        {
            if(y[i] < minY)
                minY = y[i];
            if(y[i] > maxY)
                maxY=y[i];
        }

        // une fois les 4 points trouve , on les converti en deux paire de vecteurs2D
        // contenant le point bas gauche de l'ecran et l'autre contient le point haut droit de l'ecran

        Vecteur2D bgm = new Vecteur2D(minX,minY);
        Vecteur2D hdm = new Vecteur2D(maxX,maxY);

        return new Pair<Vecteur2D>(bgm,hdm);
    }


}
