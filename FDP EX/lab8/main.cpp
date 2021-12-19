#include <iostream>
#include <cstring>
using namespace std;

//ESERCIZIO 8.4
/*
typedef int T;
struct elem {
    T inf;
    elem succ;
};

void stampaLista(elem lista) {
    elem* p = lista;
    while (p != nullptr) {
        cout << "val: " << p->inf << endl;
        p=p->succ;
    }
}
 */

//ESERCIZIO 8.5
/*
typedef int T;
struct elem {
    T inf;
    elem succ;
};

void inserisciOrdinato(elem &lista, int n) {
    elem* e = new elem;
    e->inf = n;
    e->succ = nullptr;

    if(lista != nullptr) {
        elem *l0 = lista;
        elem l1 = l0->succ;

        if(e->inf <= l0->inf) {
            e->succ = lista;
            lista = e;
            return;
        }

        while (l1 != nullptr) {
            if (e->inf <= l1->inf && e->inf >= l0->inf) {
                e->succ = l1;
                l0->succ = e;
                return;
            }

            l0 = l0->succ;
            l1 = l1->succ;
        }

        l0->succ = e;

        return;
    }

    lista->succ = e;
}

void stampaLista (elem p0) {
    elem* p = p0;

    cout << "Stampa lista \n";

    while(p != nullptr) {
        cout << p->inf << " ";
        p = p->succ;
    }
}
 */

//ESERCIZIO 8.6
struct elem {
    char titolo[64];
    elem* succ;
};

int cerca(elem* l0, char alb[]) {
    elem* p = l0;

    while(p != nullptr) {
        if(strcmp(p->titolo,alb) == 0) return 1;
        p = p->succ;
    }
    return 0;
}

int aggiungi(elem* &l0, char alb[]) {
    if(cerca(l0, alb) == 1) return 0;

    elem* e = new elem;
    strcpy(e->titolo, alb);
    e->succ = l0;
    l0 = e;

    return 1;
}

int elimina(elem* l0, char alb[]) {
    elem* l1 = l0->succ;

    while(l1 != nullptr) {
        if(strcmp(l0->titolo, alb) == 0) {
            elem* e = l1->succ;
            delete l1;
            l0->succ = e->succ;
            return 1;
        }

        l0 = l0->succ;
        l1 = l1->succ;
    }

    return 0;
}

void scrivi(elem l0, char f[]) {

}

void distruggi(elem* l0) {

}

void stampa(elem* l0) {
    elem* p0 = l0;

    cout << "Album della playlist: \n";
    while(p0 != nullptr) {
        for(int i = 0; p0->titolo[i] != '\0'; i++) {
            cout << p0->titolo[i];
        }
        cout << endl;
        p0 = p0->succ;
    }
}

int main() {
    elem* L0 = new elem;
    L0->succ = nullptr; // Playlist vuota
    stampa(L0);

    //test aggiungi
    aggiungi(L0, "titolo1 (autore1)");
    aggiungi(L0, "titolo2 (autore1)");
    aggiungi(L0, "titolo3 (autore2)");
    aggiungi(L0, "titolo2 (autore1)"); //non viene aggiunto perche' gia' presente stampa(L0);

    stampa(L0);

    //test elimina
    elimina(L0, "titolo2 (autore1)");
    elimina(L0, "titolo8 (autore1)"); //non viene rimosso perche' non presente stampa(L0);

    //test cerca
    cout<<cerca(L0, "titolo2 (autore1)")<<endl; //visualizza 1 cout<<cerca(L0, "titolo5 (autore1)")<<endl; //visualizza 0

    //test scrivi
    //scrivi(L0, "playlist.txt");

    //test distruggi
    //distruggi(L0);
    stampa(L0);

    return 0;
}
