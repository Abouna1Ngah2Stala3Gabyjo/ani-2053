#include <iostream>

int main() {
    long long C = 1, R = 1, W = 0, H = 0, F = 1, D = 1, P = 1;
    if (!(std::cin >> C >> R >> W >> H >> F >> D >> P)) {
        return 0;
    }

    int n = 0;
    if (!(std::cin >> n)) {
        n = 0;
    }

    long long cur = 0;
    long long accumule = 0;
    long long avances = 0, plafonnes = 0;

    for (int i = 0; i < n; ++i) {
        long long dt = 0;
        std::cin >> dt;

        if (dt > P) {
            dt = P;
            ++plafonnes;
        }

        accumule += dt;

        while (accumule >= D) {
            accumule -= D;
            cur = (cur + 1) % F;
            ++avances;
        }

        long long x = (cur % C) * W;
        long long y = (cur / C) * H;
        std::cout << cur << ' ' << x << ' ' << y << ' ' << W << ' ' << H << '\n';
    }

    std::cout << "AVANCES " << avances << '\n';
    std::cout << "PLAFONNES " << plafonnes << '\n';

    return 0;
}