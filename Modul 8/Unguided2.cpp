#include <iostream>
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

void hitung(const char arr[], int n, int &countv, int &countk)
{
    countv = 0;
    countk = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'i' || arr[i] == 'u' || arr[i] == 'e' || arr[i] == 'o' ||
            arr[i] == 'A' || arr[i] == 'I' || arr[i] == 'U' || arr[i] == 'E' || arr[i] == 'O')
        {
            countv++;
        }
        else if (isalpha(arr[i]))
        {
            countk++;
        }
    }
}

int main()
{
    const int MAX_LENGTH = 100;
    char kalimat[MAX_LENGTH];
    char cleaned[MAX_LENGTH];
    int countv, countk;

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

    hitung(cleaned, n, countv, countk);

    cout << "Jumlah Huruf Vokal : " << countv << endl;
    cout << "Jumlah Huruf Konsonan : " << countk << endl;
    return EXIT_SUCCESS;
}
