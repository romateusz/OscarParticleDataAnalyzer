# Instrukcja kompilacji i uruchomienia programu

## 1. Kompilacja

Aby skompilować program, należy przekazać kompilatorowi wszystkie pliki implementacyjne (`.cpp`).

Otwórz terminal w **głównym folderze projektu** (tam, gdzie znajdują się foldery `src` oraz `inc`), wpisz poniższe polecenie i wciśnij Enter:

```bash
g++ src/main.cpp src/Vec4.cpp src/Particle.cpp src/Event.cpp src/Simulation.cpp -I inc -static -o symulator
```

*Użycie flagi: -I inc informuje kompilator, w którym folderze znajdują się pliki nagłówkowe.*

*Użycie flagi: -static było u mnie wymagane, w celu zapobiegnięcia błędowi dołączenia bibliotek standardowych C++ (DLL) podczas kompilacji.*

## 2. Uruchomienie

Przed uruchomieniem upewnij się, że plik wejściowy z danymi (particle_lists.oscar) znajduje się w katalogu data.

Aby uruchomić program, wpisz w terminalu:

na systemie windows:

```bash
.\symulator.exe
```

Na systemie Linux / macOS:

```bash
./symulator
```
