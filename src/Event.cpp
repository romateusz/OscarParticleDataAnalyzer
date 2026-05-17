#include "Event.h"
#include <algorithm>
#include <string>

Event::Event() : bpar(0.0) {}

double Event::SumP(int dim) const {
    double sum = 0.0;
    for (const auto& p : particles) {
        if (dim == 1) {
            sum += p.EP.x;
        } else if (dim == 2) {
            sum += p.EP.y;
        } else if (dim == 3) {
            sum += p.EP.z;
        }
    }
    return sum;
}

void Event::Sort() {
    std::sort(particles.begin(), particles.end());
}

void Event::List() const {
    std::cout << "+ Zdarzenie z Bpar = " << bpar << ", ma " << particles.size() << " cząstek\n";
    for (const auto& p : particles) {
        std::cout << " | " << p.pdg << " " << p.P() << "\n";
    }
}
std::istream& operator>>(std::istream& is, Event& ev) {
    std::string hash, event_str, out_str;
    int event_num, N;

    // Próbuje wczytać pierwszy znak nagłówka (czyli #). 
    // jeśli się nie uda, znaczy to, że dotarł do końca pliku.
    if (!(is >> hash)) {
        return is; 
    }

    // Wczytuje resztę nagłówka eventu: "event {numer} out {N}"
    is >> event_str >> event_num >> out_str >> N;

    // Czyści wektor cząstek przed wczytaniem nowego eventu
    ev.particles.clear();

    // Pętla wczytująca dokładnie N cząstek
    for (int i = 0; i < N; ++i) {
        double t, x, y, z, m, e, px, py, pz;
        int pdg, id, q;

        is >> t >> x >> y >> z >> m >> e >> px >> py >> pz >> pdg >> id >> q;

        // Tworzy obiekty potrzebne do Particle
        Vec4 TR(t, x, y, z);
        Vec4 EP(e, px, py, pz);

        // Dodaje wygenerowaną cząstkę do wektora
        ev.particles.push_back(Particle(TR, EP, pdg, q));
    }

    // Po pętli wczytuje stopkę końcową eventu:
    std::string end_str, impact_str;
    int zero;
    
    is >> hash >> event_str >> event_num >> end_str >> zero >> impact_str >> ev.bpar;

    // Doczytuje resztę linijki, aby strumień był gotowy na wczytanie kolejnego eventu w nowej linii.
    std::string rest_of_line;
    std::getline(is, rest_of_line);

    return is;
}