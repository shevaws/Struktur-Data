#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    int n = 9;
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int a4 = 4;
    int j4 = 0;

    for (int i = 0; i <= n; i++)
    {
        if (data[i] == a4)
        {
            j4++;
        }
    }

    cout << "\tSequential Search." << endl;
    cout << "Data : [";
    for (int i = 0; i <= n; i++)
    {
        cout << data[i];
        if (i != n)
        {
            cout << ", ";
        }
    }
    cout << "]";
    cout << endl;

    cout << "Jumlah angka 4 : " << j4 << endl;

    return EXIT_SUCCESS;
}
