//
// Created by Francesco Lazzarelli on 09/12/2021.
//

#ifndef LAB11_PALAZZO_H
#define LAB11_PALAZZO_H

#include <iostream>
using namespace std;

class Palazzo {
private:
    int max;
    int ll;
    bool** finestre;

public:
    Palazzo(unsigned int);
    Palazzo(Palazzo &);
    ~Palazzo();

    void aggiungi();
    void stampa();
    void cambia(unsigned int,unsigned int);

    int operator!();
    void operator%=(Palazzo);

};


#endif //LAB11_PALAZZO_H
