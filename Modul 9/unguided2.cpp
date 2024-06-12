
#include <iostream>
#include <queue>
using namespace std;

// Deklarasi Pohon
struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};
Pohon *root, *baru;

// Inisialisasi
void init() {
    root = NULL;
}

// Cek Node
int isEmpty() {
    return (root == NULL);
}

// Buat Node Baru
void buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\n Pohon sudah dibuat" << endl;
    }
}

// Cari Node Berdasarkan Data
Pohon* findNode(Pohon* node, char data) {
    if (node == NULL) return NULL;
    if (node->data == data) return node;
    Pohon* foundNode = findNode(node->left, data);
    if (foundNode == NULL) foundNode = findNode(node->right, data);
    return foundNode;
}

// Tambah Kiri
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        // cek apakah child kiri ada atau tidak
        if (node->left != NULL) {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Tambah Kanan
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        // cek apakah child kanan ada atau tidak
        if (node->right != NULL) {
            // kalau ada
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            // kalau tidak ada
            baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Ubah Data Tree
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        else {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi " << data << endl;
        }
    }
}

// Lihat Isi Data Tree
void retrieve(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

// Cari Data Tree
void find(Pohon* node) {
    if (!root) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node)
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        else {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child Kiri : (tidak punya Child kiri)" << endl;
            else
                cout << " Child Kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child Kanan : (tidak punya Child kanan)" << endl;
            else
                cout << " Child Kanan : " << node->right->data << endl;
        }
    }
}

// Penelurusan (Traversal)
// preOrder
void preOrder(Pohon* node) {
    if (node != NULL) {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

// inOrder
void inOrder(Pohon* node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

// postOrder
void postOrder(Pohon* node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}

// Hapus Node Tree
void deleteTree(Pohon* node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        if (node == root) {
            delete root;
            root = NULL;
        } else {
            delete node;
        }
    }
}

// Hapus SubTree
void deleteSub(Pohon* node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        node->left = NULL;
        node->right = NULL;
        cout << "\n Node subtree " << node->data << " berhasil dihapus." << endl;
    }
}

// Hapus Tree
void clear() {
    deleteTree(root);
    cout << "\n Pohon berhasil dihapus." << endl;
}

// Cek Size Tree
int size(Pohon* node) {
    if (node == NULL) {
        return 0;
    } else {
        return 1 + size(node->left) + size(node->right);
    }
}

// Cek Height Level Tree
int height(Pohon* node) {
    if (node == NULL) {
        return 0;
    } else {
        int heightKiri = height(node->left);
        int heightKanan = height(node->right);
        return max(heightKiri, heightKanan) + 1;
    }
}

// Karakteristik Tree
void characteristic() {
    cout << "\n Size Tree : " << size(root) << endl;
    cout << " Height Tree : " << height(root) << endl;
    cout << " Average Node of Tree : " << (height(root) == 0 ? 0 : size(root) / height(root)) << endl;
}

// Menampilkan Child Node
void showChildren(Pohon* node) {
    if (node) {
        if (node->left)
            cout << " Child Kiri: " << node->left->data << endl;
        else
            cout << " Child Kiri: (tidak punya Child kiri)" << endl;
        if (node->right)
            cout << " Child Kanan: " << node->right->data << endl;
        else
            cout << " Child Kanan: (tidak punya Child kanan)" << endl;
    }
}

// Menampilkan Descendants Node
void showDescendants(Pohon* node) {
    if (node) {
        cout << " Descendants of Node " << node->data << ": ";
        preOrder(node);
        cout << endl;
    }
}

void menu() {
    int pilihan;
    char data;
    char raka_2311102054;
    Pohon* temp = nullptr;
    do {
        cout << "\nMENU:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Retrieve Node\n";
        cout << "6. Find Node\n";
        cout << "7. Tampilkan PreOrder\n";
        cout << "8. Tampilkan InOrder\n";
        cout << "9. Tampilkan PostOrder\n";
        cout << "10. Tampilkan Characteristic\n";
        cout << "11. Hapus SubTree\n";
        cout << "12. Hapus Tree\n";
        cout << "13. Tampilkan Children\n";
        cout << "14. Tampilkan Descendants\n";
        cout << "0. Keluar\n";
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
        case 1:
            if (isEmpty()) {
                cout << "Masukkan data root: ";
                cin >> data;
                buatNode(data);
            } else {
                cout << "\n Root sudah ada!" << endl;
            }
            break;
        case 2:
            if (!isEmpty()) {
                cout << "Masukkan data node kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                insertLeft(data, temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 3:
            if (!isEmpty()) {
                cout << "Masukkan data node kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                insertRight(data, temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 4:
            if (!isEmpty()) {
                cout << "Masukkan data baru: ";
                cin >> data;
                cout << "Masukkan data node yang akan diupdate: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                update(data, temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 5:
            if (!isEmpty()) {
                cout << "Masukkan data node yang akan dilihat: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                retrieve(temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 6:
            if (!isEmpty()) {
                cout << "Masukkan data node yang akan dicari: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                find(temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 7:
            if (!isEmpty()) {
                cout << "\n PreOrder :" << endl;
                preOrder(root);
                cout << "\n" << endl;
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 8:
            if (!isEmpty()) {
                cout << "\n InOrder :" << endl;
                inOrder(root);
                cout << "\n" << endl;
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 9:
            if (!isEmpty()) {
                cout << "\n PostOrder :" << endl;
                postOrder(root);
                cout << "\n" << endl;
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 10:
            if (!isEmpty()) {
                characteristic();
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 11:
            if (!isEmpty()) {
                cout << "Masukkan data node yang subtreenya akan dihapus: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                deleteSub(temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 12:
            clear();
            break;
        case 13:
            if (!isEmpty()) {
                cout << "Masukkan data node yang akan ditampilkan childnya: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                showChildren(temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 14:
            if (!isEmpty()) {
                cout << "Masukkan data node yang akan ditampilkan descendantnya: ";
                cin >> raka_2311102054;
                temp = findNode(root, raka_2311102054);
                showDescendants(temp);
            } else {
                cout << "\n Buat tree terlebih dahulu!" << endl;
            }
            break;
        case 0:
            cout << "\n Keluar dari program..." << endl;
            break;
        default:
            cout << "\n Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);
}

int main() {
    init();
    menu();
    return 0;
}
