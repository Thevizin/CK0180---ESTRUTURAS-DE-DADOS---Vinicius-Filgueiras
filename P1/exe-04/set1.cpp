#include <iostream>
using namespace std;

struct Set {
    int set[10];
    int size = 0;
};

bool empty(Set &set){
    return(set.size == 0);
}

bool full(Set &set){
    return(set.size == 10);
}

bool belongs(Set &set, int value){
    if(!empty(set)){
        for(int i=0; i < set.size; i++){
            if(set.set[i] == value) return true;
        }
    }
    else return false;
    return false;
}

int search(Set &set, int value){
    if(!empty(set)){
        for(int i=0; i < set.size; i++){
            if(set.set[i] == value) return i;
        }
    }
    else return -1;
    return -1;
}
    
void add(Set &set, int value){
    if(!full(set) && !belongs(set, value)){
        set.set[set.size] = value;
        set.size ++;
        cout << value << " Added" << endl;
    }
    else cout << "The set is full or the value already exists" << endl;
}

void remove(Set &set, int value){
    if(!empty(set)){
        int i = search(set, value);
        if(i == -1) cout << "The value does not exist";
        else{
            cout << set.set[i] << " removed" << endl;
            set.set[i] = set.set[set.size - 1];
            set.size --;
        }
    }
    else cout << "The element is empty" << endl;
}

void display(Set &set){
    if(empty(set)) cout << "Set is empty" << endl;
    else{
        cout << "Set: ";
        for(int i = 0; i < set.size; i++){
            cout << set.set[i] << " ";
        }
        cout << endl;
    }
}

int main(){
    Set s;
    add(s, 1);
    add(s, 2);
    add(s, 3);
    add(s, 4);
    display(s);
    add(s, 5);
    display(s);
    remove(s, 3);
    display(s);
}

