//
// Created by Utente on 30/12/2021.
//

#include "compito.h"

//Prima parte
Coppia::Coppia() {
    positiva = 5;
    negativa = -9;
}

Coppia::Coppia(long int p,long int q) {
    if(p < 0 || q < 0) return;
    positiva = p;
    negativa = -q;
}

ostream &operator<<(ostream &out, Coppia &c) {
    out << "<" << c.positiva << "," << c.negativa << ">";
    return out;
}

Insieme::Insieme(int d) {
    if(d <= 0) dim = 3;
    else dim = d;

    coppie = new Coppia [dim];
}

Insieme& Insieme::operator=(Insieme& in) {
    if(this == &in) return *this;
    if(dim != in.dim){
        delete [] coppie;
        dim = in.dim;
        coppie = new Coppia [dim];
    }
    for (int i = 0; i < dim; ++i) {
        coppie[i].positiva = in.coppie[i].positiva;
        coppie[i].negativa = in.coppie[i].negativa;
    }

    return *this;
}

Insieme& Insieme::operator-() {
    int tmp;
    for (int i = 0; i <dim; ++i) {
        tmp = coppie[i].positiva;
        coppie[i].positiva = -coppie[i].negativa;
        coppie[i].negativa = -tmp;
    }

    return *this;
}

ostream &operator<<(ostream &out, Insieme &in) {
    for (int i = 0; i < in.dim; ++i)
        out << in.coppie[i];

    return out;
}

