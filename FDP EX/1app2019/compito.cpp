//
// Created by Utente on 02/01/2022.
//

#include "compito.h"
//PRIMA PARTE
void Timeline::pubblica(char *str, int ev) {
    if(ev < 0 || ev > 1) return;
    if(strlen(str) < 1) return;

    foto * i, * nuova, *tmp;
    nuova = new foto;
    nuova->nome = new char [strlen(str)+1];
    strcpy(nuova->nome, str);
    nuova->inEvidenza = ev;
    nuova->succ = nullptr;

    if(nuova->inEvidenza){
        nuova->succ = f0;
        f0 = nuova;
    }
    else{
        for (i = f0; i != nullptr && i->inEvidenza; i = i->succ)
            tmp = i;

        if( i == f0){
            nuova->succ = f0;
            f0 = nuova;
        }
        else if(i == nullptr){
            tmp->succ = nuova;
        }
        else {
            tmp->succ = nuova;
            nuova->succ = i;
        }
    }
}

void Timeline::cancella(char *str) {
    if(strlen(str) < 1) return;

    foto * i, * tmp;
    for (i = f0; i != nullptr && strcmp(str, i->nome) != 0 ; i = i->succ)
        tmp = i;

    if (i == nullptr)
        return;
    else if(i == f0){
        delete f0;
        f0 = nullptr;
    }
    else {
        tmp->succ = i->succ;
        delete i;
    }
}

ostream &operator<<(ostream & out, const Timeline &t) {
    out << "-----\n";
    for (foto * i = t.f0; i != nullptr; i = i->succ)
        out << (i->inEvidenza ? "(*)" : "") << i->nome << endl;
    out << "-----\n";
    return out;
}

//SECONDA PARTE
int Timeline::operator!() {
    int alt = 0;
    for (; f0 != nullptr && f0->inEvidenza; f0 = f0->succ) {
        foto * tmp = f0;
        f0 = f0->succ;
        delete [] tmp->nome;
        delete tmp;
        alt = 1;
    }

    return alt;
}

void Timeline::mettiInEvidenza(char *str) {
    if(strlen(str) < 1) return;

    foto * i, * tmp;
    for ( i = f0; i != nullptr; i = i->succ) {
        if(i->inEvidenza && strcmp(i->nome, str) == 0)
            return;
        if(!i->inEvidenza && strcmp(i->nome, str) == 0){
            if(i == f0){
                f0->inEvidenza = true;
                break;
            }
            else {
                //si toglie dal mezzo la i
                tmp->succ = i->succ;
                // si sposta la i in cima
                i->succ = f0;
                f0 = i;
                f0->inEvidenza = true;
                break;
            }
        }
        tmp = i;
    }
}

Timeline::~Timeline() {
    for (foto * i = f0; i != nullptr; i = f0) {
        f0 = f0->succ;
        delete [] i->nome;
        delete i;
    }
}