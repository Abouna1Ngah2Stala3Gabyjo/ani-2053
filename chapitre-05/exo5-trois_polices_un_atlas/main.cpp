#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Groupe {
    std::string nom;
    long long n, w, h;
    long long x1, y1, x2, y2;
};

// Un essai de rangement par étagères. Renvoie vrai si tout tient.
static bool essai(std::vector<Groupe>& gs, long long P, long long W, long long H) {
    long long x = P, y = P, e = 0;

    for (Groupe& g : gs) {
        long long rw = g.w + P;
        long long rh = g.h + P;

        for (long long i = 0; i < g.n; ++i) {
            if (x + rw > W - P) {
                x = P;
                y = y + e + P;
                e = 0;
                if (x + rw > W - P) return false;
            }
            if (y + rh > H - P) return false;

            if (i == 0) {
                g.x1 = x;
                g.y1 = y;
            }
            g.x2 = x;
            g.y2 = y;

            x += rw;
            e = std::max(e, rh);
        }
    }
    return true;
}

int main() {
    long long P = 0, L = 0;
    if (!(std::cin >> P >> L)) {
        return 0;
    }

    int G = 0;
    if (!(std::cin >> G)) {
        G = 0;
    }

    if (G == 0) {
        std::cout << "AUCUN\n";
        return 0;
    }

    std::vector<Groupe> gs(G);
    long long besoin = 0, occupe = 0;
    for (int i = 0; i < G; ++i) {
        Groupe& g = gs[i];
        std::cin >> g.nom >> g.n >> g.w >> g.h;
        g.x1 = g.y1 = g.x2 = g.y2 = 0;
        besoin += g.n * (g.w + P) * (g.h + P);
        occupe += g.n * g.w * g.h;
    }

    long long W = L;
    if (L == 0) {
        W = 512;
        while (W * W < 2 * besoin && W < 4096) {
            W *= 2;
        }
    }
    long long H = W;

    int reussi = 0;
    for (int k = 1; k <= 8; ++k) {
        if (essai(gs, P, W, H)) {
            reussi = k;
            break;
        }
        if (W == H) {
            W *= 2;
        } else {
            H = W;
        }
    }

    if (reussi == 0) {
        std::cout << "ESSAIS 8\n";
        std::cout << "ECHEC\n";
        return 0;
    }

    std::cout << "ESSAIS " << reussi << '\n';
    std::cout << "TEXTURE " << W << ' ' << H << '\n';
    for (const Groupe& g : gs) {
        std::cout << g.nom << ' ' << g.x1 << ' ' << g.y1 << ' ' << g.x2 << ' ' << g.y2 << '\n';
    }
    long long surface = W * H;
    long long perdu = (surface - occupe) * 100 / surface;
    std::cout << "OCCUPE " << occupe << '\n';
    std::cout << "PERDU " << perdu << '\n';

    return 0;
}