#include <iostream>
using namespace std;
int main()
{
    //Deklarasi variabel
    int maks, a, i = 1, lokasi;
    //Memasukkan panjang array
    cout << "Masukkan panjang array: ";
    cin >> a;
    
    //Input array
    int array[a];
    cout << "Masukkan " << a << " angka\n";
 
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    
    //Deklarasi variabel nilai maksimum
    maks = array[0];
    
    //Mengecek berapa dan dimana nilai maksimum
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    //Mengoutputkan nilai maksimum dan posisinya
    cout << "Nilai maksimum adalah " << maks << " berada di Array ke " << lokasi << endl;
}