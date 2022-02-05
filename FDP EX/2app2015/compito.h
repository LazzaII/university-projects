//
// Created by Utente on 30/12/2021.
//

#include <iostream>
using namespace std;

class Coppia {
private:
    unsigned long int positiva;
    long int  negativa;

public:
    //utilità
    friend class Insieme;

    //prima parte
    Coppia();
    Coppia(long int p, long int q);
    friend ostream  & operator << (ostream & out, Coppia & c);
};

class Insieme {
private:
    Coppia * coppie;
    int dim;
public:

    //prima parte
    Insieme(int d);
    friend ostream  & operator << (ostream & out, Insieme & in);

    //seconda parte
    Insieme& operator = (Insieme& in);
    Insieme& operator -();
    ~Insieme(){delete [] coppie;}
};
