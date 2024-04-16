#include <iostream>
using namespace std;

// Definisi struktur Node untuk linked list
struct Node {
    int data;        // Data yang disimpan dalam node
    Node *next;      // Pointer yang menunjukkan ke node berikutnya
};

Node *head;  // Pointer ke kepala/awal linked list
Node *tail;  // Pointer ke ekor/akhir linked list

// Fungsi untuk menginisialisasi linked list
void init() {
    head = NULL;  // Atur pointer head menjadi NULL
    tail = NULL;  // Atur pointer tail menjadi NULL
}

// Fungsi untuk memeriksa apakah linked list kosong
bool isEmpty() {
    return head == NULL;  // Mengembalikan true jika head adalah NULL
}

// Fungsi untuk menyisipkan node baru di depan linked list
void insertDepan(int nilai) {
    Node *baru = new Node;  // Buat node baru
    baru->data = nilai;      // Atur nilai data pada node baru
    baru->next = NULL;       // Atur pointer next node baru menjadi NULL

    if (isEmpty()) {         // Jika linked list kosong
        head = tail = baru;  // Atur head dan tail menjadi node baru
    } else {
        baru->next = head;   // Atur pointer next node baru menuju head
        head = baru;         // Perbarui head menjadi node baru
    }
}

// Fungsi untuk menyisipkan node baru di belakang linked list
void insertBelakang(int nilai) {
    Node *baru = new Node;  // Buat node baru
    baru->data = nilai;      // Atur nilai data pada node baru
    baru->next = NULL;       // Atur pointer next node baru menjadi NULL

    if (isEmpty()) {         // Jika linked list kosong
        head = tail = baru;  // Atur head dan tail menjadi node baru
    } else {
        tail->next = baru;   // Atur pointer next tail menuju node baru
        tail = baru;         // Perbarui tail menjadi node baru
    }
}

// Fungsi untuk menghitung jumlah node dalam linked list
int hitungList() {
    Node *hitung = head;  // Pointer untuk menelusuri linked list
    int jumlah = 0;        // Variabel untuk menyimpan jumlah node

    while (hitung != NULL) {  // Selama pointer tidak NULL
        jumlah++;             // Tambahkan 1 ke jumlah
        hitung = hitung->next;  // Geser pointer ke node berikutnya
    }
    return jumlah;  // Kembalikan jumlah node
}

// Fungsi untuk menyisipkan node baru di tengah linked list pada posisi tertentu
void insertTengah(int data, int posisi) {
    // Penanganan jika posisi di luar jangkauan atau posisi adalah 1
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();  // Buat node baru
        baru->data = data;         // Atur nilai data pada node baru
        Node *bantu = head;        // Pointer bantu untuk menelusuri linked list
        int nomor = 1;             // Nomor untuk menunjukkan posisi saat ini

        // Temukan posisi sebelum posisi yang dituju
        while (nomor < posisi - 1) {
            bantu = bantu->next;  // Geser pointer bantu
            nomor++;              // Tambahkan 1 ke nomor
        }

        // Sisipkan node baru di antara node yang tepat
        baru->next = bantu->next;  // Atur pointer next node baru
        bantu->next = baru;         // Atur pointer next node sebelumnya
    }
}

