#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    int raka_2311102054;
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> raka_2311102054;

    string simpul[raka_2311102054];
    int bobot[raka_2311102054][raka_2311102054];
    cout << "Silakan masukkan nama simpul\n";
    for (int i = 0; i < raka_2311102054; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < raka_2311102054; i++) {
        for (int j = 0; j < raka_2311102054; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " : ";
            cin >> bobot[i][j];
        }
    }

    cout << endl << setw(10) << " ";
    for (int i = 0; i < raka_2311102054; i++) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < raka_2311102054; i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < raka_2311102054; j++) {
            cout << setw(10) << bobot[i][j];
        }
        cout << endl;
    }

    return 0;
}