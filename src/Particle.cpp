#include "Particle.h"

Particle::Particle() : TR(), EP(), pdg(0), q(0) {}

Particle::Particle(const Vec4& tr_val, const Vec4& ep_val, int pdg_val, int q_val) 
    : TR(tr_val), EP(ep_val), pdg(pdg_val), q(q_val) {}

Particle Particle::operator+(const Particle& other) const {
    return Particle(TR + other.TR, EP + other.EP, pdg + other.pdg, q + other.q);
}

double Particle::M() const {
    return EP.MS();
}

double Particle::P() const {
    return EP.Mod();
}

bool Particle::operator<(const Particle& other) const {
    // Jeśli pdg jest mniejsze, zwraca true
    if (pdg < other.pdg) {
        return true;
    } 
    // Jeśli pdg są równe, sprawdza długość pędu (zwraca true >=)
    else if (pdg == other.pdg) {
        return P() >= other.P();
    }
    // W każdym innym przypadku false
    return false;
}

// Wypisywanie na ekran
std::ostream& operator<<(std::ostream& os, const Particle& p) {
    os << "PDG: " << p.pdg << " | Ladunek (q): " << p.q << "\n"
       << "  Wektor TR: " << p.TR
       << "  Wektor EP: " << p.EP;
    return os;
}