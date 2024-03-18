#include <iostream>
using namespace std;

struct Queue{
  int front, back;
  int queue1[5], queue2[5];
};

void start(Queue &queue){
  queue.front = -1;
}

bool full(Queue &queue){
  return ( (queue.back +1) % 10 == queue.front);
}

bool empty(Queue &queue){
  return (queue.front == -1);
}

void enqueue(Queue &queue, int x){
  if(full(queue)) 
    cout << "Queue full" << endl;
  else if(empty(queue)){
    queue.front = queue.back = 0;
    queue.queue1[queue.back] = x;
    cout << x << " Added" << endl;
  }
  else{
    queue.back = (queue.back + 1) % 10;
    if(queue.back < 4){
        queue.queue1[queue.back] = x;
        cout << x << " Added" << endl;
    }
    else{
        queue.queue2[queue.back - 5] = x;
        cout << x << " Added" << endl;
    }
  }
}
void dequeue(Queue &queue){
  if(empty(queue)) 
    cout << "The queue is empty" << endl;

  else if(queue.front == queue.back){
    if(queue.front <= 4) cout << queue.queue1[queue.front] << " Removed" << endl;
    else cout << queue.queue2[queue.front - 5] << " Removed" << endl;
    queue.front = -1;
  }
  else{
    if(queue.front <= 4) cout << queue.queue1[queue.front] << " Removed" << endl;
    else cout << queue.queue2[queue.front - 5] << " Removed" << endl;
    queue.front = (queue.front + 1) % 10;
  }
}

void display(Queue &queue){
  if(empty(queue)) 
    cout << "The queue is empty" << endl;
  else if(full(queue)) 
    cout << "The queue is full" << endl;
  else{
    cout << "Queue: ";
    for(int i = queue.front; i != (queue.back + 1) % 10; i = (i + 1) % 10){
      if(i <= 4) cout << queue.queue1[i] << " "; 
      else cout << queue.queue2[i - 5] << " "; 
    }
    cout << endl;
  }
}

int main() {
  Queue q;
  start(q);
  enqueue(q, 1);
  enqueue(q, 2);
  enqueue(q, 3);
  enqueue(q, 4);
  enqueue(q, 5);
  enqueue(q, 6);
  enqueue(q, 7);
  display(q);
  enqueue(q, 8);
  display(q);
  dequeue(q);
  display(q);
  dequeue(q);
  display(q);

  return 0;
}
