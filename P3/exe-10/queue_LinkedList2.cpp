#include <iostream>
using namespace std;

class Queue{
    struct Node{
        double data;
        Node *next;
    };

    Node *start, *finish;

public:
    Queue() : start{nullptr}, finish{nullptr} {}

    void enqueue(double newdata){
        Node *newnode = new Node {newdata, nullptr};
        (finish == nullptr ? start : finish->next) = newnode;
        finish = newnode;
    }

    void dequeue(){
        Node *first = start;
    }


};