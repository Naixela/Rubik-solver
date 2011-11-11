#ifndef LISTE_H
#define LISTE_H
#include <string>

typedef struct noeud {
    int info;
    struct noeud* succ;
}noeud;

typedef struct maillon {
        noeud* info;
        struct maillon* succ;
} maillon;
typedef maillon* liste;

/**
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre lin�aire ou circulaire.
 *
 * Parametre l : liste a repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
 */
std::string chainel(liste l);
std::string chainesl(noeud* l);


/**
 * Convertit un tableau d'entiers en une liste chainee, simplement circulaire.
 *
 * Parametre n : le nombre d'elements de t.
 * Parametre t : tableau d'entiers a convertir.
 *
 * Retourne : la liste equivalente a t.
 */
noeud* listecc(int n, int* t);
/**
 * Convertit plusieurs tableaux d'entier en une liste chainee simplement chain�e de liste chain�e circulaire
 *
 * Parametre n : le nombre d'elements de t.
 * Parametres : tableaux d'entiers de taille 4 � ins�rer.
 *
 * Retourne : la liste.
 */
liste listePermutations(int n, ...);

#endif // LISTE_H
