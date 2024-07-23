#include <iostream>
using namespace std;

struct Stack{
    struct Node{
        double data;
        Node *next;
    };

    Node *top;
    
    Stack(){
        top = nullptr;
    }

    bool is_empty(){
        return(top == nullptr);
    }

    void push(double newdata){
        Node *newNode = new Node;
        newNode->data = newdata;
        newNode->next = top;
        top = newNode;
        cout << "Push: " << newdata << endl;

        //We can also use this: top = new Node {newdata, top};
    }

    double see_top(){
        return top->data;
    }

    void pop(){
        if(not is_empty()){
            cout << "Removing: " << top->data << endl;
            Node *beclear = top;
            top = top->next;
            delete beclear;
            
        }
        else{
            cout << "The stack is empty" << endl;
            return;
        }
    }

    void display(){
        if(not is_empty()){
            Node *current = top;
            cout << "Stack:" << endl;
            cout << current->data << "; ";
            while(current->next != nullptr){
                current = current->next;
                cout << current->data << "; ";
            }
            cout << endl;
        }
        else{
            cout << "The stack is empty" << endl;
        }
    }

    ~Stack(){
        while(top != nullptr){
            Node *current = top;
            top = top->next;
            delete current;
        }
    }  
};

int main() {
    Stack stack;

    stack.push(10.5);
    stack.push(20.3);
    stack.push(30.8);

    cout << "Top of the Stack: " << stack.see_top() << endl;
    stack.display();

    stack.pop();
    cout << "Top of the Stack: " << stack.see_top() << endl;
    stack.display();

    stack.pop();
    cout << "Top of the Stack: " << stack.see_top() << endl;
    stack.display();

    stack.pop();
    stack.display();
    stack.pop();

    return 0;
}