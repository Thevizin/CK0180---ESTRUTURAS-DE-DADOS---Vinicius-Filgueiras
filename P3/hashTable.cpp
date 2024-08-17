#include <iostream>
using namespace std;

class Hash{
    struct Node{
        Node *next;
        int key;
        double value;
    };
    Node **table; // Pointer that points to a pointer to Nodes
    Node sent; // We don't need to allocate our sentinel Node, because we never change it
    int size; // The size of the array
    int quantity; // The qauntity of elements on the table

    void reshape(int newsize){
        Node **newtable = new Node* [newsize];
        int actualSize = size;
        size = newsize;
        int i;
        for(i = 0; i < newsize; i++) newtable[i] = &sent;
        for(i = 0; i < newsize; i++){
            Node *n = table[i];
            while(n != &sent){
                Node *p = n->next;
                int j = hash(n->key);
                n->next = newtable[j];
                newtable[j] = n;
                n = p;
            }
        }
        delete[] table;
        table = newtable;
    }

    int hash(int newkey){
        return newkey % size;
    }

    public:
    Hash(){
        size = 1;
        quantity = 0;
        table = new Node*[size];
        // We don't need to initialize the sentinel Node
        for(int i = 0; i < size; i++) table[i] = &sent; // We built this loop for a case that size is major than 1
        //T[0] receive a pointer to sent
    }

    ~Hash(){

    }

    void insert(int key, double value){
        if(quantity == size) reshape(2*size);
        int i = hash(key);
        table[i] = new Node {table[i], key, value};
        quantity ++;
    }

    
};