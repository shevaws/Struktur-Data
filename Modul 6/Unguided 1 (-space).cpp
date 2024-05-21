#include <iostream>
#include <cctype>
#include <string>
using namespace std;

// Fungsi untuk mengubah semua karakter dalam kata menjadi huruf kecil
string cleankata(const string &kata) {
    string cleaned;
    for (char c : kata) {
        cleaned += tolower(c);
    }
    return cleaned;
}

// Fungsi untuk menentukan apakah kata adalah palindrom
bool isPalindrome(const string &kata) {
    string cleaned_kata = cleankata(kata);
    int length = cleaned_kata.length();

    // Buat stack dengan kapasitas sebesar panjang kata yang dibersihkan
    char* stack = new char[length];
    int top = -1;

    // Masukkan semua karakter ke dalam stack
    for (int i = 0; i < length; i++) {
        stack[++top] = cleaned_kata[i];
    }

    string reversed_kata;

    // Buat kata terbalik dengan mengambil karakter dari stack
    while (top != -1) {
        reversed_kata += stack[top--];
    }

    // Hapus stack
    delete[] stack;

    // Periksa apakah kata asli yang dibersihkan sama dengan kata terbalik
    return cleaned_kata == reversed_kata;
}

int main() {
    string kata;
    cout << "\nMasukkan kata: ";
    cin >> kata;

    if (isPalindrome(kata)) {
        cout << "Kata tersebut adalah palindrom." << endl;
    } else {
        cout << "Kata tersebut bukan palindrom." << endl;
    }

    return 0;
}