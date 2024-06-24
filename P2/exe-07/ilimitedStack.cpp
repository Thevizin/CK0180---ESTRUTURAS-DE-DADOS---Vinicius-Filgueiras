#include <iostream>
#define INITIAL_CAPACITY 5
using namespace std;

struct Stack{
    int *array;
    int capacity;
    int top;
};

void stack_construct(Stack &stack){
    stack.array = new int[INITIAL_CAPACITY];
    if(stack.array == nullptr){
        cerr << "Memory allocation error" << endl;
        exit(EXIT_FAILURE);
    }
    stack.capacity = INITIAL_CAPACITY;
    stack.top = -1; //Empty Stack
}

void stack_destruct(Stack &stack){
    delete[] stack.array;
    stack.array = nullptr;
}

void push(Stack &stack, int value){
    if(stack.top == stack.capacity - 1){
        cout << "Stack full, generating a new array..." << endl;
        stack.capacity = stack.capacity * 2;
        int *newArray = new int[stack.capacity];
        if (newArray == nullptr) {
            cerr << "Memory allocation error." << endl;
            exit(EXIT_FAILURE);
        }
        for(int i = 0; i <= stack.top; i++){
            newArray[i] = stack.array[i];
        }
        stack_destruct(stack);
        stack.array = newArray;
    }
    stack.top ++;
    stack.array[stack.top] = value;
    cout << value << " Added" << endl;
}

int pop(Stack &stack){
    if (stack.top == -1) {
        cerr << "The stack is empty." << endl;
        exit(EXIT_FAILURE);
    }
    int value = stack.array[stack.top];
    stack.top --;
    return value;
}

void display(Stack &stack){
    if (stack.top == -1) cout << "The stack is empty." << endl;
    else{
        cout << "Stack: ";
        for(int i = 0; i <= stack.top; i++){
            cout << stack.array[i] << " ";
        }
        cout << endl; 
    }
}

int main() {
    Stack stack;
    stack_construct(stack);

    for (int i = 0; i < 20; ++i) {
        push(stack, i*10);
    }

    display(stack);

    for (int i = 0; i < 10; ++i) {
        cout << "Popped element: " << pop(stack) << endl;
    }

    display(stack);

    return 0;
}
