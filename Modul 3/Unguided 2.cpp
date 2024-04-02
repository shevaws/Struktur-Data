#include <iostream>
using namespace std;

// Struktur untuk menyimpan nama produk dan harganya
struct Product {
    string name;
    int price;
};

class Node {
public:
    Product data; // Menggunakan struktur Product
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    // Konstruktor untuk menginisialisasi head dan tail menjadi nullptr
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menambahkan data ke depan linked list
    void push(string name, int price) { // Menggunakan string dan int untuk nama produk dan harga
        Node* newNode = new Node;
        newNode->data.name = name; // Memasukkan nama produk
        newNode->data.price = price; // Memasukkan harga
        newNode->prev = nullptr;
        newNode->next = head;
        
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        
        head = newNode;
    }

    // Fungsi untuk menghapus data dari depan linked list
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        
        delete temp;
    }

    // Fungsi untuk memperbarui data produk berdasarkan nama produk yang lama
    bool update(string oldName, string newName, int newPrice) {
        Node* current = head;
        
        while (current != nullptr) {
            if (current->data.name == oldName) {
                current->data.name = newName;
                current->data.price = newPrice;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Fungsi untuk menghapus semua data dari linked list
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    // Fungsi untuk menampilkan semua data produk dalam linked list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data.name << "\t" << "\t" << current->data.price << endl; // Menampilkan nama dan harga
            current = current->next;
        }
        cout << endl;
    }

    // Fungsi untuk menyisipkan data pada posisi tertentu dalam linked list
    void insert(string name, int price, int position) {
        Node* newNode = new Node;
        newNode->data.name = name;
        newNode->data.price = price;

        if (position <= 1) { // Insert at the beginning
            newNode->prev = nullptr;
            newNode->next = head;

            if (head != nullptr) {
                head->prev = newNode;
            } else {
                tail = newNode;
            }

            head = newNode;
        } else {
            Node* current = head;
            int currentPosition = 1;

            while (currentPosition < position - 1 && current != nullptr) {
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr) { // Position out of range
                cout << "Position out of range" << endl;
                delete newNode;
                return;
            }

            newNode->prev = current;
            newNode->next = current->next;

            if (current->next != nullptr) {
                current->next->prev = newNode;
            } else {
                tail = newNode;
            }

            current->next = newNode;
        }
    }

    // Fungsi untuk menghapus data pada posisi tertentu dalam linked list
    void remove(int position) {
        if (head == nullptr) {
            return;
        }

        if (position <= 1) { // Remove the first node
            Node* temp = head;
            head = head->next;

            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }

            delete temp;
        } else {
            Node* current = head;
            int currentPosition = 1;

            while (currentPosition < position && current != nullptr) {
                current = current->next;
                currentPosition++;
            }

            if (current == nullptr || current->next == nullptr) { // Position out of range
                cout << "Position out of range" << endl;
                return;
            }

            Node* temp = current->next;
            current->next = temp->next;

            if (temp->next != nullptr) {
                temp->next->prev = current;
            } else {
                tail = current;
            }

            delete temp;
        }
    }   
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Tambah data" << endl;
        cout << "2. Hapus data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Tambah data urutan tertentu" << endl;
        cout << "5. Hapus data urutan tertentu" << endl;
        cout << "6. Hapus seluruh data" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Keluar" << endl;
        
        int choice;
        cout << "Masukkan pilihanmu: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string name;
                int price;
                cout << "Enter product name: ";
                cin.ignore(); // Ignore previous newline character
                getline(cin, name); // Input nama produk
                cout << "Enter product price: ";
                cin >> price; // Input harga produk
                list.push(name, price);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string oldName, newName;
                int newPrice;
                cout << "Enter old product name: ";
                cin.ignore(); // Ignore previous newline character
                getline(cin, oldName); // Input nama produk yang lama
                cout << "Enter new product name: ";
                getline(cin, newName); // Input nama produk yang baru
                cout << "Enter new product price: ";
                cin >> newPrice; // Input harga produk yang baru
                bool updated = list.update(oldName, newName, newPrice);
                if (!updated) {
                    cout << "Product not found" << endl;
                }
                break;
            }
            case 4: {
                string name;
                int price, position;
                cout << "Enter product name: ";
                cin.ignore(); // Ignore previous newline character
                getline(cin, name); // Input nama produk
                cout << "Enter product price: ";
                cin >> price; // Input harga produk
                cout << "Enter position to insert: ";
                cin >> position;
                list.insert(name, price, position);
                
                break;
            }
            case 5: {
                int position;
                cout << "Enter position to remove: ";
                cin >> position;
                list.remove(position);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                cout << "Nama Produk\tHarga" << endl;
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
