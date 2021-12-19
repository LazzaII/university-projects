//
// Created by Utente on 16/12/2021.
//

#ifndef LAB12_COMPITO_H
#define LAB12_COMPITO_H

#include <iostream>
using namespace std;

struct nodo{
    int pos;
    int val;
    nodo* prossimo;
};


class VettoreSparso {
private:
    nodo *p0;
    unsigned int LF;

    void elimina();

public:
    VettoreSparso(unsigned int);
    //~VettoreSparso();

    void set(int,unsigned int);
    void visualizzaComeDenso();
    void reset(unsigned int);

    friend ostream & operator<<(ostream&, VettoreSparso);
    VettoreSparso operator*=(int);

};


#endif //LAB12_COMPITO_H
