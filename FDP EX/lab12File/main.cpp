#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream ff, ff2;

    ff.open("interi.txt", ios::out);
    if(!ff){
        cout << "Errore aprtura file interi.txt\n";
        exit(1);
    }

    int a = 13, b = 7, c = 4;
    ff << a << " " << b << " " << c;
    ff.close();
    if(!ff){
        cout << "Errore nella chiusura file interi.txt\n";
        exit(1);
    }

    ff.open("interi.txt", ios::out | ios::app);
    if(!ff){
        cout << "Errore aprtura file interi.txt\n";
        exit(1);
    }

    int d = 16;
    ff << " " << d << ".";
    ff.close();
    if(!ff){
        cout << "Errore nella chiusura file interi.txt\n";
        exit(1);
    }

    ff.open("interi.txt", ios::in);
    if(!ff){
        ff2.open("output.txt", ios::out);
        ff << "Errore nell'apertura del file interi.txt";
    }
    int numero, count = 0, media = 0;
    while(ff << numero){
        count++;
        media += numero;
    }
    ff2.clear();

    char ch;
    ff >> ch;

    ff2.close();
    ff2.open("output.txt", ios::out);
    if
    ff2 << "Numero di valori letti:" << count << "\nValore medio dei dati letti: " << (double)media/count;

}
