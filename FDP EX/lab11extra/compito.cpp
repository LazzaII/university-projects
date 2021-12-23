//
// Created by Utente on 15/12/2021.
//

#include "compito.h"
#include <iostream>
using namespace std;

/*
 * Costruttore che inizializza a vuoto tutta la matrice
 */
PuzzleBobble::PuzzleBobble() {
    for (int i = 0; i < RIGHE; ++i) //inizializzazione della matrice a vuoto
        for (int j = 0; j < COLONNE; ++j)
            matrix[i][j] = vuoto;
}

/*
 * Funzione di stampa della matrice
 */
void PuzzleBobble::print() {
    cout << "========\n";
    for (int i = 0; i < RIGHE; ++i) {
        cout << "|";
        for (int j = 0; j < COLONNE; ++j)
            cout << matrix[i][j];

        cout << "|" << endl;
    }
    cout << "========\n";
}

/*
 * Funzione che "spara" una bolla colorata
 * @param i colonna su cui infilare la bolla
 * @param color colore della bolla da mettere nella colonna i
 */
PuzzleBobble& PuzzleBobble::fire(unsigned int i, char color) {
    if(i > COLONNE) return *this;

    switch (color) {
        case 'R':
            break;
        case 'G':
            break;
        case 'B':
            break;
        case 'Y':
            break;
        default:
            return *this;
    }

    int j;
    for (j = RIGHE-1; j >= 0 ; --j)
        if(matrix[j][i] != ' ') break;

    if(j == RIGHE-1) {
        matrix[j][i] = (colori) color;
        int c = scoppiaBolle(j, i, color, false);
        if(c >= 3)
            scoppiaBolle(j, i, color, true);
    }
    else {
        matrix[j+1][i] = (colori) color;
        int c = scoppiaBolle(j+1, i, color, false);
        if(c >= 3)
            scoppiaBolle(j+1, i, color, true);
    }

    return *this;
}

/*
 * Funzione che iniziando da una determinata riga colonna e colore scoppia le bolle se in quella riga/colonna ci sono più di 3 bolle dello stesso colore dato in input di fila
 * @param r riga iniziale
 * @param c colonna iniziale
 * @param color colore della bolla
 */
int PuzzleBobble::scoppiaBolle(unsigned int r, unsigned int c, char color, bool scoppia) {
    /* -----------------------------------
     * DA FIXARE
     * CONTROLLO DESTRO DELLA BOLLA !!!CONTIGUO!!!
     * CONTROLLO SINISTRO DELLA BOLLA !!!CONTIGUO!!!
     * CONTROLLO SOPRA DELLA BOLLA !!!CONTIGUO!!!
     --------------------------------------*/

    int count = 1;

    if(scoppia)
        matrix[r][c] = (colori) ' ';

    for (int i = c+1; i < RIGHE; ++i)
        if(matrix[r][i] == color){
            count++;
            if(scoppia)
                matrix[r][i] = (colori) ' ';
        }
        else break;


    for (int i = c-1; i >= 0; --i)
        if(matrix[r][i] == color){
            count++;
            if(scoppia)
                matrix[r][i] = (colori) ' ';
        }
        else break;


    for (int i = r-1; i >= 0; --i)
        if(matrix[i][c] == color){
            count++;
            if(scoppia)
                matrix[i][c] = (colori) ' ';
        }
        else break;


    return count;
}

/*
 * Funzione che calcola l'altezza di una colonna (numero di bolle fila)
 */
int PuzzleBobble::height() {
    int height = 0, tmp;

    for (int i = 0; i < COLONNE; ++i) {
        tmp = 0;
        for (int j = 0; j < RIGHE; ++j)
            if(matrix[j][i] != ' ') tmp++;

        if(tmp > height) height = tmp;
    }

    return height;
}

/*
 * Funzione che aggiunge una riga di = in cima alla matrice
 */
PuzzleBobble& PuzzleBobble::scroll() {
    for(int i = 0; i < COLONNE; ++i) //controllo se l'ultima riga è vuota
        if(matrix[RIGHE-1][i] != ' ')
            return *this;

    for (int i = RIGHE-1; i >= 1; --i) //shift della tabella
        for (int j = 0; j < COLONNE; ++j)
            matrix[i][j] = matrix[i-1][j];

    for (int i = 0; i < COLONNE; ++i) //inserimento della prima riga con tutti ======
        matrix[0][i] = (colori) '=';

    return *this;
}

/*
 * Funzione che rimuove gli spazi tra le bolle di una colonna
 */
void PuzzleBobble::compact() {
    //matrix[2][3] = (colori ) ' '; ERA SOLO PER TEST FINO A CHE NON FINISCO LA SECONA PARTE DEL FIRE
    for (int i = 0; i < RIGHE; ++i) //shift della tabella
        for (int j = 0; j < COLONNE; ++j)
            if(matrix[i][j] == ' '){
                if(i+1 == RIGHE) return;
                if(matrix[i+1][j] != ' ' && matrix[i][j] != '=') {
                    matrix[i][j] = matrix[i+1][j];
                    matrix[i+1][j] = (colori) ' ';
                }
            }
}