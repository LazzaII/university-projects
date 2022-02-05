#include "compito.h"
//UTILITÀ
bool Memory::controllaTipo(const char tipo) {
    char tipi[5] = {'G', 'C', 'S', 'P', 'T'};
    for (int i = 0; i < 5; ++i) {
        if(tipi[i] == tipo) return true;
    }
    return false;
}

//PRIMA PARTE

/*
 * Costruttore che inizializza la matrice NxN, e gli altri attributi della classe
 * @param dim dimensione da dare alla matrice
 */
Memory::Memory(const int dim) {
    LF = (dim < 2 ? 2 : dim); //se la dimensione inserita è minore di due viene inserita data una dimensione di default
    punteggio = 0;

    tessere = new char *[LF]; //Inizializzazione della matrice
    for (int i = 0; i < LF; ++i)
        tessere[i] = new char[LF];

    for (int i = 0; i < LF; ++i) //Valorizzazione iniziale della matrice
        for (int j = 0; j < LF; ++j)
            tessere[i][j] = '-';
}

/*
 * Ridefinizione dell'operatore di output per il tipo memory
 * @return out
 */
ostream &operator<<(ostream &out, const Memory &m) {
    for (int i = 0; i < m.LF; ++i) {
        for (int j = 0; j < m.LF; ++j) {
            out << m.tessere[i][j] << (j == m.LF-1 ? "" : " ");
        }
        out << "\n";
    }
    out << "\nPunteggio: " << m.punteggio << '\n';
    return out;
}

/*
 * Funzione 'inserisci' che inserisce una coppia di tessere nel memory
 * @param tipo
 * @param riga1
 * @param colonna1
 * @param riga2
 * @param colonna2
 */
void Memory::inserisci(const char tipo, const int riga1, const int colonna1, const int riga2, const int colonna2) {
    if(!controllaTipo(tipo)) return; //controllo del tipo
    if(riga1 > LF-1 || colonna1 > LF-1 || riga2 > LF-1 || colonna2 > LF-1 || (riga1 == riga2 && colonna1 == colonna2)) return; //controllo delle righe e colonne
    if(tessere[riga1][colonna1] != '-' || tessere[riga2][colonna2] != '-' ) return; //controllo se le due posizioni sono già occupate

    tessere[riga1][colonna1] = tipo;
    tessere[riga2][colonna2] = tipo;
}

/*
 * Funzione 'riassumi' che stampa il numero di coppie presenti nel memory, se non c'è nessuna coppia stampa VITTORIA!
 */
