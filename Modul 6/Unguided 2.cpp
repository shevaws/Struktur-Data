#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Fungsi untuk menentukan apakah kalimat adalah palindrom
string terbalik(const string &sentence) {
    string kalimat = sentence;
    int length = kalimat.length();
    
    // Buat stack dengan kapasitas sebesar panjang kalimat yang dibersihkan
    char* stack = new char[length];
    int top = -1;

    // Masukkan semua karakter ke dalam stack
    for (char c : kalimat) {
        stack[++top] = c;
    }

    string reversed_sentence;

    // Buat kalimat terbalik dengan mengambil karakter dari stack
    while (top != -1) {
        reversed_sentence += stack[top--];
    }

    // Hapus stack
    delete[] stack;

    // Periksa apakah kalimat asli yang dibersihkan sama dengan kalimat terbalik
    return reversed_sentence;
}

int main() {
    string sentence;
    cout << "\nMasukkan kalimat: ";
    getline(cin, sentence);

    string reversed_sentence = terbalik(sentence);
    cout << "Kalimat terbalik: " << reversed_sentence << endl;

    return 0;
}
