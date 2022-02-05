#include "compito.h"
#include <cstring>

//PRIMA PARTE
Aula::Aula(const int N) {
    dim = (N < 1 ? 5 : N); //se la dimensione è negativa o uguale a 0 si assegna un valore default;

    postazioni = new char *[dim];
    for (int i = 0; i < dim; ++i) {
        postazioni[i] = new char[strlen("<libera>") + 1];
        strcpy(postazioni[i],"<libera>");
    }
    ll = 0;
}

bool Aula::aggiungi(const char *id) {
    if(ll == dim) return false; //controllo se tutte le postazioni sono libere, basta controllare == alla dimensione perché la ll non potrà andare oltre

    for (int i = 0; i < dim; ++i)
        if(strcmp(postazioni[i], id) == 0) return false;

    for (int i = 0; i < dim; ++i) {
        if(strcmp(postazioni[i], "<libera>") == 0) {
            postazioni[i] = new char[strlen(id) + 1];
            strcpy(postazioni[i], id);
            ll++;
            return true;
        }
    }
    return false; //ma non ci arriverà mai, solo per togliere il warning
}

ostream &operator<<(ostream &out, const Aula &t) {
    for (int i = 0; i < t.dim; ++i)
        out << "POSTAZIONE" << i+1 << ":" << t.postazioni[i] << '\n';
    return out;
}

void Aula::elimina(const int p) {
    if(ll == 0 || p >= dim || p == 0) return;
    postazioni[p-1] = new char[strlen("<libera>") + 1];
    strcpy(postazioni[p-1],"<libera>");
    ll--;
}

//SECONDA PARTE
Aula::Aula(const Aula &a) {
    if(this == &a) return; //se sono lo stesso elemento hanno già gli stessi valori

    dim = a.dim;
    ll = a.ll;

    postazioni = new char *[dim];
    for (int i = 0; i < dim; ++i) {
        postazioni[i] = new char [strlen(a.postazioni[i]) + 1];
        strcpy(postazioni[i], a.postazioni[i]);
    }
}

Aula& Aula::operator!() {
    if(ll < dim) return *this;

    int pos;
    char  *tmp;
    for (int i = 0; i < dim-1; ++i) {
        pos = i;
        for (int j = i+1; j < dim; ++j)
            if(strcmp(postazioni[pos], postazioni[j]) > 0)
                pos = j;

        if(pos != i){
            tmp = new char [strlen(postazioni[i]) + 1];
            strcpy(tmp, postazioni[i]);
            postazioni[i] = new char [strlen(postazioni[pos]) + 1];
            strcpy(postazioni[i], postazioni[pos]);
            postazioni[pos] = new char [strlen(tmp) + 1];
            strcpy(postazioni[pos], tmp);
        }
    }
    return *this;
}

Aula::~Aula() {
    for (int i = 0; i < dim; ++i) {
        delete [] postazioni[i];
    }
    delete postazioni;
}


