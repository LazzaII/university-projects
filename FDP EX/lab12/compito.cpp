//
// Created by Utente on 16/12/2021.
//

#include "compito.h"

void VettoreSparso::elimina() {
    nodo *tmp;
    for(nodo *pos = p0; pos != nullptr;){
        tmp = pos->prossimo;
        delete pos;
        pos = tmp;
    }
}

//PRIMA PARTE

VettoreSparso::VettoreSparso(unsigned int d) {
    if(d == 0) return;

    LF = d;
    p0 = nullptr;
}

void VettoreSparso::set(int v, unsigned int i) {
    if(v == 0 || i >= LF) return;

    nodo *pos, *newNodo;
    for(pos = p0; pos != nullptr && pos->pos <= i; pos = pos->prossimo)
        newNodo = pos;

    if(pos == p0) {
        p0 = new nodo;
        p0->pos = i;
        p0->val = v;
        p0->prossimo= pos;
    }
    else if(newNodo->pos == i) {
        newNodo->val = v;
    }
    else {
        nodo *tmp = new nodo;
        tmp->pos = i;
        tmp->val = v;
        tmp->prossimo= pos;
        newNodo->prossimo = tmp;
    }
}

ostream& operator<<(ostream& out, VettoreSparso vs) {
    out << "[" << vs.LF << "] { ";
    for(nodo* pos = vs.p0; pos != nullptr; pos = pos->prossimo)
        out << "(" << pos->val << "," << pos->pos << ")";
    out << " }";
    return out;
}

//SECONDA PARTE

/*VettoreSparso::~VettoreSparso() {
    elimina();
}*/

void VettoreSparso::visualizzaComeDenso() {
    int counter = 0;
    cout << "< ";
    for(nodo * pos = p0; pos != nullptr;){
        if(counter != pos->pos){
            for (int i = 0; i < pos->pos - counter; ++i)
                cout << "0 ";
            counter = pos->pos;
        }else{
            cout << pos->val << " ";
            pos = pos->prossimo;
            counter++;
        }
    }
    cout << " >";
}

void VettoreSparso::reset(unsigned int i) {
    if(p0 == nullptr || i > LF) return;

    nodo *pos, *tmp;
    for(pos = p0; pos != nullptr && pos->pos != i; pos = pos->prossimo)
        tmp = pos;

    if(pos == p0) p0 = pos->prossimo;
    else tmp->prossimo = pos->prossimo;
    delete pos;
}

VettoreSparso VettoreSparso::operator*=(int k) {
    if (k == 0) {
        elimina();
        p0 = nullptr;
    }
    nodo *pos;
    for (pos = p0; pos != nullptr; pos = pos->prossimo)
        pos->val *= k;

    return *this;
}
