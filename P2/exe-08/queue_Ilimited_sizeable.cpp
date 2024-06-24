#include <iostream>
#define INITIAL_CAPACITY 5
using namespace std;

struct Queue{
    int *array;
    int capacity;
    int front;
    int rear;
};

void queue_construct(Queue &queue){
    queue.array = new int[INITIAL_CAPACITY];
     if(queue.array == nullptr){
        cerr << "Memory allocation error" << endl;
        exit(EXIT_FAILURE);
    }
    queue.capacity = INITIAL_CAPACITY;
    queue.front = -1; //Empty Stack
}

void queue_destruct(Queue &queue){
    delete[] queue.array;
    queue.array = nullptr;
}

bool empty(Queue &queue){
    return(queue.front == -1);
}

bool full(Queue &queue){
    return((queue.rear + 1) % queue.capacity == queue.front);
}

int quantity_Values(Queue &queue){
    int quantity;
    if(!empty(queue)){
        if(queue.front <= queue.rear){
            quantity = queue.rear + 1 - queue.front;
        }
        else{
            quantity = queue.rear + 1 + (queue.capacity - queue.front);
        }
    }
    return quantity;
}

bool isMinorThanHalf(Queue &queue){
    return(quantity_Values(queue) < queue.capacity/2);
}

void enqueue(Queue &queue, int value){
    if(full(queue)){
        cout << "Queue is full" << endl;
        cout << "The last capacity: " << queue.capacity << endl;
        int *newArray = new int[queue.capacity * 2];
        int j = 0;
        for(int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity){
            newArray[j++] = queue.array[i];
        }
        newArray[j] = queue.array[queue.rear]; 
        delete[] queue.array;
        queue.array = newArray;
        queue.front = 0;
        queue.rear = j - 1;
        queue.capacity *= 2;
        cout << "The last capacity: " << queue.capacity << endl;
        enqueue(queue, value);
    }
    else if(empty(queue)){
        queue.front = queue.rear = 0;
        queue.array[0] = value;
        cout << value << " Added" << endl;
    }
    else{
        queue.rear = (queue.rear + 1) % queue.capacity;
        queue.array[queue.rear] = value;
        cout << value << " Added" << endl;
    }
}

void dequeue(Queue &queue){
    if(empty(queue)) cout << "The Queue is empty" << endl;
    else if(queue.front == queue.rear){
        cout << queue.array[queue.front] << " removed" << endl;
        queue.front = -1;
    }
    else{
        cout << queue.array[queue.front] << " removed" << endl;
        queue.front = (queue.front + 1) % queue.capacity;
    }
    if(isMinorThanHalf(queue)){
        cout << "The quantity of values is less than half of the capacity of the array" << endl;
        cout << "The last capacity: " << queue.capacity << endl;
        int newCapacity = queue.capacity / 2;
        int *newArray = new int[newCapacity];
        int j = 0;
        for(int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity){
            newArray[j++] = queue.array[i];
        }
        newArray[j++] = queue.array[queue.rear]; 
        delete[] queue.array;
        queue.array = newArray;
        queue.capacity = newCapacity;
        queue.front = 0;
        queue.rear = j - 1;
        cout << "The new capacity: " << queue.capacity << endl;
    }
}

void display(Queue &queue) {
        if (empty(queue)) {
            cout << "A fila está vazia." << endl;
            return;
        }
        cout << "Fila: ";
        for (int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity) {
            cout << queue.array[i] << " ";
        }
        cout << queue.array[queue.rear] << endl;
    }

int main(){
    Queue q;
    queue_construct(q);

    for (int i = 0; i < 20; ++i) {
        enqueue(q, i*10);
    }

    display(q);

    for (int i = 0; i < 15; ++i) {
        dequeue(q);
    }

    for (int i = 20; i < 30; ++i) {
        enqueue(q, i*10);
    }

    display(q);

    return 0;
}