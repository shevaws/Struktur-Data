#include <iostream>
#include <conio.h>

using namespace std;
struct Node
{
    string nama;
    int nim;
    Node *next;
};
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty()
    {
        return (front == nullptr);
    }
    void enqueue(string nama, int nim)
    {
        Node *newNode = new Node;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = nullptr;
        if (isEmpty())
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }
    void viewQueue()
    {
        if (isEmpty())
        {
            cout << "Antrian kosong" << endl;
        }
        else
        {
            Node *current = front;
            while (current != nullptr)
            {
                cout << "\t\t" << current->nama << " NIM : " << current->nim << endl;
                current = current->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue queue;
    string nama;
    char opsi;
    int nim;
    do
    {
        cout << "\n\n\t\t========================================" << endl;
        cout << "\t\tManajemen Antrian" << endl;
        cout << "\t\t========================================" << endl;
        cout << "\t\t1. Masukkan Data" << endl;
        cout << "\t\t2. Hapus Satu Data" << endl;
        cout << "\t\t3. Reset Data" << endl;
        cout << "\t\t4. Tampil Data" << endl;
        cout << "\t\t========================================" << endl;
        int choice;
        cout << "\t\tMasukkan Pilihan: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            cout << "\t\tMasukkan nama : ";
            getline(cin, nama);
            cout << "\t\tMasukkan NIM : ";
            cin >> nim;
            queue.enqueue(nama, nim);
            break;
        }
        case 2:
        {
            cout << "\t\t[!] 1 Data berhasil dihapus\n";
            queue.dequeue();
            break;
        }
        case 3:
        {
            cout << "\t\t[!] Data berhasil di reset\n";
            while (!queue.isEmpty())
            {
                queue.dequeue();
            }
            break;
        }
        case 4:
        {
            cout << "\t\tTampilkan Data : \n\n";
            queue.viewQueue();
            break;
        }
        }
        cout << endl << "\t\t> Kembali ke menu utama?[Y/n]\n";
        opsi = getch();
        cout << endl;
        system("cls");
        if (opsi == 'n' || opsi == 'N')
        {
            cout << endl;
            cout << "\t\tSee you :) \n";
        }
    } while (opsi == 'y' || opsi == 'Y');

    return 0;
}