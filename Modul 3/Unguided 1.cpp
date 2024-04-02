#include <iostream>
using namespace std;

// Deklarasi kelas Node untuk merepresentasikan simpul dalam linked list
class Node {
public:
    string nama;  // Variabel untuk menyimpan nama mahasiswa
    int usia;     // Variabel untuk menyimpan usia mahasiswa
    Node* next;   // Pointer ke simpul berikutnya dalam linked list

    // Konstruktor untuk membuat objek Node baru dengan nama dan usia yang diberikan
    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        next = nullptr; // Pointer next diatur menjadi nullptr karena simpul baru akan ditambahkan ke akhir linked list
    }
};

// Deklarasi kelas LinkedList untuk menyimpan linked list dari objek Node
class LinkedList {
private:
    Node* head;  // Pointer ke simpul pertama dalam linked list

public:
    // Konstruktor untuk menginisialisasi linked list dengan head yang menunjuk ke nullptr (linked list kosong)
    LinkedList() {
        head = nullptr;
    }

    // Metode untuk menambahkan mahasiswa baru ke akhir linked list
    void tambahMahasiswa(string nama, int usia) {
        // Membuat simpul baru dengan nama dan usia yang diberikan
        Node* new_node = new Node(nama, usia);
        // Jika linked list kosong, maka head diatur menjadi simpul baru
        if (head == nullptr) {
            head = new_node;
            return;
        }
        // Jika linked list tidak kosong, maka mencari simpul terakhir dalam linked list
        Node* last_node = head;
        while (last_node->next != nullptr) {
            last_node = last_node->next;
        }
        // Menambahkan simpul baru sebagai simpul berikutnya dari simpul terakhir
        last_node->next = new_node;
    }

    // Metode untuk menampilkan data mahasiswa dalam linked list
    void tampilkanMahasiswa() {
        Node* current_node = head;
        while (current_node != nullptr) {
            cout << current_node->nama << "\t" << current_node->usia << endl;
            current_node = current_node->next;
        }
    }

    // Metode untuk menghapus mahasiswa dari linked list berdasarkan nama
    void hapusMahasiswa(string nama) {
        Node* current_node = head;
        Node* prev_node = nullptr;

        // Mencari mahasiswa dengan nama yang diberikan
        while (current_node != nullptr) {
            if (current_node->nama == nama) {
                // Jika ditemukan, menghapus simpul dari linked list
                if (prev_node == nullptr) {
                    head = current_node->next;
                } else {
                    prev_node->next = current_node->next;
                }
                delete current_node;
                cout << "Mahasiswa dengan nama '" << nama << "' berhasil dihapus." << endl;
                return;
            }
            prev_node = current_node;
            current_node = current_node->next;
        }

        // Jika tidak ditemukan, memberi pesan bahwa mahasiswa tidak ditemukan dalam linked list
        cout << "Mahasiswa dengan nama '" << nama << "' tidak ditemukan dalam linked list." << endl;
    }

    // Metode untuk menambahkan mahasiswa baru di depan linked list
    void addInFront(string nama, int usia) {
        // Membuat simpul baru dengan nama dan usia yang diberikan
        Node* new_node = new Node(nama, usia);
        // Menyambungkan simpul baru ke simpul pertama, kemudian membuat simpul baru sebagai head
        new_node->next = head;
        head = new_node;
        cout << "Mahasiswa dengan nama '" << nama << "' berhasil ditambahkan di depan linked list." << endl;
    }

    // Metode untuk menambahkan mahasiswa baru di antara dua mahasiswa
    void addBetween(string nama_sebelum, string nama_baru, int usia_baru) {
        Node* current_node = head;
        // Mencari simpul dengan nama_sebelum dalam linked list
        while (current_node != nullptr) {
            if (current_node->nama == nama_sebelum) {
                // Jika ditemukan, membuat simpul baru dengan nama_baru dan usia_baru
                Node* new_node = new Node(nama_baru, usia_baru);
                // Menyambungkan simpul baru ke simpul yang berikutnya dari simpul saat ini
                new_node->next = current_node->next;
                // Menyambungkan simpul saat ini ke simpul baru
                current_node->next = new_node;
                cout << "Mahasiswa dengan nama '" << nama_baru << "' berhasil ditambahkan setelah '" << nama_sebelum << "'." << endl;
                return;
            }
            current_node = current_node->next;
        }
        // Jika nama_sebelum tidak ditemukan dalam linked list, memberi pesan bahwa nama_sebelum tidak ditemukan
        cout << "Mahasiswa dengan nama '" << nama_sebelum << "' tidak ditemukan dalam linked list." << endl;
    }

