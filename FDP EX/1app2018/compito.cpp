//
// Created by Utente on 03/01/2022.
//

#include "compito.h"
#include <cstring>

//PRIMA PARTE
void GestoreApp::operator+=(const char *str) {
    if(str == nullptr || strlen(str) > DIM) return;

    app *i, *tmp;
    //controllo se non è gia presente l'app
    for ( i = a0; i != nullptr && strcmp(str, i->nome) != 0; i = i->succ)
        tmp = i;

    //controllo di essere arrivato alla fine del for e quindi essere sicuro che non sia già presente l'app
    if(i == nullptr){
        tmp = new app;
        tmp->nome = new char[strlen(str)+1];
        strcpy(tmp->nome, str);
        tmp->succ = nullptr;

        if(i == a0) //lista vuota
            a0 = tmp;
        else{ //inserimento in testa
            tmp->succ = a0;
            a0 = tmp;
        }
    }
}

ostream &operator<<(ostream & out, const GestoreApp &g) {
    if(g.a0 == nullptr) out << "[]";

    for (app * i = g.a0;  i != nullptr; i = i->succ) {
        if(i == g.a0) out << "[" << i->nome << "]";
        else out << i->nome;

        if(i->succ != nullptr) out << ", ";
    }


    return out;
}

//SECONDA PARTE
void GestoreApp::foreground(const char *str) {
    if(str == nullptr || strlen(str) > DIM || a0 == nullptr) return;

    // app già in foreground
    if(strcmp(a0->nome, str) == 0) return;

    app *i, *tmp;
    for ( i = a0; i != nullptr && strcmp(i->nome, str) != 0; i = i->succ)
        tmp = i;

    //app non presente
    if(i == nullptr) return;
    else {
        //app tolta da metà
        tmp->succ = i->succ;
        //app messa davanti a tutte
        i->succ = a0;
        a0 = i;
    }
}

void GestoreApp::operator-=(const char *str) {
    if (str == nullptr || strlen(str) > DIM || a0 == nullptr) return;

    app *i, *tmp;
    for ( i = a0; i != nullptr && strcmp(i->nome, str) != 0; i = i->succ)
        tmp = i;

    //non è stata trovata l'app quindi esce
    if( i == nullptr) return;

    if(i == a0){ //eliminazione in testa
        a0 = a0->succ;
        delete [] i->nome;
        delete i;
    }
    else { //eliminazione nel mezzo
        tmp->succ = i->succ;
        delete [] i->nome;
        delete i;
    }

}

void GestoreApp::chiudi_tutte() {
    for (app * i = a0; i != nullptr ; i = a0) {
        a0 = a0->succ;
        delete i;
    }
}
GestoreApp::~GestoreApp() {
    chiudi_tutte();
}
