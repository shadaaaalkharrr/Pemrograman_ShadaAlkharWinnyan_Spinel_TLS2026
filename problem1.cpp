#include <iostream>

// User-defined function untuk menghapuskan elemen array dan menggeser sisa elemen
void removeAt(int arr[], int &size, int index) {
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// User-defined function untuk memperbarui nilai K berdasarkan nomor astronot tereliminasi
int updateK(int currentK, int eliminatedAstronaut) {
    if (eliminatedAstronaut % 2 == 0) {
        currentK += 2;
    } else {
        currentK -= 1;
    }

    if (currentK < 2) {
        currentK = 2;
    }
    return currentK;
}

// User-defined function utama untuk simulasi proses eliminasi
void simulateSelection(int N, int initialK) {
    int astronauts[1000];
    for (int i = 0; i < N; i++) {
        astronauts[i] = i + 1;
    }

    int size = N;
    int currentIndex = 0;
    int K = initialK;

    std::cout << "Urutan astronot yang dieliminasi: ";
    bool first = true;

    while (size > 1) {
        // Hitung posisi astronot yang dieliminasi
        currentIndex = (currentIndex + K - 1) % size;
        int eliminated = astronauts[currentIndex];

        if (!first) {
            std::cout << ", ";
        }
        std::cout << eliminated;
        first = false;

        // Hapus astronot dari daftar
        removeAt(astronauts, size, currentIndex);

        // Perbarui nilai K sesuai aturan
        K = updateK(K, eliminated);

        // Menjaga perputaran indeks jika mencapai akhir array
        if (currentIndex >= size) {
            currentIndex = 0;
        }
    }

    std::cout << std::endl;
    std::cout << "Astronot terakhir yang bertahan: " << astronauts[0] << std::endl;
}

int main() {
    int N, K;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;

    simulateSelection(N, K);

    return 0;
}