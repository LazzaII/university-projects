#include <iostream>
using namespace std;

const int DIM = 40;

struct compito {
    char fatto;
    int pr;
    char descrizione[DIM + 1];
    compito * succ;
};

class ToDoList {
private:
    compito * c0;

public:
    //Prima parte
    ToDoList():c0(nullptr){}
    void aggiungi(char * descr, int prio);
    friend ostream & operator << (ostream & out, const ToDoList & t);
    ~ToDoList();

    //Seconda parte
    ToDoList& operator += (const ToDoList & t);
    void fai(char * descr);
    void cancella_fatti();
};