    // Metode untuk memperbarui informasi mahasiswa berdasarkan nama
    void update(string nama, string nama_baru, int usia_baru) {
        Node* current_node = head;

        // Mencari mahasiswa dengan nama yang diberikan
        while (current_node != nullptr) {
            if (current_node->nama == nama) {
                // Jika ditemukan, memperbarui nama dan usia mahasiswa
                current_node->nama = nama_baru;
                current_node->usia = usia_baru;
                cout << "Informasi mahasiswa dengan nama '" << nama << "' berhasil diperbarui." << endl;
                return;
            }
            current_node = current_node->next;
        }

        // Jika tidak ditemukan, memberi pesan bahwa mahasiswa tidak ditemukan dalam linked list
        cout << "Mahasiswa dengan nama '" << nama << "' tidak ditemukan dalam linked list." << endl;
    }

    // Metode untuk mendapatkan pointer ke simpul pertama dalam linked list (head)
    Node* getHead() {
        return head;
    }
};

// Fungsi utama
int main() {
    LinkedList linkedList;

    // Loop untuk menampilkan menu dan menerima input dari pengguna
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Mahasiswa di Akhir" << endl;
        cout << "2. Tampilkan Mahasiswa" << endl;
        cout << "3. Hapus Mahasiswa" << endl;
        cout << "4. Tambah Mahasiswa di Tengah" << endl;
        cout << "5. Tambah Mahasiswa di Depan" << endl;
        cout << "6. Update Informasi Mahasiswa" << endl;
        cout << "7. Keluar" << endl;

        int pilihan;
        cout << "Pilih menu: ";
        cin >> pilihan;

        // Switch case untuk memilih operasi yang diinginkan oleh pengguna
        switch (pilihan) {
        case 1: {
            string nama;
            int usia;
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan usia mahasiswa: ";
            cin >> usia;
            linkedList.tambahMahasiswa(nama, usia);
            cout << "Mahasiswa berhasil ditambahkan di akhir." << endl;
            break;
        }
        case 2: {
            // Menampilkan daftar mahasiswa jika linked list tidak kosong, jika kosong memberi pesan
            if (linkedList.getHead() == nullptr) {
                cout << "Linked list kosong." << endl;
            } else {
                cout << "Nama\tUsia" << endl;
                linkedList.tampilkanMahasiswa();
            }
            break;
        }
        case 3: {
            string nama;
            cout << "Masukkan nama mahasiswa yang ingin dihapus: ";
            cin >> nama;
            linkedList.hapusMahasiswa(nama);
            break;
        }
        case 4: {
            string nama_sebelum, nama_baru;
            int usia_baru;
            cout << "Masukkan nama mahasiswa sebelum penambahan: ";
            cin >> nama_sebelum;
            cout << "Masukkan nama mahasiswa baru: ";
            cin >> nama_baru;
            cout << "Masukkan usia mahasiswa baru: ";
            cin >> usia_baru;
            linkedList.addBetween(nama_sebelum, nama_baru, usia_baru);
            break;
        }
        case 5: {
            string nama;
            int usia;
            cout << "Masukkan nama mahasiswa: ";
            cin >> nama;
            cout << "Masukkan usia mahasiswa: ";
            cin >> usia;
            linkedList.addInFront(nama, usia);
            break;
        }
        case 6: {
            string nama, nama_baru;
            int usia_baru;
            cout << "Masukkan nama mahasiswa yang ingin diperbarui: ";
            cin >> nama;
            cout << "Masukkan nama mahasiswa baru: ";
            cin >> nama_baru;
            cout << "Masukkan usia mahasiswa baru: ";
            cin >> usia_baru;
            linkedList.update(nama, nama_baru, usia_baru);
            break;
        }
        case 7:
            // Keluar dari program jika dipilih
            cout << "Program selesai." << endl;
            return 0;
        default:
            // Memberi pesan jika pilihan tidak valid
            cout << "Menu tidak valid. Silakan pilih menu yang sesuai." << endl;
        }
    }

    return 0;
}
