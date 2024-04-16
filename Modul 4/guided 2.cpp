#include <iostream>
using namespace std;

// Definisi struktur Node untuk linked list
struct Node {
    string data;  // Data yang disimpan dalam node
    Node *next;   // Pointer yang menunjukkan ke node berikutnya
};

// Deklarasi pointer global untuk head, tail, serta node baru, bantu, dan hapus
Node *head, *tail, *baru, *bantu, *hapus;

// Fungsi untuk menginisialisasi linked list
void init() {
    head = NULL;  // Atur pointer head menjadi NULL
    tail = head;  // Atur pointer tail menjadi NULL
}

// Fungsi untuk memeriksa apakah linked list kosong
int isEmpty() {
    return head == NULL;  // Mengembalikan 1 jika head adalah NULL, 0 jika tidak
}

// Fungsi untuk membuat node baru dengan data tertentu
void buatNode(string data) {
    baru = new Node;  // Buat node baru
    baru->data = data;  // Atur nilai data pada node baru
    baru->next = NULL;  // Atur pointer next node baru menjadi NULL
}

// Fungsi untuk menghitung jumlah node dalam linked list
int hitungList() {
    bantu = head;  // Pointer untuk menelusuri linked list
    int jumlah = 0;  // Variabel untuk menyimpan jumlah node

    while (bantu != NULL) {  // Selama pointer tidak NULL
        jumlah++;  // Tambahkan 1 ke jumlah
        bantu = bantu->next;  // Geser pointer ke node berikutnya
    }
    return jumlah;  // Kembalikan jumlah node
}

// Fungsi untuk menyisipkan node baru di depan linked list
void insertDepan(string data) {
    buatNode(data);  // Buat node baru dengan data yang diberikan
    if (isEmpty()) {  // Jika linked list kosong
        head = baru;  // Atur head menjadi node baru
        tail = head;  // Atur tail menjadi head
        baru->next = head;  // Atur pointer next node baru ke head
    } else {
        while (tail->next != head) {  // Temukan node terakhir
            tail = tail->next;  // Geser pointer tail ke node berikutnya
        }
        baru->next = head;  // Atur pointer next node baru ke head
        head = baru;  // Perbarui head menjadi node baru
        tail->next = head;  // Hubungkan node terakhir dengan head
    }
}

// Fungsi untuk menyisipkan node baru di belakang linked list
void insertBelakang(string data) {
    buatNode(data);  // Buat node baru dengan data yang diberikan
    if (isEmpty()) {  // Jika linked list kosong
        head = baru;  // Atur head menjadi node baru
        tail = head;  // Atur tail menjadi head
        baru->next = head;  // Atur pointer next node baru ke head
    } else {
        while (tail->next != head) {  // Temukan node terakhir
            tail = tail->next;  // Geser pointer tail ke node berikutnya
        }
        tail->next = baru;  // Hubungkan node terakhir dengan node baru
        baru->next = head;  // Atur pointer next node baru ke head
    }
}

// Fungsi untuk menyisipkan node baru di tengah linked list pada posisi tertentu
void insertTengah(string data, int posisi) {
    if (isEmpty()) {  // Jika linked list kosong
        head = baru;  // Atur head menjadi node baru
        tail = head;  // Atur tail menjadi head
        baru->next = head;  // Atur pointer next node baru ke head
    } else {
        baru->data = data;  // Atur nilai data pada node baru
        int nomor = 1;  // Variabel untuk menyimpan nomor posisi
        bantu = head;  // Pointer untuk menelusuri linked list

        // Temukan posisi node sebelum posisi yang dituju
        while (nomor < posisi - 1) {
            bantu = bantu->next;  // Geser pointer bantu
            nomor++;  // Tambahkan 1 ke nomor
        }

        baru->next = bantu->next;  // Atur pointer next node baru
        bantu->next = baru;  // Hubungkan node sebelumnya dengan node baru
    }
}

