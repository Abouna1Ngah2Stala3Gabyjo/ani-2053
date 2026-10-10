#include <iostream>
#include <string>

struct Format {
    const char* nom;
    long long octets;
    bool couleur;
    bool transparence;
    bool flottants;
};

static const Format FORMATS[] = {
    {"GRAY8",    1,  false, false, false},
    {"GRAY_A16", 2,  false, true,  false},
    {"RGB24",    3,  true,  false, false},
    {"RGBA32",   4,  true,  true,  false},
    {"RGB96F",   12, true,  false, true},
    {"RGBA128F", 16, true,  true,  true},
};

static const Format* cherche(const std::string& nom) {
    for (const Format& f : FORMATS) {
        if (nom == f.nom) return &f;
    }
    return nullptr;
}

int main() {
    long long w = 0, h = 0;
    int n = 0;
    if (!(std::cin >> w >> h)) {
        return 0;
    }
    if (!(std::cin >> n)) {
        n = 0;
    }

    long long total = 0, sansPerte = 0, refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string src, dst;
        std::cin >> src >> dst;

        const Format* a = cherche(src);
        const Format* b = cherche(dst);

        if (!a || !b) {
            std::cout << src << ' ' << dst << " REFUSE\n";
            ++refuses;
            continue;
        }

        long long octSrc = w * h * a->octets;
        long long octDst = w * h * b->octets;

        std::string pertes;
        if (a->transparence && !b->transparence) {
            pertes += "TRANSPARENCE";
        }
        if (a->couleur && !b->couleur) {
            if (!pertes.empty()) pertes += '+';
            pertes += "COULEUR";
        }
        if (a->flottants && !b->flottants) {
            if (!pertes.empty()) pertes += '+';
            pertes += "ETENDUE";
        }
        if (pertes.empty()) {
            pertes = "AUCUNE";
            ++sansPerte;
        }

        total += octDst;

        std::cout << src << ' ' << dst << ' ' << octSrc << ' ' << octDst << ' ' << pertes << '\n';
    }

    std::cout << "TOTAL " << total << '\n';
    std::cout << "SANS_PERTE " << sansPerte << '\n';
    std::cout << "REFUSES " << refuses << '\n';

    return 0;
}