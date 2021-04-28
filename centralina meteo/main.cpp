//esercizio 1, esercitazione 21/04/2021
#include <iostream>
using namespace std;

class Rilevamento
{
public:
    //metodi
    //costruttori
    Rilevamento();
    Rilevamento(float t, float p);
    Rilevamento(float dati[2]);
    Rilevamento(const Rilevamento& r);
    //distruttori
    ~Rilevamento();
    //selettori
    float get_temperatura() const;
    float get_pressione() const;
    // modificatori
    void set_pressione(float p);
    void set_temperatura(float t);
private:
    //attributi
    float _temperatura;
    float _pressione;
};

Rilevamento::Rilevamento()
{
    _temperatura=0.0;
    _pressione=0.0;
    cout<<"questo e' il costruttore di default della classe rilevamento"<<endl;
}

Rilevamento::Rilevamento(float t, float p)
{
    _temperatura=t;
    _pressione=p;
    cout<<"questo e' il costruttore con parametri della classe rilevamento"<<endl;
}

Rilevamento::Rilevamento(float dati[2])
{
    _temperatura=dati[0];
    _pressione=dati[1];
    cout<<"secondo costruttore con parametri della classe rilevamento"<<endl;
}

Rilevamento::~Rilevamento()
{

    cout<<"distruttore della classe rilevamento"<<endl;
}

Rilevamento::Rilevamento(const Rilevamento& r)
{
    _temperatura=r._temperatura;
    _pressione=r._pressione;
    cout<<"costruttore di copia"<<endl;
    
}
float Rilevamento::get_temperatura() const
{
    return _temperatura;
}

float Rilevamento::get_pressione() const
{
    return _pressione;
}

void Rilevamento::set_temperatura(float t)
{
    _temperatura=t;
}

void Rilevamento::set_pressione(float p)
{
    _pressione=p;
}

void Stampa_rilevamento(Rilevamento a)
{
    float t=a.get_temperatura(),p=a.get_pressione();
    cout<<"Rilevamento: temperatura= "<<t<<" C ,pressione= "<<p<<" hpa"<<endl;
}

void Leggi_rilevamento(Rilevamento& a)
{
    float t,p;
    cout<<"inserisci il valore della temperatura e della pressione"<<endl;
    cin>>t>>p;
    a.set_temperatura(t);
    a.set_pressione(p);
    
}

int main()
{
    Rilevamento r1;
    Rilevamento r2(20.0, 1000.0);
    Rilevamento r4;
    float ril[2]={15.0, 1010.0};
    Rilevamento r3(ril);
    Stampa_rilevamento(r1);
    Stampa_rilevamento(r2);
    Stampa_rilevamento(r3);
    Leggi_rilevamento(r4);
    return 0;
}