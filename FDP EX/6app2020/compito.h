//
// Created by Utente on 29/12/2021.
//

#include <iostream>
using namespace std;

class Tartaglia {
private:
    int ** tabella;
    int dim;
public:
    //funzioni di utilità
    void inizializzazione();
    void elimina();

    //prima parte
    Tartaglia(int n);
    friend ostream & operator << (ostream & out, Tartaglia & t);
    int fibonacci(int n);

    //seconda parte
    void espandi(int n);
    void operator = (Tartaglia& t);
    ~Tartaglia(){ elimina(); }
};

