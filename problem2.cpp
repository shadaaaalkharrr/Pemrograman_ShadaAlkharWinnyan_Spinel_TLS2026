#include <iostream>

// User-defined function untuk menghitung panjang karakter string (C-string)
int customStrLen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// User-defined function untuk mengubah huruf kecil menjadi kapital
char customToUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// User-defined function untuk mengecek apakah karakter merupakan alfabet
bool customIsAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// User-defined function untuk melakukan enkripsi enkripsi cipher
void encryptAlienCipher(const char inputStr[], char outputStr[]) {
    int length = customStrLen(inputStr);
    int prevVal = 0;

    for (int i = 0; i < length; i++) {
        char currentChar = inputStr[i];

        if (customIsAlpha(currentChar)) {
            char upperChar = customToUpper(currentChar);
            int currentVal = upperChar - 'A' + 1; // A=1, B=2, ..., Z=26

            if (i == 0) {
                outputStr[i] = upperChar;
            } else {
                int shiftedVal = currentVal + prevVal;
                while (shiftedVal > 26) {
                    shiftedVal -= 26;
                }
                outputStr[i] = (char)('A' + shiftedVal - 1);
            }
            // Simpan nilai huruf asli sebelumnya
            prevVal = currentVal;
        } else {
            outputStr[i] = currentChar;
        }
    }
    outputStr[length] = '\0';
}

int main() {
    char message[500];
    char encrypted[500];

    std::cout << "Masukkan pesan rahasia: ";
    std::cin >> message;

    encryptAlienCipher(message, encrypted);

    std::cout << "Pesan terenkripsi: " << encrypted << std::endl;

    return 0;
}