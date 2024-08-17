#include <iostream>
#include <string>
using namespace std;

class Queue {
    struct Node {
        Node *next;
        Node *rear;
        string value;
    };

    Node *sentinel;

public:
    Queue() {
        sentinel = new Node;
        sentinel->next = sentinel->rear = sentinel;
    }

    ~Queue() {
        while (!empty()) {
            dequeue();
        }
        delete sentinel;
    }

    bool empty() {
        return (sentinel->next == sentinel && sentinel->rear == sentinel);
    }

    void enqueue(string newvalue) {
        Node *newnode = new Node;
        if (newnode == nullptr) {
            cerr << "Memory Error" << endl;
            exit(EXIT_FAILURE);
        }
        cout << "Adding " << newvalue << endl;
        newnode->value = newvalue;
        newnode->next = sentinel;
        if (empty()) {
            sentinel->next = newnode;
            newnode->rear = sentinel;
            sentinel->rear = newnode;
        } else {
            newnode->rear = sentinel->rear;
            sentinel->rear->next = newnode;
            sentinel->rear = newnode;
        }
    }

    void dequeue() {
        if (empty()) {
            cout << "Empty!" << endl;
            return;
        }
        Node *aux = sentinel->next;
        sentinel->next = aux->next;
        sentinel->next->rear = sentinel;
        cout << "Removing " << aux->value << endl;
        delete aux;
    }

    Node* search(string questvalue) {
        if (empty()) {
            cout << "Empty!" << endl;
            return nullptr;
        }
        sentinel->value = questvalue;
        Node *aux = sentinel->next;
        while (aux->value != questvalue) {
            aux = aux->next;
        }
        if (aux != sentinel) {
            return aux;
        }
        return nullptr;
    }

    void display() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *aux = sentinel->next;
        while (aux != sentinel) {
            cout << aux->value << " ";
            aux = aux->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    q.enqueue("Alice");
    q.enqueue("Bob");
    q.enqueue("Charlie");
    q.display();

    q.dequeue();
    q.display();

    q.enqueue("Dave");
    q.display();

    if (q.search("Bob") != nullptr) {
        cout << "Bob found in queue" << endl;
    } else {
        cout << "Bob not found in queue" << endl;
    }

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.display();

    return 0;
}
