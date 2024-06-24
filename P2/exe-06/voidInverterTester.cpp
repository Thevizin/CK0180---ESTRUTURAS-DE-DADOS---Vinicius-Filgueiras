#include <iostream>
using namespace std;

void display(double *vetor, int size){
    for(int i = 0; i < size; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void adder(double *vetor, int size){
    cout << "Enter the numbers you chose: " << endl;
    for(int i= 0; i < size; i++){
        cout << i + 1 <<": ";
        cin >> vetor[i];
    }
    cout << endl;
}

void inverter(double *vetor, int size){
    double *inicio = vetor;
    double *fim = vetor + (size - 1);

    while(inicio < fim){
        double temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        
        inicio ++;
        fim --;
    }
}

int main(){
   double vetor[10]; int size;
   cout << "Select a number from 1 to 10: ";
   cin >> size;
   adder(vetor, size);

   cout << "Vetor Original: ";
   display(vetor, size);
   
   inverter(vetor, size);
   
   cout << "Vetor Invertido: ";
   display(vetor, size);
}