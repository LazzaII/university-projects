//
// Created by Utente on 29/12/2021.
/*digit = 0; tmp = t.tabella[i][j];
while( tmp != 0){
tmp /= 10;
digit++;
}
switch (digit) {
case 1:
tmp = 4;
break;
case 2:
tmp = 3;
break;
case 3:
tmp = 2;
break;
case 4:
tmp = 1;
break;
default:
tmp = 1;
}*/
//

#include "compito.h"
#include <iomanip>
//utility
void Tartaglia::inizializzazione() {
    tabella = new int * [dim+1];

    for (int i = 0; i < dim+1; ++i)
        tabella[i] = new int [i+1];

    tabella[0][0] = 1;
    for (int i = 1; i < dim+1; ++i) {
        for (int j = 0; j < i+1; ++j) {
            if(j == 0) tabella[i][j] = 1;
            else if(j == i) tabella[i][j] = 1;
            else tabella[i][j] = tabella[i-1][j] + tabella[i-1][j-1];
        }
    }
}

void Tartaglia::elimina() {
    for (int i = 0; i < dim+1; ++i)
        delete [] tabella[i];

    delete [] tabella;
}

//prima parte
Tartaglia::Tartaglia(int n) {
    if(n <= 0) return;

    dim = n;
    inizializzazione();
}

ostream &operator<<(ostream &out, Tartaglia &t) {
    for (int i = 0; i < t.dim+1; ++i) {
        for (int j = 0; j < i + 1; ++j)
            out << t.tabella[i][j] << setw(5);
        out << '\n';
    }
    return out;
}

int Tartaglia::fibonacci(int n) {
    if(n < 0 || n > dim) {
        return -1;
    }
    int somma = 0;
    for (int i = 0; i < n+1; ++i)
        for (int j = 0; j < i + 1; ++j)
            if(i+j == n) somma += tabella[i][j];

    return somma;
}

//seconda parte
void Tartaglia::espandi(int n) {
    if(n < 0 || n > dim) {
        return;
    }

    cout << '{';
    if(n == 0) cout << "1";
    else {
        cout << "a^" << n << " + ";
        if( n != 1){
            for (int i = 1; i < n; ++i)
                cout << tabella[n][i] << "a^" << n-i << "*b^" << i << " + ";
        }
        cout << "b^" << n;
    }
    cout << "}\n";
}

void Tartaglia::operator=(Tartaglia &t) {
    if(this == &t) return;

    elimina();
    this->dim = t.dim;
    inizializzazione();
}

