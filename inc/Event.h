#ifndef EVENT_H
#define EVENT_H

#include <vector>
#include <iostream>
#include "Particle.h"

// Struktura obsługująca pojedyncze zderzenie
struct Event {
    // Wektor przechowujący obiekty typu Particle
    std::vector<Particle> particles;
    
    // Parametr zderzenia
    double bpar;

    // Konstruktor bezargumentowy
    Event();

    // Metoda zwracająca sumę składowych pędu wszystkich cząstek 
    double SumP(int dim) const;

    // Metoda sortująca wektor cząstek
    void Sort();

    // Metoda wypisująca na ekran podsumowanie eventu i listę cząstek
    void List() const;

    // Zaprzyjaźniony operator strumieniowy >> do wczytywania danych z pliku
    friend std::istream& operator>>(std::istream& is, Event& ev);
};

#endif