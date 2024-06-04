#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int partition(char arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(char arr[], int start, int end)
{
    if (start >= end)
        return;

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void binary_search(char data[], int n, char cari)
{
    int awal = 0, akhir = n - 1, tengah;
    bool found = false;
    while (!found && awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (data[tengah] == cari)
        {
            found = true;
        }
        else if (data[tengah] < cari)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }
    if (found)
    {
        cout << "\n Data ditemukan pada index ke- " << tengah << endl;
    }
    else
    {
        cout << "\n Data tidak ditemukan\n";
    }
}

int main()
{
    const int MAX_LENGTH = 100;
    char kalimat[MAX_LENGTH];
    char cleaned[MAX_LENGTH];
    char cari;

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Masukkan sebuah kalimat : ";
    cin.getline(kalimat, MAX_LENGTH);

    // Remove spaces
    int n = 0;
    for (int i = 0; kalimat[i] != '\0'; i++)
    {
        if (kalimat[i] != ' ')
        {
            cleaned[n++] = kalimat[i];
        }
    }
    cleaned[n] = '\0';

    cout << "\n Data diurutkan : ";
    quickSort(cleaned, 0, n - 1);

    // Tampilkan data setelah diurutkan
    for (int i = 0; i < n; i++)
    {
        cout << cleaned[i];
    }
    cout << endl;

    cout << "\n Masukkan karakter yang ingin Anda cari : ";
    cin >> cari;

    binary_search(cleaned, n, cari);

    return EXIT_SUCCESS;
}
