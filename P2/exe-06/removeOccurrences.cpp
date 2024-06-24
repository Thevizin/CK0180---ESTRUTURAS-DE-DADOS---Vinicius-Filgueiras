#include <iostream>

using namespace std;

void display(double *array, int size){
    cout << endl;
    cout << "Iniciando Display..." << endl;
    for(int i=0; i < size; i++){
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

void reduce(double *array, int &size, int place){
    for(int i = place; i < size - 1; i ++){
        array[i] = array[i+1];
    }
    size --;
}

void remove(double *array, int &size, double value){
    int counter = size;
    for(int i = 0; i<size; i++){
        if(array[i] == value){
            counter --;
            reduce(array, size, i);
            i--; 
        }
    }
     cout << counter << " " << size << endl;
}

void adder(double *array, int size){
    cout << "Adicione os valores do Array: " << endl;
    for(int i = 0; i < size; i++){
        cout << i + 1 << ": ";
        cin >> array[i];
    }
}

int main(){
    int size;
    cout << "Digite o tamanho do array: ";
    cin >> size;
    double *array = new double[size];
    adder(array, size);
    display(array, size);
    remove(array, size, 2.0);
    display(array, size);
    delete[] array; 
    return 0;
}
