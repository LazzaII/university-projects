//
// Created by Utente on 27/12/2021.
//

#include <iostream>
#include <cstdlib>
using namespace std;


class Polinomio {
private:
    int grado;
    int * coeff;
public:

    //Prima parte
    Polinomio(int gr, const int * vett);
    int valuta(int x);
    friend ostream & operator << (ostream& out, const Polinomio& p);
    ~Polinomio(){delete [] coeff;}

    //Seconda parte
    operator bool ();
    Polinomio& operator = (const Polinomio& p);
    Polinomio operator * (const Polinomio& p);
};

