#include <iostream>

using namespace std;

struct Node
{
    string data;
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
    void enqueue(string data)
    {
        Node *newNode = new Node;
        newNode->data = data;
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
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    Queue queue;
    cout << "\nMenambahkan 3 orang ke antrian" << endl;
    queue.enqueue("Andi");
    queue.enqueue("Maya");
    queue.enqueue("Budi");
    queue.viewQueue();
    cout << "\nMengurangi antrian, orang yang pertama masuk akan pertama keluar " << endl;
    queue.dequeue();
    queue.viewQueue();
    cout << "\nMenambahkan 2 orang ke antrian" << endl;
    queue.enqueue("Ucup");
    queue.enqueue("Umar");
    queue.viewQueue();
    cout << "\nMenghapus semua antrian" << endl;
    while (!queue.isEmpty())
    {
        queue.dequeue();
    }
    queue.viewQueue();
    return 0;
}
