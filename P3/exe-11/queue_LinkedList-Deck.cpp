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
        last = nullptr;
    }

    bool is_empty(){
        return(first == nullptr);
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

    void pop(bool display_message = true){ 
        if(is_empty()){
            cout << "The queue is empty" << endl;
            return;
        }
        Node *remove = first;
        if(display_message) cout << "Removing: " << first->data << endl;
        if(first == last){
            first = nullptr;
            last = nullptr;
        }
        else{
            first = first->next;
            first->previous = nullptr;
        }
        delete remove;
    }

    void add_with_priority(double newdata){
        cout << "Push with priority: " << newdata << endl;
        Node *newvalue = new Node;
        newvalue->data = newdata;
        newvalue->previous = nullptr;
        if(is_empty()){
            newvalue->next = nullptr;
            first = newvalue;
            last = newvalue;
        }
        else{
            newvalue->next = first;
            first->previous = newvalue;
            first = newvalue;
        }
    }

    void display(){
        if(is_empty()){
            cout << "The queue is empty" << endl;
            return;
        }
        Node *current = first;
        cout << "Queue: ";
        while(current != nullptr){
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
            pop(false); //I decided to put a parameter to control the message about the removing of items
        }
    }
};

int main() {
    Queue queue;

    queue.push(10.5);
    queue.push(20.3);
    queue.push(30.8);

    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.add_with_priority(50.7);
    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    cout << "First of the Queue: " << queue.seeFirst() << endl;
    queue.display();

    queue.pop();
    queue.pop(); 
    queue.display();

    queue.add_with_priority(40.6);
    queue.add_with_priority(30.5);
    queue.display();

    return 0;
}
