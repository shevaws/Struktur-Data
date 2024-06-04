#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int nomor[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;
void selection_sort()
{
        int temp, min, i, j;
        for(i=0; i<7;i++)
        {
                min = i;
                for(j = i+1; j<7; j++)
                {
                        if(nomor[j]<nomor[min])
                        {
                        min=j;
                        }
                }
                temp = nomor[i];
                nomor[i] = nomor[min];
                nomor[min] = temp;
        }
}

void binarysearch() // 
{
        //searching
        int awal, akhir, tengah, b_flag = 0; 
        awal = 0; // awal 0
        akhir = 7; // akhir 7
        while (b_flag == 0 && awal<=akhir)
        {
                tengah = (awal + akhir)/2;
                if(nomor[tengah] == cari)
                {
                    b_flag = 1;
                    break;
                }
                else if(nomor[tengah]<cari)
                    awal = tengah + 1;
                else
                    akhir = tengah -1;
        }
        if(b_flag == 1)
             cout<<"\n nomor ditemukan pada index ke- "<< tengah << endl;
        else
            cout<<"\n nomor tidak ditemukan\n";
}

int main()
{
        cout << "\t BINARY SEARCH " << endl;
        cout << "\n nomor : ";
        //tampilkan nomor awal
        for(int x = 0; x<7; x++)
            cout << setw(3) << nomor[x];
        cout << endl;
        cout << "\n Masukkan nomor yang ingin Anda cari :";
        cin >> cari;
        cout << "\n nomor diurutkan : ";
        //urutkan nomor dengan selection sort
        selection_sort();
        //tampilkan nomor setelah diurutkan
        for(int x = 0; x < 7; x++)
            cout<<setw(3)<<nomor[x];
        cout<<endl;
        binarysearch();
        _getche();
        return EXIT_SUCCESS;
}