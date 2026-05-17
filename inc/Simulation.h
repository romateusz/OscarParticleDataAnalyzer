#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include <string>
#include "Event.h"

// Struktura zarządzająca całą symulacją i zbiorem eventów
struct Simulation {
    // Wektor przechowujący wszystkie wczytane eventy
    std::vector<Event> events;
    Simulation();

    // Metoda wczytująca dane z pliku
    bool ReadFile(const std::string& fileName);

    // Szuka wartości min, mean, max bpar ze wszystkich wczytanych zderzeń
    void AnalyseBpar() const;
};

#endif