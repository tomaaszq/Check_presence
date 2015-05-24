#include "obecnosc.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;
int menu ()
{
    int k;
    cout << "W tym programie mozesz zrobic nastepujace rzeczy:" <<
            endl << "1.Dodaj studenta"<<endl<<"2.Sprawdz obecnosc"<<endl<<"3.Wyswietl obecnosc"<<endl<<"Inny:Zakoncz program"<<endl;
    cout << "Co chcesz zrobic? :";
    cin >> k;
    return k;
}

int main()
{
    Student s;
    Dziennik *d;
    d=new Dziennik ("E02-70cj");
    string n,i;
    int k,numer;
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
            cout << "Podaj nr zajec dla jakiego chcesz wyswietlic obecnosc: ";
            cin >> numer;
            d->pokaz_obecnosc(numer);
        }
    }
    while ((k==1)||(k==2)||(k==3));
    delete d;
}


