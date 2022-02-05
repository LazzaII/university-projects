//
// Created by Utente on 27/12/2021.
//

#include "compito.h"

//Prima parte
Polinomio::Polinomio(int gr, const int *vett) {
    if(gr < 0 || ( vett == nullptr ) || (vett[0] == 0) ) return;

    grado = gr;
    coeff = new int [grado+1];

    for (int i = 0; i < grado+1; ++i)
        coeff[i] = vett[i];
}

int Polinomio::valuta(int x) {
    int somma = coeff[grado], tmp;
    for (int i = 0; i < grado; ++i) {
        tmp = 1;
        for (int j = grado-i; j > 0; --j) {
            tmp *= x;
        }
        tmp *= coeff[i];
        somma += tmp;
    }
    return somma;
}

ostream &operator<<(ostream &out, const Polinomio &p) {
    for (int i = 0, j = p.grado; i < p.grado+1; ++i, --j) {
        out << (p.coeff[i] >= 0 ? "+" : "") << p.coeff[i] << (j != 0 ? "x^" : "" );
        if(j != 0) out << j;
        out << " ";
    }
    return out;
}


//Seconda parte
Polinomio::operator bool() {
    int precedente = coeff[0];

    for (int i = 1; i < grado+1; ++i) {
        if(coeff[i] == 0) continue;
        if(precedente > 0 && coeff[i] > 0)
            precedente = coeff[i];
        else if (precedente < 0 && coeff[i] < 0)
            precedente = coeff[i];
        else
            return false;
    }
    return true;

}

Polinomio& Polinomio::operator=(const Polinomio &p) {
    if ( this == &p )
        return *this;

    if(this->grado != p.grado){
        this->grado = p.grado;
        delete [] this->coeff;
        this->coeff = new int [grado+1];
    }

    for (int i = 0; i < grado+1; ++i) {
        this->coeff[i] = p.coeff[i];
    }

    return *this;
}

Polinomio Polinomio::operator*(const Polinomio &p) {
   /* int grado_prod = grado + p.grado;
    int *coef_prod = new int[ grado_prod + 1 ];

    for (int i = 0; i <= grado_prod; i++)
        coef_prod[i] = 0;
    for (int i=0; i <= grado; i++)
        for (int j=0; j <= p.grado; j++)
            coef_prod[i+j] += coeff[i]*p.coeff[j];

    Polinomio Prod(grado_prod, coef_prod);
    delete [] coef_prod;
    return prod;
*/

   //da rivedere
    return *this;
}