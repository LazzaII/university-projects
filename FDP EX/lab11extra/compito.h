//
// Created by Utente on 15/12/2021.
//

#ifndef LAB11EXTRA_COMPITO_H
#define LAB11EXTRA_COMPITO_H

enum colori : char {R = 'R', G = 'G', B = 'B', Y = 'Y', shift = '=', vuoto = ' '};

class PuzzleBobble {
private:
    static const int COLONNE = 6;
    static const int RIGHE = 10;
    colori matrix[RIGHE][COLONNE];

public:
    PuzzleBobble();

    int scoppiaBolle(unsigned int, unsigned int, char, bool);

    void print();
    PuzzleBobble& fire(unsigned int, char);
    int height();
    PuzzleBobble& scroll();
    void compact();

};


#endif //LAB11EXTRA_COMPITO_H
