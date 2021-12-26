//
// Created by Utente on 24/12/2021.
//

#ifndef INC_2APP2014_COMPITO_H
#define INC_2APP2014_COMPITO_H

#include <iostream>
using namespace std;

class Display {
private:
    bool **led;
    unsigned int LF;

public:
    Display(unsigned int N);
    //Funzioni non richieste ma di utilità
    void elimina();
    void inizializzazione();

    void set(char ch);
    void specchia();

    friend ostream & operator<< (ostream& out, const Display& d);
    void operator |= (const Display& d);
    Display& operator = (const Display& d);

    ~Display();
};


#endif //INC_2APP2014_COMPITO_H
