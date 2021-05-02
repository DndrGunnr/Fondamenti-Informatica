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
 #include <fstream>
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
        //costruttori
        Dipendenti();
        Dipendenti(float v[5],int m[8][5]);
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

int Dipendenti::totaleDipendenti()
{
    int somma_dipendenti=0;
    for (int i=0; i<8; i++)
    {
        for(int j=0; j<5; j++)
            somma_dipendenti+=_D[i][j];
    }
    return somma_dipendenti;
}

void Dipendenti::estremiStipendio()
{
    double costo_max=_s[0]*_D[0][0], costo_min=_s[0]*_D[0][0];
    int dipartimento_max_R=1, dipartimento_max_C=1, dipartimento_min_R=1, dipartimento_min_C=1; 
    for (int i=0; i<8; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(costo_max<(_s[j]*_D[i][j]))
            {   
                costo_max=_s[j]*_D[i][j]; 
                dipartimento_max_R=i+1;
                dipartimento_max_C=j+1;
            }
            if(costo_min>(_s[j]*_D[i][j]))
            {
                costo_min=_s[j]*_D[i][j];
                dipartimento_min_C=j+1;
                dipartimento_min_R=i+1;
            }
        }
    }
    cout<<"il dipartimento più costoso ha indice: "<<dipartimento_max_R<<" "<<dipartimento_min_C<<endl;
    cout<<"con una spesa di: "<<costo_max<<endl;
    cout<<"il dipartimento meno costoso ha indice: "<<dipartimento_min_R<<" "<<dipartimento_min_R<<endl;
    cout<<"con una spesa di: "<<costo_min<<endl;

}

 int main()
{
    int stp[5];
    float Dip[8][5];
    Dipendenti a;
    Dipendenti b(a);
    return 0;
}

