#include <iostream>
#include <string>
using namespace std;

// Definisi struktur Node untuk linked list
struct Node {
    string nama;      // Nama mahasiswa yang disimpan dalam node
    intptr_t nim;     // NIM mahasiswa yang disimpan dalam node
    Node* next;       // Pointer yang menunjukkan ke node berikutnya
};

Node* head;  // Pointer ke kepala/awal linked list
Node* tail;  // Pointer ke ekor/akhir linked list

// Fungsi untuk menginisialisasi linked list
void init() {
    head = nullptr;  // Atur pointer head menjadi nullptr
    tail = nullptr;  // Atur pointer tail menjadi nullptr
}

// Fungsi untuk memeriksa apakah linked list kosong
bool isEmpty() {
    return head == nullptr;  // Mengembalikan true jika head adalah nullptr
}

// Fungsi untuk menyisipkan node baru di depan linked list
void insertDepan(string nama, intptr_t nim) {
    Node* baru = new Node;  // Buat node baru
    baru->nama = nama;      // Atur nama mahasiswa pada node baru
    baru->nim = nim;        // Atur NIM mahasiswa pada node baru
    baru->next = nullptr;   // Atur pointer next node baru menjadi nullptr

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Atur head dan tail menjadi node baru
    } else {
        baru->next = head;  // Atur pointer next node baru menuju head
        head = baru;        // Perbarui head menjadi node baru
    }
}

// Fungsi untuk menyisipkan node baru di belakang linked list
void insertBelakang(string nama, intptr_t nim) {
    Node* baru = new Node;  // Buat node baru
    baru->nama = nama;      // Atur nama mahasiswa pada node baru
    baru->nim = nim;        // Atur NIM mahasiswa pada node baru
    baru->next = nullptr;   // Atur pointer next node baru menjadi nullptr

    if (isEmpty()) {        // Jika linked list kosong
        head = tail = baru; // Atur head dan tail menjadi node baru
    } else {
        tail->next = baru;  // Atur pointer next tail menuju node baru
        tail = baru;        // Perbarui tail menjadi node baru
    }
}

// Fungsi untuk menampilkan data mahasiswa dalam linked list
void tampilkanData() {
    if (isEmpty()) {  // Jika linked list kosong
        cout << "Linked list kosong." << endl;
    } else {
        cout << "DATA MAHASISWA" << endl;
        cout << "NAMA\t   NIM" << endl;
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->nim << endl;
            temp = temp->next;
        }
    }
}

// Fungsi untuk menyisipkan node baru di antara dua node yang sudah ada
void addBetween(string nama, intptr_t nim, int posisi) {
    if (posisi < 1) {
        cout << "Posisi tidak valid" << endl;
        return;
    }

    Node* baru = new Node;  // Buat node baru
    baru->nama = nama;      // Atur nama mahasiswa pada node baru
    baru->nim = nim;        // Atur NIM mahasiswa pada node baru
    baru->next = nullptr;   // Atur pointer next node baru menjadi nullptr

    if (isEmpty()) {  // Jika linked list kosong
        head = tail = baru;
    } else if (posisi == 1) {  // Jika posisi adalah di depan
        baru->next = head;
        head = baru;
    } else {  // Jika posisi di tengah atau belakang
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1 && bantu->next != nullptr) {
            bantu = bantu->next;
            nomor++;
        }
        if (nomor == posisi - 1) {
            baru->next = bantu->next;
            bantu->next = baru;
            if (bantu == tail) {
                tail = baru;
            }
        } else {
            cout << "Posisi tidak valid" << endl;
            delete baru;
        }
    }
}

// Fungsi untuk menghapus node dari depan linked list
void hapusDepan() {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else {
        cout << "- Hapus Depan\n\n";
        cout << "Data " << head->nama << " berhasil dihapus." << endl;
        Node* hapus = head;
        head = head->next;
        delete hapus;
    }
}

// Fungsi untuk menghapus node dari belakang linked list
void hapusBelakang() {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else if (head == tail) {
        cout << "- Hapus Belakang\n\n";
        cout << "Data " << head->nama << " berhasil dihapus." << endl;
        delete head;
        head = tail = nullptr;
    } else {
        Node* bantu = head;
        while (bantu->next != tail) {
            bantu = bantu->next;
        }
        cout << "- Hapus Belakang\n\n";
        cout << "Data " << tail->nama << " berhasil dihapus." << endl;
        delete tail;
        tail = bantu;
        tail->next = nullptr;
    }
}

// Fungsi untuk menghapus node berdasarkan posisi
void hapusTengah(int posisi) {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else if (posisi == 1) {
        hapusDepan();
    } else {
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1 && bantu->next != nullptr) {
            bantu = bantu->next;
            nomor++;
        }
        if (nomor == posisi - 1 && bantu->next != nullptr) {
            cout << "\nData " << bantu->next->nama << " berhasil dihapus." << endl;
            Node* hapus = bantu->next;
            bantu->next = hapus->next;
            delete hapus;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    }
}


// Fungsi untuk memperbarui data mahasiswa di depan linked list
void updateDepan(string namaBaru, intptr_t nimBaru) {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else {
        cout << "Data " << head->nama << " telah diganti dengan data " << namaBaru << "." << endl;
        head->nama = namaBaru;
        head->nim = nimBaru;
    }
}

