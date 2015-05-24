#include "obecnosc.h"
#include <iostream>
#include <string>
using namespace std;
Student::Student()
{
    ile_ocen=0;
    for (int i=0; i<7; i++)
    {
        obecnosci[i]=0;
    }
}

void Student::wypelnij(string name,string index)
{
    indeks=index;
    nazwisko=name;
}
void Student::dodaj_ocene(int Oc)
{
    int *oceny2;
    if (ile_ocen==0)
    {
        ile_ocen++;
        oceny = new int [1];
        oceny[0]=Oc;
    }
    else
    {
        ile_ocen++;
        oceny2 = new int [ile_ocen];
        for (int i=0; i<ile_ocen-1;i++)
        {
            oceny2[i]=oceny[i];
        }
        oceny2[ile_ocen-1]=Oc;
        delete []oceny;
        oceny=oceny2;
    }
}
 Student::Student(Student& s)
 {
     nazwisko=s.nazwisko;
     indeks=s.indeks;
     ile_ocen=s.ile_ocen;
     for (int i=0;i<7;i++)
     {
     obecnosci[i]=s.obecnosci[i];
 }
     if (ile_ocen != 0)
     {
     oceny=new int [ile_ocen];
     for (int i=0;i<ile_ocen;i++)
     {
         oceny[i]=s.oceny[i];
     }
     }
 }


string Student::czytaj_indeks()
{
    return indeks;
}
string Student::czytaj_nazwisko()
{
    return nazwisko;
}
void Student::dodaj_obecnosc(int numer_zajec)
{
    int k;
    cout << "Czy student " << nazwisko << " jest obecny? 0-nie, 1-tak" << endl;
    cin >> k;
    obecnosci[numer_zajec-1]=k;
}
void Student::wypisz_oceny()
{
    cout << "Oceny studenta " << nazwisko << ", " << indeks << " :";
    for (int i=0; i<ile_ocen; i++)
    {
        cout << "  " << oceny[i] ;
    }
    cout << endl;
}
void Student::wypisz_obecnosc()
{
    cout << "Obecnosc studenta " << nazwisko << ", " << indeks << ":";
    for (int i=0;i<7;i++)
    {
        cout << "  " << obecnosci[i];
    }
}
Student::~Student()
{
    delete []oceny;
}

Dziennik::Dziennik()
{
    ile_std=0;
}
void Dziennik::dodaj_studenta(Student s)
{
    Student *std1;
    if(ile_std==0)
    {
        ile_std++;
        std=new Student [1];
        std[0]=s;
    }
    else
    {
        ile_std++;
        std1=new Student [ile_std];
                for (int i=0; i<ile_std-1;i++)
                {
                    std1[i]=std[i];
                }
                std1[ile_std-1]=s;
                delete []std;
                std=std1;
    }
}

void Dziennik::sprawdz_obecnosc(int numer)
{
for(int n=0;n<ile_std;n++)
{
   std[n].dodaj_obecnosc(numer);
}
}
void Dziennik::pokaz_obecnosc()
{
   for (int n=0;n<ile_std;n++)
   {
      std[n].wypisz_obecnosc();
      cout << endl;
   }
}
void Dziennik::dodaj_ocene(string indeks, int ocena)
{
    int tmp=0;
    for (int n=0;n<ile_std;n++)
    {
       if(std[n].czytaj_indeks() == indeks)
       {
       std[n].dodaj_ocene(ocena);
       tmp=1;
       }
       }
    if(tmp==0)
    {
        cout << "Nie dodano oceny, podano zly nr indeksu!!!" << endl;
    }
}
void Dziennik::pokaz_oceny()
{
    for (int n=0;n<ile_std;n++)
    {
       std[n].wypisz_oceny();
    }
}

Dziennik::~Dziennik()
{
    delete[]std;
}
