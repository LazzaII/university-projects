#include <iostream>
using namespace std;

const int DIM = 6;

struct automobile {
    char id[DIM+1];
    automobile * succ;
};


class PonteMobile {
private:
    automobile * a0;
    bool aperto;
public:
    //UTILITÀ
    void eliminaAuto();

    //PRIMA PARTE
    PonteMobile(const char * s);
    void aggiungi(const char * s);
    friend ostream & operator << (ostream &out, const PonteMobile &t);

    //SECONDA PARTE
    void cambiaStato();
    void operator -=(const char *s);
    int operator ~();
    ~PonteMobile();


};


