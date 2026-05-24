# Instrukcja kompilacji i uruchomienia programu

## Informacje o projekcie

Analizator danych wyjściowych z symulatora zderzeń jądrowych (SMASH). Program wczytuje, strukturyzuje i przetwarza wyniki symulacji zapisane w formacie tekstowym `.oscar`.

## Główne funkcjonalności:
* **Parsowanie plików:** Wczytywanie i podział strumienia danych na bloki zdarzeń (eventów) oraz występujące po sobie, przypisane do nich cząstki.
* **Reprezentacja obiektowa:** Mapowanie wczytanych danych na struktury C++ (`Vec4` dla czterowektorów, `Particle` dla cząstek, `Event` dla całych zderzeń).
* **Obliczenia kinematyczne:** Wyznaczanie masy cząstki oraz długości jej pędu na podstawie czterowektorów czasu-pozycji (TR) i energii-pędu (EP).
* **Sortowanie danych:** Wykorzystanie przeciążonych operatorów relacyjnych do sortowania cząstek (względem numeru PDG oraz pędu).
* **Analiza zderzeń:** Agregacja danych z całej symulacji w celu wyznaczenia minimalnej, maksymalnej oraz średniej wartości parametru zderzenia (`bpar`).

## Struktura katalogów

Przed rozpoczęciem kompilacji należy zapewnić następującą strukturę katalogów:

```
.
├── data/
│    └── particle_lists.oscar
├── inc/
│    └── (pliki nagłówkowe .h)
└── src/
     └── (pliki źródłowe .cpp)
 ```

## Kompilacja

Aby skompilować program, należy przekazać kompilatorowi wszystkie pliki implementacyjne (`.cpp`).

W tym celu należy uruchomić terminal w **głównym folderze projektu** i wykonać poniższe polecenie:

```bash
g++ src/main.cpp src/Vec4.cpp src/Particle.cpp src/Event.cpp src/Simulation.cpp -I inc -static -o symulator
```

*Użycie flagi: -I inc informuje kompilator, w którym folderze znajdują się pliki nagłówkowe.*

*Użycie flagi: -static było u mnie wymagane, w celu zapobiegnięcia błędowi dołączenia bibliotek standardowych C++ (DLL) podczas kompilacji.*

## Uruchomienie

Przed uruchomieniem programu wymagane jest sprawdzenie obecności pliku wejściowego (`particle_lists.oscar`) w katalogu `data/`.

Uruchomienie skompilowanej aplikacji przeprowadza się poprzez wykonanie w terminalu odpowiedniego polecenia:

Na systemie Windows:

```bash
.\symulator.exe
```

Na systemie Linux / macOS:

```bash
./symulator
```
