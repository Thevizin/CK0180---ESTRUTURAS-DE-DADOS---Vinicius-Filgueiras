#include <iostream>
using namespace std;

struct Stack{
    int last;
    int stack[10];
};

void start(Stack &stack){
    stack.last = -1;
}

bool empty(Stack &stack){
    return(stack.last == -1);
}

bool full(Stack &stack){
    return(stack.last == 9);
}

void stackup(Stack &stack, int valor){
    if(!full(stack)){
        stack.stack[stack.last+1] = valor;
        stack.last ++;
        cout << valor << " Added" << endl;
    }
    else cout << "The stack is full" << endl;
}

void unstack(Stack &stack){
    if(!empty(stack)){
        cout << stack.stack[stack.last] << " Removed" << endl;
        stack.last --;
    }
    else cout << "The stack is empty" << endl;
}

int peek(Stack &stack){
    cout << "value at the top: " << stack.stack[stack.last] << endl;
    return stack.stack[stack.last];
}

void display(Stack &stack){
    if(empty(stack)) cout << "The stack is empty" << endl;
    else if(full(stack)) cout << "The stack is full" << endl;
    else{
        cout << "Stack: ";
        for(int i=0; i<stack.last+1; i++){
            cout << stack.stack[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    Stack s;
    start(s);
    unstack(s);
    stackup(s,1);
    stackup(s,2);
    stackup(s,3);
    stackup(s,4);
    stackup(s,5);
    display(s);
    unstack(s);
    display(s);
}