#include <iostream>
#define INITIAL_CAPACITY 5
using namespace std;

template<typename T>
struct Stack{
    T *array;
    int capacity;
    int top;
};

template<typename T>
void stack_construct(Stack<T> &stack){
    stack.array = new T[INITIAL_CAPACITY];
    if(stack.array == nullptr){
        cerr << "Memory allocation error" << endl;
        exit(EXIT_FAILURE);
    }
    stack.capacity = INITIAL_CAPACITY;
    stack.top = -1; //Empty Stack
}

template<typename T>
void stack_destruct(Stack<T> &stack){
    delete[] stack.array;
    stack.array = nullptr;
}

template<typename T>
void push(Stack<T> &stack, T value){
    if(stack.top == stack.capacity - 1){
        cout << "Stack full, generating a new array..." << endl;
        stack.capacity = stack.capacity * 2;
        T *newArray = new T[stack.capacity];
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

template<typename T>
T pop(Stack<T> &stack){
    if (stack.top == -1) {
        cerr << "The stack is empty." << endl;
        exit(EXIT_FAILURE);
    }
    T value = stack.array[stack.top];
    stack.top --;
    return value;
}

template<typename T>
void display(Stack<T> &stack){
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
    Stack<int> intStack;
    stack_construct(intStack);

    for (int i = 0; i < 20; ++i) {
        push(intStack, i*10);
    }

    display(intStack);

    for (int i = 0; i < 10; ++i) {
        cout << "Popped element: " << pop(intStack) << endl;
    }

    display(intStack);

    // Testing with double
    Stack<double> doubleStack;
    stack_construct(doubleStack);

    for (int i = 0; i < 5; ++i) {
        push(doubleStack, i*3.14);
    }

    display(doubleStack);

    return 0;
}
