//
// Created by Utente on 15/12/2021.
//

#include "compito.h"
#include <iostream>
using namespace std;

PuzzleBobble::PuzzleBobble() {
    for (int i = 0; i < RIGHE; ++i)
        for (int j = 0; j < COLONNE; ++j)
            matrix[i][j] = vuoto;
}

void PuzzleBobble::print() {
    cout << "========\n";
    for (int i = 0; i < RIGHE; ++i) {
        cout << "|";
        for (int j = 0; j < COLONNE; ++j) {
            cout << matrix[i][j];
        }
        cout << "|" << endl;
    }
    cout << "========\n";
}