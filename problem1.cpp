#include <iostream>

void hapusAstronot(int astronot[], int &total, int indeks) {
    for (int i = indeks; i < total - 1; i++) {
        astronot[i] = astronot[i + 1];
    }
    total--;
}

int main() {
    int n, k;
    
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> n;
    std::cout << "Masukkan nilai K awal: ";
    std::cin >> k;

    int astronot[1000];
    for (int i = 0; i < n; i++) {
        astronot[i] = i + 1;
    }

    int pos = 0;
    int total = n;

    std::cout << "Urutan astronot yang tereliminasi: ";

    while (total > 1) {
        pos = (pos + k - 1) % total;
        int nomorDiuji = astronot[pos];

        std::cout << nomorDiuji;
        if (total > 2) {
            std::cout << ", ";
        }

        hapusAstronot(astronot, total, pos);

        if (nomorDiuji % 2 == 0) {
            k += 2;
        } else {
            k -= 1;
        }

        if (k < 2) {
            k = 2;
        }

        if (pos >= total) {
            pos = 0;
        }
    }

    std::cout << std::endl;
    std::cout << "Astronot terakhir yang bertahan: " << astronot[0] << std::endl;

    return 0;
}
