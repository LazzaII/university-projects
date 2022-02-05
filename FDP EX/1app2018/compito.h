#include <iostream>
using namespace std;

const int DIM = 20;

struct app {
    char * nome;
    app * succ;
};

class GestoreApp {
private:
    app * a0;

public:
    //PRIMA PARTE
    GestoreApp():a0(nullptr){}
    void operator +=(const char * str);
    friend ostream & operator <<(ostream & out, const GestoreApp & g);

    //SECONDA PARTE
    void foreground(const char * str);
    void operator -=(const char *str);
    void chiudi_tutte();
    ~GestoreApp();
};
