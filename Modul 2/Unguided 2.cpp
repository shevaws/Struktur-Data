#include <iostream>

using namespace std;

int main() {
    // Deklarasi variabel untuk ukuran array
    int x, y, z;
    
    // Meminta user untuk memasukkan ukuran array
    cout << "Masukkan ukuran array x: ";
    cin >> x;
    cout << "Masukkan ukuran array y: ";
    cin >> y;
    cout << "Masukkan ukuran array z: ";
    cin >> z;

    // Membuat array tiga dimensi dengan ukuran yang diinputkan user
    int arr[x][y][z];

    // Meminta user untuk memasukkan nilai untuk setiap elemen array
    cout << "Masukkan nilai untuk setiap elemen array:" << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << "arr[" << i << "][" << j << "][" << k << "]: ";
                cin >> arr[i][j][k];
            }
        }
    }

    // Mencetak isi array tiga dimensi
    cout << "Isi array tiga dimensi:" << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            for (int k = 0; k < z; ++k) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
