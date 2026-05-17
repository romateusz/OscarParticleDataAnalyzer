#include <iostream>
#include <string>
#include "Simulation.h"

int main() {
    Simulation sim;
    
    std::string fileName = "particle_lists.oscar";
    std::cout << "Rozpoczynam wczytywanie danych z pliku: " << fileName << "\n";

    if (!sim.ReadFile("data/" + fileName)) {
        std::cerr << "Nie udalo sie otworzyc pliku: " << fileName << "\n";
        return 1; 
    }

    if (!sim.events.empty()) {
        std::cout << "\nWyświetlenie pierwszego eventu:\n\n";
        sim.events[0].List();
        sim.events[0].Sort();
        std::cout << "\nWyświetlenie pierwszego eventu (po sortowaniu)\n\n";
        sim.events[0].List();
    }
    else {
        std::cout << "Plik zostal wczytany, ale nie znaleziono w nim zadnych eventow.\n";
    }

    std::cout << "Analiza bpar:\n";
    sim.AnalyseBpar();

    return 0;
}