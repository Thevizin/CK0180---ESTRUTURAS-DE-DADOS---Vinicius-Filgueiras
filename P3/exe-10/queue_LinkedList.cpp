#include <iostream>
using namespace std;

struct Queue{
    struct Node{
        double data;
        Node *next;
        Node *previous;
    };

    Node *first;
    Node *last;

    Queue(){
        first = nullptr;
    }

    bool is_empty(){
        return(first==nullptr);
    }

    void push(double newdata){
        cout << "Push: " << newdata << endl;
        Node *newvalue = new Node;
        newvalue->data = newdata;
        newvalue->next = nullptr;
        if(is_empty()){
            newvalue->previous = nullptr;
            first = newvalue;
            last = newvalue;
        }   
        else{
            newvalue->previous = last;
            last->next = newvalue;
            last = newvalue;
        }
    }

    void pop(){
        if(is_empty()){
            cout << "The queue is empty" << endl;
            return;
        }
        Node *remove = first;
        if(first == last){
            cout << "Removing: " << first->data << endl;
            last = nullptr;
            first = nullptr;
        }
        else{
            cout << "Removing: " << first->data << endl;
            first = first->next;
            first->previous = nullptr;
        }
        delete remove;
    }

    void display(){
        if(is_empty()){
            cout << "The queue is empty" << endl;
            return;
        }
        Node *current = first;
        cout << "Queue: ";
        while(current!= nullptr){
            cout << current->data << "; ";
            current = current->next;
        }
        cout << endl;
    }
    
    double seeFirst(){
        if (is_empty()){
            throw runtime_error("Queue is empty");
        }
        return first->data;
    }

     ~Queue(){
        while (!is_empty()){
            pop();
        }
    }
};

int main() {
    Queue queue;

    // Testando a fila
    queue.push(10.5);
    queue.push(20.3);
    queue.push(30.8);

    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    queue.display();
    queue.pop(); 

    return 0;
}