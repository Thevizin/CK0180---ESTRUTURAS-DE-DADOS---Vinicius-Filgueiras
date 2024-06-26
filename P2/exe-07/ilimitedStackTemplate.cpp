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
    stack.top = -1;
}

template<typename T>
void stack_destruct(Stack<T> &stack){
    delete[] stack.array;
    stack.array = nullptr;
}

template<typename T>
void push(Stack<T> &stack, T value){
    if(stack.top == stack.capacity - 1){
        stack.capacity = stack.capacity * 2;
        cout << "Stack is full, generating a array with size "<< stack.capacity << "..." << endl;
        T  *newArray = new T [stack.capacity];
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
    if(stack.top == (stack.capacity / 2) - 1 && stack.capacity >= 10){
        stack.capacity = stack.capacity / 2;
        cout << "The stack is too big for too few values, decreasing to "<< stack.capacity << "..." << endl;
        T  *newArray = new T [stack.capacity];
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
    if (stack.top == -1) {
        cerr << "The stack is empty." << endl;
        exit(EXIT_FAILURE);
    }
    T  value = stack.array[stack.top];
    cout << stack.array[stack.top] << " Removed" << endl;
    stack.top --;
    return value;
}

template<typename T>
void display(Stack<T> &stack){
    if(stack.top == -1) cout << "The Stack is empty." << endl;
    else{
        
        cout << "Size: " << stack.capacity << "\n" << "Stack: ";
        for(int i = 0; i <= stack.top; i++){
            cout << stack.array[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    Stack<double> stackDb;
    stack_construct(stackDb);

    for(double i = 1; i < 21; ++i){
        push(stackDb, i/10);
    }

    display(stackDb);

    for(int i = 1; i < 19; ++i){
        pop(stackDb);
    }

    display(stackDb);

    Stack<int> stackInt;
    stack_construct(stackInt);

    for(int i = 1; i < 21; ++i){
        push(stackInt, i*10);
    }

    display(stackInt);

    for(int i = 1; i < 19; ++i){
        pop(stackInt);
    }

    display(stackInt);

    return 0;

}