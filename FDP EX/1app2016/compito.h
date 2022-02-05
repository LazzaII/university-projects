#include <iostream>
using namespace std;

class Aula {
private:
    char ** postazioni;
    int dim;
    int ll;
public:
    //PRIMA PARTE
    Aula(const int N);
    bool aggiungi(const char * id);
    friend ostream & operator <<(ostream &out, const Aula &t);
    void elimina(const int p);

    //SECONDA PARTE
    Aula(const Aula& a);
    Aula& operator !();
    ~Aula();

};

