#include <iostream>
#define INITIAL_CAPACITY 5
using namespace std;

struct Stack{
    double *array;
    int capacity;
    int top;
};

void stack_construct(Stack &stack){
    stack.array = new double[INITIAL_CAPACITY];
    if(stack.array == nullptr){
        cerr << "Memory allocation error" << endl;
        exit(EXIT_FAILURE);
    }
    stack.capacity = INITIAL_CAPACITY;
    stack.top = -1;
}

void stack_destruct(Stack &stack){
    delete[] stack.array;
    stack.array = nullptr;
}

void push(Stack &stack, double value){
    if(stack.top == stack.capacity - 1){
        stack.capacity = stack.capacity * 2;
        cout << "Stack is full, generating a array with size "<< stack.capacity << "..." << endl;
        double *newArray = new double[stack.capacity];
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

double pop(Stack &stack){
    if(stack.top == (stack.capacity / 2) - 1 && stack.capacity >= 10){
        stack.capacity = stack.capacity / 2;
        cout << "The stack is too big for too few values, decreasing to "<< stack.capacity << "..." << endl;
        double *newArray = new double[stack.capacity];
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
    double value = stack.array[stack.top];
    cout << stack.array[stack.top] << " Removed" << endl;
    stack.top --;
    return value;
}

void display(Stack &stack){
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
    Stack stack;
    stack_construct(stack);

    for(double i = 1; i < 21; ++i){
        push(stack, i*10);
    }

    display(stack);

    for(int i = 1; i < 19; ++i){
        pop(stack);
    }

    display(stack);

    return 0;

}