//
// Created by Utente on 31/12/2021.
//

#include "compito.h"

void Seggio::nuovoElettore(int id) {
    if(id < 0 ) id = -id;

    //inserimento in coda
    voto * i, *tmp;
    tmp = new voto;
    tmp->id = id;
    tmp->v = null;
    tmp->succ = nullptr;

    if(v0 == nullptr){
        v0 = tmp;
        eleInCoda++;
        return;
    }

    for (i = v0; i->succ != nullptr ; i = i->succ) {
        tmp = i;
    }

    tmp = new voto;
    tmp->id = id;
    tmp->v = null;
    tmp->succ = nullptr;

    if(i == v0)
        v0->succ = tmp;
    else
        i->succ = tmp;

    eleInCoda++;
}

ostream &operator<<(ostream &out, const Seggio &s) {
    out << "Elettori che hanno votato: " << s.votanti << endl;
    if(s.votanti != 0)
        for (voto * i = s.v0; i != nullptr && i->v != null; i = i->succ)
            out << "->" << i->id;

    out << "\nElettori in coda: " << s.eleInCoda << endl;
    return out;
}

//Seconda parete
void Seggio::nuovoVoto(votazione v) {
    if(v == contrario || v == favorevole) { //controllo se l'inserimento dei valori rispetta l'enum
        for( voto * i = v0; i != nullptr; i = i->succ)
            if(i->v == null) {
                eleInCoda--;
                votanti++;
                i->v = v;
                break;
            }
    }
}

void Seggio::spoglioDeiVoti() {
    int fav = 0, cont = 0;

    if(eleInCoda != 0) cout << "Spoglio impossibile!\n";
    else {
        for (voto * i  = v0;  i != nullptr ; i = i->succ) {
            if(i->v == favorevole) fav++;
            else cont ++;
        }
        cout << "Favorevoli: " << fav << endl;
        cout << "Contrari: " << cont << endl;
        cout << "Vittoria dei " << (fav > cont ? "favorevoli!" : "contrari!") << endl;
    }
}

Seggio::~Seggio() {
    for (voto * i = v0; i != nullptr ; i = v0) {
        v0 = v0->succ;
        delete i;
    }
}


