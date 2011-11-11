/******************************************************************************
  MANIPULATION DE LISTES
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdarg>

#include "liste.h"
using namespace std;

/**
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre lin�aire ou circulaire.
 *
 * Parametre l : liste a repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
 */
string chainel(liste l) {
        if (l == NULL) {
                return ".";
        }
        ostringstream r;
        maillon* c = l;
        do {
                r << "[" << c->info->info << "]";
                if (c->succ == NULL || c->succ == l) {
                    break;
                }
                r << "->";
                c = c->succ;
        } while (true);
        r << (c->succ == NULL ? "|" : ">");
        return r.str();
}

/**
 * Repr�sente une liste sous forme d'une cha�ne de caract�res. La liste peut
 * �tre lin�aire ou circulaire.
 *
 * Parametre l : liste a repr�senter.
 *
 * Retourne : la cha�ne repr�sentant l.
 */
string chainesl(noeud* l) {
        if (l == NULL) {
                return ".";
        }
        ostringstream r;
        noeud* c = l;
        do {
                r << "[" << c->info << "]";
                if (c->succ == NULL || c->succ == l) {
                    break;
                }
                r << "->";
                c = c->succ;
        } while (true);
        r << (c->succ == NULL ? "|" : ">");
        return r.str();
}

/**
 * Convertit un tableau d'entiers en une liste chainee, simplement circulaire.
 *
 * Parametre n : le nombre d'elements de t.
 * Parametre t : tableau d'entiers a convertir.
 *
 * Retourne : la liste equivalente a t.
 */
noeud* listecc(int n, int* t) {
        if (t == NULL || n == 0) {
            return NULL;
        }
        noeud* m = new noeud;
        m->info = t[0];
        noeud* l = m;
        for (int i = 1; i < n; i++) {
                m->succ = new noeud;
                m->succ->info = t[i];
                m = m->succ;
        }
        m->succ = l;
        return l;
}

/**
 * Convertit plusieurs tableaux d'entier en une liste chainee simplement chain�e de liste chain�e circulaire
 *
 * Parametre n : le nombre d'elements de t.
 * Parametres : tableaux d'entiers de taille 4 � ins�rer.
 *
 * Retourne : la liste.
 */
liste listePermutations(int n, ...) {
    if(n==0) return NULL;
    va_list ap;
    va_start(ap, n);
    liste m = new maillon;
    liste l = m;
    for(int i = 0 ; i < n ; i++){
        noeud* c = listecc(4, va_arg(ap, int*));
        m->info = c;
        if(i < n-1) {
            m->succ = new maillon;
            m = m->succ;
        }
        else m->succ = NULL;
    }
    va_end(ap);
    return l;
}
