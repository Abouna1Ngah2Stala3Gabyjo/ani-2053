#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long long D = 0, C = 0;
    if (!(std::cin >> D >> C)) {
        return 0;
    }

    int n = 0;
    if (!(std::cin >> n)) {
        n = 0;
    }

    std::vector<long long> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
    }

    long long voixMax = 0, retardMax = 0, coupes = 0;
    long long finPrecedent = 0;
    int p = 0;  // première lecture encore active

    for (int i = 0; i < n; ++i) {
        // Voix : lectures j <= i avec t_j + D > t_i (fin exclue).
        // Les instants sont triés, donc les fins aussi : un seul pointeur suffit.
        while (p < i && t[p] + D <= t[i]) {
            ++p;
        }
        long long voix = i - p + 1;

        // Chargements enchaînés, sans superposition.
        long long debut = (i == 0) ? t[i] : std::max(t[i], finPrecedent);
        long long fin = debut + C;
        long long retard = fin - t[i];
        finPrecedent = fin;

        // Une seule voix rejouée : coupée si la suivante commence avant la fin.
        bool coupe = (i + 1 < n) && (t[i + 1] < t[i] + D);
        if (coupe) ++coupes;

        voixMax = std::max(voixMax, voix);
        retardMax = std::max(retardMax, retard);

        std::cout << t[i] << ' ' << voix << ' ' << retard << ' '
                  << (coupe ? "COUPE" : "ENTIER") << '\n';
    }

    std::cout << "VOIX_MAX " << voixMax << '\n';
    std::cout << "RETARD_MAX " << retardMax << '\n';
    std::cout << "COUPES " << coupes << '\n';

    return 0;
}