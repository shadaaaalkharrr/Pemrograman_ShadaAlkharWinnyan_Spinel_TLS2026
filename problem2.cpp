#include <iostream>

int hitungPanjang(char teks[]) {
    int len = 0;
    while (teks[len] != '\0') {
        len++;
    }
    return len;
}

char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int main() {
    char pesan[500];
    
    std::cout << "Masukkan pesan rahasia: ";
    std::cin >> pesan;

    int panjang = hitungPanjang(pesan);
    int nilaiSebelumnya = 0;

    std::cout << "Pesan terenkripsi: ";

    for (int i = 0; i < panjang; i++) {
        char c = pesan[i];

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            char hurufBesar = keKapital(c);
            int nilaiSekarang = hurufBesar - 'A' + 1;

            if (i == 0) {
                std::cout << hurufBesar;
            } else {
                int nilaiBaru = nilaiSekarang + nilaiSebelumnya;
                
                while (nilaiBaru > 26) {
                    nilaiBaru -= 26;
                }
                
                char hasil = 'A' + nilaiBaru - 1;
                std::cout << hasil;
            }
            
            nilaiSebelumnya = nilaiSekarang;
        } else {
            std::cout << c;
        }
    }

    std::cout << std::endl;
    return 0;
}
