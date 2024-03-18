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
    int first = 0;
    int last = set.size - 1;
    while(first <= last){
        int mid = (first + last)/2;
        if(set.set[mid] == value) return true;
        else if (set.set[mid] < value) first = mid + 1;
        else last = mid - 1;
    }
    return false;
}

int search(Set &set, int value){
    if(belongs(set, value)){
        int first = 0;
        int last = set.size - 1;
        while (first <= last) {
            int mid = (first + last) / 2;
            if (set.set[mid] == value) {
                return mid;
            } else if (set.set[mid] < value) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }
    } else {
        return -1; 
    }
    return -1;
}
    
void add(Set &set, int value){
    if(full(set)){
        cout << "The set is full" << endl;
        return;
    }
    int first = 0;
    int last = set.size - 1;
    int insert_position = set.size;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (set.set[mid] == value) {
            cout << "The element already belongs to the set" << endl;
            return;
        } else if (set.set[mid] < value) {
            first = mid + 1;
        } else {
            last = mid - 1;
            insert_position = mid;
        }
    }
    for(int i = set.size -1; i > last - 1; i--){
        set.set[i + 1] = set.set[i];
    }
    set.set[insert_position] = value;
    set.size++;
    cout << value << " Added" << endl;
}

void remove(Set &set, int value){
    if(!empty(set)){
        int j = search(set, value);
        if(j == -1) cout << "The value does not exist";
        else{
            cout << set.set[j] << " removed" << endl;
            for(int i = j; i < set.size - 1; i++) set.set[i] = set.set[i + 1];
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
    add(s, 4);
    add(s, 5);
    display(s);
    add(s, 6);
    display(s);
    remove(s, 2);
    display(s);
    add(s, 3);
    display(s);
}

