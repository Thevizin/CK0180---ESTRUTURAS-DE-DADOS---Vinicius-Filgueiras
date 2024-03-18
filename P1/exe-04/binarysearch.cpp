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

int searchrecursive(int arr[], int value, int first, int last){
    if(first > last){
        return -1;
    }
    int mid = first + (last - first) / 2;
    if(arr[mid] == value){
        return mid;
    }
    else if(arr[mid] < value){
        return searchrecursive(arr, value, mid+1, last);
    }
    else{
        return searchrecursive(arr, value, first, mid-1);
    }
}

int search(Set &set, int value){
    if(belongs(set, value)){
        return searchrecursive(set.set, value, 0, set.size - 1);
    }
    else return -1;
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
    add(s, 3);
    add(s, 4);
    display(s);
    add(s, 5);
    display(s);
    remove(s, 3);
    display(s);
}

