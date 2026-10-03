#include <iostream>
#include <string>

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        n = 0;
    }

    long long points = 0, segments = 0, triangles = 0, refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string type;
        long long s = 0;
        std::cin >> type >> s;

        if (type == "POINTS") {
            std::cout << type << ' ' << s << ' ' << s << " POINTS 0\n";
            points += s;
        } else if (type == "LINES") {
            long long nb = s / 2;
            std::cout << type << ' ' << s << ' ' << nb << " SEGMENTS " << s % 2 << '\n';
            segments += nb;
        } else if (type == "LINE_STRIP") {
            long long nb = (s >= 2) ? s - 1 : 0;
            long long reste = (s >= 2) ? 0 : s;
            std::cout << type << ' ' << s << ' ' << nb << " SEGMENTS " << reste << '\n';
            segments += nb;
        } else if (type == "TRIANGLES") {
            long long nb = s / 3;
            std::cout << type << ' ' << s << ' ' << nb << " TRIANGLES " << s % 3 << '\n';
            triangles += nb;
        } else if (type == "TRIANGLE_STRIP" || type == "TRIANGLE_FAN") {
            long long nb = (s >= 3) ? s - 2 : 0;
            long long reste = (s >= 3) ? 0 : s;
            std::cout << type << ' ' << s << ' ' << nb << " TRIANGLES " << reste << '\n';
            triangles += nb;
        } else {
            std::cout << type << ' ' << s << " REFUSE\n";
            ++refuses;
        }
    }

    std::cout << "POINTS " << points << '\n';
    std::cout << "SEGMENTS " << segments << '\n';
    std::cout << "TRIANGLES " << triangles << '\n';
    std::cout << "REFUSES " << refuses << '\n';

    return 0;
}
