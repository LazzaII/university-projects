#include "compito.h"
#include <iostream>
using namespace std;

int main(){
    // PRIMA PARTE:
    cout << "--- PRIMA PARTE ---" << endl;
    cout << "Test costruttore" << endl;
    PuzzleBobble pb;
    pb.print();

    /*cout << "Test funzione fire" << endl;
    pb.fire(0,'R').fire(1,'R').fire(0,'B').fire(2,'Y');
    pb.fire(3,'Y').fire(3,'Y').fire(0,'B').fire(3,'G');
    pb.print();

    cout << "Test operatore int" << endl;
    cout << "Altezza: " << pb.height() << endl;

    // SECONDA PARTE:
    cout << "--- SECONDA PARTE ---" << endl;
    cout << "Test funzionalita' scoppio bolle" << endl;
    pb.fire(0,'B'); // scoppio verticale di 3 bolle
    pb.fire(0,'R'); // no scoppio
    pb.fire(5,'Y').fire(4,'Y'); // scoppio orizzontale di 4 bolle
    pb.fire(3,'G'); // no scoppio
    pb.print();

    cout << "Test funzione scroll" << endl;
    pb.scroll().scroll();
    pb.print();

    cout << "Test funzione compact" << endl;
    pb.compact();
    pb.print();*/

    return 0;
}
