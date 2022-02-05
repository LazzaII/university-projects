#include <iostream>
using namespace std;

struct foto {
    char * nome;
    bool inEvidenza;
    foto * succ;
};

class Timeline {
private:
    foto * f0;

public:
    //PRIMA PARTE
    Timeline():f0(nullptr){}
    void pubblica(char * str, int ev);
    void cancella(char * str);
    friend ostream & operator <<(ostream & out, const Timeline & t);

    //SECONDA PARTE
    int operator !();
    void mettiInEvidenza(char * str);
    ~Timeline();
};
