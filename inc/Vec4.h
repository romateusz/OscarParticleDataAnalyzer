#ifndef VEC4_H
#define VEC4_H

#include <iostream>

// Struktura reprezentująca czterowektor
struct Vec4 {
    double et;
    double x;
    double y;
    double z;

    // Konstruktory
    Vec4();
    Vec4(double et_val, double x_val, double y_val, double z_val);
    Vec4(const Vec4& other);    // Konstruktor kopiujący

    // Przeciążony operator dodawania
    Vec4 operator+(const Vec4& other) const;

    // Metoda licząca długość wektora przestrzennego (x, y, z)
    double Mod() const;

    // Metoda licząca masę cząstki ze wzoru: sqrt(et^2 - x^2 - y^2 - z^2)
    double MS() const;

    // Zaprzyjaźniony operator strumieniowy << 
    friend std::ostream& operator<<(std::ostream& os, const Vec4& v);
};

#endif