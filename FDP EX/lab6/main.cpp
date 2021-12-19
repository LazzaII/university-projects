#include <iostream>
using namespace std;

//----ESERCIZIO 2
/*
double posMin (const double vett[], int dim){
    int posizioneMin = 0;
    if(dim == 0) return NAN;

    for (int i = 1; i < dim; ++i) {
        if(vett[posizioneMin] > vett[i]){
            posizioneMin = i;
        }
    }

    return posizione;
}
 */

//----ESERCIZIO 3
/*
bool pari(const int v[], int n){
    int somma = 0;
    if(n == 0) return NAN;
    for (int i = 0; i < n; ++i) {
        somma += v[i];
    }

    if(somma%2 == 0) return true;
    return false;
}
 */

//----ESERCIZIO 4
/*
void concatena(const int* v1, const int* v2, int n1, int n2, int* v3){
    for (int i = 0; i < n1; ++i) {
        v3[i] = v1[i];
    }
    for (int i = 0; i < n2; ++i) {
        v3[i+n1] = v2[i];
    }
}
 */

//----ESERCIZIO 5
/*
void traslaVettore (int vett[], int n) {
    int a = vett[n-1];

    for (int i = n-1; i > 0; i--)
        vett[i] = vett[i-1];

    vett[0] = a;
}
 */

//----ESERCIZIO 6
/*
bool palindroma(const char stringa[]){
    int LL = 0;
    while(stringa[LL] != '\0')
        LL++;

    for(int i = 0; i < LL/2; i++){
        if(stringa[i] == stringa[LL-1-i])
            continue;
        else return false;
    }
    return true;
}
 */

int main() {
    //----ESERCIZIO 2
    /*
    unsigned const int LF = 6;
    double num[LF] = {1.3, 4.5, 2.4, 8.4, -3.14, -3.14};
    cout << "La posizione del primo minimo all'interno del vettore e':" << posMin(num, LF);
    */

    //----ESERCIZIO 3
    /*
    unsigned const int LF = 10;
    int num[10];

    cout << "Inserisci 10 elementi dell'array:\n";
    for (int i = 0; i < LF; ++i)
        cin >> num[i];
    cout << "La somma degli interi inseriti e` " << (pari(num, LF) ? "PARI" : "DISPARI");
    */

    //----ESERCIZIO 4
    /*
    unsigned const int LF1 = 2, LF2 = 3, LF3 = LF1 + LF2;
    int v1[LF1] =  {2, 6}, v2[LF2] = {3, 15, 4}, v3[LF3];
    concatena(v1, v2, LF1, LF2, v3);
    cout << "v3: ";
    for (int i = 0; i < LF3; ++i)
        cout << v3[i];
    */

    //----ESERCIZIO 5
    /*
    unsigned const int N = 6;
    int num[N], k;

    cout << "Inserire gli elementi del vettore:\n";
    for (int i = 0; i < N; ++i)
        cin >> num[i];
    cout << "Inserire il numero di passi di traslazione\n";
    cin >> k;
    for (int j = 0; j < k; j++)
        traslaVettore(num, N);
    cout << "Vettore risultante\n";
    for(int i = 0; i < N; i++)
        cout << num[i] << " ";
    */

    //----ESERCIZIO 6
    /*
    char stringa[40];
    cout << "Inserisci una parola:\n";
    cin >> stringa;
    if(palindroma(stringa))
        cout << "La parola e` palindroma";
    else
        cout << "La parola NON e` palindroma";
     */




    return 0;
}
