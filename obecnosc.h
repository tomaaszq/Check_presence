#ifndef OBECNOSC_H
#define OBECNOSC_H
#include <string>
using namespace std;

class Student
{
    string nazwisko;
    string indeks;
    bool obecnosci[7];
    int *oceny;
    int ile_ocen;
public:
    Student();
    void wypelnij(string lastname,string index);
    Student(Student& s);
    string czytaj_nazwisko ();
    string czytaj_indeks ();
    void dodaj_ocene(int ocena);
    void dodaj_obecnosc(int numer_zajec);
    void wypisz_oceny();
    void wypisz_obecnosc();
    ~Student();
};

class Dziennik
{
    Student *std;
    int ile_std;
public:
    Dziennik ();
    void dodaj_studenta(Student s);
    void sprawdz_obecnosc(int numer_zajec);
    void pokaz_obecnosc();
    void dodaj_ocene(string indeks, int ocena);
    void pokaz_oceny();
    ~Dziennik();
};

#endif // OBECNOSC_H
