//
// Created by Utente on 26/12/2021.
//

#include "compito.h"

void Prepagata::elimina(acquisto *p) {
    acquisto * i = p;
    while (i != nullptr){
        p = p->pun;
        delete i;
        i = p;
    }
}

Prepagata::Prepagata( int crIn) {
    if(crIn < 0) crIn = -crIn;

    credito = crIn;
    a0 = nullptr;
}

bool Prepagata::acquista(int imp, char *luogo) {
    if(imp < 0) return false;

    acquisto * i ,* penultimo = nullptr;
    for (i = a0; i != nullptr; i = i->pun)
        penultimo = i; //qui è ancora l'ultimo

    i = new acquisto;
    i->negozio = new char [strlen(luogo)+1];
    strcpy(i->negozio, luogo);
    i->importo = imp;
    i->pun = nullptr;

    if(a0 == nullptr)
        a0 = i;
    else
        penultimo->pun = i;

    return true;
}

ostream &operator<<(ostream &out, const Prepagata &p) {
    int creditoTmp = p.credito, credito = p.credito;
    for (acquisto * i = p.a0; i != nullptr; i = i->pun) {
        creditoTmp -= i->importo;
        out << i->importo << (creditoTmp < 0 ? "<S>[" : "<C>[" ) << credito << "=>" << creditoTmp << "]" << i->negozio << endl;
        credito -= i->importo;
    }
    return out;
}

Prepagata::operator int() {
    int creditoTmp = credito;
    for (acquisto * i = a0; i != nullptr; i = i->pun)
        creditoTmp -= i->importo;
    return creditoTmp;
}

Prepagata &Prepagata::operator!() {
    acquisto *p = a0;
    int saldo = credito;
    acquisto *q = p;
    while( saldo - p->importo >= 0){
        saldo -= p->importo;
        q = p;
        p = p->pun;
    }

    if (p == a0){
        elimina(a0);
        a0= nullptr;
    }else{
        elimina(p);
        q->pun = nullptr;
    }
    return *this;
}

Prepagata::Prepagata(Prepagata &p) {
    this->credito = p.credito;
    if(p.a0 == nullptr){
        this->a0 = nullptr;
        return;
    }
    this->a0 = new acquisto;
    this->a0->negozio = p.a0->negozio;
    this->a0->importo = p.a0->importo;
    this->a0->pun = nullptr;

    for (acquisto * i = this->a0, * j = p.a0->pun; j != nullptr; j = j->pun) {
        i->pun = new acquisto;
        i = i->pun;
        i->importo = j->importo;
        i->negozio = j->negozio;
        i->pun = nullptr;
    }
}

Prepagata::~Prepagata() {
    acquisto * i = a0;
    while (i != nullptr){
        a0 = a0->pun;
        delete i;
        i = a0;
    }
    a0 = nullptr;
}


