//
// Created by Utente on 31/12/2021.
//

#include "compito.h"

//prima parte
void Nastro::aggiungi(char *s, int c) {
    int prezzo = 0; char nome[DIM+1] = "";
    Piatto *tmp, *i, *nuovo;

    //controllo degli input
    if(c >= 0) prezzo = c;
    if(strlen(s) < DIM) strcpy(nome, s);
    for (i = p0; i != nullptr; i = i->succ)
        if(strcmp(i->nome, nome) == 0 && i->prezzo != prezzo) //stesso nome ma con prezzo diverso
            return;

    //inserimento
    nuovo = new Piatto;
    nuovo->prezzo = c;
    strcpy(nuovo->nome, nome);
    nuovo->succ = nullptr;
    for (i = p0; i != nullptr && i->prezzo < prezzo; i = i->succ)
        tmp = i;

    //controllo del nome
    for (;i != nullptr && i->prezzo == prezzo && strcmp(i->nome, nome) < 0; i = i->succ)
        tmp = i;

    if(i == p0)
        p0 = nuovo;
    else
        tmp->succ = nuovo;

    nuovo->succ = i;
}

Nastro &Nastro::consuma(char *s) {
    if(strlen(s) > DIM) return *this;

    Piatto *tmp, *i;
    for (i = p0; i != nullptr && strcmp(i->nome, s) != 0; i = i->succ)
        tmp = i;

    if(i == nullptr) return *this;

    conto += i->prezzo;
    if(i == p0)
        p0 = p0->succ;
    else
        tmp->succ = i->succ;

    delete i;
    return *this;
}

ostream &operator<<(ostream &out, const Nastro &n) {
    out << "Piatti sul nastro:\n";
    for (Piatto * i = n.p0; i != nullptr; i = i->succ)
        out << (strcmp(i->nome, "") == 0 ? " " : i->nome) << " " << i->prezzo << endl;
    out << "Conto: " << n.conto << endl;
    return out;
}

//seconda parte
Nastro &Nastro::operator+=(const Nastro &n) {
    if( this == &n || n.p0 == nullptr )
        return *this;

    for(Piatto* i = n.p0; i != nullptr; i = i->succ)
        aggiungi(i->nome, i->prezzo);

    return *this;
}

Nastro Nastro::operator|(const Nastro &n) {
    Nastro nn;

    if(this == &n)
        return nn;

    int cmp_nomi;
    int diff_prezzi;

    Piatto * i, * j;
    for ( i = p0, j = n.p0; i != nullptr && j != nullptr; ) {

        diff_prezzi = i->prezzo - j->prezzo;
        cmp_nomi = strcmp(i->nome, j->nome);

        if(diff_prezzi < 0 || (diff_prezzi == 0 && cmp_nomi < 0)){
            nn.aggiungi(i->nome, i->prezzo);
            i = i->succ;
        }else {
            nn.aggiungi(j->nome, j->prezzo);
            j = j->succ;
        }
    }

    if(i == nullptr){
        for(; j != nullptr; j = j->succ)
            nn.aggiungi(j->nome, j->prezzo);
    }else {
        for(; i != nullptr; i = i->succ)
            nn.aggiungi(i->nome, i->prezzo);
    }
    return nn;
}

Nastro::~Nastro() {
    Piatto *i;
    for ( i = p0; i != nullptr; i = p0) {
        p0 = p0->succ;
        delete i;
    }
}
