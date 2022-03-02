package Serveur.Convertisseur;

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

    public Vecteur2D transforme(Vecteur2D v)
    {
        return new Vecteur2D((lambdaEps1*v.x + a),(lambdaEps2 * v.y + b));
    }

    public Vecteur2D transformeInverse(Vecteur2D v)
    {
        return new Vecteur2D((v.x-a)/lambdaEps1,(v.y-b)/lambdaEps2);
    }


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

    public int convertirRayonDuCercle( Vecteur2D centre, double r,Vecteur2D min,Vecteur2D max) {
        Vecteur2D vr = centre.plus(new Vecteur2D(r,0));
        vr = vr.convertirRepereMondeToRepereEcran(min, max).moins(centre.convertirRepereMondeToRepereEcran(min, max));
        return (int) vr.getX();
    }

}
