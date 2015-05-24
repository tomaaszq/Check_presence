#include "obecnosc.h"
#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

void Student::wypelnij(string name,string index)
{
    indeks=index;
    nazwisko=name;
}
string Student::czytaj_indeks()
{
    return indeks;
}
string Student::czytaj_nazwisko()
{
    return nazwisko;
}
void Dziennik::dodaj_studenta(Student s)
{
    array <bool,15>tab;
    for(int i=0;i<15;i++)
    {
     tab[i]=false;
    }
    studenci.push_back(s);
    obecnosci.push_back(tab);
}
void Dziennik::sprawdz_obecnosc(int numer)
{
    char tmp;
for(int n=0;n<studenci.size();n++)
{
    string nazw;
    nazw=studenci[n].czytaj_nazwisko ();
    cout << "Wpisz O-obecnosc N-nieobecnosc dla studenta: " << nazw << endl;
    cin >> tmp;
    if (tmp=='O')
    {
        obecnosci[n][numer]=true;
    }
}
}
void Dziennik::pokaz_obecnosc(int numer_zajec)
{
    string tmp,ind,naz;
    for (int n=0;n<studenci.size();n++)
    {
        ind = studenci[n].czytaj_indeks ();
        naz = studenci[n].czytaj_nazwisko();
        if (obecnosci[n][numer_zajec]==true)
        {
            tmp="Ob";
        }
        else
        {
            tmp="Nb";
        }
        cout << tmp << "   " << ind << "   " << naz << endl;
    }
}
Dziennik::Dziennik(string kod_gr)
{
    kod_grupy=kod_gr;
}
Dziennik::~Dziennik()
{
    studenci.clear();
    obecnosci.clear();
}
