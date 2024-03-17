#include <iostream>
using namespace std;

struct Fila{
  int front, back;
  int fila[10];
};

bool Full(Fila &fila){
  return ( (fila.back +1) % 10 == fila.front);
}

bool Empty(Fila &fila){
  return (fila.front == -1);
}

void Enqueue(Fila &fila, int x){
  if(Full(fila)) 
    cout << "Fila cheia" << endl;
  else if(Empty(fila)){
    fila.front = fila.back = 0;
    fila.fila[fila.back] = x;
    cout << x << " Adicionado" << endl;
  }
  else{
    fila.back = (fila.back + 1) % 10;
    fila.fila[fila.back] = x;
    cout << x << " Adicionado" << endl;
  }
}

void Dequeue(Fila &fila){
  if(Empty(fila)) 
    cout << "a Fila está vazia" << endl;
  else if(fila.front == fila.back){
    cout << fila.fila[fila.front] << " Removido" << endl;
    fila.front = -1;
  }
  else{
    cout << fila.fila[fila.front] << " Removido" << endl;
    fila.front = (fila.front + 1) % 10;
  }
}

void Display(Fila &fila){
  if(Empty(fila)) 
    cout << "a Fila está vazia" << endl;
  else{
    cout << "Fila: ";
    for(int i = fila.front; i != (fila.back + 1) % 10; i = (i + 1) % 10){
      cout << fila.fila[i] << " ";
    }
    cout << endl;
  }
}

int main() {
  Fila f;
  f.front = f.back = -1;
  Enqueue(f, 1);
  Enqueue(f, 2);
  Enqueue(f, 3);
  Display(f);
  Enqueue(f, 4);
  Display(f);
  Dequeue(f);
  Display(f);

  return 0;
}
