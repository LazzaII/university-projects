//
// Created by Utente on 26/12/2021.
//

#ifndef INC_3APP2014_COMPITO_H
#define INC_3APP2014_COMPITO_H

#include <iostream>
using namespace std;

struct acquisto {
    int importo;
    char * negozio;
    acquisto * pun;
};

class Prepagata {
private:
    acquisto * a0;
    int credito;

public:
    void elimina(acquisto *p);

    Prepagata(int crIn);
    bool acquista(int imp, char * luogo);
    friend ostream & operator << (ostream& out, const Prepagata& p);

    operator int();
    Prepagata& operator ! ();
    Prepagata(Prepagata& p);
    ~Prepagata();
};


#endif //INC_3APP2014_COMPITO_H
