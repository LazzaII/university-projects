#include <iostream>
using namespace std;

const int DIM = 25;

struct Piatto{
    char nome[DIM+1];
    unsigned int prezzo;
    Piatto * succ;
};

class Nastro {
private:
    int conto;
    Piatto * p0;

public:

    //Prima parte
    Nastro(){ conto = 0; p0 = nullptr;}
    void aggiungi(char * s, int c);
    Nastro& consuma(char * s);
    friend ostream & operator << (ostream & out, const Nastro &n);

    //Seconda parte
    Nastro& operator += (const Nastro & n);
    Nastro operator | (const Nastro & n);
    ~Nastro();
};


