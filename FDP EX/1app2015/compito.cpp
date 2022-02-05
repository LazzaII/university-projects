#include "compito.h"

//UTILITÀ
void PonteMobile::eliminaAuto() {
    for (automobile * i = a0; i != nullptr; i = a0) {
        a0 = a0->succ;
        delete i;
    }
    a0 = nullptr;
}

//PRIMA PARTE
PonteMobile::PonteMobile(const char *s) {
    if(strlen(s) > DIM) return; //controllo della dimensione

    for (int i = 0; s[i] != '\0'; ++i) //controllo se è maiuscola
        if(s[i] < 'A' || s[i] > 'Z') {
            a0 = nullptr;
            return;
        }

    a0 = new automobile;
    strcpy(a0->id, s);
    a0->succ = nullptr;
    aperto = aperto;
}

void PonteMobile::aggiungi(const char *s) {
    if(strlen(s) > DIM) return; //controllo della dimensione

    for (int i = 0; s[i] != '\0'; ++i) //controllo se è maiuscola
        if(s[i] < 'A' || s[i] > 'Z') return;

    automobile *i, *tmp, *nuova;
    nuova = new automobile;
    strcpy(nuova->id, s);
    nuova->succ = nullptr;

    if(aperto){

        for (i = a0; i != nullptr; i = i->succ) //controllo che l'id non sia già presente
            if(strcmp(i->id, s) == 0) return;

        for (i = a0; i != nullptr ; i = i->succ)
            tmp = i;

        if(a0 == nullptr)
            a0 = nuova;
        else if(i == a0)
            a0->succ = nuova;
        else
            tmp->succ = nuova;
    }
}

ostream &operator<<(ostream &out, const PonteMobile &t) {
    if(!t.aperto)
        out << "PONTE CHIUSO";
    else{
        out << "PONTE APERTO";
        for (automobile * i = t.a0; i != nullptr ; i = i->succ)
            out << "=>" << i->id;
    }
    out << endl;

    return out;
}

//SECONDA PARTE
void PonteMobile::cambiaStato() {
    aperto = !aperto;
    if(!aperto) //se è chiuso quindi false fa passare tutte le auto
        eliminaAuto();
}

void PonteMobile::operator-=(const char *s) {
    if(strlen(s) > DIM) return; //controllo della dimensione

    for (int i = 0; s[i] != '\0'; ++i) //controllo se è maiuscola
        if(s[i] < 'A' || s[i] > 'Z') return;

    automobile *i, *tmp;
    for (i = a0; i != nullptr; i = i->succ){
        if(strcmp(i->id, s) == 0){
            if(i == a0)
                a0 = a0->succ;
            else
                tmp->succ = i->succ;
            delete i;
            return;
        }
        tmp = i;
    }
}

int PonteMobile::operator~() {
    int count = 0;
    if(aperto){
        for (automobile * i = a0; i != nullptr ; i = i->succ)
            count++;
    }
    return count;
}

PonteMobile::~PonteMobile() {
    eliminaAuto();
}