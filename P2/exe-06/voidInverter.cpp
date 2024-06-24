#include <iostream>

using namespace std;

void display(double *vetor, int size){
    for(int i = 0; i < size; i++){
        cout << vetor[i] << " ";
    }
    cout << endl;
}

void inverter (double *p, int n){
    double *inicio = p;
    double *fim = p + (n - 1);

    while(inicio < fim){
        double temp = *inicio;
        *inicio = *fim;
        *fim = temp;

        inicio ++;
        fim --;
    }
}
int main(){
    double vetor[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int size = sizeof(vetor)/sizeof(vetor[0]);

    cout << "Vetor Original: ";
    display(vetor, size);

    inverter(vetor, size);

    cout << "Vetor Invertido: ";
    display(vetor, size);


}