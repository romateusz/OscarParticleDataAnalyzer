#ifndef PARTICLE_H
#define PARTICLE_H

#include "Vec4.h"
#include <iostream>

// Struktura reprezentująca pojedynczą cząstkę
struct Particle {
    Vec4 TR; // Czas i wektor pozycji
    Vec4 EP; // Energia i wektor pędu
    int pdg; // Kod typu cząstki
    int q;   // Ładunek elektryczny

    // Konstruktory
    Particle();
    Particle(const Vec4& tr_val, const Vec4& ep_val, int pdg_val, int q_val);

    // Przeciążony operator dodawania
    Particle operator+(const Particle& other) const;

    // Metoda zwracająca masę z czterowektora EP
    double M() const;

    // Metoda zwracająca długość 3-wymiarowego wektora pędu z czterowektora EP
    double P() const;

    // Przeciążony operator mniejszości
    bool operator<(const Particle& other) const;

    // Zaprzyjaźniony operator strumieniowy
    friend std::ostream& operator<<(std::ostream& os, const Particle& p);
};

#endif