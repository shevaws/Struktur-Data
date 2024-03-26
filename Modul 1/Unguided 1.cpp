#include <cstdlib>
#include <iostream>

using namespace std;

//RANDOMIZER NO ABSEN
void absen() {
    int btm = 0;
    int top = 41; 

	for (int i = 0; i < 5; i++){
		cout << (rand() % top - btm + 1) + btm << " ";
    }
}

//MENGHITUNG LUAS LINGKARAN
void ll() {
    int r;
    cout << "Masukkan jari-jari: ";
    cin >> r;
    
    cout << "Luas lingkaran anda adalah : "<< 3.14 * (r * r) << " satuan luas";
}

int main(int argc, char const *argv[])
{
    char pilih;

    cout << "Apakah menu yang ingin anda gunakan?\na. Randomizer nomor absen\nb. Menghitung luas lingkaran\n";
    cin >> pilih;

    if (pilih == 'a' || pilih == 'A'){
        absen();
    } else if (pilih == 'b' || pilih == 'B') {
        ll();
    }
	return 0;
}
