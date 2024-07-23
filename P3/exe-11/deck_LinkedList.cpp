#include <iostream>
using namespace std;

class Deck{
    struct Node{
        Node *previous;
        Node *next;
        double data;
    };

    Node *first, *last;

    public:
    
    Deck(){
        first = last = nullptr;
    }

    bool is_empty(){
        return(first == nullptr);
    }

    void push(bool direction, double newdata){
        Node *newNode = new Node;
        newNode->data = newdata;
        if(is_empty()){
            cout << "Added " << newdata << endl;
            first = last = newNode;
            newNode->next = newNode->previous = nullptr;
            return;
        }
        if(direction){
            cout << "Added to the right " << newdata << endl;
            newNode->next = nullptr;
            newNode->previous = last;
            last->next = newNode;
            last = newNode;
        }
        else{
            cout << "Added to the left " << newdata << endl;
            newNode->next = first;
            newNode->previous = last;
            first->previous = newNode;
            first = newNode;
        }
    }

    void pop(bool direction, bool message){
        if(is_empty()){
            if (message) cout << "The Deck is empty" << endl;
            return;
        }
        if(first == last){
            if (message) cout << "Removed " << last->data << endl;
            Node *remove = first;
            first = last = nullptr;
            delete remove;
        }
        else if(direction){
            if (message) cout << "Removed from the right " << last->data << endl;
            Node *remove = last;
            last = last->previous;
            last->next = nullptr;
            delete remove;
        }
        else{
            if (message) cout << "Removed from the left " << first->data << endl;
            Node *remove = first;
            first = first->next;
            first->previous = nullptr;
            delete remove;
        }
    }

    void display(){
        if(is_empty()){
            cout << "The Deck is empty" << endl;
            return;
        }
        cout << "Deck: ";
        Node *current = first;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Deck(){
        while(!is_empty()){
            pop(true, false);
        }
    }
};


int main() {
    Deck deck;

    // Testando a deque
    deck.push(true, 10.5);  // Adiciona à direita
    deck.push(false, 20.3); // Adiciona à esquerda
    deck.push(true, 30.8);  // Adiciona à direita
    deck.push(false, 40.7); // Adiciona à esquerda

    deck.display();

    deck.pop(true, true); // Remove da direita
    deck.display();

    deck.pop(false, true); // Remove da esquerda
    deck.display();

    deck.pop(true, true); // Remove da direita
    deck.display();

    deck.pop(false, true); // Remove da esquerda
    deck.display();

    return 0;
}