#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //Deklarasi variabel yang digunakan
    int n, i;
    //Buat variabel posisi dengan awalnya berada pada indeks ke 0
    int posisi = 0, posisi2 = 0;
    //Buat variabel total untuk mean yang awalnya 0
    double total = 0;
    //User memasukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> n;

    //Membuat array dinamis
    int* arr = new int [n];
    //User memasukkan isi array menggunakan loop
    cout << "Masukkan isi array: \n";
    for (i =0; i < n; i++) {
        cout << "Array ke-" << i+1 << ": ";
        cin >> arr[i];
        //Tambahkan total sesuai dengan ukuran array
        total += arr[i];
    }

    //Membuat variabel untuk nilai maksimum, minimum, dan mean.
    int maks = arr[0];
    int minn = arr[0];
    double mean = total / n;

    //Melalukan pengecekan untuk nilai maksimum dan minimum.
    for (i = 0; i < n; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
            posisi = i;
        } else if (arr[i] < minn) {
            minn = arr[i];
            posisi2 = i;
        }
    }

    //Mengoutputkan hasil
    cout << "Data Array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i];
        //Agar rapih, menambahkan koma (,) di setiap iterasi. Kecuali untuk iterasi terakhir
        if (i != n - 1) {
            cout << ", ";
        }
    }
    cout << '\n';

    cout << "Nilai maksimum adalah : " << maks << " dan berada pada posisi ke-" << posisi + 1 << '\n';
    cout << "Nilai minimum : " << minn << " dan berada pada posisi ke-" << posisi2 + 1 << '\n';
    cout << "Nilai rata-rata : " << mean << '\n';

    //Menghapus array
    delete[] arr;

    return 0;
}