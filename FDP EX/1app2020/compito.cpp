#include "compito.h"

//Prima parte
void ToDoList::aggiungi(char *descr, int prio) {
    if(prio <= 0 || strlen(descr) > DIM) return;

    compito * nuovo = new compito;
    nuovo->fatto =  ' ';
    nuovo->pr = prio;
    strcpy(nuovo->descrizione, descr);
    nuovo->succ = nullptr;

    if(c0 == nullptr){
        c0 = nuovo;
        return;
    }

    compito * i, * tmp;
    for (i = c0; i != nullptr && i->pr <= prio; i = i->succ) {
        tmp = i;
    }

    if(i == nullptr)
        tmp->succ = nuovo;
    else if(i == c0){
        nuovo->succ = c0;
        c0 = nuovo;
    }
    else{
        tmp->succ = nuovo;
        nuovo->succ = i;
    }

}

ostream &operator<<(ostream &out, const ToDoList &t) {
    for (compito * i = t.c0; i != nullptr; i = i->succ)
        out << i->fatto << " " << i->pr << " - " << i->descrizione << endl;

    return out;
}

ToDoList::~ToDoList() {
    for (compito * i = c0; i != nullptr; i = c0) {
        c0 = c0->succ;
        delete i;
    }
}


//seconda parte
ToDoList& ToDoList::operator+=(const ToDoList &t) {
    if(this == &t) return *this;

    for (compito * i = t.c0; i != nullptr ; i = i->succ)
        aggiungi(i->descrizione, i->pr);

    return *this;
}

void ToDoList::fai(char *descr) {
    if(strlen(descr) > DIM) return;

    compito * i;
    for (i = c0; i != nullptr; i = i->succ){
        if(strcmp(i->descrizione, descr) == 0 && i->fatto != 'V'){
            i->fatto = 'V';
            break;
        }
    }
}

void ToDoList::cancella_fatti() {
    compito *i, *tmp, *tmp2;
    for ( i = c0; i != nullptr; i = i->succ) {
        if(i->fatto == 'V'){
            if(i == c0){
                tmp2 = c0->succ;
                delete c0;
                c0 = tmp2;
            }else {
                tmp2 = i->succ;
                delete i;
                tmp->succ = tmp2;
                i = tmp;
            }
        }
        tmp = i;
    }
}


