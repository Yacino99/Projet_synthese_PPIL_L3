/**
 * \file      Vecteur2D.java
 * \date      06 mars 2022
 * \brief     Classe Vecteur2D
 */

package Serveur.Convertisseur;

import java.util.ArrayList;

public class Vecteur2D {
    double x,y;
    /**
     * \brief Constructeur
     * @param x
     * @param y
     */
    public Vecteur2D(double x,double y) {
        this.x = x;
        this.y = y;
    }
    /**
     * \brief Constructeur par recopie
     * @param v
     */
    public Vecteur2D(Vecteur2D v) {
        this.x = v.x;
        this.y = v.y;
    }

    /**
     * \brief Constructeur
     * @param vect : une chaine de caractere cense etre sous la forme de (double , double ) ou double est un nombre
     */
    public Vecteur2D(String vect) {

        try {
            int parOuvrante = vect.indexOf('(');
            int parFermante = vect.indexOf(')');
            if(parOuvrante == -1 || parFermante == -1) throw new Exception() ;

            String XY = vect.substring(parOuvrante+1,parFermante);

            String tabXY[] = XY.split(",");

            this.x = Double.parseDouble(tabXY[0].trim());
            this.y = Double.parseDouble(tabXY[1].trim());

        }catch (Exception e)
        {
            System.err.println("pas de parenthese ouvrante ou fermante, forme vecteur errone");
        }

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
     * \brief additionne deux vecteurs ensemble
     * @param v
     * @return Vecteur2D
     */
    public Vecteur2D plus(Vecteur2D v) {
        return new Vecteur2D(v.getX() + x,v.getY() + y);
    }
    /**
     * \brief soustrait deux vecteurs ensemble
     * @param v
     * @return Vecteur2D
     */
    public Vecteur2D moins(Vecteur2D v) {
        return new Vecteur2D(x -v.getX(),y - v.getY());
    }
    /**
     * \brief soustrait double au Vecteur2D
     * @param n
     * @return Vecteur2D
     */
    public Vecteur2D moins(double n) {
        return new Vecteur2D(x - n,y - n);
    }
    /**
     * \brief multiplie un double au Vecteur2D
     * @param f
     * @return Vecteur2D
     */
    public Vecteur2D fois(double f) {
        return new Vecteur2D(f*x,f*y);
    }

    /**
     * \brief retourne un Vecteur2D contenant les valeur absolue de x y et z du Vecteur2D
     * @return Vecteur2D
     */
    public Vecteur2D valeurAbs() {
        return new Vecteur2D(Math.abs(x),Math.abs(y));
    }




    /**
     * \brief retourne la distance entre deux points ou vecteurs dans un plan
     * @param b : vecteur b pour faire la distance
     * @return un double qui est la distance entre deux vecteurs dans un plan
     */
    public double distance( Vecteur2D b) {

        double opg = (b.x-x)*(b.x-x);
        double opd = (b.y-y)*(b.y-y);

        return Math.sqrt(opg + opd);
    }


    /**
     * \brief     methode statique pour convertir deux tableaux d'entier en un ArrayList de vecteurs
     * \details    Cette méthode pointsToVect() permet de prendre deux tableaux d'entier qui sont
     *             cense etre un des tableaux de coordoonnes x et y , cette methde regroupe les deux
     *             tableaux d'entier en un ArrayList de coordoones ( vecteurs )
     * \param      int x[]  tableau d'entier cense regrouper tout les points X d'un plan
     * \param      int y[]  tableau d'entier cense regrouper tout les points Y d'un plan
     * @return un ArrayList<Vecteur2D> censer regrouper les deux parametres
     */
    static public ArrayList<Vecteur2D> pointsToVect(int x[] , int y[])
    {
        ArrayList <Vecteur2D> vects= new ArrayList<>();

        for(int i = 0 ; i < x.length ; i++)
            vects.add(new Vecteur2D(x[i],y[i]));

        return vects;
    }

    /**
     * \brief methode toString
     * @return String sous forme de (v.x , v.y )
     */
    public String toString() {
        return "("+x+","+y+")";
    }

}
