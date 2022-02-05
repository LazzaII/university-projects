#include <iostream>
using namespace std;

enum votazione {favorevole, contrario, null};

struct voto{
    votazione v;
    int id;
    voto * succ;
};

class Seggio {
private:
    voto * v0;
    int eleInCoda;
    int votanti;
public:
    //prima parte
    Seggio(): eleInCoda(0), votanti(0), v0(nullptr){};
    void nuovoElettore(int id);
    friend ostream & operator << (ostream & out, const Seggio & s);

    //seconda parte
    void nuovoVoto(votazione v);
    void spoglioDeiVoti();
    ~Seggio();

};

