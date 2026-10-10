#include <iostream>
#include <string>
#include <vector>
#include <cctype>

static int hexVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

static std::vector<int> decode(const std::string& s) {
    std::vector<int> b;
    if (s == "-") return b;
    for (size_t i = 0; i + 1 < s.size(); i += 2) {
        int h = hexVal(s[i]);
        int l = hexVal(s[i + 1]);
        if (h < 0 || l < 0) break;
        b.push_back(h * 16 + l);
    }
    return b;
}

// Vrai si les octets donnés commencent par le motif (octets absents => faux).
static bool commence(const std::vector<int>& b, size_t debut, const std::vector<int>& motif) {
    if (debut + motif.size() > b.size()) return false;
    for (size_t i = 0; i < motif.size(); ++i) {
        if (b[debut + i] != motif[i]) return false;
    }
    return true;
}

static std::string detecte(const std::vector<int>& b, long long taille) {
    if (taille < 4) return "";

    if (taille >= 8 && commence(b, 0, {0x89, 0x50, 0x4E, 0x47})) return "PNG";
    if (commence(b, 0, {0xFF, 0xD8, 0xFF})) return "JPEG";
    if (commence(b, 0, {0x42, 0x4D})) return "BMP";
    if (commence(b, 0, {0x71, 0x6F, 0x69, 0x66})) return "QOI";
    if (commence(b, 0, {0x47, 0x49, 0x46, 0x38})) return "GIF";

    if (b.size() >= 4 && b[0] == 0x00 && b[1] == 0x00 &&
        (b[2] == 0x01 || b[2] == 0x02) && b[3] == 0x00) return "ICO";

    if (taille >= 10 && commence(b, 0, {0x23, 0x3F})) return "HDR";
    if (commence(b, 0, {0x76, 0x2F, 0x31, 0x01})) return "EXR";

    if (b.size() >= 2 && b[0] == 0x50 && b[1] >= 0x31 && b[1] <= 0x36) {
        if (b[1] == 0x31 || b[1] == 0x34) return "PBM";
        if (b[1] == 0x32 || b[1] == 0x35) return "PGM";
        return "PPM";
    }

    if (taille >= 18 && b.size() >= 3) {
        int v = b[2];
        if (v == 0x00 || v == 0x01 || v == 0x02 || v == 0x03 ||
            v == 0x09 || v == 0x0A || v == 0x0B) return "TGA";
    }

    size_t p = 0;
    if (commence(b, 0, {0xEF, 0xBB, 0xBF})) p = 3;
    while (p < b.size() && (b[p] == 0x20 || b[p] == 0x09 || b[p] == 0x0A || b[p] == 0x0D)) ++p;
    if (commence(b, p, {0x3C, 0x3F, 0x78, 0x6D, 0x6C}) ||
        commence(b, p, {0x3C, 0x73, 0x76, 0x67})) return "SVG";

    return "";
}

static std::string extension(const std::string& nom) {
    size_t pos = nom.find_last_of('.');
    if (pos == std::string::npos) return "";
    std::string e = nom.substr(pos + 1);
    for (size_t i = 0; i < e.size(); ++i) {
        e[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(e[i])));
    }
    return e;
}

static bool extensionJuste(const std::string& fmt, const std::string& ext) {
    if (ext.empty()) return false;
    if (fmt == "PNG") return ext == "png";
    if (fmt == "JPEG") return ext == "jpg" || ext == "jpeg";
    if (fmt == "BMP") return ext == "bmp";
    if (fmt == "QOI") return ext == "qoi";
    if (fmt == "GIF") return ext == "gif";
    if (fmt == "ICO") return ext == "ico" || ext == "cur";
    if (fmt == "HDR") return ext == "hdr";
    if (fmt == "EXR") return ext == "exr";
    if (fmt == "PBM") return ext == "pbm";
    if (fmt == "PGM") return ext == "pgm";
    if (fmt == "PPM") return ext == "ppm";
    if (fmt == "TGA") return ext == "tga";
    if (fmt == "SVG") return ext == "svg";
    return false;
}

int main() {
    int n = 0;
    if (!(std::cin >> n)) {
        n = 0;
    }

    long long lus = 0, mensonges = 0, refuses = 0;

    for (int i = 0; i < n; ++i) {
        std::string nom, hex;
        long long taille = 0;
        std::cin >> nom >> taille >> hex;

        std::vector<int> octets = decode(hex);
        std::string fmt = detecte(octets, taille);

        if (fmt.empty()) {
            std::cout << nom << " REFUSE\n";
            ++refuses;
        } else {
            ++lus;
            if (extensionJuste(fmt, extension(nom))) {
                std::cout << nom << ' ' << fmt << " OK\n";
            } else {
                std::cout << nom << ' ' << fmt << " MENT\n";
                ++mensonges;
            }
        }
    }

    std::cout << "LUS " << lus << '\n';
    std::cout << "MENSONGES " << mensonges << '\n';
    std::cout << "REFUSES " << refuses << '\n';

    return 0;
}