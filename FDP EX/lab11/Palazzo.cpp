//
// Created by Francesco Lazzarelli on 09/12/2021.
//

#include "Palazzo.h"

/*
 * Costruttore
 * @param N numero massimo di piani
 */
Palazzo::Palazzo(unsigned int N) {
    ll = 0;
    max = N;
    finestre = new bool *[N];
    aggiungi();
}

/*
 * Costruttore di copia
 * @param p1 palazzo di copia
 */
Palazzo::Palazzo(Palazzo &p1) {
    max = p1.max;
    ll = p1.ll;
    finestre = new bool*[max];

    //Copia dei valori
    for (int i = 0; i < ll; ++i) {
        finestre[i] = new bool[i+1];
        for (int j = 0; j < ll; ++j) {
            finestre[i][j] = p1.finestre[i][j];
        }
    }
}

/*
 * Distruttore
 */
Palazzo::~Palazzo() {
    for (int i = 0; i < ll; ++i) {
        delete [] finestre[i];
    }
    delete [] finestre;
}

/*
 * Aggiungi un nuovo piano al palazzo
 */
void Palazzo::aggiungi() {
    if(ll < max){
        ll++;
        finestre[ll-1] = new bool[ll];
        for (int i = 0; i < ll; ++i) {
            finestre[ll-1][i] = false;
        }
    }
}

/*
 * Funzione di stampa del palazzo
 */
void Palazzo::stampa() {
    cout << "<" << ll << "> \n";
    for (int i = 0; i < ll; ++i) {
        cout << "Piano " << (i + 1) << ": ";
        for (int j = 0; j < (i + 1); ++j) {
            cout << ((finestre[i][j]) ? "Aperta " : "Chiusa ");
        }
        cout << "\n";
    }
}

/*
 * Funzione che cambia lo stato di una finestra
 */
void Palazzo::cambia(unsigned int i,unsigned int j) {
    if(!(i == 0) || !(j == 0) || !(i > max) || !(j > i))
        finestre[i-1][j-1] = !finestre[i-1][j-1];
}

/*
 * Operatore negazione che rende il numero di finestre aperte
 */
int Palazzo::operator!() {
    int tot = 0;
    for (int i = 0; i < ll; ++i) {
        for (int j = 0; j < i+1; ++j) {
            if(finestre[i][j]) tot++;
        }
    }
    return tot;
}

/*
 * Operatore modulo che chiude le finestre del primo palazzo che corrispondo alle finestre chiuse nel palazzo p1
 */
void Palazzo::operator%=(Palazzo p1) {
    if(this->ll == p1.ll) {
        for (int i = 0; i < this->ll; ++i) {
            for (int j = 0; j < i+1; ++j) {
                if(!(p1.finestre[i][j]) && this->finestre[i][j])  this->finestre[i][j] = false;
            }
        }
    }
}