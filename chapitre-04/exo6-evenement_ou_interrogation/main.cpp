#include <iostream>
#include <string>

int main() {
    long long v = 0;
    int n = 0;
    if (!(std::cin >> v >> n)) {
        v = 0;
        n = 0;
    }

    bool space = false, left = false, right = false;
    long long xe = 0, xi = 0;
    long long sautsEv = 0, sautsInt = 0, manques = 0;

    for (int i = 1; i <= n; ++i) {
        int k = 0;
        std::cin >> k;

        long long plusSpace = 0;

        for (int j = 0; j < k; ++j) {
            std::string ev;
            std::cin >> ev;
            if (ev.size() < 2) continue;

            char signe = ev[0];
            std::string nom = ev.substr(1);
            bool enfoncee = (signe == '+');
            if (signe != '+' && signe != '-') continue;

            if (nom == "SPACE") {
                space = enfoncee;
                if (enfoncee) {
                    ++sautsEv;
                    ++plusSpace;
                }
            } else if (nom == "LEFT") {
                left = enfoncee;
                if (enfoncee) xe -= v;
            } else if (nom == "RIGHT") {
                right = enfoncee;
                if (enfoncee) xe += v;
            }
        }

        if (space) ++sautsInt;
        if (right) xi += v;
        if (left) xi -= v;

        if (!space) manques += plusSpace;

        std::cout << i << ' ' << xe << ' ' << xi << '\n';
    }

    std::cout << "SAUTS EVENEMENTS " << sautsEv << '\n';
    std::cout << "SAUTS INTERROGATION " << sautsInt << '\n';
    std::cout << "MANQUES " << manques << '\n';

    return 0;
}