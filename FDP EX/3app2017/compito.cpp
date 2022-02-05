#include "compito.h"
//PRIMA PARTE
Barriera::Barriera() {
    for (int i = 0; i < N_CASELLI; ++i) { //Inizializzazione di tutti e 5 i caselli
        caselli[i].a0 = nullptr;
        caselli[i].inIncoda = 0;
        caselli[i].aperto = i < 3;
    }
}

void Barriera::nuovoVeicolo(const char *s) {
    if(s == nullptr || strlen(s) != L_TARGA) return; //controllo della lunghezza della strinza

    for (int i = 0; i < L_TARGA; ++i)
        if(s[i] < 'A' || s[i] > 'Z') return; //controllo se la targa è tutta maiuscola

    int min = -1, pos;
    for (int i = 0; i < N_CASELLI; ++i) {
        if(caselli[i].aperto && min == -1){
            min = caselli[i].inIncoda;
            pos = i;
        }
        if(caselli[i].aperto && caselli[i].inIncoda < min) {
            min = caselli[i].inIncoda;
            pos = i;
        }
    }

    //Inserimento in fondo dell'auto
    automobile *nuova, *i, *tmp;
    nuova = new automobile;
    strcpy(nuova->targa, s);
    nuova->succ = nullptr;


    for (i = caselli[pos].a0; i != nullptr; i = i->succ)
        tmp = i;

    if( i == caselli[pos].a0) // lista vuota
        caselli[pos].a0 = nuova;
    else
        tmp->succ = nuova;

    caselli[pos].inIncoda++;
}

bool Barriera::serviVeicolo(const int i) {
    if(i < 1 || i > N_CASELLI) return false; //se inserisce un numero minore di 1 o maggiore di 5 esce (non compresi)
    if(!caselli[i-1].aperto) return false; //casello chiuso

    automobile * tmp = caselli[i-1].a0;
    caselli[i-1].a0 = caselli[i-1].a0->succ;
    delete tmp;
    caselli[i-1].inIncoda--;
    return true;
}

ostream &operator<<(ostream &out, const Barriera &b) {

    for (int i = 0; i < N_CASELLI; ++i) {
        out << "[" << i+1 << "]  ";
        if(b.caselli[i].aperto)
            if(b.caselli[i].a0 == nullptr)
                out << "(libero)";
            else
                for (automobile * j = b.caselli[i].a0; j != nullptr ; j = j->succ)
                    out << j->targa << (j->succ == nullptr ? "" : "=>");
        else out << "(chiuso)";
        out << endl;
    }
    return out;
}

//SECONDA PARTE
int Barriera::apriOppureChiudi(double mediaIdeale) {
    if(mediaIdeale < 0) return 0; //se la media è minore di restituisce 0 perchè i caselli non sono stati alterati

    double media = 0.0;
    int aperti = 0;
    for (int i = 0; i < N_CASELLI; ++i) {
        if (caselli[i].aperto) {
            media += caselli[i].inIncoda;
            aperti++;
        }
    }
    media /= aperti;

    if(media < mediaIdeale){
        for (int i = 0; i < N_CASELLI; ++i) {
            if(caselli[i].aperto && caselli[i].a0 == nullptr){
                caselli[i].aperto = false;
                return -1;
            }
        }
    }
    else if(media > mediaIdeale){
        for (int i = N_CASELLI; i > -1 ; --i) {
            if(!caselli[i].aperto){
                caselli[i].aperto = true;
                return 1;
            }
        }
    }
    return 0;
}

Barriera::operator int() {
    int tot = 0;
    for (int i = 0; i < N_CASELLI; ++i)
        tot += caselli[i].inIncoda;

    return tot;
}

Barriera::~Barriera() {
    for (int i = 0; i < N_CASELLI; ++i) {
        for (automobile *j = caselli[i].a0; j != nullptr ; j = caselli[i].a0) {
            caselli[i].a0 = caselli[i].a0->succ;
            delete j;
        }
    }
}
