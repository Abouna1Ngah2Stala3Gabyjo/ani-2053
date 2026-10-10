#include <iostream>
#include <string>

int main() {
    long long S = 0;
    int n = 0;
    if (!(std::cin >> S)) {
        return 0;
    }
    if (!(std::cin >> n)) {
        n = 0;
    }

    long long memoire = 0, flux = 0, refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string nom;
        long long frequence = 0, canaux = 0, bits = 0, duree = 0, fichier = 0;
        std::cin >> nom >> frequence >> canaux >> bits >> duree >> fichier;

        if (bits != 8 && bits != 16 && bits != 24 && bits != 32) {
            std::cout << nom << " REFUSE\n";
            ++refuses;
            continue;
        }

        long long brut = frequence * canaux * (bits / 8) * duree / 1000;
        long long pourcent = (brut > 0) ? fichier * 100 / brut : 0;

        if (brut > S) {
            ++flux;
            std::cout << nom << ' ' << brut << ' ' << pourcent << " FLUX\n";
        } else {
            memoire += brut;
            std::cout << nom << ' ' << brut << ' ' << pourcent << " MEMOIRE\n";
        }
    }

    std::cout << "MEMOIRE " << memoire << '\n';
    std::cout << "FLUX " << flux << '\n';
    std::cout << "REFUSES " << refuses << '\n';

    return 0;
}