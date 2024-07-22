#include <iostream>
#define INITIAL_CAPACITY 4
using namespace std;

struct Queue {
    double *array;
    int capacity;
    int front;
    int rear;
};

void queue_construct(Queue &queue) {
    queue.front = -1;
    queue.rear = -1;
    queue.capacity = INITIAL_CAPACITY;
    queue.array = new double[queue.capacity];
    if (queue.array == nullptr) {
        cerr << "Memory allocation error" << endl;
        exit(EXIT_FAILURE);
    }
}

void queue_destruct(Queue &queue) {
    delete[] queue.array;
    queue.array = nullptr;
}

int sizeOf(Queue &queue) {
    if (queue.front == -1) return 0;
    if (queue.rear >= queue.front) {
        return (queue.rear - queue.front + 1);
    } else {
        return (queue.capacity - queue.front + queue.rear + 1);
    }
}

void resize(Queue &queue, int new_capacity) {
    double *newArray = new double[new_capacity];
    int j = 0;
    for (int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity) {
        newArray[j++] = queue.array[i];
    }
    newArray[j++] = queue.array[queue.rear];

    delete[] queue.array;
    queue.array = newArray;
    queue.capacity = new_capacity;
    queue.front = 0;
    queue.rear = j - 1;

    cout << "Queue resized to " << new_capacity << endl;
}

void enqueue(Queue &queue, double value) {
    if (sizeOf(queue) >= queue.capacity - 1) {
        resize(queue, queue.capacity * 2);
    }
    if (sizeOf(queue) == 0) {
        queue.front = queue.rear = 0;
    } else {
        queue.rear = (queue.rear + 1) % queue.capacity;
    }
    queue.array[queue.rear] = value;
    cout << "Enqueued: " << value << endl;
}

void dequeue(Queue &queue) {
    if (sizeOf(queue) == 0) {
        cout << "The Queue is empty\n";
        return;
    }
    cout << "Dequeued: " << queue.array[queue.front] << endl;
    if (queue.front == queue.rear) {
        queue.front = queue.rear = -1;
    } else {
        queue.front = (queue.front + 1) % queue.capacity;
    }
    if (sizeOf(queue) > 0 && sizeOf(queue) < queue.capacity / 4 && queue.capacity > INITIAL_CAPACITY) {
        resize(queue, queue.capacity / 2);
    }
}

void display(Queue &queue) {
    if (queue.front == -1) {
        cout << "The queue is empty" << endl;
        return;
    }
    cout << "Queue: ";
    for (int i = queue.front; i != queue.rear; i = (i + 1) % queue.capacity) {
        cout << queue.array[i] << " ";
    }
    cout << queue.array[queue.rear] << endl;
}

int main() {
    Queue q;
    queue_construct(q);

    for (int i = 0; i < 20; ++i) {
        enqueue(q, i * 10);
    }

    display(q);

    for (int i = 0; i < 15; ++i) {
        dequeue(q);
    }

    for (int i = 20; i < 30; ++i) {
        enqueue(q, i * 10);
    }

    display(q);

    queue_destruct(q);
    return 0;
}