// Fungsi untuk memperbarui data mahasiswa di belakang linked list
void updateBelakang(string namaBaru, intptr_t nimBaru) {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else {
        cout << "Data " << tail->nama << " telah diganti dengan data " << namaBaru << "." << endl;
        tail->nama = namaBaru;
        tail->nim = nimBaru;
    }
}

// Fungsi untuk memperbarui data mahasiswa di tengah linked list
void updateTengah(string namaBaru, intptr_t nimBaru, int posisi) {
    if (isEmpty()) {
        cout << "Linked list kosong." << endl;
    } else if (posisi == 1) {
        head->nama = namaBaru;
        head->nim = nimBaru;
    } else {
        Node* bantu = head;
        int nomor = 1;
        while (nomor < posisi && bantu != nullptr) {
            bantu = bantu->next;
            nomor++;
        }
        if (bantu != nullptr) {
            cout << "Data " << bantu->nama << " telah diganti dengan data " << namaBaru << "." << endl;
            bantu->nama = namaBaru;
            bantu->nim = nimBaru;
        } else {
            cout << "Posisi tidak valid" << endl;
        }
    }
}

// Fungsi untuk menghapus seluruh data dari linked list
void hapusSeluruhData() {
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next; // Simpan pointer ke node berikutnya
        delete current;       // Hapus node saat ini
        current = next;       // Pindah ke node berikutnya
    }

    // Atur head dan tail menjadi nullptr setelah menghapus semua node
    head = tail = nullptr;
}

// Fungsi utama
int main() {
    init();  // Inisialisasi linked list

    int pilihan;
    string nama;
    string namaBaruDepan;  // Deklarasi di sini
    string namaBaruBelakang;  // Deklarasi di sini
    string namaBaruTengah;  // Deklarasi di sini
    intptr_t nim;
    intptr_t nimBaruDepan;
    intptr_t nimBaruBelakang;
    intptr_t nimBaruTengah;

    do {
        cout << "\nMenu:";
        cout << "\n1. Tambah Data Mahasiswa (Depan)";
        cout << "\n2. Tambah Data Mahasiswa (Belakang)";
        cout << "\n3. Tambah Data Mahasiswa (Tengah)";
        cout << "\n4. Hapus Data Mahasiswa (Depan)";
        cout << "\n5. Hapus Data Mahasiswa (Belakang)";
        cout << "\n6. Hapus Data Mahasiswa (Tengah)";
        cout << "\n7. Perbarui Data Mahasiswa (Depan)";
        cout << "\n8. Perbarui Data Mahasiswa (Belakang)";
        cout << "\n9. Perbarui Data Mahasiswa (Tengah)";
        cout << "\n10. Tampilkan Data Mahasiswa";
        cout << "\n11. Hapus Seluruh Data";
        cout << "\n0. Keluar";
        cout << "\nPilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "- Tambah Depan\n\n";
                cout << "Masukkan Nama : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertDepan(nama, nim);
                cout << "\nData berhasil ditambahkan.";
                break;
            case 2:
                cout << "- Tambah Belakang\n\n";
                cout << "Masukkan Nama : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                insertBelakang(nama, nim);
                cout << "\nData berhasil ditambahkan.";
                break;
            case 3:
                cout << "- Tambah Tengah\n\n";
                int pos;
                cout << "Masukkan Nama : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, nama);
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan posisi : ";
                cin >> pos;
                addBetween(nama, nim, pos);
                cout << "\nData berhasil ditambahkan.";
                break;
            case 4:
                hapusDepan();
                break;
            case 5:
                hapusBelakang();
                break;
            case 6:
                int posHapus;
                cout << "- Hapus Tengah\n\n";
                cout << "Masukkan posisi : ";
                cin >> posHapus;
                hapusTengah(posHapus);
                break;
            case 7:
                cout << "- Perbarui Depan\n\n";
                cout << "Masukkan Nama Baru : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, namaBaruDepan);
                cout << "Masukkan NIM Baru : ";
                cin >> nimBaruDepan;
                updateDepan(namaBaruDepan, nimBaruDepan);
                break;
            case 8:
                cout << "- Perbarui Belakang\n\n";
                cout << "Masukkan Nama Baru : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, namaBaruBelakang);
                cout << "Masukkan NIM Baru : ";
                cin >> nimBaruBelakang;
                updateBelakang(namaBaruBelakang, nimBaruBelakang);
                break;
            case 9:
                cout << "- Perbarui Tengah\n\n";
                int posUpdate;
                cout << "Masukkan posisi : ";
                cin >> posUpdate;
                cout << "Masukkan Nama Baru : ";
                cin.ignore(); // Membersihkan buffer sebelum getline
                getline(cin, namaBaruTengah);
                cout << "Masukkan NIM Baru : ";
                cin >> nimBaruTengah;
                updateTengah(namaBaruTengah, nimBaruTengah, posUpdate);
                break;
            case 10:
                tampilkanData();
                break;
            case 11:
                cout << "Menghapus seluruh data..." << endl;
                hapusSeluruhData();
                cout << "Seluruh data berhasil dihapus." << endl;
                break;
            case 0: 
                cout << "Program berakhir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);

    return 0;
}