void Memory::riassumi() {
    int count[5] = {0,0,0,0,0};
    bool vinto = true;
    for (int i = 0; i < LF; ++i) {
        for (int j = 0; j < LF; ++j) {
            switch (tessere[i][j]) {
                case 'G':
                    count[0]++;
                    break;
                case 'C':
                    count[1]++;
                    break;
                case 'S':
                    count[2]++;
                    break;
                case 'P':
                    count[3]++;
                    break;
                case 'T':
                    count[4]++;
                    break;
                default:
                    break;
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        if(count[i] > 1){ //se non sono presenti dati oppure se è presente una carta sola
            vinto = false;
            break;
        }
    }
    if(vinto) cout << "VITTORIA!";
    else {
        cout << "Gatto: " << count[0]/2;
        cout << "\nCane: " << count[1]/2;
        cout << "\nSerpente: " << count[2]/2;
        cout << "\nPavone: " << count[3]/2;
        cout << "\nTigre: " << count[4]/2;
    }
    cout << '\n';
}

/*
 * Funzione 'flip' che controlla se le tessere inserite dall'utente sono uguali, in caso positivo assegna un punto in caso negativo ne perde uno
 * @return bool:
 *      true se viene assegnato il punto
 *      false in tutti gli altri casi
 */
bool Memory::flip(const int riga1, const int colonna1, const int riga2, const int colonna2) {
    //controllo se le due posizioni sono già occupate e se le righe e le colonne non sono uguali oppure vanno oltre la dimensione
    if(riga1 > LF-1 || colonna1 > LF-1 || riga2 > LF-1 || colonna2 > LF-1 || (riga1 == riga2 && colonna1 == colonna2)) return false;
    if(tessere[riga1][colonna1] == '-' || tessere[riga2][colonna2] == '-' ) return false;

    if(tessere[riga1][colonna1] == tessere[riga2][colonna2]){
        punteggio++;
        tessere[riga1][colonna1] = '-';
        tessere[riga2][colonna2] = '-';
        return true;
    }
    else {
        punteggio--;
        return false;
    }
}

/*
 * Ridefinizione dell'operatore ~ come distruttore della funzione
 */
void Memory::operator~() {
    for (int i = 0; i < LF; ++i)
        delete [] tessere[i];

    delete [] tessere;
}

//SECONDA PARTE
/*
 * Costruttore di copia che assegna il tabellone di m all'oggetto richiamato, però con il punteggio a 0
 */
Memory::Memory(const Memory &m) {
    if(this == &m) //Se sono già lo stesso oggetto non ha senso richiamare il costruttore
        return;

    this->LF = m.LF;
    this->punteggio = 0;


    this->tessere = new char *[this->LF]; //Inizializzazione della matrice
    for (int i = 0; i < LF; ++i)
        this->tessere[i] = new char[this->LF];

    for (int i = 0; i < LF; ++i) //Valorizzazione della matrice uguale a quelli di m
        for (int j = 0; j < LF; ++j)
            this->tessere[i][j] = m.tessere[i][j];

}

/*
 * Ridefinizione operatore +
 * @return Memory
 *      Ritorna un memory formato inizialmente dal memory su cui viene richiamato e successivamente vengono riempite
 *      le sue celle vuote con una tessera piena nella stessa posizione di m
 */
Memory Memory::operator+(const Memory &m) {
    Memory nuovo(*this);

    //Assegnazione se sono della stessa dimensione
    if(nuovo.LF == m.LF){
        for (int i = 0; i < nuovo.LF; ++i) {
            for (int j = 0; j < nuovo.LF; ++j) {
                if(nuovo.tessere[i][j] == '-' && m.tessere[i][j] != '-')
                    nuovo.tessere[i][j] = m.tessere[i][j];
            }
        }
    } // Assegnazione se hanno dimensione differente
    else if(nuovo.LF >= m.LF) {
        int diff = nuovo.LF - m.LF;
        for (int i = diff; i < nuovo.LF-diff; ++i) {
            for (int j = diff; j < nuovo.LF-diff; ++j) {
                if(nuovo.tessere[i][j+diff] == '-' && m.tessere[i][j] != '-')
                    nuovo.tessere[i][j+diff] = m.tessere[i][j];
            }
        }
    }
    else {
        int diff = m.LF - nuovo.LF;
        for (int i = 0; i < nuovo.LF; ++i) {
            for (int j = 0; j < nuovo.LF; ++j) {
                if(nuovo.tessere[i][j] == '-' && m.tessere[i][j+diff] != '-')
                    nuovo.tessere[i][j] = m.tessere[i][j+diff];
            }
        }
    }

    return nuovo;
}

/*
 * Ridefinizione operatore >>
 * @return Memory
 *      Ritorna il memory su cui è stato chiamato ruotato di un angolo pari a i*π/2
 */
Memory& Memory::operator>>(int i) {
    if(i&4 == 0) return *this; //se è un multiplo di quatto ritorna lo stesso oggetto perché la rotazione è di 360*
    int r = i%4;
    if(r < 0){
       r += 4;
    }

    for(int l = 0; l < r; l++){
        Memory tmp(*this);
        for (int j = 0; j < LF; ++j) {
            for (int k = 0; k < LF; ++k) {
                tessere[j][k] = tmp.tessere[LF - k - 1][j];
            }
        }
    }

    return *this;
}
