#include <iostream>
using namespace std;

const int N_CASELLI = 5;
const int L_TARGA = 6;

struct automobile{
    char targa[L_TARGA+1];
    automobile * succ;
};

struct casello{
    bool aperto;
    automobile * a0;
    int inIncoda;
};


class Barriera {
private:
    casello caselli[N_CASELLI];

public:

    //PRIMA PARTE
    Barriera();
    void nuovoVeicolo(const char *s);
    bool serviVeicolo(const int i);
    friend ostream& operator << (ostream & out, const Barriera & b);

    //SECONDA PARTE
    int apriOppureChiudi(double mediaIdeale);
    operator int();
    ~Barriera();
};

