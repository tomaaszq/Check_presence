#ifndef OBECNOSC_H
#define OBECNOSC_H
#include <string>
#include <vector>
#include <array>
using namespace std;

class Student
{
    string nazwisko;
    string indeks;
    bool obecnosci[7];
    int *oceny[];
    int ile_ocen;

public:
    Student(Student& s);
    string czytaj_nazwisko ();
    string czytaj_indeks ();
    void wypelnij (string lastname,string index);
};

class Dziennik
{
public:
    void dodaj_studenta(Student s);
    void sprawdz_obecnosc();
    void dodaj_ocene(int numerIndeksu, int ocena);
    ~Dziennik();
};

#endif // OBECNOSC_H