// Fungsi untuk menghapus node dari depan linked list
void hapusDepan() {
    if (!isEmpty()) {  // Jika linked list tidak kosong
        hapus = head;  // Simpan pointer ke node yang akan dihapus
        tail = head;  // Atur tail menjadi head

        // Jika linked list hanya memiliki satu node
        if (hapus->next == head) {
            head = NULL;  // Atur head menjadi NULL
            tail = NULL;  // Atur tail menjadi NULL
            delete hapus;  // Hapus node yang disimpan
        } else {
            while (tail->next != hapus) {  // Temukan node terakhir
                tail = tail->next;  // Geser pointer tail ke node berikutnya
            }
            head = head->next;  // Atur head baru menjadi node setelahnya
            tail->next = head;  // Hubungkan node terakhir dengan head
            hapus->next = NULL;  // Putuskan hubungan node yang dihapus dengan linked list
            delete hapus;  // Hapus node yang disimpan
        }
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus node dari belakang linked list
void hapusBelakang() {
    if (!isEmpty()) {  // Jika linked list tidak kosong
        hapus = head;  // Simpan pointer ke node yang akan dihapus
        tail = head;  // Atur tail menjadi head

        // Jika linked list hanya memiliki satu node
        if (hapus->next == head) {
            head = NULL;  // Atur head menjadi NULL
            tail = NULL;  // Atur tail menjadi NULL
            delete hapus;  // Hapus node yang disimpan
        } else {
            while (hapus->next != head) {  // Temukan node sebelum node terakhir
                hapus = hapus->next;  // Geser pointer hapus ke node berikutnya
            }
            while (tail->next != hapus) {  // Temukan node sebelum node hapus
                tail = tail->next;  // Geser pointer tail ke node berikutnya
            }
            tail->next = head;  // Hubungkan node sebelumnya dengan head
            hapus->next = NULL;  // Putuskan hubungan node yang dihapus dengan linked list
            delete hapus;  // Hapus node yang disimpan
        }
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus node dari tengah linked list pada posisi tertentu
void hapusTengah(int posisi) {
    if (!isEmpty()) {  // Jika linked list tidak kosong
        int nomor = 1;  // Variabel untuk menyimpan nomor posisi
        bantu = head;  // Pointer untuk menelusuri linked list

        // Temukan node sebelum node yang akan dihapus
        while (nomor < posisi - 1) {
            bantu = bantu->next;  // Geser pointer bantu
            nomor++;  // Tambahkan 1 ke nomor
        }

        hapus = bantu->next;  // Simpan pointer ke node yang akan dihapus
        bantu->next = hapus->next;  // Hubungkan node sebelumnya dengan node setelahnya
        delete hapus;  // Hapus node yang disimpan
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi untuk menghapus semua node dari linked list
void clearList() {
    if (head != NULL) {  // Jika linked list tidak kosong
        hapus = head->next;  // Simpan pointer ke node setelah head
        while (hapus != head) {  // Selama masih ada node yang tersisa
            bantu = hapus->next;  // Simpan pointer ke node setelah node yang akan dihapus
            delete hapus;  // Hapus node yang disimpan
            hapus = bantu;  // Atur pointer hapus ke node berikutnya
        }
        delete head;  // Hapus node head
        head = NULL;  // Atur head menjadi NULL
    }
    cout << "List berhasil terhapus!" << endl;  // Tampilkan pesan berhasil
}

// Fungsi untuk menampilkan isi linked list
void tampil() {
    if (!isEmpty()) {  // Jika linked list tidak kosong
        tail = head;  // Atur tail menjadi head
        do {
            cout << tail->data << " ";  // Tampilkan nilai data node
            tail = tail->next;  // Geser pointer tail ke node berikutnya
        } while (tail != head);  // Lakukan iterasi sampai kembali ke head
        cout << endl;  // Pindah baris setelah selesai menampilkan linked list
    } else {
        cout << "List masih kosong!" << endl;  // Tampilkan pesan jika linked list kosong
    }
}

// Fungsi utama
int main() {
    init();  // Inisialisasi linked list
    insertDepan("Ayam");  // Sisipkan node dengan nilai "Ayam" di depan linked list
    tampil();  // Tampilkan isi linked list
    insertDepan("Bebek");  // Sisipkan node dengan nilai "Bebek" di depan linked list
    tampil();
    insertBelakang("Cicak");  // Sisipkan node dengan nilai "Cicak" di belakang linked list
    tampil();  
    insertBelakang("Domba");  // Sisipkan node dengan nilai "Domba" di belakang linked list
    tampil();  
    hapusBelakang();  // Hapus node terakhir dari linked list
    tampil();  
    hapusDepan();  // Hapus node pertama dari linked list
    tampil();
    insertTengah("Sapi", 2);  // Sisipkan node dengan nilai "Sapi" di posisi kedua linked list
    tampil(); 
    hapusTengah(2);  // Hapus node pada posisi kedua dari linked list
    tampil();  
    return 0;  
}
