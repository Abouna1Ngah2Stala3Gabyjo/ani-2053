#include <iostream>
#include <string>
#include <map>

struct Noeud {
    long long x, y, angle, echelle, niveau;
};

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        n = 0;
    }

    std::map<std::string, Noeud> objets;
    long long profondeur = 0;

    for (int i = 0; i < n; ++i) {
        std::string nom, parent;
        long long tx, ty, angle, echelle;
        std::cin >> nom >> parent >> tx >> ty >> angle >> echelle;

        Noeud o;
        if (parent == "-") {
            o.x = tx;
            o.y = ty;
            o.angle = ((angle % 360) + 360) % 360;
            o.echelle = echelle;
            o.niveau = 1;
        } else {
            const Noeud& p = objets[parent];

            long long ax = tx * p.echelle;
            long long ay = ty * p.echelle;

            long long c = 0, s = 0;
            if (p.angle == 0)        { c = 1;  s = 0; }
            else if (p.angle == 90)  { c = 0;  s = 1; }
            else if (p.angle == 180) { c = -1; s = 0; }
            else                     { c = 0;  s = -1; }

            long long rx = ax * c - ay * s;
            long long ry = ax * s + ay * c;

            o.x = p.x + rx;
            o.y = p.y + ry;
            o.angle = (((p.angle + angle) % 360) + 360) % 360;
            o.echelle = p.echelle * echelle;
            o.niveau = p.niveau + 1;
        }

        objets[nom] = o;
        if (o.niveau > profondeur) profondeur = o.niveau;

        std::cout << nom << ' ' << o.x << ' ' << o.y << ' ' << o.angle << ' ' << o.echelle << '\n';
    }

    std::cout << "PROFONDEUR " << profondeur << '\n';

    return 0;
}