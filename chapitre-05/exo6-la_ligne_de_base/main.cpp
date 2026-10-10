#include <iostream>
#include <string>
#include <map>
#include <algorithm>

struct Glyphe {
    long long avance, x0, y0, x1, y1;
};

int main() {
    int G = 0;
    if (!(std::cin >> G)) {
        G = 0;
    }

    std::map<char, Glyphe> table;
    for (int i = 0; i < G; ++i) {
        std::string c;
        Glyphe g;
        std::cin >> c >> g.avance >> g.x0 >> g.y0 >> g.x1 >> g.y1;
        if (!c.empty()) table[c[0]] = g;
    }

    int K = 0;
    if (!(std::cin >> K)) {
        K = 0;
    }

    std::map<std::string, long long> crenage;
    for (int i = 0; i < K; ++i) {
        std::string ab;
        long long k;
        std::cin >> ab >> k;
        crenage[ab] = k;
    }

    std::string texte;
    long long ox = 0, oy = 0;
    std::cin >> texte >> ox >> oy;

    long long x = ox;
    long long minx = 0, miny = 0, maxx = 0, maxy = 0;
    bool dessine = false;
    long long absents = 0;

    for (size_t i = 0; i < texte.size(); ++i) {
        char c = texte[i];
        auto it = table.find(c);

        if (it == table.end()) {
            std::cout << c << " ABSENT\n";
            ++absents;
            continue;
        }

        const Glyphe& g = it->second;
        std::cout << c << ' ' << x << '\n';

        if (g.x1 > g.x0 && g.y1 > g.y0) {
            long long rx0 = x + g.x0;
            long long ry0 = oy + g.y0;
            long long rx1 = x + g.x1;
            long long ry1 = oy + g.y1;
            if (!dessine) {
                minx = rx0; miny = ry0; maxx = rx1; maxy = ry1;
                dessine = true;
            } else {
                minx = std::min(minx, rx0);
                miny = std::min(miny, ry0);
                maxx = std::max(maxx, rx1);
                maxy = std::max(maxy, ry1);
            }
        }

        x += g.avance;

        if (i + 1 < texte.size()) {
            std::string paire;
            paire += c;
            paire += texte[i + 1];
            auto kt = crenage.find(paire);
            if (kt != crenage.end()) x += kt->second;
        }
    }

    std::cout << "CURSEUR " << x << '\n';

    if (!dessine) {
        std::cout << "BOITE AUCUNE\n";
        std::cout << "MONTE 0\n";
        std::cout << "DESCEND 0\n";
        std::cout << "ECRAN RIEN\n";
    } else {
        long long monte = (miny < oy) ? oy - miny : 0;
        long long descend = (maxy > oy) ? maxy - oy : 0;
        std::cout << "BOITE " << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << '\n';
        std::cout << "MONTE " << monte << '\n';
        std::cout << "DESCEND " << descend << '\n';
        if (maxy <= 0) {
            std::cout << "ECRAN HORS\n";
        } else if (miny < 0) {
            std::cout << "ECRAN COUPE\n";
        } else {
            std::cout << "ECRAN VISIBLE\n";
        }
    }

    std::cout << "ABSENTS " << absents << '\n';

    return 0;
}