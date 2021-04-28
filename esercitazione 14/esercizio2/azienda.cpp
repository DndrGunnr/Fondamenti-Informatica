/*Un’azienda ha otto dipartimenti. I dipendenti che lavorano in ciascun dipartimento possono
appartenere ad una di cinque diverse classi stipendiali. Allo scopo di gestire i dipendenti dell’azienda,
si realizzi in linguaggio C++ la classe Dipendenti avente iseguenti attributi: un array _s di cinque numeri
reali per rappresentare lo stipendio corrispondente a ciascuna delle cinque classi stipendiali e una
matrice di numeri interi _D di otto righe e cinque colonne i cui elementi rappresentano, per ciascun
dipartimento, il numero di dipendenti appartenenti a ciascuna classe stipendiale. Se, ad esempio,
l’elemento nella terza riga e quarta colonna di _D valesse 10, significherebbe che nel terzo
dipartimento lavorano 10 dipendenti appartenenti alla quarta classe stipendiale. Si implementino,
inoltre, i seguenti metodi: */
 #include <iostream>
 using namespace std;

 class Dipendenti{
     private:
        float _s[5];
        //matrice a 5 colonne 8 righe, le righe rappresentano i dipartimenti
        // le colonne rappresentano la classe stipendiale di tale dipartimento
        //vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
        int _D[8][5];
        //costruttore di default
     public:
        Dipendenti();
        //costruttore  con parametri
        Dipendenti(float v[5],int m[8][5]);
        //costruttore di copia
        Dipendenti(Dipendenti& p);
        //distruttore
        ~Dipendenti();
        //selettori
        float* get_s() const;
        int get_d(int h, int k) const;
        //modificatori
        void set_s(float v[5]);
        void set_d(int m[5][8]);
        //operatori
        int totaleDipendenti();
        /* Il metodo estremiStipendio che calcoli e restituisca come parametri di uscita (ovvero passati per
        riferimento) gli indici dei due dipartimenti (due numeri interi) per i quali l’azienda spende
        l ’ammontare massimo e l’ammontare minimo per gli stipendi dei dipendenti. Il metodo non
        restituisce alcun valore di ritorno. */
        void estremiStipendio();



 };

 Dipendenti::Dipendenti()
 {
    for(int i=0; i<5; i++)
        _s[i]=0.0;
    for (int i=0; i<8 ;i++)
    {
        for(int j=0; j<5 ;j++)
            _D[i][j]=0;
    }
 }

Dipendenti::Dipendenti(float v[5], int m [8][5])
{
    for(int i=0; i<5; i++)
        _s[i]=v[i];
    for(int i=0; i<8; i++)
    {
        for (int j = 0; j < 5; j++)
            _D[i][j]= m[i][j];    
        
    }

}

Dipendenti::Dipendenti(Dipendenti& p)
{
    for (int i=0; i<8 ;i++)
    {
        for (int j=0; j<5; j++)
            _D[i][j]=p._D[i][j];
    }

    for(int i=0;i<5 ;i++)
        _s[i]=p._s[i];

}

Dipendenti::~Dipendenti()
{
    
}

 int main()
{
    Dipendenti a;
    Dipendenti b(a);
    return 0;
}

