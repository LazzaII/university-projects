//
// Created by Utente on 24/12/2021.
//

#include "compito.h"

void Display::elimina() {
    for (int i = 0; i < LF; ++i) {
        delete [] led[i];
    }
    delete [] led;
}

void Display::inizializzazione() {
    led = new bool *[LF]; //inizializzazione della matrice
    for (int i = 0; i < LF; ++i)
        led[i] = new bool[LF];

    for (int i = 0; i < LF; ++i) //valorizzazione della matrice iniziale a false
        for (int j = 0; j < LF; ++j)
            led[i][j] = false;
}

Display::Display(unsigned int N) {
    if(N%2 != 0) //controllo se N è dispari
        LF = N;
    else LF = 5;

    inizializzazione();
}

void Display::set(char ch) {
    switch (ch) {
        case '-':
            for (int i = 0; i < LF; ++i) {
                led[(int)(LF/2)][i] = true;
            }
            break;
        case '|':
            for (int i = 0; i < LF; ++i) {
                led[i][(int)(LF/2)] = true;
            }
            break;
        case '/':
            for (int i = 0; i < LF; ++i) {
                for (int j = 0; j < LF; ++j) {
                    if(i+j+1 == LF) led[i][j] = true;
                }
            }
            break;
        default: // se non è nessuno dei comandi accettati ritorna zero
            return;
    }
}

ostream& operator << (ostream& out, const Display& d){
    for (int i = 0; i < d.LF; ++i) {
        for (int j = 0; j < d.LF; ++j) {
            out << (d.led[i][j] ? "1" : "0");
        }
        out << endl;
    }
    return out;
}

void Display::operator|=(const Display& d) {
    if(this->LF != d.LF) return;

    for (int i = 0; i < LF; ++i) {
        for (int j = 0; j < LF; ++j) {
            if(d.led[i][j] && !this->led[i][j]) this->led[i][j] = true;
        }
    }
}

void Display::specchia() {
    bool tmp;
    for (int i = 0; i < LF; ++i) {
        for (int j = 0; j < LF/2; ++j) {
            tmp = led[i][j];
            led[i][j] = led[i][LF-j-1];
            led[i][LF-j-1] = tmp;
        }
    }
}

Display& Display::operator=(const Display& d) {
    if(this != &d){
        if(this->LF != d.LF){
            elimina();
            this->LF = d.LF;
            inizializzazione();
        }
        for (int i = 0; i < LF; ++i)
            for (int j = 0; j < LF; ++j)
                this->led[i][j] = d.led[i][j];

    }
    return *this;
}

Display::~Display() {
    elimina();
}