// Fungsi untuk menghapus node dari depan linked list
void hapusDepan() {
    // Penanganan jika linked list tidak kosong
    if (!isEmpty()) {
        Node *hapus = head;        // Simpan pointer ke node yang akan dihapus

        // Jika masih ada node lain setelah head
        if (head->next != NULL) {
            head = head->next;     // Atur head baru menjadi node setelahnya
        } else {
            head = tail = NULL;    // Atur head dan tail menjadi NULL
        }
        delete hapus;              // Hapus node yang disimpan
    } else {
        cout << "List kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus node dari belakang linked list
void hapusBelakang() {
    // Penanganan jika linked list tidak kosong
    if (!isEmpty()) {
        Node *hapus = tail;        // Simpan pointer ke node yang akan dihapus

        // Jika linked list memiliki lebih dari satu node
        if (head != tail) {
            Node *bantu = head;    // Pointer bantu untuk menelusuri linked list
            // Temukan node sebelum tail
            while (bantu->next != tail) {
                bantu = bantu->next;  // Geser pointer bantu
            }
            tail = bantu;            // Perbarui tail menjadi node sebelumnya
            tail->next = NULL;       // Atur pointer next tail menjadi NULL
        } else {
            head = tail = NULL;     // Atur head dan tail menjadi NULL
        }
        delete hapus;               // Hapus node yang disimpan
    } else {
        cout << "List kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus node dari tengah linked list pada posisi tertentu
void hapusTengah(int posisi) {
    // Penanganan jika posisi di luar jangkauan atau posisi adalah 1
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *bantu = head;     // Pointer bantu untuk menelusuri linked list
        Node *hapus;            // Pointer untuk menyimpan node yang akan dihapus
        Node *sebelum = NULL;   // Pointer untuk menyimpan node sebelum node yang akan dihapus
        int nomor = 1;          // Nomor untuk menunjukkan posisi saat ini

        // Temukan node sebelum node yang akan dihapus
        while (nomor < posisi) {
            sebelum = bantu;    // Simpan pointer sebelum
            bantu = bantu->next;  // Geser pointer bantu
            nomor++;            // Tambahkan 1 ke nomor
        }

        hapus = bantu;          // Simpan pointer ke node yang akan dihapus
        if (sebelum != NULL) {
            sebelum->next = bantu->next;  // Hubungkan node sebelumnya dengan node setelahnya
        } else {
            head = bantu->next;    // Atur head baru jika node pertama dihapus
        }
        delete hapus;               // Hapus node yang disimpan
    }
}

// Fungsi untuk mengubah nilai data dari node di depan linked list
void ubahDepan(int data) {
    // Penanganan jika linked list tidak kosong
    if (!isEmpty()) {
        head->data = data;  // Ubah nilai data pada node head
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk mengubah nilai data dari node di tengah linked list pada posisi tertentu
void ubahTengah(int data, int posisi) {
    // Penanganan jika linked list tidak kosong
    if (!isEmpty()) {
        // Penanganan jika posisi di luar jangkauan atau posisi adalah 1
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;  // Pointer bantu untuk menelusuri linked list
            int nomor = 1;        // Nomor untuk menunjukkan posisi saat ini

            // Temukan node pada posisi yang dituju
            while (nomor < posisi) {
                bantu = bantu->next;  // Geser pointer bantu
                nomor++;              // Tambahkan 1 ke nomor
            }

            bantu->data = data;       // Ubah nilai data pada node yang dituju
        }
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk mengubah nilai data dari node di belakang linked list
void ubahBelakang(int data) {
    // Penanganan jika linked list tidak kosong
    if (!isEmpty()) {
        tail->data = data;  // Ubah nilai data pada node tail
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus semua node dari linked list
void clearList() {
    Node *bantu = head;  // Pointer bantu untuk menelusuri linked list
    Node *hapus;         // Pointer untuk menyimpan node yang akan dihapus

    // Selama masih ada node yang tersisa
    while (bantu != NULL) {
        hapus = bantu;     // Simpan pointer ke node yang akan dihapus
        bantu = bantu->next;  // Geser pointer bantu ke node berikutnya
        delete hapus;      // Hapus node yang disimpan
    }

    head = tail = NULL;   // Atur head dan tail menjadi NULL
    cout << "List berhasil terhapus!" << endl;  // Tampilkan pesan berhasil
}

// Fungsi untuk menampilkan isi linked list
void tampil() {
    Node *bantu = head;  // Pointer untuk menelusuri linked list

    if (!isEmpty()) {    // Jika linked list tidak kosong
        while (bantu != NULL) {
            cout << bantu->data << " ";  // Tampilkan nilai data node
            bantu = bantu->next;          // Geser pointer ke node berikutnya
        }
        cout << endl;  // Pindah baris setelah selesai menampilkan linked list
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi utama
int main() {
    init();            // Inisialisasi linked list
    insertDepan(3);    // Sisipkan node dengan nilai 3 di depan linked list
    tampil();          // Tampilkan isi linked list
    insertBelakang(5); // Sisipkan node dengan nilai 5 di belakang linked list
    tampil();          
    insertDepan(2);    // Sisipkan node dengan nilai 2 di depan linked list
    tampil();          
    insertDepan(1);    // Sisipkan node dengan nilai 1 di depan linked list
    tampil();          
    hapusDepan();      // Hapus node pertama dari linked list
    tampil();          
    hapusBelakang();   // Hapus node terakhir dari linked list
    tampil();       
    insertTengah(7, 2);  // Sisipkan node dengan nilai 7 di posisi kedua linked list
    tampil();          
    hapusTengah(2);      // Hapus node pada posisi kedua dari linked list
    tampil();      
    ubahDepan(1);        // Ubah nilai data node pertama menjadi 1
    tampil();         
    ubahBelakang(8);     // Ubah nilai data node terakhir menjadi 8
    tampil();         
    ubahTengah(11, 2);   // Ubah nilai data node pada posisi kedua menjadi 11
    tampil();         

    return 0;  
}
