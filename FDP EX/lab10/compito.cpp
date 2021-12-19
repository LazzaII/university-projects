#include "compito.h"
#include "cstring"
#include "iostream"

using namespace std;

Cinema::Cinema(int n, int p, char * s) {
    if(n < FILE_MAX) file = n;
    else file = FILE_MAX;

    if(p < POSTI_MAX) posti = p;
    else posti = POSTI_MAX;

    if(strlen(s) < 30) strcpy(nome_cinema, s);
    else strcpy(nome_cinema,"Nome cinema non valido");

    //inizializzazione matrice
    for (int i = 0; i < file; ++i) {
        for (int j = 0; j < posti; ++j) {
            schema_posti[i][j] = false;
        }
    }
}

bool Cinema::prenota(const char l, const int j) {
    if(j < POSTI_MAX) {
        if(l >= 'A' && l <= 'Z'){
            //controllo se nella fila il posto è occupato (il controllo della fila si fa tramite la conversione implcita della lettera inserita sottraendogli 64 (cioè A))
            if(schema_posti[l-'A'][j-1]) return false;
            else {
                schema_posti[l-'A'][j-1] = true; //prenota il posto
                return true;
            }
        }
        else return false;
    }
    else return false;
}

bool Cinema::cancella(const char l, const int j) {
    if(j < POSTI_MAX) {
        if(l >= 'A' && l <= 'Z'){
            //controllo se nella fila il posto è occupato (il controllo della fila si fa tramite la conversione implcita della lettera inserita sottraendogli 64 (cioè A))
            if(schema_posti[l-'A'][j-1] == 1)  {
                schema_posti[l-'A'][j-1] = false ; //libera il posto
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

void Cinema::stampa() {
    cout << "Nome del cinema: " << nome_cinema << "\n";
    cout << " ";
    for (int i = 0; i < posti; i++)
        cout << i+1;
    cout << endl;

    for (int i = 0; i < file; i++) {
        char posto = 'A' + i;
        cout << posto;
        for (int j = 0; j < posti; j++) {
            if(schema_posti[i][j]) cout << "*";
            else cout << " ";
        }
        cout << endl;
    }
}

int Cinema::quantiLiberi() {
    int liberi = 0;
    for (int i = 0; i < file; ++i) {
        for (int j = 0; j < posti; ++j) {
            if(!schema_posti[i][j]) liberi++;
        }
    }
    return liberi;
}

bool Cinema::prenotaAdiacenti(const int k) {
    if(k > posti) return false;

    for (int i = 0; i < file; ++i) {
        for (int j = 0; j < posti; ++j) {
            if(j+k-1 < posti) {
                if (!schema_posti[i][j]) {
                    for (int n = 1; n < k; n++) {
                        if (schema_posti[i][j + n]) break;
                        else if (n == k - 1) {
                            for (int v = 0; v < k; v++) schema_posti[i][j + v] = true;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}




