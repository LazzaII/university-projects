class Cinema {

private:
    //Var
    static const int FILE_MAX = 26, POSTI_MAX = 9;
    char nome_cinema[31];
    bool schema_posti[FILE_MAX][POSTI_MAX];
    int file;
    int posti;

public:
    //Constructor
    Cinema (int , int , char[] );

    //Functions
    bool prenota (const char , const int );
    bool cancella(const char, const int);
    void stampa();
    int quantiLiberi();
    bool prenotaAdiacenti(const int);
};


