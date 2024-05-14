#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int TABLE_SIZE = 11;
string nim;
int nilai;
class HashNode
{
public:
    string nim;
    int nilai;
    HashNode(string nim, int nilai)
    {
        this->nim = nim;
        this->nilai = nilai;
    }
};
class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string nim, int nilai)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                node->nilai = nilai;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(nim, nilai));
    }

    void remove(string nim)
    {
        int hash_val = hashFunc(nim);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->nim == nim)
            {
                table[hash_val].erase(it);
                return;
            }
            else
            {
                cout << "Tidak Ditemukan" << endl;
            }
        }
    }

    int searchByNim(string nim)
    {
        int hash_val = hashFunc(nim);
        for (auto node : table[hash_val])
        {
            if (node->nim == nim)
            {
                cout << "\nMahasiswa dengan NIM " << node->nim << " ditemukan di database, dan memiliki nilai " << node->nilai << endl;
            }
        }
        return 0;
    }

    int searchByNilai(int minn, int maxx)
    {
        bool found = false;
        for (const auto &bucket : table)
        {
            for (auto node : bucket)
            {
                if (node->nilai >= minn && node->nilai <= maxx)
                {
                    cout << "Mahasiswa dengan [ NIM : " << node->nim << ", dan NILAI : " << node->nilai << " ] ditemukan dalam database." << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "Tidak ada mahasiswa pada rentang nilai tersebut.";
        }
        return 0;
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[ NIM : " << pair->nim << ", NILAI : " << pair->nilai << " ]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap mahasiswa_map;
    int choice;
    do
    {
        cout << "\t\nData Mahasiswa\t" << endl;
        cout << "1. Tambah Data\n";
        cout << "2. Hapus Data\n";
        cout << "3. Cari mahasiswa dengan NIM\n";
        cout << "4. Cari mahasiswa dengan Nilai\n";
        cout << "0. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> nim;
            cout << "Masukkan Nilai Mahasiswa : ";
            cin >> nilai;

            mahasiswa_map.insert(nim, nilai);

            cout << "\t\nData Mahasiswa\t" << endl;
            mahasiswa_map.print();
            cout << endl;
            break;
        case 2:
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> nim;
            mahasiswa_map.remove(nim);

            cout << "\t\nData Mahasiswa\t" << endl;
            mahasiswa_map.print();
            cout << endl;
            break;
        case 3:
            cout << "Masukkan NIM Mahasiswa : ";
            cin >> nim;
            mahasiswa_map.searchByNim(nim);

            break;
        case 4:
            int maxx, minn;
            cout << "Masukkan Nilai Tertinggi : ";
            cin >> maxx;
            cout << "Masukkan Nilai Terendah : ";
            cin >> minn;
            mahasiswa_map.searchByNilai(minn, maxx);
            break;
        default:
            cout << "Harap masukkan pilihan sesuai menu.\n";
            break;
        }

    } while (choice != 0);
    return 0;
}