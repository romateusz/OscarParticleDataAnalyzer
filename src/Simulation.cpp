#include "Simulation.h"
#include <fstream>
#include <iostream>

Simulation::Simulation() {}

bool Simulation::ReadFile(const std::string& fileName) {
    // Podpina strumień wejściowy pod plik
    std::ifstream file(fileName);

    // Sprawdza, czy plik na pewno istnieje i się otworzył
    if (!file.is_open()) {
        return false;
    }

    // Odrzuca pierwsze 3 linii globalnego nagłówka pliku
    std::string line;
    for (int i = 0; i < 3; ++i) {
        std::getline(file, line);
    }

    // Pętla odczytu. Tworzy pusty event, a potem używa na nim operatora >>
    // Pętla będzie działać dopóki operator >> zwraca "dobry" strumień.
    Event ev;
    while (file >> ev) {
        events.push_back(ev);
    }

    // Zamyka plik po skończonej pracy
    file.close();
    return true;
}

void Simulation::AnalyseBpar() const {
    if (events.empty()) {
        std::cout << "Brak danych do analizy.\n";
        return;
    }

    // Inicjuje minimum i maksimum pierwszym elementem
    double min_b = events[0].bpar;
    double max_b = events[0].bpar;
    double sum_b = 0.0;

    for (const auto& ev : events) {
        // Sprawdza minimum
        if (ev.bpar < min_b) {
            min_b = ev.bpar;
        }
        // Sprawdza maksimum
        if (ev.bpar > max_b) {
            max_b = ev.bpar;
        }
        // Sumuje do średniej
        sum_b += ev.bpar;
    }

    double avg_b = sum_b / events.size();

    std::cout << " Bpars: [ min_b: " << min_b << ", mean_b: " << avg_b << ", maxb: " << max_b << " ]\n";
}