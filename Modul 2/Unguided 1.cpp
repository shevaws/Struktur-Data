#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //Deklarasi variabel yang digunakan
    int n, i;
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
    }
    //Membuat variabel untuk menampung angka ganjil dan genap
    int ganjil[n], genap[n];
    int count_ganjil = 0, count_genap = 0;

    //Mengecek angka ganjil dan genap
    for (i = 0; i < n; i++) {
        //Melakukan pengecekan, jika modulus 2 = 0, maka genap. Jika sebaliknya maka ganjil
        if (arr[i] % 2 == 0) {
            genap[count_genap] = arr [i];
            count_genap++;
        } else {
            ganjil[count_ganjil] = arr[i];
            count_ganjil++;
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

    cout << "Angka Genap: ";
    for (i = 0; i < count_genap; i++) {
        cout << genap[i];
        if (i != count_genap - 1) {
            cout << ", ";
        }
    }
    cout << '\n';

    cout << "Angka Ganjil: ";
    for (i = 0; i < count_ganjil; i++) {
        cout << ganjil[i];
        if (i != count_ganjil - 1) {
            cout << ", ";
        }
    }
    cout << '\n';

    //Menghapus array
    delete[] arr;

    return 0;
}
