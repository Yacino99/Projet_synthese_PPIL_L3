/**
 * \file      Pair.java
 * \date      06 mars 2022
 * \brief     Classe Pair
 * \details   classe  generique Pair qui permet de contenir une paire d'objet de meme type , utile pour stocker les couples de vecteur
 * \param <T> objet quelconque et  generique de la classe
 */

package Serveur.Convertisseur;

public class Pair<T> {

    private T premier;
    private T deuxieme;

    public Pair(T premier , T deuxieme){
        this.premier = premier;
        this.deuxieme = deuxieme;
    }

    public void setPremier(T premier) {
        this.premier = premier;
    }

    public void setDeuxieme(T deuxieme) {
        this.deuxieme = deuxieme;
    }

    public T getDeuxieme() {
        return deuxieme;
    }

    public T getPremier() {
        return premier;
    }
}
