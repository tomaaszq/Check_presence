#include "obecnosc.h"
#include <iostream>
#include <string>
using namespace std;
int menu ()
{
    int k;
    cout << "W tym programie mozesz zrobic nastepujace rzeczy:" <<
            endl << "1.Dodaj studenta"<<endl<<"2.Sprawdz obecnosc"<<endl<<"3.Wyswietl obecnosc"<<endl<<"4.Dodaj Ocene"<<endl<<"5.Wyswietl oceny"<<endl<<"Inny:Zakoncz program"<<endl;
    cout << "Co chcesz zrobic? :";
    cin >> k;
    return k;
}

int main()
{
    Student s;
    Dziennik *d;
    d=new Dziennik ();
    string n,i,indeks;
    int k,numer,ocena;
    do
    {
        k=menu ();
        switch(k)
        {
        case 1:
            cout << "Wpisz nazwisko i indeks studenta:";
            cin >> n;
            cin >> i;
            s.wypelnij(n,i);
            d->dodaj_studenta(s);
            break;
        case 2:
            cout << endl << "Podaj nr zajec dla ktorych chcesz sprawdzic obecnosc: " << endl;
            cin >> numer;
            d->sprawdz_obecnosc(numer);
            break;
        case 3:
            d->pokaz_obecnosc();
            break;
        case 4:
            cout << "Jakiemu studentowi(nr indeksu) chcesz wpisac ocene?"<< endl;
            cin >> indeks;
            cout << "Jaką ocenę chcesz mu wpisac?" << endl;
            cin >> ocena;
            d->dodaj_ocene(indeks,ocena);
            break;
        case 5:
            d->pokaz_oceny();
            break;
        }
    }
    while ((k==1)||(k==2)||(k==3)||(k==4)||(k==5));
    delete d;
}


