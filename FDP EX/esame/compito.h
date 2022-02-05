#ifndef ESAME_COMPITO_H
#define ESAME_COMPITO_H

#include <iostream>
using namespace std;

class Memory {
private:
    char **tessere;
    int punteggio;
    int LF;

public:
    //Utilità
    bool controllaTipo(const char tipo);

    //PRIMA PARTE
    Memory(const int dim);
    friend ostream & operator << (ostream & out, const Memory & m);
    void inserisci(const char tipo, const int riga1, const int colonna1, const int riga2, const int colonna2);
    void riassumi();
    bool flip(const int riga1, const int colonna1, const int riga2, const int colonna2);
    void operator~();

    //SECONDA PARTE
    Memory(const Memory & m);
    Memory operator +(const Memory & m);
    Memory& operator>>(int i);

};


#endif //ESAME_COMPITO_H
